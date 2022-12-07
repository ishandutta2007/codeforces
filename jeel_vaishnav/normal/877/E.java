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
    void updateSegTree(int low, int high, int pos, int l, int r)
    {
        if(low >= l  && high <= r)
        {
            if(lazy[pos] == 0)
            {
                segTree[pos] = (high - low + 1) - segTree[pos];
                if(low != high)
                {
                    lazy[2 * pos + 1] ^= 1;
                    lazy[2 * pos + 2] ^= 1;
                }
            }
            else
                lazy[pos] = 0;
            return;
        }
        if(low > r || high < l)
        {
            if(lazy[pos] == 1)
            {
                lazy[pos] = 0;
                segTree[pos] = (high - low + 1) - segTree[pos];
                if(low != high)
                {
                    lazy[2 * pos + 1] ^= 1;
                    lazy[2 * pos + 2] ^= 1;
                }
            }
            return;        
        }
        int mid = (low + high) >> 1;
        if(lazy[pos] == 1)
        {
            lazy[pos] = 0;
            lazy[2 * pos + 1] ^= 1;
            lazy[2 * pos + 2] ^= 1;
        }
        updateSegTree(low, mid, 2 * pos + 1, l, r);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }
    
    void printSegTree(int low, int high, int pos)
    {   
        if(low == high)
        {
            System.out.println(low + " " + high + " " + segTree[pos] + " " + lazy[pos]);
            return;
        }
        int mid = (low + high) >> 1;
        printSegTree(low, mid, 2 * pos + 1);
        printSegTree(mid + 1, high, 2 * pos + 2);
        System.out.println(low + " " + high + " " + segTree[pos] + " " + lazy[pos]);
    }
    
    int querySegTree(int low, int high, int pos, int l, int r)
    {   
        if(low >= l && high <= r)
        {   
            if(lazy[pos] == 1)
            {
                segTree[pos] = (high - low + 1) - segTree[pos];
                if(low != high)
                {
                    lazy[2 * pos + 1] ^= 1;
                    lazy[2 * pos + 2] ^= 1;
                }
                lazy[pos] = 0;
            }
            return segTree[pos];
        }
        if(low > r || high < l)
        {
            if(lazy[pos] == 1)
            {
                lazy[pos] = 0;
                segTree[pos] = (high - low + 1) - segTree[pos];
                if(low != high)
                {
                    lazy[2 * pos + 1] ^= 1;
                    lazy[2 * pos + 2] ^= 1;
                }
            }
            return 0;
        }
        int mid = (low + high) >> 1;
        if(lazy[pos] == 1)
        {
            lazy[pos] = 0;
            lazy[2 * pos + 1] ^= 1;
            lazy[2 * pos + 2] ^= 1;
        }
        int val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        int val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
        return val1 + val2;
    }
    
    void dfs(int i)
    {
        occ[i] = cur;
        eulerTour[cur++] = i;
        for(int j : adj[i])
            dfs(j);
        lastocc[i] = cur - 1;
    }
    
    int cur = 0;
    ArrayList<Integer> adj[];
    int occ[], lastocc[], eulerTour[];
    int segTree[], lazy[];
    
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
		
        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        
        occ = new int[n];
        lastocc = new int[n];
        eulerTour = new int[n];
        
        for(int i = 1; i < n; ++i)
        {
            int u = sc.nextInt() - 1;
            adj[u].add(i);
        }
        
        dfs(0);
        
        segTree = new int[4 * n];
        lazy = new int[4 * n];
        
        for(int i = 0; i < n; ++i)
        {
            if(sc.nextInt() == 1)
                updateSegTree(0, n - 1, 0, occ[i], occ[i]);
        }
        
        //printSegTree(0, n - 1, 0);
        
        int q = sc.nextInt();
        
        for(int x = 0; x < q; ++x)
        {
            String type = sc.next();
            if(type.equals("get"))
            {
                int u = sc.nextInt() - 1;
                w.println(querySegTree(0, n - 1, 0, occ[u], lastocc[u]));
            }
            else
            {
                int u = sc.nextInt() - 1;
                updateSegTree(0, n - 1, 0, occ[u], lastocc[u]);
                //printSegTree(0, n - 1, 0);
            }
        }
        
		w.close();
	}
}