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
        new Thread(null, new Main(),"Main",1<<27).start();
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
    long mod = (long)998244353;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        long inv[] = new long[n + 1];
        for(int i = 1; i <= n; ++i)
            inv[i] = fast_pow(i, mod - 2);

        int a[] = new int[n];

        int freq[] = new int[n + 1];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            freq[a[i]]++;
        }

        ArrayList<Integer> ele = new ArrayList<>();
        ele.add(0);
        for(int i = 0; i <= n; ++i) {
            if(freq[i] > 0)
                ele.add(i);
        }

        int m = ele.size();

        long dp[][] = new long[m][n + 1];
        dp[0][0] = 1;

        for(int i = 1; i < m; ++i) {
            int curEle = ele.get(i);

            for(int j = 1; j <= n; ++j) {
                int remEle = n - j + 1;
                long curProb = freq[curEle] * inv[remEle] % mod;
                dp[i][j] = dp[i - 1][j - 1] * curProb % mod;
            }

            for(int j = 0; j <= n; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }

        long ans = 0;
        for(int i = 1; i < m; ++i) {
            int curEle = ele.get(i);

            if(freq[curEle] < 2)
                continue;

            for(int j = 0; j <= n - 2; ++j) {
                int remEle1 = n - j;
                long curProb1 = (long)freq[curEle] * inv[remEle1] % mod;
                int remEle2 = n - j - 1;
                long curProb2 = (freq[curEle] - 1L) * inv[remEle2] % mod;

                long curProb = curProb1 * curProb2 % mod;
                ans += dp[i - 1][j] * curProb % mod;
                ans %= mod;
            }   
        }

        w.print(ans);

        w.close();
    }
}