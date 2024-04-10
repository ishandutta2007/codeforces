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
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int a[] = new int[n];
		for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        
        long sum[] = new long[n+1];
        for(int i = n - 1; i >= 0; --i)
            sum[i] = sum[i + 1] + (long)a[i];
        
        long dp[][] = new long[n + 1][3];
        for(int i = 0; i <= n; ++i)
            Arrays.fill(dp[i], Long.MIN_VALUE);
        int sup[][] = new int[n + 1][3];
        
        long ans = Long.MIN_VALUE;
        int ans_i = -1;
        for(int i = 0; i <= n; ++i)
        {
            dp[i][0] = sum[0] - sum[i];
            
            for(int j = 0; j <= i; ++j)
            {
                if(dp[j][0] - sum[j] + sum[i] > dp[i][1])
                {
                    dp[i][1] = dp[j][0] - sum[j] + sum[i];
                    sup[i][1] = j;
                }
            }
            
            for(int j = 0; j <= i; ++j)
            {
                if(dp[j][1] + sum[j] - sum[i] > dp[i][2])
                {
                    dp[i][2] = dp[j][1] + sum[j] - sum[i];
                    sup[i][2] = j;
                }
            }
            
            if(dp[i][2] - sum[i] > ans)
            {
                ans = dp[i][2] - sum[i];
                ans_i = i;
            }
        }
        
        int res[] = new int[3];
        int cur = 3;
        while(cur != 0)
        {
            res[--cur] = ans_i;
            ans_i = sup[ans_i][cur];
        }
        
        for(int i = 0; i < 3; ++i)
            w.print(res[i] + " ");
        
        w.close();		
	}
}