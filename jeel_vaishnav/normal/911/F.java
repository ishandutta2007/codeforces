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
	class Pair {
		int leaf1;
		int leaf2;
		int leafr;
		Pair(int a, int b, int c) {
			leaf1 = a + 1;
			leaf2 = b + 1;
			leafr = c + 1;
		}
		public String toString() {
			return leaf1 + " " + leaf2 + " " + leafr;
		}
	}
	void dfs(int i, int level, int par) {
		if(level > maxl) {
			maxl = level;
			root = i;
		}
		for(int j : adj[i]) {
			if(j != par) {
				dfs(j, level + 1, i);
			}
		}
	}
	boolean dfsFindDiameter(int i, int par, int dest) {
		if(i == dest) {
			isDiameter[i] = true;
		}
		for(int j : adj[i]) {
			if(j != par)
				isDiameter[i] |= dfsFindDiameter(j, i, dest);
		}
		return isDiameter[i];
	}
	void dfsFindAns(int i, int level, int par, ArrayList<Integer> temp) {
		if(isDiameter[i]) {
			ArrayList<Integer> leaves = new ArrayList<Integer>();
			for(int j : adj[i]) {
				if(j != par) {
					if(!isDiameter[j])
						dfsFindAns(j, 1, i, leaves);
					else
						dfsFindAns(j, level + 1, i, null);
				}
			}
			if(level > maxl - level) {
				for(int j : leaves) {
					pairs.add(new Pair(j, end1, j));
					ans += (long)level;
				}
			}
			else {
				for(int j : leaves) {
					pairs.add(new Pair(j, end2, j));
					ans += (long)(maxl - level);
				}
			}
			diam.add(i);
		}
		else {
			for(int j : adj[i]) {
				if(j != par)
					dfsFindAns(j, level + 1, i, temp);
			}
			ans += (long)level;
			temp.add(i);
		}
	}
	long ans = 0;
	int maxl = 0;
	int root = 0;
	int end1, end2;
	ArrayList<Integer> adj[], diam;
	boolean isDiameter[];
	ArrayList<Pair> pairs;
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

		dfs(0, 0, -1);
		end1 = root;

		isDiameter = new boolean[n];

		maxl = 0;
		dfs(root, 0, -1);
		end2 = root;

		dfsFindDiameter(end1, -1, end2);

		pairs = new ArrayList<>();
		diam = new ArrayList<>();
		dfsFindAns(end1, 0, -1, null);

		for(int i : diam) {
			if(i != end1) {
				ans += (long)maxl;
				maxl--;
				pairs.add(new Pair(i, end1, i));
			}
		}

		w.println(ans);
		for(Pair i : pairs) {
			w.println(i);
		}		

		w.close();
   	}
}