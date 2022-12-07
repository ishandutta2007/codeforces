
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
    long fast_pow(long a, long b) {
        if(b == 0)
            return 1;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)  return val * val % mod;
        else return val * val % mod * a % mod;
    }
	long mod = (long)1e9 + 7;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        
        int a[] = new int[n];
        int freq[] = new int[71];
        int mask[] = new int[71];
        
        int prime[] = new int[19];
        int cur = 0;
        for(int i = 2; i <= 70; ++i) {
            int flag = 0;
            for(int j = 2; j < i; ++j) {
                if(i % j == 0)
                    flag = 1; 
            } 
            if(flag == 0)
                prime[cur++] = i;
        }  
        for(int i = 1; i <= 70; ++i) {
            int temp = i;
            for(int j = 0; j < 19; ++j) {
                int cnt = 0;
                while(temp % prime[j] == 0) {
                    temp /= prime[j];
                    cnt ^= 1;
                }
                if(cnt == 1)
                    mask[i] |= (1 << j);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            freq[a[i]]++;
        }
        
        long even[] = new long[71];
        long odd[] = new long[71];
        
        even[1] = fast_pow(2, freq[1]);
        for(int i = 2; i <= 70; ++i) {
            if(freq[i] == 0) {
                even[i] = 1;
                odd[i] = 0;
            }
            else {
                even[i] = fast_pow(2, freq[i] - 1);
                odd[i] = even[i];
            }
        }
        
        long dp[] = new long[1 << 19];
		long pdp[] = new long[1 << 19];
		pdp[0] = even[1];
        for(int i = 2; i <= 70; ++i) {
            for(int j = 0; j < (1 << 19); ++j) {
                dp[j] = (dp[j] + pdp[j] * even[i] % mod) % mod;
                dp[j] = (dp[j] + pdp[j ^ mask[i]] * odd[i] % mod) % mod;
                //System.out.println("y");
            }
			for(int j = 0; j < (1 << 19); ++j) {
				pdp[j] = dp[j];
				dp[j] = 0;
			}
        }
        
        w.println(pdp[0] - 1);
        
 		w.close();		
	}
}