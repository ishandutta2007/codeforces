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
        
        int a[] = new int[n];
        
        for(int i = 0; i < n; ++i)  
            a[i] = sc.nextInt();
            
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < n; ++i) {
            if(map.get(a[i]) == null)
                map.put(a[i], 1);
            else
                map.put(a[i], map.get(a[i]) + 1);
        }
        
        int m = sc.nextInt();
		Movies[] movies = new Movies[m];
        
        for(int i = 0; i < m; ++i) {
            movies[i] = new Movies(i + 1, sc.nextInt(), 0);
        }
        
        for(int i = 0; i < m; ++i) {
            movies[i].c = sc.nextInt();
        }
        
        Arrays.sort(movies, new Comparator<Movies>() {
            public int compare(Movies m1, Movies m2) {
                if(map.get(m1.b) == null && map.get(m2.b) != null)
                    return 1;
                if(map.get(m1.b) != null && map.get(m2.b) == null)
                    return -1;
                if(map.get(m1.b) != null && map.get(m2.b) != null) {
                    if(map.get(m1.b) > map.get(m2.b))
                        return -1;
                    if(map.get(m1.b) < map.get(m2.b))
                        return 1;
                }
                if(map.get(m1.c) == null && map.get(m2.c) != null)
                    return 1;
                if(map.get(m1.c) != null && map.get(m2.c) == null)
                    return -1;
                if(map.get(m1.c) == null && map.get(m2.c) == null)
                    return 0;
                if(map.get(m1.c) > map.get(m2.c))
                    return -1;
                if(map.get(m1.c) < map.get(m2.c))
                    return 1;
                return 0;
            }
        });
        
        w.println(movies[0].ind);
        
		w.close();
	}
}
class Movies {
    int ind;
    int b;
    int c;
    Movies(int a, int x, int y) {
        ind = a;
        b = x;
        c = y;
    }
}