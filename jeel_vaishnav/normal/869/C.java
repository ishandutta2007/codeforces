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
    
    long fast_pow(long a, long b)
    {
        if(b == 0)
            return 1;
        long val = fast_pow(a, b / 2);
        if((b & 1) == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    
	long mod = 998244353;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        long fact[] = new long[5001];
        long factinv[] = new long[5001];
        
        fact[0] = 1;
        factinv[0] = fast_pow(1, mod - 2);
        for(int i = 1; i <= 5000; ++i)
        {
            fact[i] = (fact[i - 1] * i) % mod;
            factinv[i] = fast_pow(fact[i], mod - 2);
        }
        
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        
        //xy
        long ans1 = 0;
        for(int i = 0; i <= min(x, y); ++i)
        {
            long curans = fact[x] * fact[y] % mod * factinv[i] % mod * factinv[x - i] % mod * factinv[y - i] % mod;
            ans1 = (ans1 + curans) % mod;
        }
        
        long ans2 = 0;
        for(int i = 0; i <= min(x, z); ++i)
        {
            long curans = fact[x] * fact[z] % mod * factinv[i] % mod * factinv[x - i] % mod * factinv[z - i] % mod;
            ans2 = (ans2 + curans) % mod;
        }
        
        long ans3 = 0;
        for(int i = 0; i <= min(y, z); ++i)
        {
            long curans = fact[y] * fact[z] % mod * factinv[i] % mod * factinv[y - i] % mod * factinv[z - i] % mod;
            ans3 = (ans3 + curans) % mod;
        }
        
        long ans = ans1 * ans2 % mod * ans3 % mod;
        w.print(ans);
        
		w.close();
	}
}