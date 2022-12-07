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
	void querySegTree(int low, int high, int pos, int l, int r, int x) {
		if(chances > 1)
			return;
		if(low > r || high < l)
			return;
		if(low >= l && high <= r) {
			if(segTree[pos] % x == 0)
				return;
			if(low == high && segTree[pos] % x != 0) {
				chances++;
				return;
			}
			int mid = (low + high) >> 1;
			if(segTree[2 * pos + 1] % x != 0 && segTree[2 * pos + 2] % x != 0) {
				chances = 2;
				return;
			}
			else if(segTree[2 * pos + 1] % x != 0)
				querySegTree(low, mid, 2 * pos + 1, l, r, x);
			else if(segTree[2 * pos + 2] % x != 0)
				querySegTree(mid + 1, high, 2 * pos + 2, l, r, x);
			return;
		}
		int mid = (low + high) >> 1;
		querySegTree(low, mid, 2 * pos + 1, l, r, x);
		querySegTree(mid + 1, high, 2 * pos + 2, l, r, x);
	}
	void updateSegTree(int low, int high, int pos, int ind, int val) {
		if(low > ind || high < ind) {
			return;
		}
		if(low == high) {
			segTree[pos] = val;
			return;
		}
		int mid = (low + high) >> 1;
		updateSegTree(low, mid, 2 * pos + 1, ind, val);
		updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
		segTree[pos] = getGcd(segTree[2 * pos + 1], segTree[2 * pos + 2]);
	}
	int getGcd(int a, int b) {
		if(a == 0)
			return b;
		return getGcd(b % a, a);
	}
	int segTree[];
	int chances = 0;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = sc.nextInt();

		int a[] = new int[n];

		for(int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
		}

		segTree = new int[4 * n];

		for(int i = 0; i < n; ++i)
			updateSegTree(0, n - 1, 0, i, a[i]);

		int q = sc.nextInt();

		for(int p = 0; p < q; ++p){
			int type = sc.nextInt();
			if(type == 1) {
				chances = 0;
				int l = sc.nextInt() - 1;
				int r = sc.nextInt() - 1;
				int x = sc.nextInt();
				querySegTree(0, n - 1, 0, l, r, x);
				if(chances <= 1) 
					w.println("YES");
				else
					w.println("NO");
			}
			else {
				int ind = sc.nextInt() - 1;
				int val = sc.nextInt();
				updateSegTree(0, n - 1, 0, ind, val);
			}
		}

		w.close();	
   	}
}