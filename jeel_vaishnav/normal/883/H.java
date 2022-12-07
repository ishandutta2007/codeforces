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
    
    long querySegTree(int low, int high, int pos, int l, int r)
    {
        if(low >= l && high <= r)
            return segTree[pos];
            
        if(low > r || high < l)
            return Long.MAX_VALUE;
       
        int mid = (low + high) >> 1;
        
        long val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return min(val1, val2);
    }
    
    void updateSegTree(int low, int high, int pos, int ind, long val)
    {
        if(low > ind || high < ind)
            return;
        if(low == high)
        {
            segTree[pos] = val;
            return;
        }
        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    
    long segTree[];
	
    public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        char s[] = sc.next().toCharArray();
        
        int freq[] = new int[150];
        for(int i = 0; i < n; ++i)
        {
            freq[s[i]]++;
        }
        
        int oddcnt = 0;
        for(int i = 0; i < 150; ++i)
        {
            if(freq[i] % 2 == 1)
                oddcnt++;
        }     
        
        if(oddcnt == 0 || oddcnt == 1)
        {
            w.println("1");
            char ans[] = new char[n];
            int cur = 0;
            for(int i = 0; i < 150; ++i)
            {
                while(freq[i] > 1)
                {
                    ans[cur] = (char)(i);
                    ans[n - 1 - cur] = (char)(i);
                    cur++;
                    freq[i] -= 2;
                }
            }
            for(int i = 0; i < 150; ++i)
            {
                if(freq[i] == 1)
                    ans[cur] = (char)(i);
            }
            w.print(ans);
        }
        else
        {
            int extoddcnt = 0;
            while(n % (oddcnt + extoddcnt) != 0 || (n / (oddcnt + extoddcnt) % 2 == 0))
                extoddcnt += 2;
            w.println((oddcnt + extoddcnt));
            int size = n / (oddcnt + extoddcnt);
            char parts[][] = new char[oddcnt + extoddcnt][size];
            int poss = size / 2;
            for(int i = 0; i < oddcnt + extoddcnt; ++i)
            {
                int alr = 0;
                int cur = 0;
                for(int j = 0; j < 150; ++j)
                {
                    while(freq[j] > 1 && alr < poss)
                    {
                        alr++;
                        freq[j] -= 2;
                        parts[i][cur] = (char)(j);
                        parts[i][size - 1 - cur] = (char)(j);
                        cur++;
                    }
                }
                    int flag = 0;
                    for(int j = 0; j < 150; ++j)
                    {
                        if(freq[j] % 2 == 1)
                        {
                            parts[i][cur] = (char)(j);
                            flag = 1;
                            freq[j]--;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        for(int j = 0; j < 150; ++j)
                        {
                           if(freq[j] > 0)
                           {
                                freq[j]--;
                                parts[i][cur] = (char)(j);
                                break;
                           }
                        }
                    }
                }
                
                for(int i = 0; i < oddcnt + extoddcnt; ++i)
                w.print(new String(parts[i]) + " ");
            }
		w.close();
	}
}