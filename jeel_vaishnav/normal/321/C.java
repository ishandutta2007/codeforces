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

	void dfsFindSize(int i, int par) {
		size[i] = 1;
		for(int j : adj[i]) {
			if(j != par && isActive[j]) {
				dfsFindSize(j, i);
				size[i] += size[j];
			}
		}
	}

	void decompose(int i, int curlevel) {
		dfsFindSize(i, -1);

		int curCentroid = i;
		int curpar = -1;
		boolean foundCentroid = false;

		while(!foundCentroid) {
			boolean centroidFlag = true;
			int possibleCentroid = -1;

			for(int j : adj[curCentroid]) {
				if(j != curpar && isActive[j]) {
					if(size[j] >= size[i] / 2) {
						centroidFlag = false;
						possibleCentroid = j;
					}
				}
				if(!centroidFlag)
					break;
			}

			curpar = curCentroid;

			if(!centroidFlag)
				curCentroid = possibleCentroid;
			else
				foundCentroid = true; 
		}

		isActive[curCentroid] = false;

		for(int j : adj[curCentroid]) {
			if(isActive[j])
				decompose(j, curlevel + 1);
		}

		level[curCentroid] = curlevel;
	}

	ArrayList<Integer> adj[];
	int size[];
	int level[];
	boolean isActive[];

	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = sc.nextInt();

		adj = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			adj[i] = new ArrayList<>();

		for(int i = 0; i < n - 1; ++i) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			adj[u].add(v);
			adj[v].add(u);
		}

		size = new int[n];
		level = new int[n];
		isActive = new boolean[n];
		Arrays.fill(isActive, true);
		decompose(0, 0);

		for(int i = 0; i < n; ++i)
			w.print((char)(level[i] + 'A') + " ");

		w.close();	
   	}
}