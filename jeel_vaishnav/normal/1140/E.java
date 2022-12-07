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
        int k = sc.nextInt();

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int flag = 0;
        for(int i = 0; i < n; ++i) {
            if(i + 2 < n && a[i] != -1 && a[i] == a[i + 2])
                flag = 1;
        }

        if(flag == 1) {
            w.print("0");
            w.close();
            return;
        }

        long dp[][] = new long[n][2];
        dp[0][0] = 0;
        dp[0][1] = 1;

        for(int i = 1; i < n; ++i) {
            dp[i][0] = (long)(k - 1) * dp[i - 1][1] % mod;
            dp[i][1] = ((long)(k - 2) * dp[i - 1][1] % mod + dp[i - 1][0]) % mod;
        }

        int start = -1, end = -1;
        int cnt = 0;
        long ans = 1L;
        for(int i = 0; i < n; i += 2) {
            if(a[i] != -1) {
                if(cnt > 0) {
                    end = a[i];
                    if(start != -1) {
                        if(end == start) {
                            long cans = dp[cnt - 1][1] * (long)(k - 1) % mod;
                            ans = ans * cans % mod;
                        }
                        else {
                            long cans = (dp[cnt - 1][1] * (long)(k - 2) % mod + dp[cnt - 1][0]) % mod;
                            ans = ans * cans % mod;
                        }
                    }
                    else {
                        ans = ans * fast_pow(k - 1, cnt) % mod;
                    }
                }
                start = a[i];
                end = -1;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }

        if(cnt > 0) {
            if(start == -1) {
                ans = ans * fast_pow(k - 1, cnt - 1) % mod * k % mod;
            }
            else {
                ans = ans * fast_pow(k - 1, cnt) % mod;
            }
        }

        start = -1;
        end = -1;
        cnt = 0;
        for(int i = 1; i < n; i += 2) {
            if(a[i] != -1) {
                if(cnt > 0) {
                    end = a[i];
                    if(start != -1) {
                        if(end == start) {
                            long cans = dp[cnt - 1][1] * (long)(k - 1) % mod;
                            ans = ans * cans % mod;
                        }
                        else {
                            long cans = (dp[cnt - 1][1] * (long)(k - 2) % mod + dp[cnt - 1][0]) % mod;
                            ans = ans * cans % mod;
                        }
                    }
                    else {
                        ans = ans * fast_pow(k - 1, cnt) % mod;
                    }
                }
                start = a[i];
                end = -1;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }

        if(cnt > 0) {
            if(start == -1) {
                ans = ans * fast_pow(k - 1, cnt - 1) % mod * k % mod;
            }
            else {
                ans = ans * fast_pow(k - 1, cnt) % mod;
            }
        }

        w.print(ans);

        w.close();
    }
}