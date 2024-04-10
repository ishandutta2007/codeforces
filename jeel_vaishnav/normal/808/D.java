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
        
        if(n == 1)
        {
            w.print("NO");
            w.close();
            return;
        }
        
        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();
        
        long prefix[] = new long[n];
        long suffix[] = new long[n];
        prefix[0] = a[0];
        suffix[n - 1] = a[n - 1];
        HashMap<Long, Integer> focc = new HashMap<>();
        HashMap<Long, Integer> locc = new HashMap<>();
        focc.put(a[0], 0);
        locc.put(a[0], 0);
        
        for(int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] + a[i];
            suffix[n - 1 - i] = suffix[n - i] + a[n - 1 -i];
            if(focc.get(a[i]) == null)
                focc.put(a[i], i);
            locc.put(a[i], i);
        }
        
        int flag = 0;
        
        if((prefix[n - 1] | 1) != prefix[n - 1] && focc.get(prefix[n - 1] >> 1) != null)
            flag = 1;
        
        for(int i = 0; i < n - 1 && flag != 1; ++i)
        {
            long sum1 = prefix[i];
            long sum2 = suffix[i + 1];
            long diff = Math.abs(sum2 - sum1);
            if((diff | 1) == diff)
                continue;
            if(sum1 > sum2)
            {
                long value = diff >> 1;
                if(focc.get(value) != null && focc.get(value) <= i)
                {
                    flag = 1;
                    break;
                }
            }
            else if(sum1 < sum2)
            {
                long value = diff >> 1;
                if(locc.get(value) != null && locc.get(value) >= i + 1)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            w.print("YES");
        else
            w.print("NO");
		w.close();		
	}
}