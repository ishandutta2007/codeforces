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
    
    int police[], visited[], d;
    HashSet<Integer> ans = new HashSet<>();
    ArrayList<Edge> adj[];
    
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        d = sc.nextInt();
        
        police = new int[n];
        for(int i = 0; i < k; ++i)
            police[sc.nextInt() - 1] = 1;
            
        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        for(int i = 0; i < n - 1; ++i)
        {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u].add(new Edge(v, i + 1));
            adj[v].add(new Edge(u, i + 1));
        }
        
        Queue<QueueNode> queue = new LinkedList<>();
        
        visited = new int[n];
        for(int i = 0; i < n; ++i)
        {
            if(police[i] == 1)
            {
                queue.add(new QueueNode(i, -1));
                visited[i] = 1;
            }
        }
        
        while(!queue.isEmpty())
        {
            int len = queue.size();
            for(int i = 0; i < len; ++i)
            {
                QueueNode cur = queue.poll();
                for(Edge p : adj[cur.label])
                {
                    int j = p.dest;
                    if(j != cur.parent && visited[j] == 1)
                        ans.add(p.index);
                    else if(j != cur.parent)
                    {
                        visited[j] = 1;
                        queue.add(new QueueNode(j, cur.label));
                    }
                }
            }
        }
        
        w.println(ans.size());
        for(int i : ans)
            w.print(i + " ");
		w.close();		
	}
} 

class Edge
{
    int dest;
    int index;
    Edge(int dest, int index)
    {
        this.dest = dest;
        this.index = index;
    }
}

class QueueNode
{
    int label;
    int parent;
    QueueNode(int label, int parent)
    {
        this.label = label;
        this.parent = parent;
    }
}