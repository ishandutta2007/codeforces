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
    long fast_pow(long a, long b) {
        if(b == 0)
            return 1L;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    long mod = (long)1e9 + 7;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        char[][] s = new char[n][m];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next().toCharArray();

        char[][] t = new char[m][n];
        for(int i = 0; i < m; ++i) 
            t[i] = sc.next().toCharArray();

        long dp[][] = new long[m][n];

        long pow[] = new long[5000000];

        pow[0] = 1;

        for(int i = 1; i < 5000000; ++i) {
            pow[i] = pow[i - 1] * 26 % mod;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int ind = i * n + j;
                dp[i][j] = (t[i][j] - 'a') * pow[ind] % mod;

                if(i != 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

                if(j != 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

                if(i != 0 && j != 0)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - 1] + mod) % mod;
            }
        }

        HashMap<Long, Integer> map = new HashMap<>();

        for(int j = m - 1; j < n; ++j) {
            long cval = dp[m - 1][j];
            if(j != m - 1) {
                cval = (cval - dp[m - 1][j - m] + mod) % mod;
                cval = cval * fast_pow(pow[j - m + 1], mod - 2) % mod;
            }
            map.put(cval, j);
        }

        dp = new long[n][m];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int ind = i * n + j;
                dp[i][j] = (s[i][j] - 'a') * pow[ind] % mod;

                if(i != 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

                if(j != 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

                if(i != 0 && j != 0)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - 1] + mod) % mod;
            }
        }

        for(int i = m - 1; i < n; ++i) {
            long cval = dp[i][m - 1];
            if(i != m - 1) {
                cval = (cval - dp[i - m][m - 1] + mod) % mod;
                cval = cval * fast_pow(pow[n * (i - m + 1)], mod - 2) % mod;
            }
            if(map.get(cval) != null) {
                int ind1 = i + 2 - m;
                int ind2 = map.get(cval) + 2 - m;
                w.print(ind1 + " " + ind2);
                w.close();
                return;
            }
        }

        w.print("-1");

        w.close();      

    }
}