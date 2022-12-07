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
        new Thread(null, new Main(),"Main",1<<27).start();
    }
    long fast_pow(long a, long b) {
        if(b == 0)
            return 1;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    long mod = (long)1e9 + 7;
    public void run()
    {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[n];

        long ext = 1;

        for(int i = 0; i < n; ++i) 
            a[i] = sc.nextInt();

        for(int i = 0; i < n; ++i)
            b[i] = sc.nextInt();

        int cnta[] = new int[n];
        cnta[n - 1] = a[n - 1] == 0 ? 1 : 0;
        int cntb[] = new int[n];
        cntb[n - 1] = b[n - 1] == 0 ? 1 : 0;

        for(int i = n - 2; i >= 0; --i) {
            cnta[i] = cnta[i + 1];
            cntb[i] = cntb[i + 1];
            if(a[i] == 0)
                cnta[i]++;
            if(b[i] == 0)
                cntb[i]++;
        }   

        long ans = 0;

        for(int i = 0; i < n; ++i) {
            if(a[i] == 0 && b[i] == 0) {
                long parm = (long)m * ((long)m - 1L) / 2L;
                parm %= mod;
                long cans = fast_pow((long)m, (long)(cnta[i] + cntb[i] - 2L)) * parm % mod;
                cans = cans * ext % mod;                
                ans = (ans + cans) % mod;
                ext = ext * m % mod;
            }
            else if(a[i] == 0) {
                long parm = (long)(m - b[i]);
                long cans = fast_pow((long)m, (long)(cnta[i] + cntb[i] - 1L)) * parm % mod;
                cans = cans * ext % mod;
                ans = (ans + cans) % mod;
            }
            else if(b[i] == 0) {
                long parm = (long)(a[i] - 1);
                long cans = fast_pow((long)m, (long)(cnta[i] + cntb[i] - 1L)) * parm % mod;
                cans = cans * ext % mod;
                ans = (ans + cans) % mod;
            }
            else if(a[i] > b[i]) {
                long cans = fast_pow((long)m, (long)(cnta[i] + cntb[i]));
                cans = cans * ext % mod;
                ans = (ans + cans) % mod;
                break;
            }
            else if(a[i] < b[i]) {
                break;
            }
        }



        long poss = fast_pow((long)m, (long)(cnta[0] + cntb[0]));

        //w.println(ans + " " + poss);
        long fans = ans * fast_pow(poss, mod - 2) % mod;

        w.print(fans);

        w.close();      
    }
}