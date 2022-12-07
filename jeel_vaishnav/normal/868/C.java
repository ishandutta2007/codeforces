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
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < n; ++i)
        {
            int mat[] = new int[k];
            for(int j = 0; j < k; ++j)
                mat[j] = sc.nextInt();
            int flag = 0;
            for(int j = 0; j < k; ++j)
                if(mat[j] == 1)
                    flag = 1;
            if(flag == 0)
            {
                w.print("YES");
                w.close();
                return;
            }
            for(int p = 0; p < 2; ++p)
            {
                if(mat[0] == 1 && p == 1)
                    continue;
                if(k > 1)
                {
                    for(int q = 0; q < 2; ++q)
                    {
                        if(mat[1] == 1 && q == 1)
                            continue;
                        if(k > 2)
                        {
                            for(int r = 0; r < 2; ++r)
                            {
                                if(mat[2] == 1 && r == 1)
                                    continue;
                                if(k > 3)
                                {
                                    for(int s = 0; s < 2; ++s)
                                    {
                                        if(mat[3] == 1 && s == 1)
                                            continue;
                                        int val = p + 2 * q + 4 * r + 8 * s;
                                        if(map.get(val) != null)
                                        {
                                            w.print("YES");
                                            w.close();
                                            return;
                                        }
                                    }
                                }
                                else
                                {
                                    int val = p + 2 * q + 4 * r;
                                    if(map.get(val) != null)
                                    {
                                        w.print("YES");
                                        w.close();
                                        return;
                                    }
                                }
                            }
                        }
                        else
                        {
                            int val = p + 2 * q;
                            if(map.get(val) != null)
                            {
                                w.print("YES");
                                w.close();
                                return;
                            }
                        }
                    }
                }
                else
                {
                    int val = p;
                    if(map.get(val) != null)
                    {
                        w.print("YES");
                        w.close();
                        return;
                    }
                }
            }
            int val = 0;
            if(k >= 1)
                val += mat[0];
            if(k >= 2)
                val += 2 * mat[1];
            if(k >= 3)
                val += 4 * mat[2];
            if(k == 4)
                val += 8 * mat[3];
            map.put(val, 1);
        }
        w.print("NO");
        
		w.close();
	}
}