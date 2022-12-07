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
	int bitCount(int i) { 
		i = i - ((i >>> 1) & 0x55555555); 
		i = (i & 0x33333333) + ((i >>> 2) & 0x33333333); 
		i = (i + (i >>> 4)) & 0x0f0f0f0f; 
		i = i + (i >>> 8); 
		i = i + (i >>> 16); 
		return i & 0x3f; 
	}
	long fast_pow(long a, long b) {
		if(b == 0)
			return 1;
		long val = fast_pow(a, b / 2);
		if(b % 2 == 0)
			return val * val % mod;
		else
			return val * val % mod * a % mod;
	}
	long getComb(int n, int r) {
		return fact[n] * factinv[r] % mod * factinv[n - r] % mod;
	}
	long mod = (long)1e9 + 7;
	long fact[];
	long factinv[];
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		char s[] = sc.next().toCharArray();
		long ans = 0;
		int alrbits = 0;
		int k = sc.nextInt();

		if(k == 0) {
			w.print("1");
			w.close();
			return;
		}
		else if(k == 1) {
			w.print(s.length - 1);
			w.close();
			return;
		}

		int dp[] = new int[1001];


		dp[0] = 1000000;
		for(int i = 1; i <= 1000; ++i) {
			int temp = i;
			while(temp != 1) {
				dp[i]++;
				temp = bitCount(temp);
			}
		}

		fact = new long[1001];
		factinv = new long[1001];

		fact[0] = 1;
		factinv[0] = fast_pow(fact[0], mod - 2);

		for(int i = 1; i <= 1000; ++i) {
			fact[i] = fact[i - 1] * i % mod;
			factinv[i] = fast_pow(fact[i], mod - 2);
		}

		int leftBits = 0;

		for(int i = 0; i < s.length; ++i) {
			if(s[i] == '1') {
				int maxBits = s.length - 1 - i;
				for(int j = 0; j <= maxBits; ++j) {
					if(dp[j + alrbits] == k - 1) {
						ans = (ans + getComb(maxBits, j)) % mod;
					}
				}
				alrbits++;
			}
		}

		if(dp[alrbits] == k - 1)
			ans = (ans + 1) % mod;

		w.print(ans);

		w.close();	
   	}
}