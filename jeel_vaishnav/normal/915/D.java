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
	class Vertex {
		HashMap<Integer, Integer> map = new HashMap<>();
	}
	void dfs(int i) {
		vis[i] = 2;
		for(int j : v[i].map.keySet()) {
			if(vis[j] == 2) {
				cycleFlag = true;
				cycleList.add(j);
				cycleList.add(i);
				return;
			}
			if(vis[j] == 0) {
				dfs(j);
			}
			if(cycleFlag) {
				if(i == cycleList.get(0)) {
					cycleList.add(cycleList.get(0));
					cycleFlag = false;
					returnFlag = true;
				}
				else {
					cycleList.add(i);
				}
				return;
			}
			if(returnFlag)
				return;
		}
		vis[i] = 1;
	}
	void dfsFindAns(int i) {
		vis[i] = 2;
		for(int j : v[i].map.keySet()) {
			if(vis[j] == 0)
				dfsFindAns(j);
			else if(vis[j] == 2)
				cycleFlag = true;
			if(cycleFlag)
				return;
		}
		vis[i] = 1;
	}
	ArrayList<Integer> cycleList = new ArrayList<>();
	Vertex v[];
	int vis[];
	boolean cycleFlag, returnFlag;
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
     	
		int n = sc.nextInt();	
		int m = sc.nextInt();

		v = new Vertex[n];
		for(int i = 0; i < n; ++i)
			v[i] = new Vertex();

		for(int i = 0; i < m; ++i) {
			int u = sc.nextInt() - 1;
			int x = sc.nextInt() - 1;
			v[u].map.put(x, 1);
		}

		vis = new int[n];
		
		for(int i = 0; i < n; ++i) {
			if(vis[i] == 0 && cycleList.size() == 0) {
				dfs(i);
			}
		}

		if(cycleList.size() == 0) {
			w.print("YES");
			w.close();
			return;
		}

		for(int i = 0; i < cycleList.size() - 1; ++i) {
			v[cycleList.get(i + 1)].map.remove(cycleList.get(i));
			cycleFlag = false;
			vis = new int[n];
			for(int j = 0; j < n; ++j) {
				if(vis[j] == 0) {
					dfsFindAns(j);
				}
			}
			if(!cycleFlag) {
				w.print("YES");
				w.close();
				return;
			}
			v[cycleList.get(i + 1)].map.put(cycleList.get(i), 1);
		}

		w.print("NO");

		w.close();	
   	}
}