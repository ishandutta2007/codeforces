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
    static void dfs(int i,int level)
    {
        occurence.put(i,eulerTour.size());
        stage.put(i,level);
        eulerTour.add(i);
        levels.add(level);
        for(int j=0;j<adj[i].size();j++)
        {
            if(occurence.get(adj[i].get(j))==null)
            {
                dfs(adj[i].get(j),level+1);
                eulerTour.add(i);
                levels.add(level);
            }
        }
    }
    static void formBlock()
    {
        m=new Minimum[blocks];
        for(int i=0;i<blocks;i++)
        {
            m[i]=new Minimum();
            int min=Integer.MAX_VALUE,min_i=0;
            for(int j=para*i;j<para*(i+1)&&j<eulerTour.size();j++)//eulerTour.size()=levels.size()
            {
                if(levels.get(j)<min)
                {
                    min=levels.get(j);
                    min_i=j;
                }
            }
            m[i].min=min;
            m[i].min_i=min_i;
        }
    }
    static int lca(int a,int b)
    {
        if(occurence.get(a)>occurence.get(b))
            return lca(b,a);
        int l=occurence.get(a),r=occurence.get(b);
        int min=Integer.MAX_VALUE,min_i=0;
        int l_block=(l/para)+1,r_block=(r/para)-1;
        for(int i=l;i<l_block*para&&i<=r;i++)
        {
            if(levels.get(i)<min)
            {
                min=levels.get(i);
                min_i=i;
            }
        }
        for(int i=l_block;i<=r_block;i++)
        {
            if(m[i].min<min)
            {
                min=m[i].min;
                min_i=m[i].min_i;
            }
        }
        if(r>=l_block*para)
        {
            for(int i=(r_block+1)*para;i<=r;i++)
            {
                if(levels.get(i)<min)
                {
                    min=levels.get(i);
                    min_i=i;
                }
            }
        }
        return eulerTour.get(min_i);
    }
    static void find(int a,int b,int c,int Misha,int Grisha,int center)
    {
        //System.out.println(Misha+" "+Grisha+" "+center);
        int distac=Math.abs(stage.get(a)-Misha)+1+Math.abs(Misha-stage.get(c));
        int distbc=Math.abs(stage.get(b)-Grisha)+1+Math.abs(Grisha-stage.get(c));
        int distab=Math.abs(stage.get(a)-center)+1+Math.abs(center-stage.get(b));
        //System.out.println(a+" "+b+" "+c+" "+distac+" "+distbc+" "+distab);
        int distance=(distac+distbc-distab+1)/2;
        if(distance>maximum)
            maximum=distance;
    }
    static ArrayList<Integer>[] adj;
    static ArrayList<Integer> eulerTour;
    static HashMap<Integer,Integer> occurence,stage;
    static ArrayList<Integer> levels;
    static int maximum;
    static int n,para,blocks;
    static Minimum m[];
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        n=sc.nextInt();
        int q=sc.nextInt();
        adj=new ArrayList[n];
        for(int i=0;i<n;i++)
            adj[i]=new ArrayList<Integer>();
        for(int i=0;i<n-1;i++)
        {
            int p=sc.nextInt();
            adj[p-1].add(i+1);
            adj[i+1].add(p-1);            
        }
        eulerTour=new ArrayList<Integer>();
        occurence=new HashMap<Integer,Integer>();
        levels=new ArrayList<Integer>();
        stage=new HashMap<Integer,Integer>();
        dfs(0,0);
        para=(int)Math.sqrt(eulerTour.size());
        blocks=(int)Math.ceil((float)eulerTour.size()/para);
        formBlock();
        for(int i=0;i<q;i++)
        {
            maximum=0;
            int a=sc.nextInt()-1;
            int b=sc.nextInt()-1;
            int c=sc.nextInt()-1;
            int Misha=stage.get(lca(a,c));
            int Grisha=stage.get(lca(b,c));
            int center=stage.get(lca(a,b));
            find(a,b,c,Misha,Grisha,center);
            find(a,c,b,center,Grisha,Misha);
            find(b,a,c,Grisha,Misha,center);
            find(b,c,a,center,Misha,Grisha);
            find(c,a,b,Grisha,center,Misha);
            find(c,b,a,Misha,center,Grisha);
            w.println(maximum);
        }
		w.close();		
	}
}
class Minimum
{
    int min;
    int min_i;
}