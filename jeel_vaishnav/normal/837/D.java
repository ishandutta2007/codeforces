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
    
    public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
        int n = sc.nextInt();
        int k = sc.nextInt();        
        int pow2[] = new int[n];
        int pow5[] = new int[n];
        
        for(int i = 0; i < n; ++i)
        {
            long a = sc.nextLong();
            
            while((a | 1) != a)
            {
                pow2[i]++;
                a >>= 1;
            }
             
            while(a % 5 == 0)
            {
                pow5[i]++;
                a /= 5;
            }
        }
        
        int dp[][] = new int[k + 1][5001];
        int pdp[][] = new int[k + 1][5001];
        
        for(int i = 0; i <= k; ++i)
        {
            for(int j = 0; j <= 5000; ++j)
                pdp[i][j] = -1;
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= k; ++j)
                for(int l = 0; l <= 5000; ++l)
                    dp[j][l] = -1;
            
            pdp[0][0] = max(pdp[0][0], 0);
            
            for(int j = 0; j <= k; ++j)
            {
                for(int l = 0; l <= 5000; ++l)
                {
                    if(pdp[j][l] != -1)
                    {
                        if(j + 1 <= k)
                            dp[j + 1][l + pow5[i]] = max(dp[j + 1][l + pow5[i]], pdp[j][l] + pow2[i]);
                        dp[j][l] = max(dp[j][l], pdp[j][l]);
                    }
                }
            }
            
            for(int j = 0; j <= k; ++j)
                for(int l = 0; l <= 5000; ++l)
                    pdp[j][l] = dp[j][l];
        }
        
        int ans = 0;
        for(int i = 0; i <= 5000; ++i)
            ans = max(ans, min(dp[k][i], i));
        
        w.print(ans);
        
        w.close();
	}
}