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
    int querySegTree(int low, int high, int pos, int[] segTree, int[] lazy, int type, int l, int r) {
        if(lazy[pos] != 0) {
            if(type == 1)
                segTree[pos] = -1;
            else
                segTree[pos] = Integer.MAX_VALUE;
            if(low != high) {
                lazy[2 * pos + 1] = 1;
                lazy[2 * pos + 2] = 1;
            }
            lazy[pos] = 0;
        }
        if(low > r || high < l) {
            if(type == 1)
                return -1;
            else
                return Integer.MAX_VALUE;
        }
        if(low >= l && high <= r) 
            return segTree[pos];
        int mid = (low + high) >> 1;
        int val1 = querySegTree(low, mid, 2 * pos + 1, segTree, lazy, type, l, r);
        int val2 = querySegTree(mid + 1, high, 2 * pos + 2, segTree, lazy, type, l, r);
        if(type == 0)
            return min(val1, val2);
        else
            return max(val1, val2);
    }
    void updateSegTree(int low, int high, int pos, int[] segTree, int[] lazy, int type, int l, int r) {
        if(lazy[pos] != 0) {
            if(type == 1)
                segTree[pos] = -1;
            else
                segTree[pos] = Integer.MAX_VALUE;
            if(low != high) {
                lazy[2 * pos + 1] = 1;
                lazy[2 * pos + 2] = 1;
            }
            lazy[pos] = 0;
        }
        if(low > r || high < l) 
            return;
        if(low >= l && high <= r) {
            if(type == 1)
                segTree[pos] = -1;
            else
                segTree[pos] = Integer.MAX_VALUE;
            if(low != high) {
                lazy[2 * pos + 1] = 1;
                lazy[2 * pos + 2] = 1;
            }
            return;
        }
        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, segTree, lazy, type, l, r);
        updateSegTree(mid + 1, high, 2 * pos + 2, segTree, lazy, type, l, r);
        if(type == 0)
            segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        else
            segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    void buildSegTree(int low, int high, int pos, int[] segTree, int type) {
        if(low == high) {
            segTree[pos] = low;
            return;
        }
        int mid = (low + high) >> 1;
        buildSegTree(low, mid, 2 * pos + 1, segTree, type);
        buildSegTree(mid + 1, high, 2 * pos + 2, segTree, type);
        if(type == 0)
            segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        else
            segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = sc.nextInt();
        int m = sc.nextInt();
        int p = sc.nextInt() - 1;
        
        char s[] = sc.next().toCharArray();
        
        char opr[] = sc.next().toCharArray();
        
        Stack<Integer> stack = new Stack<Integer>();
        int pair[] = new int[n];
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(')
                stack.push(i);
            else {
                int cur = stack.pop();
                pair[cur] = i;
                pair[i] = cur;
            }
        }
        
        int[] segTree = new int[4 * n];
        int[] lazy = new int[4 * n];
        int[] segTree1 = new int[4 * n];
        int[] lazy1 = new int[4 * n];
        int[] prefix = new int[n];
        
        buildSegTree(0, n - 1, 0, segTree, 0);
        buildSegTree(0, n - 1, 0, segTree1, 1);
        
        for(int i = 0; i < m; ++i) {
            //w.println(p);
            if(opr[i] == 'L') {
                p = querySegTree(0, n - 1, 0, segTree1, lazy1, 1, 0, p - 1);
            }
            else if(opr[i] == 'R') {
                p = querySegTree(0, n - 1, 0, segTree, lazy, 0, p + 1, n - 1);
            }
            else {
                updateSegTree(0, n - 1, 0, segTree, lazy, 0, min(p, pair[p]), max(p, pair[p]));
                updateSegTree(0, n - 1, 0, segTree1, lazy1, 1, min(p, pair[p]), max(p, pair[p]));
                prefix[min(p, pair[p])]++;
                if(max(p, pair[p]) != n - 1)
                    prefix[max(p, pair[p]) + 1]--;
                p = querySegTree(0, n - 1, 0, segTree, lazy, 0, p + 1, n - 1); 
                if(p == Integer.MAX_VALUE)
                    p = querySegTree(0, n - 1, 0, segTree1, lazy1, 1, 0, p - 1);
            }
        }
        
        for(int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + prefix[i];
        
        for(int i = 0; i < n; ++i) {
            if(prefix[i] == 0)
                w.print(s[i]);
        }
        
        
        
		w.close();
	}
}