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
    int[] find(int i, int decider)
    {
        if(map.get(i) != null && map.get(i).get(decider) != null)
            return map.get(i).get(decider);
        if(i == n - 1)
        {
            int ans[] = new int[2];
            ans[decider] = a[i];
            ans[decider ^ 1] = 0;
            if(map.get(i) == null)
                map.put(i, new HashMap<>());
            map.get(i).put(decider, ans);
            return ans;
        }
        int ans[];
        int temp3[] = find(i + 1, decider ^ 1);
        int temp4[] = find(i + 1, decider);
        int temp[] = new int[2];
        int temp2[] = new int[2];
        temp[0] = temp3[0];
        temp[1] = temp3[1];
        temp2[0] = temp4[0];
        temp2[1] = temp4[1];
        temp[decider] += a[i];
        temp2[decider ^ 1] += a[i];
        if(temp[decider] > temp2[decider])
            ans = temp;
        else
            ans = temp2;
        if(map.get(i) == null)
            map.put(i, new HashMap<>());
        map.get(i).put(decider, ans);
        return ans;
    }
    int n, a[];
    HashMap<Integer, HashMap<Integer, int[]>> map = new HashMap<>();
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        n = sc.nextInt();
        a = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        int ans[] = find(0, 1);
        w.print(ans[0] + " " + ans[1]);
		w.close();		
	}
}