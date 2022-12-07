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
    int msb(int mask) {
        int lastBit = 0;
        for(int i = 1; i <= 29; ++i) {
            if((mask >> i & 1) == 1)
                lastBit = i;
        }
        return lastBit;
    }
    int getGrundy(int mask) {
        if(map.get(mask) != null)
            return map.get(mask);
        HashMap<Integer, Integer> curmap = new HashMap<>();
        int curmask = 1;
        int mex[] = new int[30];
        for(int i = 1; i <= msb(mask); ++i) {
            int recmask = (mask & curmask) | (mask >> i);
            int val = getGrundy(recmask);
            mex[val] = 1;
            curmask |= (1 << i);
        }
        for(int i = 0; i <= 29; ++i) {
            if(mex[i] == 0) {
                map.put(mask, i);
                break;
            }
        }
        return map.get(mask);
    }
    HashMap<Integer, Integer> map = new HashMap<>();
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
       
        int n = sc.nextInt();
        int a[] = new int[n];
        
        int prime[] = new int[9592];
        int curp = 0;
        int sieve[] = new int[100001];
        
        for(int i = 2; i <= 100000; ++i) {
            if(sieve[i] == 0) {
                prime[curp++] = i;
                for(int j = i; j <= 100000; j += i) {
                    sieve[j] = i;
                }
            }
        }
        
        int mask[] = new int[9592];
        HashMap<Integer, Integer> largePrimes = new HashMap<>();
        
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
            
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 9592; ++j) {
                int cnt = 0;
                while(a[i] % prime[j] == 0) {
                    a[i] /= prime[j];
                    cnt++;
                }
                mask[j] |= (1 << cnt);
            }
            if(a[i] != 1)
                largePrimes.put(a[i], 1);
        }
        
        int nimSum = 0;
        
        if(largePrimes.size() % 2 == 1)
            nimSum = 1;
            
        map.put(1, 0);
        for(int i = 0; i < 9592; ++i) {
            nimSum ^= getGrundy(mask[i]);
            
        }
        
        if(nimSum != 0)
            w.print("Mojtaba");
        else
            w.print("Arpa");
        
		w.close();
	}
}