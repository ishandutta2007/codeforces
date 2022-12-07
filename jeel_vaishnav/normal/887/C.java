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
    
    void swap(int a[], int i, int j)
    {
        int temp = a[i - 1];
        a[i - 1] = a[j - 1];
        a[j - 1] = temp;
    }
    
    boolean check(int a[])
    {
        boolean flag = true;
        for(int i = 0; i < 6; ++i)
        {
            int color = a[4 * i];
            for(int j = 1; j < 4; ++j)
            {
                if(a[4 * i + j] != color)
                    flag = false;
            }
        }
        return flag;
    }
    
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int cube[][] = new int[12][24];
        
        for(int i = 0; i < 24; ++i)
        {
            cube[0][i] = sc.nextInt();
            for(int j = 1; j < 12; ++j)
                cube[j][i] = cube[0][i];
        }
        
        int flag = 0;
        
        //1
        swap(cube[0], 2, 6);
        swap(cube[0], 4, 8);
        swap(cube[0], 6, 10);
        swap(cube[0], 8, 12);
        swap(cube[0], 10, 23);
        swap(cube[0], 12, 21);
        if(check(cube[0]))
            flag = 1;
        
        //2
        swap(cube[1], 2, 23);
        swap(cube[1], 4, 21);
        swap(cube[1], 10, 23);
        swap(cube[1], 12, 21);
        swap(cube[1], 6, 10);
        swap(cube[1], 8, 12);
        if(check(cube[1]))
            flag = 1;
        
        //3
        swap(cube[2], 1, 5);
        swap(cube[2], 3, 7);
        swap(cube[2], 5, 9);
        swap(cube[2], 7, 11);
        swap(cube[2], 9, 24);
        swap(cube[2], 11, 22);
        if(check(cube[2]))
            flag = 1;
        
        //4
        swap(cube[3], 1, 24);
        swap(cube[3], 3, 22);
        swap(cube[3], 9, 24);
        swap(cube[3], 11, 22);
        swap(cube[3], 5, 9);
        swap(cube[3], 7, 11);
        if(check(cube[3]))
            flag = 1;
        
        //5
        swap(cube[4], 13, 5);
        swap(cube[4], 14, 6);
        swap(cube[4], 5, 17);
        swap(cube[4], 6, 18);
        swap(cube[4], 17, 21);
        swap(cube[4], 18, 22);
        if(check(cube[4]))
            flag = 1;
        
        //6
        swap(cube[5], 13, 21);
        swap(cube[5], 14, 22);
        swap(cube[5], 17, 21);
        swap(cube[5], 18, 22);
        swap(cube[5], 5, 17);
        swap(cube[5], 6, 18);
        if(check(cube[5]))
            flag = 1;
        
        //7
        swap(cube[6], 15, 7);
        swap(cube[6], 16, 8);
        swap(cube[6], 7, 19);
        swap(cube[6], 8, 20);
        swap(cube[6], 19, 23);
        swap(cube[6], 20, 24);
        if(check(cube[6]))
            flag = 1;
        
        //8
        swap(cube[7], 15, 23);
        swap(cube[7], 16, 24);
        swap(cube[7], 19, 23);
        swap(cube[7], 20, 24);
        swap(cube[7], 7, 19);
        swap(cube[7], 8, 20);
        if(check(cube[7]))
            flag = 1;
        
        //9
        swap(cube[8], 17, 10);
        swap(cube[8], 19, 9);
        swap(cube[8], 10, 16);
        swap(cube[8], 9, 14);
        swap(cube[8], 16, 3);
        swap(cube[8], 14, 4);
        if(check(cube[8]))
            flag = 1;
        
        //10
        swap(cube[9], 17, 3);
        swap(cube[9], 19, 4);
        swap(cube[9], 16, 3);
        swap(cube[9], 14, 4);
        swap(cube[9], 16, 10);
        swap(cube[9], 14, 9);
        if(check(cube[9]))
            flag = 1;
        
        //11
        swap(cube[10], 18, 12);
        swap(cube[10], 20, 11);
        swap(cube[10], 12, 15);
        swap(cube[10], 11, 13);
        swap(cube[10], 15, 1);
        swap(cube[10], 13, 2);
        if(check(cube[10]))
            flag = 1;
        
        //12
        swap(cube[11], 18, 1);
        swap(cube[11], 20, 2);
        swap(cube[11], 15, 1);
        swap(cube[11], 13, 2);
        swap(cube[11], 12, 15);
        swap(cube[11], 11, 13);
        if(check(cube[11]))
            flag = 1;
        
        if(flag == 1)
            w.print("YES");
        else
            w.print("NO");
        
		w.close();
	}
}