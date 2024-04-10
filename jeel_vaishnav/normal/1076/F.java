import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;

public class Main implements Runnable {
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                }
                catch (IOException e) {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt() {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
            
            int sgn = 1;
            
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
            
            return res * sgn;
        }
        
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
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
        
        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next() {
            return readString();
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
    public static void main(String args[]) throws Exception {
        new Thread(null, new Main(),"Main",1<<26).start();
    }
    long minSolveDiff(long x, long y, long alry) {
        if(alry == k)
            return Long.MAX_VALUE;

        if(x == 0)
            return Long.MAX_VALUE;

        long reqPairs = (x - 1L) / k + 1L;

        if(y < reqPairs)
            return Long.MAX_VALUE;

        if(y == reqPairs)
            return x % k == 0 ? k : x % k;

        if(y > (k - alry) + (x - 1L) * k)
            return Long.MAX_VALUE;

        return 1;
    }
    long minSolveSame(long x, long y, long alrx) {
        if(x == 0)
            return Long.MAX_VALUE;

        if(alrx == k)
            return Long.MAX_VALUE;

        long reqPairs;

        if(k - alrx >= x) {
            if(y == 0)
                return x;

            if(y > (x - 1L) * k)
                return Long.MAX_VALUE;

            return 1L;
        }

        reqPairs = 1 + (x - (k - alrx) - 1L) / k + 1L;

        if(y < reqPairs - 1) 
            return Long.MAX_VALUE;

        if(y == reqPairs - 1)
            return ((x - (k - alrx)) % k == 0 ? k : (x - (k - alrx)) % k);

        if(y > (x - 1L) * k)
            return Long.MAX_VALUE;

        return 1L;
    }
    long k;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        k = sc.nextLong();

        long x[] = new long[n];
        long y[] = new long[n];

        for(int i = 0; i < n; ++i)
            x[i] = sc.nextLong();

        for(int i = 0; i < n; ++i)
            y[i] = sc.nextLong();

        long dp[][] = new long[n + 1][2];
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < 2; ++j)
                dp[i][j] = Long.MAX_VALUE;
        }

        dp[0][0] = 0;
        dp[0][1] = 0;

        for(int i = 1; i <= n; ++i) {
            if(dp[i - 1][0] != Long.MAX_VALUE) {
                dp[i][0] = min(minSolveSame(x[i - 1], y[i - 1], dp[i - 1][0]), minSolveDiff(x[i - 1], y[i - 1], 0));
                dp[i][1] = min(minSolveSame(y[i - 1], x[i - 1], 0), minSolveDiff(y[i - 1], x[i - 1], dp[i - 1][0]));
            }
            if(dp[i - 1][1] != Long.MAX_VALUE) {
                long cans0 = min(minSolveSame(x[i - 1], y[i - 1], 0), minSolveDiff(x[i - 1], y[i - 1], dp[i - 1][1]));
                long cans1 = min(minSolveSame(y[i - 1], x[i - 1], dp[i - 1][1]), minSolveDiff(y[i - 1], x[i - 1], 0));
                dp[i][0] = min(dp[i][0], cans0);
                dp[i][1] = min(dp[i][1], cans1);
            }
        }

        if(min(dp[n][0], dp[n][1]) == Long.MAX_VALUE)
            w.print("NO");
        else
            w.print("YES");

        w.close();
    }
}