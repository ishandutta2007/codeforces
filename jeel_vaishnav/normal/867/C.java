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
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        long pp = sc.nextLong();
        
        Person person[] = new Person[n];
        
        long tslices = 0;
        for(int i = 0; i < n; ++i)
        {
            person[i] = new Person(sc.nextLong(), sc.nextLong(), sc.nextLong());
            tslices += person[i].s;
        }
        
        Arrays.sort(person, new Comparator<Person>(){
            public int compare(Person p1, Person p2)
            {
                if(p1.diff > p2.diff)
                    return -1;
                if(p1.diff < p2.diff)
                    return 1;
                return 0;
            }
        });
        
        long prefixb[] = new long[n];
        long suffixa[] = new long[n];
        long prefixs[] = new long[n];
        long suffixs[] = new long[n];
        
        prefixb[0] = person[0].s * person[0].b;
        prefixs[0] = person[0].s;
        suffixa[n - 1] = person[n - 1].s * person[n - 1].a;
        suffixs[n - 1] = person[n - 1].s;
        
        for(int i = 1; i < n; ++i)
        {
            prefixb[i] = prefixb[i - 1] + person[i].s * person[i].b;
            prefixs[i] = prefixs[i - 1] + person[i].s;
            suffixa[n - 1 - i] = suffixa[n - i] + person[n - 1 - i].s * person[n - 1 - i].a;
            suffixs[n - i - 1] = suffixs[n - i] + person[n - i - 1].s;
        }
        
        int boundary = n;
        
        for(int i = 0; i < n; ++i)
        {
            if(person[i].diff <= 0)
            {
                boundary = i;
                break;
            }
        }
        
        if(boundary == 0)
        {
            long ansm = 0;
            for(int i = 0; i < n; ++i)
                ansm += person[i].s * person[i].a;
            w.print(ansm);
            w.close();
            return;
       }
       
       if(boundary == n)
       {
            long ansm = 0;
            for(int i = 0; i < n; ++i)
                ansm += person[i].s * person[i].b;
            w.print(ansm);
            w.close();
            return;
       }
        
        long tot = (tslices - 1) / pp + 1;
        long ans = 0;
        
            long x = (suffixs[boundary] - 1)/ pp + 1;
            long y = tot - x;
            int start = 0, end = boundary - 1, ind1 = -1, ind2 = n;
            while(start <= end)
            {
                int mid = (start + end) / 2;
                if(prefixs[mid] <= pp * y)
                {
                    ind1 = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            start = boundary; end = n - 1;
            while(start <= end)
            {
                int mid = (start + end) / 2;
                if(suffixs[mid] <= pp * x)
                {
                    ind2 = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            long cur = 0;
            if(ind1 == boundary - 1 && ind2 == boundary)
                cur = prefixb[boundary - 1] + suffixa[boundary];
            else if(ind1 == boundary - 1)
            {
                long rema = x * pp;
                if(ind2 != n)
                {
                    rema -= suffixs[ind2];
                    cur += suffixa[ind2];
                }
                cur += rema * person[ind2 - 1].a;
                cur += (person[ind2 - 1].s - rema) * person[ind2 - 1].b;
                cur += prefixb[ind2 - 2];
            }
            else
            {
                long remb = y * pp;
                if(ind1 != -1)
                {
                    remb -= prefixs[ind1];
                    cur += prefixb[ind1];
                }
                cur += remb * person[ind1 + 1].b;
                cur += (person[ind1 + 1].s - remb) * person[ind1 + 1].a;
                cur += suffixa[ind1 + 2];
            }
            if(cur > ans)
                ans = cur;
        
            
            y = (prefixs[boundary - 1] - 1) / pp + 1;
            x = tot - y;
            start = 0; end = boundary - 1; ind1 = -1; ind2 = n;
            while(start <= end)
            {
                int mid = (start + end) / 2;
                if(prefixs[mid] <= pp * y)
                {
                    ind1 = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            start = boundary; end = n - 1;
            while(start <= end)
            {
                int mid = (start + end) / 2;
                if(suffixs[mid] <= pp * x)
                {
                    ind2 = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            cur = 0;
            if(ind1 == boundary - 1 && ind2 == boundary)
                cur = prefixb[boundary - 1] + suffixa[boundary];
            else if(ind1 == boundary - 1)
            {
                long rema = x * pp;
                if(ind2 != n)
                {
                    rema -= suffixs[ind2];
                    cur += suffixa[ind2];
                }
                cur += rema * person[ind2 - 1].a;
                cur += (person[ind2 - 1].s - rema) * person[ind2 - 1].b;
                cur += prefixb[ind2 - 2];
            }
            else
            {
                long remb = y * pp;
                if(ind1 != -1)
                {
                    remb -= prefixs[ind1];
                    cur += prefixb[ind1];
                }
                cur += remb * person[ind1 + 1].b;
                cur += (person[ind1 + 1].s - remb) * person[ind1 + 1].a;
                cur += suffixa[ind1 + 2];
            }
            if(cur > ans)
                ans = cur;
        
        w.print(ans);
        
		w.close();
	}
}
class Person
{
    long s;
    long a;
    long b;
    long diff;
    Person(long x, long y, long z)
    {
        s = x;
        a = y;
        b = z;
        diff = b - a;
    }
}