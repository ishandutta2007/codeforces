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
    
    void addTrie(TrieNode node, int num, int level)
    {
        if(level == -1)
        {
            node.isCompleted=true;
            return;
        }
        int cur = num & 1 << level;
        //System.out.print(cur);
        if(node.map.get(cur) == null)
            node.map.put(cur, new TrieNode());
        addTrie(node.map.get(cur), num, level - 1);
        
        if(node.map.get(0) != null && node.map.get(1 << level) != null)
            node.isCompleted = node.map.get(0).isCompleted && node.map.get(1 << level).isCompleted;
    }
    
    int queryTrie(TrieNode node, int num, int level)
    {
        HashMap<Integer, TrieNode> map = node.map;
        if(level == 0)
        {
            if((num & 1 << level) == 0)
            {
                if(map.get(0) == null)
                    return 0;
                else
                    return 1;
            }
            else
            {
                if(map.get(1) == null)
                    return 0;
                else
                    return 1;
            }
        }
        
        if((num & 1 << level) == 0)
        {
            if(map.get(0) == null)
                return 0;
            else if(!map.get(0).isCompleted)
                return queryTrie(map.get(0), num, level - 1);
            else if(map.get(1 << level) == null)
                return 1 << level;
            else
                return queryTrie(map.get(1 << level), num, level - 1) | 1 << level;
        }
        else
        {
            if(map.get(1 << level) == null)
                return 0; 
            else if(!map.get(1 << level).isCompleted)
                return queryTrie(map.get(1 << level), num, level - 1);
            else if(map.get(0) == null)
                return 1 << level;
            else
                return queryTrie(map.get(0), num, level - 1) | 1 << level;
        }
    }
    
	TrieNode root = new TrieNode();
    
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
		
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a;
        
        for(int i = 0; i < n; ++i)
        {
            a = sc.nextInt();  
            addTrie(root, a, 18);
            //System.out.println();
        }
        
        int q=0;
        
        for(int i = 0; i < m; ++i)
        {
            q ^= sc.nextInt();
            w.println(queryTrie(root, q, 18));
            //System.out.println();
        }
		w.close();		
	}
}
class TrieNode
{
    HashMap<Integer, TrieNode> map = new HashMap<>();
    boolean isCompleted;
}