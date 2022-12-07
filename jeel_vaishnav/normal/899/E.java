import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Main implements Runnable
{
	static class InputReader
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars)
			{
				curChar = 0;
				try 
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			return buf[curChar++];
		}
	 
		public String nextLine()
		{
			String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
		}
		public int nextInt()
		{
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			do 
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
		
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() 
		{
			return readString();
		}
		
		public interface SpaceCharFilter 
		{
			public boolean isSpaceChar(int ch);
		}
	}
 	
	public static void main(String args[]) throws Exception
	{
		new Thread(null, new Main(),"Main",1<<26).start();
	}
    long findAns(int n) {
        long ans = 1;
        for(long i = 0; i < n; ++i)
            ans *= 10;
        return ans;
    }
    long findValue(int n) {
        long ans = 0;
        long val = 1;
        for(int i = 0; i < n; ++i) {
            ans += 9 * val;
            val *= 10;
        }
        return (ans - 1) / 2;
    }
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
       
        int n = sc.nextInt();
        int a[] = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> rmap = new HashMap<>();
        HashMap<Integer, Integer> size = new HashMap<>();
        PriorityQueue<Pair> queue = new PriorityQueue(new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.size > p2.size)
                    return -1;
                if(p1.size < p2.size)
                    return 1;
                if(p1.l < p2.l)
                    return -1;
                if(p1.l > p2.l)
                    return 1;
                return 0;
            }
        });
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        int l = 0, r = -1;
        for(int i = 1; i < n; ++i) {
            if(a[i] != a[i - 1]) {
                r = i - 1;
                map.put(l, r);
                rmap.put(r, l);
                size.put(l, r - l + 1);
                queue.add(new Pair(l, r, r - l + 1));
                l = i;
            }
        }
        r = n - 1;
        map.put(l, r);
        rmap.put(r, l);
        size.put(l, r - l + 1);
        queue.add(new Pair(l, r, r - l + 1));
        int moves = 0;
        int prev[] = new int[n];
        int next[] = new int[n];
        for(int i = 0; i < n; ++i)
            prev[i] = i - 1;
        for(int i = 0; i < n; ++i)
            next[i] = i + 1;
        while(map.size() != 0) {
            Pair cur = queue.poll();
            if(map.get(cur.l) == null)
                continue;
            if(map.get(cur.l) != cur.r)
                continue;
            if(size.get(cur.l) != cur.size)
                continue;
            moves++;
            l = cur.l;
            r = cur.r;
            map.remove(l);
            rmap.remove(r);
            size.remove(l);
            if(next[r] != n) {
                prev[next[r]] = prev[l];
            }
            if(prev[l] != -1) { 
                next[prev[l]] = next[r];
            }
            if(next[r] == n || prev[l] == -1)
                continue;
            if(a[prev[l]] == a[next[r]]) {
                int oldl1 = rmap.get(prev[l]);
                int oldr1 = prev[l];
                int oldl2 = next[r];
                int oldr2 = map.get(next[r]);
                rmap.remove(oldr1);
                map.remove(oldl2);
                size.put(oldl1, size.get(oldl1) + size.get(oldl2));
                size.remove(oldl2);
                map.put(oldl1, oldr2);
                rmap.put(oldr2, oldl1);
                queue.add(new Pair(oldl1, oldr2, size.get(oldl1)));
            }
        }
        
        w.print(moves);
        
		w.close();
	}
}
class Pair {
    int l;
    int r; 
    int size;
    Pair(int l, int r, int size) {
        this.l = l;
        this.r = r;
        this.size = size;
    }
}