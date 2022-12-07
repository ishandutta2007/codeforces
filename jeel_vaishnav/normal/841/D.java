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
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        int n=sc.nextInt();
	    int m=sc.nextInt();
        int wild=-1,odd=0;
        int d[]=new int[n];
        for(int i=0;i<n;i++)
        {
            d[i]=sc.nextInt();
            if(d[i]==-1)
                wild=i;
            if(d[i]==1)
                odd++;
        }
        ArrayList<Integer> adj[]=new ArrayList[n];
        for(int i=0;i<n;i++)
            adj[i]=new ArrayList<Integer>();
        HashMap<Integer,HashMap<Integer,Integer>> map=new HashMap<>();
        for(int i=0;i<m;i++)
        {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            adj[u].add(v);
            adj[v].add(u);
            if(map.get(v)==null)
                map.put(v,new HashMap<>());
            if(map.get(u)==null)
                map.put(u,new HashMap<>());
            map.get(v).put(u,i);
            map.get(u).put(v,i);
        }
        int root;
        if(wild==-1)
            root=0;
        else
            root=wild;
        int parent[]=new int[n];
        Arrays.fill(parent,-1);
        parent[root]=-2;
        if(odd%2==1&&wild==-1)
        {
            w.print("-1");  
        }
        else
        {
            Queue<Integer> queue=new LinkedList<Integer>();
            ArrayList<Integer> bfs=new ArrayList<>();
            queue.add(root);
            while(!queue.isEmpty())
            {
                int cur=queue.poll();
                for(int i=0;i<adj[cur].size();i++)
                {
                    int j=adj[cur].get(i);
                    if(parent[j]==-1)
                    {
                        parent[j]=cur;
                        queue.add(j);
                        bfs.add(j);
                    }
                }
            }
            ArrayList<Integer> edges=new ArrayList<Integer>();
            for(int i=0;i<bfs.size();i++)
            {
                int cur=bfs.get(n-2-i);
                if(d[cur]==1)
                {
                    edges.add(map.get(cur).get(parent[cur]));
                    if(d[parent[cur]]!=-1)
                        d[parent[cur]]=(d[parent[cur]]+1)%2;
                }
            }
            w.println(edges.size());
            for(int i=0;i<edges.size();i++)
                w.println(edges.get(i)+1);
        }
		w.close();		
	}
}