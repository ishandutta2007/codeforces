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
    long getOrientation(Point p1, Point p2, Point p3)
    {
        long val = (p1.y - p2.y) * (p2.x - p3.x) - (p1.x - p2.x) * (p2.y - p3.y);
        
        if(val == 0)
            return 0;
        
        return val / abs(val);
    }
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        
        HashMap<Long, HashMap<Long, Integer>> map = new HashMap<>();
        
        Point p1[] = new Point[n];
        for(int i = 0; i < n; ++i)
        {
            p1[i] = new Point(sc.nextLong(), sc.nextLong());
            if(map.get(p1[i].x) == null)
                map.put(p1[i].x, new HashMap<>());
            map.get(p1[i].x).put(p1[i].y, 1);;
        }
        
        int m = sc.nextInt();
        
        Point p2[] = new Point[m];
        for(int i = 0; i < m; ++i)
        {
            p2[i] = new Point(sc.nextLong(), sc.nextLong());
            if(map.get(p2[i].x) != null && map.get(p2[i].x).get(p2[i].y) != null)
            {
                w.print("NO");
                w.close();
                return;
            }
        }
        
        Point point[] = new Point[n + m];
        
        for(int i = 0; i < n; ++i)
            point[i] = p1[i];
        
        for(int i = 0; i < m; ++i)
            point[n + i] = p2[i];
            
        Comparator<Point> pointSort = new Comparator<Point>()
        {
            public int compare(Point p1, Point p2)
            {
                if(p1.x < p2.x)
                    return -1;
                if(p1.x > p2.x)
                    return 1;
                if(p1.y < p2.y)
                    return -1;
                if(p1.y > p2.y)
                    return 1;
                return 0;
            }
        };
        
        Arrays.sort(point, pointSort);
        
        Arrays.sort(point, 1, n + m, new Comparator<Point>(){
            public int compare(Point p1, Point p2)
            {
                long val = getOrientation(point[0], p1, p2);
                
                return (int)-val;
            }
        }); 
        
        int ocur = n + m - 2;
        
        while(true)
        {
            long val = getOrientation(point[0], point[n + m - 1], point[ocur]);
            if(val == 0)
                ocur--;
            else
                break;
        }
        
        
        
        Arrays.sort(point , ocur + 1, n + m, new Comparator<Point>(){
            public int compare(Point p1, Point p2)
            {
                if(p1.x < p2.x)
                    return 1;
                if(p1.x > p2.x)
                    return -1;
                if(p1.y < p2.y)
                    return -1;
                if(p1.y > p2.y)
                    return 1;
                return 0;
            }
        });
        
        Stack<Point> stack = new Stack<>();
        
        stack.push(point[0]);
        
        for(int i = 1; i < n + m; ++i)
        {
            while(true)
            {
                if(stack.size() == 1)
                {   
                    stack.push(point[i]);
                    break;
                }
                
                Point cur = stack.pop();
                long val = getOrientation(stack.peek(), cur, point[i]);
                //w.println(stack.peek() + " " + cur + " " + point[i] + " " + val);
                if(val >= 0)
                {
                    stack.push(cur);
                    stack.push(point[i]);
                    break;
                }
            }
        }
        
        Point[] convexHull = new Point[stack.size()];
        
        for(int i = 0; i < convexHull.length; ++i)
            convexHull[i] = stack.pop();
        
        //for(int i = 0; i < convexHull.length; ++i)
            //w.println(convexHull[i]);
        
        Arrays.sort(convexHull, pointSort);
        Arrays.sort(p1, pointSort);
        
        if(convexHull.length != p1.length)
        {
            w.print("NO");
            w.close();
            return;
        }
        
        for(int i = 0; i < convexHull.length; ++i)
        {
            if(!convexHull[i].equals(p1[i]))
            {
                w.print("NO");
                w.close();
                return;
            }
        }
        
        w.print("YES");
        
		w.close();
	}
}
class Point
{
    long x;
    long y;
    Point(long a, long b)
    {
        x = a;
        y = b;
    }
    boolean equals(Point p)
    {
        if(x == p.x && y == p.y)
            return true;
        return false;
    }
    public String toString()
    {
        return x + " " + y;
    }
}