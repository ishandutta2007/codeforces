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
    long querySegTree(int low, int high, int pos, int l, int r) {
        if(lazy[pos] != 0) {
            if(lazy[pos] >= 6) {
                for(int i = 0; i < 6; ++i)
                    segTree[pos][i] = 2L * (long)(high - low + 1) - (long)cnt[pos];
            }
            else {
                for(int i = lazy[pos]; i < 6; ++i) 
                    segTree[pos][i - lazy[pos]] = segTree[pos][i];
                for(int i = 6 - lazy[pos]; i < 6; ++i)
                    segTree[pos][i] = 2L * (long)(high - low + 1) - (long)cnt[pos];
            }
            if(low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(low >= l && high <= r) 
            return segTree[pos][0];

        if(low > r || high < l)
            return 0;

        int mid = (low + high) >> 1;
        long val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return val1 + val2;
    }
    void updateSegTree(int low, int high, int pos, int l, int r) {
        if(lazy[pos] != 0) {
            if(lazy[pos] >= 6) {
                for(int i = 0; i < 6; ++i)
                    segTree[pos][i] = 2L * (long)(high - low + 1) - (long)cnt[pos];
            }
            else {
                for(int i = lazy[pos]; i < 6; ++i) 
                    segTree[pos][i - lazy[pos]] = segTree[pos][i];
                for(int i = 6 - lazy[pos]; i < 6; ++i)
                    segTree[pos][i] = 2L * (long)(high - low + 1) - (long)cnt[pos];
            }
            if(low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(low >= l && high <= r) {
            for(int i = 1; i < 6; ++i)
                segTree[pos][i - 1] = segTree[pos][i];
            segTree[pos][5] = 2L * (long)(high - low + 1) - (long)cnt[pos];
            if(low != high) {
                lazy[2 * pos + 1]++;
                lazy[2 * pos + 2]++;
            }
            return;
        }

        if(low > r || high < l)
            return;

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, l, r);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r);
        for(int i = 0; i < 6; ++i)
            segTree[pos][i] = segTree[2 * pos + 1][i] + segTree[2 * pos + 2][i];
    }
    void buildSegTree(int low, int high, int pos) {
        if(low == high) {
            segTree[pos][0] = a[low];
            for(int i = 1; i < 6; ++i)
                segTree[pos][i] = sieve[(int)segTree[pos][i - 1]];
            if(a[low] == 1)
                cnt[pos]++;
            return;
        }
        
        int mid = (low + high) >> 1;
        buildSegTree(low, mid, 2 * pos + 1);
        buildSegTree(mid + 1, high, 2 * pos + 2);

        for(int i = 0; i < 6; ++i)
            segTree[pos][i] = segTree[2 * pos + 1][i] + segTree[2 * pos + 2][i];
        cnt[pos] = cnt[2 * pos + 1] + cnt[2 * pos + 2];
    }
    long segTree[][];
    int lazy[];
    long sieve[];
    long a[];
    int cnt[];
    public void run()
    {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int q = sc.nextInt();

        sieve = new long[1000001];

        for(int i = 1; i <= 1000000; ++i) {
            for(int j = i; j <= 1000000; j += i)
                sieve[j]++;
        } 

        segTree = new long[4 * n][6];
        lazy = new int[4 * n];
        cnt = new int[4 * n];

        a = new long[n];

        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();

        buildSegTree(0, n - 1, 0);

        for(int i = 0; i < q; ++i) {
            int type = sc.nextInt();

            if(type == 1) {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                updateSegTree(0, n - 1, 0, l, r);
            }
            else {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                w.println(querySegTree(0, n - 1, 0, l, r));
            }
        }

        w.close();      
    }
}