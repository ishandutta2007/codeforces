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
        String good=sc.next();
        int freq[]=new int[26];
        for(int i=0;i<good.length();i++)
            freq[good.charAt(i)-'a']++;
        String check=sc.next();
        int occur=0;
        for(int i=0;i<check.length();i++)
        {
            if(check.charAt(i)=='*')
                occur=1;
        }
        int q=sc.nextInt();
        for(int x=0;x<q;x++)
        {
            String try1=sc.next();
            if(occur==0&&try1.length()!=check.length())
            {
                w.println("NO");
                continue;
            }
            if(occur==1&&try1.length()<(check.length()-1))
            {
                w.println("NO");
                continue;
            }   
            int i=0,j=try1.length()-1,flag=0;
            int l=check.length()-1;
            while(i<try1.length()&&check.charAt(i)!='*')
            {
                if(check.charAt(i)=='?'&&freq[try1.charAt(i)-'a']!=1)
                {
                    flag=1;
                    break;
                }
                else if(check.charAt(i)!='?'&&check.charAt(i)!=try1.charAt(i))
                {
                    flag=1;
                    break;
                }
                i++;
            }
            if(flag!=1)
            {
                while(j>=0&&l>=0&&check.charAt(l)!='*')
                {
                    if(check.charAt(l)=='?'&&freq[try1.charAt(j)-'a']!=1)
                    {
                        flag=1;
                        break;
                    }
                    else if(check.charAt(l)!='?'&&check.charAt(l)!=try1.charAt(j))
                    {
                        flag=1;
                        break;
                    }
                    j--;
                    l--;
                }
                if(flag!=1)
                {
                    for(int k=i;k<=j;k++)
                    {
                        if(freq[try1.charAt(k)-'a']!=0)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag==1)
                w.println("NO");
            else
                w.println("YES");            
        }
		w.close();		
	}
}