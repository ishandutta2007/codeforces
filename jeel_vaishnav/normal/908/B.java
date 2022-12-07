
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
	static class Edge {
		int dest;
		long weight;
		Edge(int a, long b) {
			dest = a;
			weight = b;
		} 
	}
	static class Vertex {
		int type;
		boolean isChocolate;
		ArrayList<Edge> edges = new ArrayList<>();
		void addEdge(int ind, long cost) {
			edges.add(new Edge(ind, cost));
		}
	}
	static class Pair {
		int ind;
		int type;
		long cost;
		int ccity = -1;
		Pair(int a, int b, long c, int d) {
			ind = a;
			type = b;
			cost = c;
			ccity = d;
		}
	}
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
       	int n = sc.nextInt();

       	int m = sc.nextInt();

       	String types1[] = {"0123", "0132", "0213", "0231", "0321", "0312", "1023", "1032", "1203", "1230", "1302", "1320", "2013", "2031", "2130", "2103", "2301", "2310", "3012", "3021", "3102", "3120", "3201", "3210"};

       	char types[][] = new char[24][];

       	for(int i = 0; i < 24; ++i)
       		types[i] = types1[i].toCharArray();

       	char s[][] = new char[n][m];

       	for(int i = 0; i < n; ++i)
       		s[i] = sc.next().toCharArray();

       	int startx = -1, starty = -1;

       	for(int i = 0; i < n; ++i) 
       		for(int j = 0; j < m; ++j)
       			if(s[i][j] == 'S') {
       				startx = i;
       				starty = j;
       			}

       	char inst[];
       	inst = sc.next().toCharArray();
       	int ans = 0;

       	main : for(int i = 0; i < 24; ++i) {	
       		int posx = startx, posy = starty;
       		int flag = 0;
       		for(int j = 0; j < inst.length; ++j) {
       			char move = types[i][inst[j] - '0'];
       			if(move == '0')
       				posx++;
       			if(move == '1')
       				posx--;
       			if(move == '2')
       				posy++;
       			if(move == '3')
       				posy--;
       			if(posx < 0 || posx >= n || posy < 0 || posy >= m || s[posx][posy] == '#') 
       				continue main;
       			if(s[posx][posy] == 'E') {
       				ans++;
       				continue main;
       			}
       		}
       	}

       	w.print(ans);

 		w.close();		
	}
}