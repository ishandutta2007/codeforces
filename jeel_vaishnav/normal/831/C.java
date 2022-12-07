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
        int k=sc.nextInt();
        int n=sc.nextInt();
        int a[]=new int[k];
        int b[]=new int[n];
        for(int i=0;i<k;i++)
            a[i]=sc.nextInt();
        for(int i=0;i<n;i++)
            b[i]=sc.nextInt();
        for(int i=1;i<n;i++)
            b[i]=b[i]-b[0];
        int diff[][]=new int[k+1][k];
        for(int i=0;i<=k;i++)
        {
            int value=0;
            for(int j=i;j<k;j++)
            {
                value+=a[j];
                diff[i][j]=value;
            }
            value=0;
            for(int j=i-1;j>=0;j--)
            {
                value-=a[j];
                diff[i][j]=value;
            }
        }
        int count=0;
        ArrayList<Integer> check=new ArrayList<Integer>();
        for(int i=1;i<=k;i++)
        {
            HashMap<Integer,Integer> data=new HashMap<Integer,Integer>();
            for(int j=1;j<k;j++)
            {
                if(data.get(diff[i][j])==null)
                    data.put(diff[i][j],1);
                else
                {
                    int number=data.get(diff[i][j]);
                    data.put(diff[i][j],number+1);
                }
            }
            int flag=0;
            for(int j=1;j<n;j++)
            {
                if(data.get(b[j])==null)
                {
                    flag=1;
                    break;
                }
                else
                {
                    int number=data.get(b[j]);
                    if(number==1)
                        data.remove(b[j]);
                    else
                    {
                        data.put(b[j],(number-1));
                    }
                }
            }
            if(flag==0)
            {
           // w.println(diff[i][0]+" "+i);
                int flag1=0;
                for(int m=0;m<count;m++)
                {
                    if(check.get(m)==diff[i][0])
                        flag1=1;
                }
                if(flag1==0)
                {
                    count++;
                    check.add(diff[i][0]);
                }
            }
        }
        w.print(count);
		w.close();		
	}
}