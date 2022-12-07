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
    
    void updateSegTree(int low, int high, int pos, int find, int val)
    {
        if(find < low || find > high)
            return;
        if(low == high)
        {
            segTree[pos] = val;
            return;
        }
        int mid = (low + high) / 2;
        updateSegTree(low, mid, 2 * pos + 1, find, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, find, val);
        segTree[pos] = min(segTree[2 * pos +1], segTree[2 * pos +2]);
    }
    
    int querySegTree(int low, int high, int pos, int l, int r)
    {
        if(low >= l && high <= r)
            return segTree[pos];
        if(low > r || high < l)
            return Integer.MAX_VALUE;
        int mid = (low + high) / 2;
        return min(querySegTree(low, mid, 2 * pos + 1, l, r), querySegTree(mid + 1, high, 2 * pos + 2, l, r));
    }
    int segTree[];
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
		int n = sc.nextInt();
        segTree = new int[4 * n];
        Arrays.fill(segTree, Integer.MAX_VALUE);
        ArrayList<Integer> adj[] = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        int a[] = new int[n], b[] = new int[n];
        for(int i = 0; i < n; ++i)
        {
            a[i] = sc.nextInt();
            b[i] = a[i];
        }
        Arrays.sort(b);
        for(int i = 0; i < n; ++i)
            map.put(b[i], i);
        int cur = 0;
        for(int i = 0; i < n; ++i)
        {
            int val = querySegTree(0, n - 1, 0, 0, map.get(a[i]));
            if(val == Integer.MAX_VALUE)
            {
                adj[cur++].add(a[i]);
                updateSegTree(0, n - 1, 0, map.get(a[i]), cur - 1);
            }
            else
            {
                adj[val].add(a[i]);
                updateSegTree(0, n - 1, 0, map.get(adj[val].get(adj[val].size() - 2)), Integer.MAX_VALUE);
                updateSegTree(0, n - 1, 0, map.get(a[i]), val);
            }
        }
        for(int i = 0; i < cur; ++i)
        {
            for(int j : adj[i])
                w.print(j + " ");
            w.println();
        }
		w.close();		
	}
}