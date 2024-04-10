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
    void compute(ArrayList<Integer> list)
    {   
        if(list.size() == 1)
        {
            int cur = list.get(0);
            for(int i = 0; i < 6; ++i)
                map.put(cube[cur][i], 1);
        }
        else if(list.size() == 2)
        {
            int cur = list.get(0);
            int cur2 = list.get(1);
            for(int i = 0; i < 6; ++i)
            {
                int num = cube[cur][i];
                if(num == 0)
                    continue;
                for(int j = 0; j < 6; ++j)
                    map.put(num * 10 + cube[cur2][j], 1);
            }
        }
        else
        {
            int cur = list.get(0);
            int cur2 = list.get(1);
            int cur3 = list.get(2);
            for(int i = 0; i < 6; ++i)
            {
                int num = cube[cur][i];
                if(num == 0)
                    continue;
                for(int j = 0; j < 6; ++j)
                {
                    int num2 = num * 10 + cube[cur2][j];
                    for(int k = 0; k < 6; ++k)
                        map.put(num2 * 10 + cube[cur3][k], 1);
                }
            }
        }
    }
    void permute(int len, int max, ArrayList<Integer> list)
    {
        if(len == max)
        {
            compute(list);
            return;
        }
        //System.out.print(n);
        for(int i = 0; i < n; ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                list.add(i);
                permute(len + 1, max, list);
                list.remove(list.size() - 1);
                visited[i] = 0;
            }
        }
    }
    int cube[][];
    HashMap<Integer, Integer> map = new HashMap<>();
    int visited[], n;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        n = sc.nextInt();
        cube = new int[n][6];
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 6; ++j)
                cube[i][j] = sc.nextInt();
        
        for(int i = 1; i <= n; ++i)
        {
            visited = new int[n];
            permute(0, i, new ArrayList<Integer>());
        }
		
        int ans = -1;
        
        for(int i = 1; i <= 1000000; ++i)
        {
            if(map.get(i) == null)
            {
                ans = i - 1;
                break;
            }
        }
        
        w.print(ans);
        
		w.close();
	}
}