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
    
    void updateSegTree(int low, int high, int pos, int l, int r, int val) {
        if(lazy[pos] != -1) {
            segTree[pos] = lazy[pos];
            if(low != high) {
                lazy[2 * pos + 1] = lazy[pos];
                lazy[2 * pos + 2] = lazy[pos];
            }
            lazy[pos] = -1;
        }
        
        if(l > high || r < low) return;
        
        if(low >= l && high <= r) {
            segTree[pos] = val;
            if(low != high) {            
                lazy[2 * pos + 1] = val;
                lazy[2 * pos + 2] = val;
            }
            return;
        }
        
        int mid = (low + high) >> 1;
        
        updateSegTree(low, mid, 2 * pos + 1, l, r, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r, val);
    }
    
    int querySegTree(int low, int high, int pos, int ind) {
        if(lazy[pos] != -1) {
            segTree[pos] = lazy[pos];
            if(low != high) {
                lazy[2 * pos + 1] = lazy[pos];
                lazy[2 * pos + 2] = lazy[pos];
            }
            lazy[pos] = -1;
        }
        if(low > ind || high < ind)
            return -1;
        if(low == high)
            return segTree[pos];
        int mid = (low + high) >> 1;
        int val1 = querySegTree(low, mid, 2 * pos + 1, ind);
        int val2 = querySegTree(mid + 1, high, 2 * pos + 2, ind);
        if(val1 == -1)
            return val2;
        else
            return val1;
    }
    
    int segTree[], lazy[];
    
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = sc.nextInt();
        
        TreeMap<Long, Integer> map = new TreeMap<>();
        
        long a[] = new long[n];
        
        for(int i = 0; i < n; ++i) 
            a[i] = sc.nextLong();
        
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            map.put(a[i], 1);
        
        for(long i : map.keySet())
            map.put(i, cnt++);
        
        segTree = new int[4 * cnt];
        lazy = new int[4 * cnt];
        
        Arrays.fill(lazy, -1);
        
        int min[] = new int[n];
        int max[] = new int[n];
        int parent[] = new int[n];
        
        parent[0] = -1;
        min[0] = 0;
        max[0] = cnt - 1;
        updateSegTree(0, n - 1, 0, 0, cnt - 1, 0);
        
        for(int i = 1; i < n; ++i) {
            parent[i] = querySegTree(0, n - 1, 0, map.get(a[i]));
            //w.println(parent[i]);
            if(a[i] > a[parent[i]]) {
                min[i] = map.get(map.higherKey(a[parent[i]]));
                max[i] = max[parent[i]];
                updateSegTree(0, n - 1, 0, min[i], max[i], i);
            }
            else {
                min[i] = min[parent[i]];
                max[i] = map.get(a[parent[i]]);
                updateSegTree(0, n - 1, 0, min[i], max[i], i);
            }
        }
        
        /*for(int i = 0; i < n; ++i)
        {
            w.println(map.get(a[i]));
            w.println(min[i] + " " + max[i]);
        }*/
        
        for(int i = 1; i < n; ++i)
            w.print(a[parent[i]] + " ");
		
		w.close();
	}
}