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
        Pair[] pair=new Pair[n];
        for(int i=0;i<n;i++)
            pair[i]=new Pair((double)(i+1),sc.nextDouble());
        int mflag=0;
        for(int i=1;i<n;i++)
        {
            int flag=0;
            double m1=0.0,m2=0.0,c1=0.0,c2=0.0;
            int cnt2=0;
            m1=(pair[i].y-pair[0].y)/(pair[i].x-pair[0].x);
            c1=pair[0].y-m1*pair[0].x;
            Pair pair2=new Pair(0.0,0.0);
            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    double value=m1*pair[j].x+c1;
                    if(value!=pair[j].y)
                    {
                        if(cnt2==0)
                        {
                            pair2=pair[j];
                            cnt2++;
                        }
                        else if(cnt2==1)
                        {
                            m2=(pair2.y-pair[j].y)/(pair2.x-pair[j].x);
                            c2=pair2.y-m2*pair2.x;
                            if(m2!=m1)
                            {
                                flag=1;
                                break;
                            }
                            cnt2++;
                        }
                        else
                        {
                            double value2=m2*pair[j].x+c2;
                            if(value2!=pair[j].y)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(cnt2==0)
                flag=1;
            if(flag==0)
            {
                mflag=1;
                break;
            }
        }
        double tm=(pair[2].y-pair[1].y)/(pair[2].x-pair[1].x);
        double tc=pair[1].y-tm*pair[1].x;
        int tflag=0;
        for(int i=3;i<n;i++)
        {
            double value=tm*pair[i].x+tc;
            if(value!=pair[i].y)
            {
                tflag=1;
                break;
            }
        }
        if(tm*pair[0].x+tc==pair[0].y)
            tflag=1;
        if(tflag==0)
            mflag=1;
        if(mflag==1)
            w.print("Yes");
        else
            w.print("No");
		w.close();		
	}
}
class Pair
{
    double x;
    double y;
    Pair(double x,double y)
    {
        this.x=x;
        this.y=y;
    }
}