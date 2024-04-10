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
    void union(int i,int j)
    {
        int x=findSet(i);
        int y=findSet(j);
        if(x==y)
            return;
        if(size[x]>size[y])
        {
            parent[y]=x;
            size[x]+=size[y];
        }
        else
        {
            parent[x]=y;
            size[y]+=size[x];
        }
    }
    int findSet(int i)
    {
        if(parent[i]==i)
            return i;
        parent[i]=findSet(parent[i]);
        return parent[i];
    }
    HashMap<Integer,Integer> map=new HashMap<>();
	int parent[];
    int size[];
    int a[],b[];
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        int n=sc.nextInt();
        a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
            map.put(a[i],i);
        }
        b=new int[n];
        for(int i=0;i<n;i++)
            b[i]=a[i];
        Arrays.sort(b);
        parent=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            union(i,map.get(b[i]));
        }
        int cnt=0;
        ArrayList<Integer> list[]=new ArrayList[n];
        for(int i=0;i<n;i++)
            list[i]=new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            list[findSet(i)].add(i);
        }
        for(int i=0;i<n;i++)
        {
            if(list[i].size()>0)
                cnt++;
        }
        w.println(cnt);
        for(int i=0;i<n;i++)
        {
            if(list[i].size()>0)
            {
                w.print(list[i].size()+" ");
                for(int j=0;j<list[i].size();j++)
                    w.print((list[i].get(j)+1)+" ");
                w.println();
            }
        }
		w.close();		
	}
}