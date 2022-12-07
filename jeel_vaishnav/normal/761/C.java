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
	
    void find(int i, int lvl)
    {
        if(lvl == 3)
        {
            ans = min(ans, cnt[arr[0]][0] + cnt[arr[1]][1] + cnt[arr[2]][2]);
            ans = min(ans, cnt[arr[0]][1] + cnt[arr[1]][2] + cnt[arr[2]][0]);
            ans = min(ans, cnt[arr[0]][2] + cnt[arr[1]][0] + cnt[arr[2]][1]);
            ans = min(ans, cnt[arr[0]][0] + cnt[arr[1]][2] + cnt[arr[2]][1]);
            ans = min(ans, cnt[arr[0]][1] + cnt[arr[1]][0] + cnt[arr[2]][2]);
            ans = min(ans, cnt[arr[0]][2] + cnt[arr[1]][1] + cnt[arr[2]][0]);
            return;
        }
        for(int j = i + 1; j < n; ++j)
        {
            arr[lvl] = j;
            find(j, lvl + 1);
        }
    }
    
    int arr[] = new int[3];
    int cnt[][];
    int n;
    int ans =Integer.MAX_VALUE;
    
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w1 = new PrintWriter(System.out);
        n = sc.nextInt();
        int m = sc.nextInt();
        
        String s[] = new String[n];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next();
            
        cnt = new int[n][3];
        for(int i = 0; i < n; ++i)
            Arrays.fill(cnt[i], Integer.MAX_VALUE);
        
        for(int i = 0; i < n; ++i)
        {
            int ind[] = new int[3];
            Arrays.fill(ind, -1);
            for(int j = 0; j < m; ++j)
            {
                if(s[i].charAt(j) >= 'a' && s[i].charAt(j) <= 'z')
                {
                    ind[0] = j;
                    if(cnt[i][0] == Integer.MAX_VALUE)
                        cnt[i][0] = j;
                }
                else if(s[i].charAt(j) >= '0' && s[i].charAt(j) <= '9')
                {
                    ind[1] = j;
                    if(cnt[i][1] == Integer.MAX_VALUE)
                        cnt[i][1] = j;
                }
                else
                {
                    ind[2] = j;
                    if(cnt[i][2] == Integer.MAX_VALUE)
                        cnt[i][2] = j;
                }
            }
   
            cnt[i][0] = min(cnt[i][0], m - ind[0]);
            cnt[i][1] = min(cnt[i][1], m - ind[1]);
            cnt[i][2] = min(cnt[i][2], m - ind[2]);   
        }
        
        find(-1, 0);
        
        w1.print(ans);
        
 		w1.close();		
	}
}