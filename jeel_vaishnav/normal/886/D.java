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
    
    void dfsFindTopo(int i, int[] visited, int[] mask, Stack<Integer> topoSort)
    {
        visited[i] = 1;   
        
        int cnt = 0, exist = -1;
        for(int j = 0; j < 26; ++j)
        {
            if((mask[i] >> j & 1) == 1)
            {
                exist = j;
                cnt++;
            }
        }
        
        if(cnt == 0)
        {
            topoSort.push(i);
            return;
        }
        
        if(cnt > 1)
        {
            //System.out.println((char)('a' + i) + " D " + cnt);
            flag = 1;
            return;
        }
        
        if(visited[exist] == 0)
            dfsFindTopo(exist, visited, mask, topoSort);
        
        topoSort.push(i);
    }
    
    void dfs(int i, int[] visited, int[] mask)
    {
        visited[i] = 1;
        
        ans += (char)('a' + i);
        
        int exist = -1;
        for(int j = 0; j < 26; ++j)
        {
            if((mask[i] >> j & 1) == 1)
            {
                exist = j;
                break;
            }
        }
        if(exist == -1)
            return;
        if(visited[exist] == 1)
        {   
            flag = 1;
            return;
        }
        
        dfs(exist, visited, mask);
    }
    int flag = 0;
    String ans = "";
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
       
        int exist[] = new int[26];
        int mask[] = new int[26];
        
        int n = sc.nextInt();
        
        for(int x = 0; x < n; ++x)
        {
            char s[] = sc.next().toCharArray();
            for(int i = 0; i < s.length; ++i)
                exist[s[i] - 'a'] = 1;
            for(int i = 1; i < s.length; ++i)
                mask[s[i - 1] - 'a'] |= (1 << (s[i] - 'a'));
        }
        
        /*for(int i = 0; i < 26; ++i)
        {
            for(int j = 0; j < 26; ++j)
            {
                if((mask[i] >> j & 1) == 1)
                    w.print("1");
                else
                    w.print("0");
            }
            w.println();
        }*/
        int visited[] = new int[26];
        Stack<Integer> topoSort = new Stack<>();        
        
        for(int i = 25; i >= 0; --i)
        {
            if(visited[i] == 0 && exist[i] == 1)
                dfsFindTopo(i, visited, mask, topoSort);
        }
        
        if(flag == 1)
        {
            w.print("NO");
            w.close();
            return;
        }
        
        visited = new int[26];
        
        while(!topoSort.empty())
        {
            int i = topoSort.pop();
            if(visited[i] == 0)
                dfs(i, visited, mask);
        }
        
        if(flag == 1)
            w.print("NO");
        else
            w.print(ans);
        
		w.close();
	}
}