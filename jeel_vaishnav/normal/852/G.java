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
    void addTrie(TrieNode node,int i)
    {   
        HashMap<Character,TrieNode> map= node.map;
        if(i==s.length())
        {
            node.endsHere++;
            return;
        }
        if(map.get(s.charAt(i))==null)
            map.put(s.charAt(i),new TrieNode());
        addTrie(map.get(s.charAt(i)),i+1);
    }
    int queryTrie(TrieNode node,int i)
    {
        HashMap<Character,TrieNode> map=node.map;
        if(i==s.length())
        {
            if(map1.get(node)==null)
            {
                map1.put(node,1);
                return node.endsHere;
            }
            else
                return 0;
        }
        if(s.charAt(i)=='?')
        {
            int ans=0;
            for(int j=0;j<5;j++)
            {
                if(map.get((char)('a'+j))!=null)
                    ans+=queryTrie(map.get((char)('a'+j)),i+1);
            }
            ans+=queryTrie(node,i+1);
            return ans;
        }
        else
        {
            if(map.get(s.charAt(i))!=null)
                return queryTrie(map.get(s.charAt(i)),i+1);
            else
                return 0;
        }
    }
    TrieNode root=new TrieNode(); 
    HashMap<TrieNode,Integer> map1;
    String s;
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
		int n=sc.nextInt();
        int m=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            s=sc.next();
            addTrie(root,0);
        }
        for(int i=0;i<m;i++)
        {
            s=sc.next();
            map1=new HashMap<>();
            w.println(queryTrie(root,0));
        }
		w.close();		
	}
}
class TrieNode
{
    HashMap<Character,TrieNode> map = new HashMap<>();
    int endsHere;
}