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
    boolean vowel(char i)
    {
        if(i == 'a' || i == 'e' || i == 'u' || i == 'o' || i == 'i')
            return true;
            return false;
    }
    int find(int x, int n, int a)
    {
		int found = x ^ 1;
        int size = (n % 2 == 0) ? n / 2 : n / 2 + 1;
        int start = 0, end = min(n - 1, size - 1);
        char ask[] = new char[n];
		if(found == 0)
			Arrays.fill(ask, '0');
		else	
			Arrays.fill(ask, '1');
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            for(int i = start; i <= end; ++i)
                ask[i] = (char)('0' + x);
            String temp = new String(ask);
            System.out.println("? " + temp);
            System.out.flush();
            int error = sc.nextInt();
            for(int i = start; i <= end; ++i)
                ask[i] = (char)('0' + found);
			if(end - start + 1 == 1 && (a - error) == 1)
				break;
            if((error - a) != (end - start + 1))
            {
                size = (size % 2 == 0) ? size / 2 : size / 2 + 1;
                end = min(n - 1, start + size - 1);
            }
            else
            {
                start = end + 1;
                size = (size % 2 == 0) ? size / 2 : size / 2 + 1;
                end = min(n - 1, start + size - 1);
            }
        }
        return start;
    }
    public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
	    int n = sc.nextInt();
        char ask[] = new char[n];
        int pos0, pos1;
        int found;
        Arrays.fill(ask,'0');
        String temp = new String(ask);
        System.out.println("? " + temp);
        System.out.flush();
        int error = sc.nextInt();
        ask[n - 1] = '1';
        temp = new String(ask);
        System.out.println("? " + temp);
        System.out.flush();
        int error2 = sc.nextInt();
        if(error2 == error - 1)
        {
            found = 1;
            pos1 = n - 1;
			Arrays.fill(ask, '1');
			temp = new String(ask);
			System.out.println("? " + temp);
			System.out.flush();
			int error3 = sc.nextInt();	
            pos0 = find(0, n, error3);
        }
        else
        {
            found = 0;
            pos0 = n - 1;
            pos1 = find(1, n, error);
        }
        w.print("! " + (pos0 + 1) + " " + (pos1 + 1));
		w.close();		
	}
}