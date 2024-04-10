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
	static int max(int a,int b)
    {
        if(a>b)
            return a;
            else 
            return b;
    }
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
	    String board[]=new String[10];
        int flag=0;
        for(int i=0;i<10;i++)
        board[i]=sc.next();
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i<=5)
                {
                int count1=0,count2=0;
                    for(int k=i;k<=i+4;k++)
                    {
                        if(board[k].charAt(j)=='X')
                            count1++;
                        if(board[k].charAt(j)=='.')
                            count2++;    
                    }
                    if(count1==4&&count2==1)
                    flag=1;
                }
                if(j<=5)
                {
                int count1=0,count2=0;
                    for(int k=j;k<=j+4;k++)
                    {
                        if(board[i].charAt(k)=='X')
                            count1++;
                        if(board[i].charAt(k)=='.')
                            count2++;    
                    }
                    if(count1==4&&count2==1)
                    flag=1;
                }
                if(i<=5&&j<=5)
                {
                int count1=0,count2=0;
                    for(int k=0;k<=4;k++)
                    {
                        if(board[i+k].charAt(j+k)=='X')
                            count1++;
                        if(board[i+k].charAt(j+k)=='.')
                            count2++;    
                    }
                    if(count1==4&&count2==1)
                    flag=1;
                }
                if(i<=5&&j>=4)
                {
                int count1=0,count2=0;
                    for(int k=0;k<=4;k++)
                    {
                        if(board[i+k].charAt(j-k)=='X')
                            count1++;
                        if(board[i+k].charAt(j-k)=='.')
                            count2++;    
                    }
                    if(count1==4&&count2==1)
                    flag=1;
                }
            }
        }
        if(flag==1)
            w.print("YES");
        else
            w.print("NO");
		w.close();		
	}
}