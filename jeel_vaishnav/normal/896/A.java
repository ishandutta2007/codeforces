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
    boolean find(int n, long k) {
        if(n == 0) {
            if(k >= (long)s.length) { 
                return false;
            }
            else {
                ans = s[(int)k];
                return true;
            }
        }
        if(n < 54 && k >= length[n]) return false;
        if(k < (long)fn1.length) {
            ans = fn1[(int)k];
            return true;
        }
        boolean tryv = find(n - 1, k - (long)fn1.length);
        if(tryv)
            return true;
        k -= (long)fn1.length;
        k -= length[n - 1];
        if(k < (long)fn2.length) {
            ans = fn2[(int)k];
            return true;
        }
        tryv = find(n - 1, k - (long)fn2.length);
        if(tryv)
            return true;
        k -= (long)fn2.length;
        k -= length[n - 1];
        if(k < (long)fn3.length) {
            ans = fn3[(int)k];
            return true;
        }
        return false;
    }
    char s[] = "What are you doing at the end of the world? Are you busy? Will you save us?".toCharArray();
    char fn1[] = "What are you doing while sending \"".toCharArray();
    char fn2[] = "\"? Are you busy? Will you send \"".toCharArray();
    char fn3[] = "\"?".toCharArray();
        
    long length[] = new long[54];
        
    char ans = '0';
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int q = sc.nextInt();
        
        length[0] = s.length;
        for(int i = 1; i < 54; ++i) {
            length[i] = 2 * length[i - 1] + fn1.length + fn2.length + fn3.length;
        }
        
        for(int i = 0; i < q; ++i) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            boolean tryv = find(n, k - 1);
            if(tryv)
                w.print(ans);
            else
                w.print(".");
        }
        
        
        
		w.close();
	}
}
class Queries {
    int ind;
    int n;
    long k;
    Queries(int c, int a, long b) {
        ind = c;
        n = a;
        k = b - 1;
    }
}