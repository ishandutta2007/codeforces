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
        
		int n = sc.nextInt();
		int k = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        
        int votes[] = new int[n];
        int last[] = new int[n];
        Arrays.fill(last, -1);
        for(int i = 0; i < a; ++i)
        {
            int x = sc.nextInt() - 1;
            votes[x]++;
            last[x] = i;
        }
        
        Candidate[] cand = new Candidate[n];
        for(int i = 0; i < n; ++i)
            cand[i] = new Candidate(i, votes[i], last[i]);
        
        Arrays.sort(cand, new Comparator<Candidate>(){
            public int compare(Candidate c1, Candidate c2)
            {
                if(c1.votes > c2.votes)
                    return -1;
                if(c1.votes < c2.votes)
                    return 1;
                if(c1.last < c2.last)
                    return -1;
                if(c1.last > c2.last)
                    return 1;
                return 0;
            }
        });
        
        for(int i = 0; i < n; ++i)
        {
            int ind = -1;
            for(int j = 0; j < n; ++j)
            {
                if(cand[j].label == i)
                    ind = j;
            }
            int req = 0;
            for(int j = ind + 1; j < min(k + 1, n); ++j)
                req += cand[ind].votes + 1 - cand[j].votes;
                
            if(req > m - a && cand[ind].votes != 0)
                w.print("1 ");
            else if(n == k && cand[ind].votes != 0)
                w.print("1 ");
            else
            {
                Candidate temp[] = new Candidate[n];
                for(int j = 0; j < n; ++j)
                {
                    if(j == ind)
                        temp[j] = new Candidate(i, cand[j].votes + m - a, Integer.MAX_VALUE);
                    else
                        temp[j] = cand[j];
                }
                Arrays.sort(temp, new Comparator<Candidate>(){
                    public int compare(Candidate c1, Candidate c2)
                    {
                        if(c1.votes > c2.votes)
                            return -1;
                        if(c1.votes < c2.votes)
                            return 1;
                        if(c1.last < c2.last)
                            return -1;
                        if(c1.last > c2.last)
                            return 1;
                        return 0;
                    }
                });

                int ans = 3;
                for(int j = 0; j < k; ++j)
                {
                    if(temp[j].votes == 0)
                        break;
                    if(temp[j].label == i)
                    {
                        ans = 2;
                        break;
                    }
                }
                w.print(ans + " ");
            }
            
        }
		w.close();		
	}
}

class Candidate
{
    int label;
    int votes;
    int last;
    Candidate(int a, int b, int c)
    {
        label = a;
        votes = b;
        last = c;
    }
}