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
    long queryBit(long[][] bit, int x, int y)
    {
        long curans = 0;
        for(int i = x; i > 0; i -= i & -i)
        {
            for(int j = y; j > 0; j -= j & -j)
                curans ^= bit[i][j];
        }
        return curans;
    }
    void updateBit(long[][] bit, int x, int y, long val)
    {
        for(int i = x; i < n + 3; i += i & -i)
        {
            for(int j = y; j < m + 3; j += j & -j)
                bit[i][j] ^= val;
        }
    }
    Random preRand = new Random();
    Random rand = new Random((long)preRand.nextInt(Integer.MAX_VALUE));
    long getHash()
    {
        return rand.nextLong();
    }
    long ind1[][], ind2[][];
    int n, m;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        n = sc.nextInt();
        m = sc.nextInt();
        
        long bit1[][] = new long[n + 3][m + 3];
        long bit2[][] = new long[n + 3][m + 3];
        
        ind1 = new long[n + 3][m + 3];
        ind2 = new long[n + 3][m + 3];
        
        for(int i = 0; i < n + 3; i++)
        {
            for(int j = 0; j < m + 3; j++)
            {
                ind1[i][j] = getHash();
                ind2[i][j] = getHash();
            }
        }        
        
        int q = sc.nextInt();
        
        for(int x = 0; x < q; ++x)
        {
            int type = sc.nextInt();
            if(type == 1 || type == 2)
            {
                int r1 = sc.nextInt() + 1;
                int c1 = sc.nextInt() + 1;
                int r2 = sc.nextInt() + 1;
                int c2 = sc.nextInt() + 1;
                long val1 = ind1[r1][c1];
                long val2 = ind2[r1][c1];
                updateBit(bit1, r1, c1, val1);
                updateBit(bit1, r1, c2 + 1, val1);
                updateBit(bit1, r2 + 1, c1, val1);
                updateBit(bit1, r2 + 1, c2 + 1, val1);
                updateBit(bit2, r1, c1, val2);
                updateBit(bit2, r1, c2 + 1, val2);
                updateBit(bit2, r2 + 1, c1, val2);
                updateBit(bit2, r2 + 1, c2 + 1, val2);
            }
            else
            {
                int r1 = sc.nextInt() + 1;
                int c1 = sc.nextInt() + 1;
                int r2 = sc.nextInt() + 1;
                int c2 = sc.nextInt() + 1;
                if(queryBit(bit1, r1, c1) == queryBit(bit1, r2, c2) && queryBit(bit2, r1, c1) == queryBit(bit2, r2, c2))
                    w.println("Yes");
                else
                    w.println("No");
            }
        }
    
		w.close();
	}
}