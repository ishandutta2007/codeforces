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
    long comb(int n, int r)
    {
        return fact[n] * factinv[r] % mod * factinv[n - r] % mod;
    }
    long fact[] = new long[1100001];
    long factinv[] = new long[1100001];
    long fast_pow(long a, long b)
    {
        if(b == 0)
            return 1;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    long mod = (long)1e9 + 7;
    public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        fact[0] = 1;
        for(int i = 1; i <= 1100000; ++i)
            fact[i] = fact[i - 1] * i % mod;
        for(int i = 0; i <= 1100000; ++i)
            factinv[i] = fast_pow(fact[i], mod - 2);
        
        int sieve[] = new int[1000001];
        
        for(int i = 2; i <= 1000000; ++i)
        {
            if(sieve[i] == 0)
            {
                for(int j = i; j <= 1000000; j += i)
                    sieve[j] = i;
            }
        }
        
        int q = sc.nextInt();
        
        for(int x = 0; x < q; ++x)
        {
            int n = sc.nextInt();
            int y = sc.nextInt();
            HashMap<Integer, Integer> map = new HashMap<>();
            if(n == 1)
            {
                long ans = fast_pow(2, y - 1);
                w.println(ans);
                continue;
            }
            while(sieve[n] != n)
            {
                if(map.get(sieve[n]) == null)
                    map.put(sieve[n], 1);
                else
                    map.put(sieve[n], map.get(sieve[n]) + 1);
                n /= sieve[n];
            }
           if(map.get(sieve[n]) == null)
                    map.put(sieve[n], 1);
                else
                    map.put(sieve[n], map.get(sieve[n]) + 1);
            long ans = fast_pow(2, y - 1);
            for(int i : map.keySet())
            {
                int val = map.get(i);
                ans = ans * comb(y + val - 1, val) % mod;
            }
            w.println(ans);
        }
        
		w.close();
	}
}