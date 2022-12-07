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
    
    void updateTrie(TrieNode node, long a, int level)
    {
        if(level == 0)
            return;
        
        level--;
        
        if((a >> level & 1L) == 1)
        {
            if(node.right == null)
                node.right = new TrieNode();
            updateTrie(node.right, a, level);
        }
        else
        {
            if(node.left == null)
                node.left = new TrieNode();
            updateTrie(node.left, a, level);
        }
    }
    
    long queryTrie(TrieNode node, long a, int level)
    {
        if(level == 0)
            return 0;
        
        level--;
        
        if((a >> level & 1L) == 1)
        {
            if(node.left != null)
                return queryTrie(node.left, a, level);
            else
                return queryTrie(node.right, a, level) ^ (1L << level);
        }
        else
        {
            if(node.right != null)
                return queryTrie(node.right, a, level) ^ (1L << level);
            else
                return queryTrie(node.left, a, level);
        }
    }

	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
       
        int n = sc.nextInt();
        
        TrieNode root = new TrieNode();
        
        long a[] = new long[n];
        
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();
        
        long prefix[] = new long[n];
        prefix[0] = a[0];
        for(int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] ^ a[i];
        
        long suffix = 0;
        long ans = prefix[n - 1];
        
        for(int i = n - 2; i >= 0; --i)
        {
            suffix ^= a[i + 1];
            updateTrie(root, suffix, 40);
            
            long curans = queryTrie(root, prefix[i], 40) ^ prefix[i];
            //w.println(i + " " + queryTrie(root, prefix[i], 40) + " " + prefix[i]);
            ans = max(ans, curans);
            ans = max(ans, prefix[i]);
        }
        
        suffix ^= a[0];
        updateTrie(root, suffix, 40);
        
        ans = max(ans, queryTrie(root, 0, 40));
        
        w.println(ans);

		w.close();
	}
}
class TrieNode
{
    TrieNode left, right;
}