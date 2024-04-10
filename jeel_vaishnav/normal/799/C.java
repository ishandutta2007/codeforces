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
    
    int binarySearch(ArrayList<Pair> list, int start, int end, int ub)
    {
        int ans = -1;
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            if(list.get(mid).cost <= ub)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        if(ans == -1)
            return 0;
        else
            return list.get(ans).beauty;
    }
    
    public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
        int n = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        ArrayList<Pair> coin = new ArrayList<>();
        ArrayList<Pair> diamond = new ArrayList<>();
        
        for(int i = 0; i < n; ++i)
        {
            int b = sc.nextInt();
            int co = sc.nextInt();
            if(sc.next().charAt(0) == 'C')
                coin.add(new Pair(b,co));
            else    
                diamond.add(new Pair(b,co));
        }
        
        Collections.sort(coin);
        Collections.sort(diamond);
        
        ArrayList<Pair> coin1 = new ArrayList<>();
        ArrayList<Pair> diamond1 = new ArrayList<>();
        
        for(int i = 0; i < coin.size(); ++i)
            coin1.add(new Pair(coin.get(i)));
        for(int i = 0; i < diamond.size(); ++i)
            diamond1.add(new Pair(diamond.get(i)));
        
        for(int i = 1; i < coin.size(); i++)
        {
            Pair cur = coin.get(i);
            cur.beauty = max(cur.beauty, coin.get(i - 1).beauty);
        }
        
        for(int i = 1; i < diamond.size(); ++i)
        {
            Pair cur = diamond.get(i);
            cur.beauty = max(cur.beauty, diamond.get(i - 1).beauty);
        }
        
        int ans = 0;
        
        int v1 = binarySearch(coin, 0, coin.size() - 1, c);
        int v2 = binarySearch(diamond, 0, diamond.size() - 1,  d);
        if(v1 > 0 && v2 > 0)
            ans = max(ans, v1 + v2);
        
        for(int i = 0; i < coin.size(); ++i)
        {
            Pair cur = coin1.get(i);
            if(cur.cost > c)
                break;
            int value = binarySearch(coin, 0, i - 1, c - cur.cost);
            if(value > 0)
                ans = max(ans, cur.beauty + value);
        }
        
        for(int i = 0; i < diamond.size(); ++i)
        {
            Pair cur = diamond1.get(i);
            if(cur.cost > d)
                break;
            int value = binarySearch(diamond, 0, i - 1, d - cur.cost);
            if(value > 0)
                ans = max(ans, cur.beauty + value);
        }
        
        w.print(ans);
        
		w.close();		
	}
}
class Pair implements Comparable<Pair>
{
    int beauty;
    int cost;
    Pair(int beauty, int cost)
    {
        this.beauty = beauty;
        this.cost = cost;
    }
    Pair(Pair p)
    {
        beauty = p.beauty;
        cost = p.cost;
    }
    public int compareTo(Pair p)
    {
        if(cost > p.cost)
            return 1;
        if(cost < p.cost)
            return -1;
        if(beauty > p.beauty)
            return -1;
        if(beauty < p.beauty)
            return 1;
        return 0;
    }
}