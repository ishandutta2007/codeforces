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
        int m = sc.nextInt();
        
        if((n & 1) == 1)
        {
            w.print("-1");
            w.close();
            return;
        }
        
        int a[] = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>();
        int cntodd = 0, cnteven = 0;
        int uniodd = 0, unieven = 0;
        ArrayList<Integer> index = new ArrayList<>();
        
        for(int i = 0; i < n; ++i)
        {
            a[i] = sc.nextInt();
		    
            if(map.get(a[i]) == null)
            {
                map.put(a[i], i);
                if((a[i] & 1) == 0)
                    unieven++;
                else
                    uniodd++;
                if(a[i] <= m)
                {
                    if((a[i] & 1) == 0)
                        cnteven++;
                    else
                        cntodd++; 
                }
            }
            else
                index.add(i);
        }
        
        for(int j : map.keySet())
        {
            if(uniodd > n / 2)
            {
                if((j & 1) == 1)
                {
                    index.add(map.get(j));
                    uniodd--;
                }
            }
            else if(unieven > n / 2)
            {
                if((j & 1) == 0)
                {
                    index.add(map.get(j));
                    unieven--;
                }
            }
            else
                break;
        }
        
        if(uniodd == n / 2)
            cntodd = 0;
        if(unieven == n / 2)
            cnteven = 0;
        
        int reqodd = n / 2 - uniodd + cntodd, reqeven = n / 2 - unieven + cnteven;
        
        if(2 * reqodd - 1 > m || 2 * reqeven > m)
        {
            w.print("-1");
            w.close();
            return;
        }
        
        reqodd -= cntodd;
        reqeven -= cnteven;
        
        w.println(index.size());
        int point = 0;
        for(int i = 1;;i += 2)
        {
            if(reqodd == 0)
                break;
            if(map.get(i) == null)
            {
                a[index.get(point++)] = i;
                reqodd--;
            }
        }
        for(int i = 2;;i += 2)
        {
            if(reqeven == 0)
                break;
            if(map.get(i) == null)
            {
                a[index.get(point++)] = i;
                reqeven--;
            }
        }
        
        for(int i = 0; i < n; ++i)
            w.print(a[i] + " ");
        
        w.close();
	}
}