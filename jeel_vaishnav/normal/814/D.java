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
    
    double pow2(double a)
    {
        return a * a;
    }
    
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
        int n = sc.nextInt();
        Dancer dancer[] = new Dancer[n];
        for(int i = 0; i < n; ++i)
            dancer[i] = new Dancer(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
        
        Arrays.sort(dancer, new Comparator<Dancer>(){
            public int compare(Dancer d1, Dancer d2)
            {
                if(d1.r > d2.r)
                    return -1;
                if(d1.r < d2.r)
                    return 1;
                return 0;
            }
        });
        
        int level[] = new int[n];
        Arrays.fill(level, -1);
        for(int i = 0; i < n; ++i)
        {   
            for(int j = i - 1; j >= 0; --j)
            {
                double value = Math.sqrt(pow2(dancer[i].x - dancer[j].x) + pow2(dancer[i].y - dancer[j].y));
                if(value <= dancer[j].r)
                {
                    level[i] = level[j] + 1;
                    break;
                }
            }
        }
        
        double ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(level[i] == -1 || level[i] % 2 == 0)
                ans += Math.PI * dancer[i].r * dancer[i].r;
            else  
                ans -= Math.PI * dancer[i].r * dancer[i].r;
        }
        
        //for(int i = 0; i < n; ++i)
            //w.println(dancer[i].x + " " + dancer[i].y + " " + dancer[i].r + " " + level[i]);
        
        w.print(ans);
		w.close();		
	}
}
class Dancer
{
    double x;
    double y;
    double r;
    Dancer(double x, double y, double r)
    {
        this.x = x;
        this.y = y;
        this.r = r;
    }
}