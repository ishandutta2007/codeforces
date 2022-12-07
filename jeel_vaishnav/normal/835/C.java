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
        int n=sc.nextInt();
        int q=sc.nextInt();
        int c=sc.nextInt();
        Record record[][]=new Record[101][101];
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                record[i][j]=new Record();
            }
        }
        for(int i=0;i<n;i++)
        {
            record[sc.nextInt()][sc.nextInt()].bright.add(sc.nextInt());
        }
        Pos prefix[][]=new Pos[101][101];
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                prefix[i][j]=new Pos(c);
            }
        }
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                int present[]=new int[c+1];
                for(int k=0;k<record[i][j].bright.size();k++)
                {
                    present[record[i][j].bright.get(k)]++;
                }
                for(int k=0;k<=c;k++)
                {
                    prefix[i][j].bright[k]=prefix[i][j-1].bright[k]+prefix[i-1][j].bright[k]-prefix[i-1][j-1].bright[k]+present[k];
                }
            }
        }
        for(int x=0;x<q;x++)
        {
            int t=sc.nextInt();
            int x1=sc.nextInt();
            int y1=sc.nextInt();
            int x2=sc.nextInt();
            int y2=sc.nextInt();
            int ans=0;
            int finaled[]=new int[c+1];
            for(int i=0;i<=c;i++)
            {
                finaled[i]=prefix[x2][y2].bright[i]-prefix[x2][y1-1].bright[i]-prefix[x1-1][y2].bright[i]+                                                      prefix[x1-1][y1-1].bright[i];
            }
            for(int i=0;i<=c;i++)
            {
                int value=(i+t)%(c+1);
                //w.println(finaled[i]+" "+i);
                ans+=value*finaled[i];
            }
            w.println(ans);
        }
		w.close();		
	}
}
class Pos
{
    int bright[];
    Pos(int c)
    {
        bright=new int[c+1];
    }
}
class Record
{
    ArrayList<Integer> bright=new ArrayList<Integer>();
}