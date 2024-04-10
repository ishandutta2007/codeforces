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
        int k = sc.nextInt();
        
        int visited[][] = new int[n][m];
        
        for(int i = 0; i < n; ++i)
        {
            char s[] = sc.next().toCharArray();
            for(int j = 0; j < m; ++j)
            {
                if(s[j] == '#')
                    visited[i][j] = 1;
            }
        }
        
        int x1 = sc.nextInt() - 1;
        int y1 = sc.nextInt() - 1;
        int x2 = sc.nextInt() - 1;
        int y2 = sc.nextInt() - 1;
        
        if(x1 == x2 && y1 == y2)
        {
            w.print("0");
            w.close();
            return;
        }
        
        Queue<Point> queue = new LinkedList<Point>();
        queue.add(new Point(x1, y1));
        visited[x1][y1] = 1;
        
        int steps = 0;
        int flag = 0;
        main : while(!queue.isEmpty())
        {
            int len = queue.size();
            ArrayList<Point> list = new ArrayList<>();
            for(int p = 0; p < len; ++p)
            {
                Point cur = queue.poll();
                int x = cur.x, y = cur.y;
                if(cur.x == x2 && cur.y == y2)
                {
                    flag = 1;
                    break main;
                }        
                for(int i = 1; i <= k; ++i)
                {
                    if(x + i < n && visited[x + i][y] == 0)
                    {
                        visited[x + i][y] = 2;
                        queue.add(new Point(x + i, y));
                        list.add(new Point(x + i, y));
                    }
                    else if(x + i >= n || visited[x + i][y] == 1)
                        break;
                }
                for(int i = 1; i <= k; ++i)
                {
                    if(y + i < m && visited[x][y + i] == 0)
                    {
                        visited[x][y + i] = 2;
                        queue.add(new Point(x, y + i));
                        list.add(new Point(x, y + i));
                    }
                    else if(y + i >= m || visited[x][y + i] == 1)
                        break;
                }
                for(int i = 1; i <= k; ++i)
                {
                    if(x - i >= 0 && visited[x - i][y] == 0)
                    {
                        visited[x - i][y] = 2;
                        queue.add(new Point(x - i, y));
                        list.add(new Point(x - i, y));
                    }
                    else if(x - i < 0 || visited[x - i][y] == 1)
                        break;
                }
                for(int i = 1; i <= k; ++i)
                {
                    if(y - i >= 0 && visited[x][y - i] == 0)
                    {
                        visited[x][y - i] = 2;
                        queue.add(new Point(x, y - i));
                        list.add(new Point(x, y - i));
                    }
                    else if(y - i < 0 || visited[x][y - i] == 1)
                        break;
                }
            }
            for(Point q : list)
            {
                visited[q.x][q.y] = 1;
            }
            steps++;
        }
        
        if(flag == 0)
            w.print("-1");
        else
            w.print(steps);
        
		w.close();
	}
}
class Point
{
    int x;
    int y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
}