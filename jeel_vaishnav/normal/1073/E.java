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
    long dp[][][];
    long ans[][][];
    long sum[][][];
    long mod = (long)998244353;
    char[] a;
    void calcDP(long ele) {
        int dig = 0;
        long temp = ele;
        while(temp != 0) {
            dig++;
            temp /= 10L;
        }

        temp = ele;
        a = new char[dig];
        for(int i = dig - 1; i >= 0; --i) {
            a[i] = (char)(temp % 10L + '0');
            temp /= 10L;
        }

        dp = new long[1 << 10][dig + 1][2];
        dp[0][0][1] = 1L;
        for(int j = 1; j <= dig; ++j)
            dp[0][j][0] = 1L;
        for(int i = 0; i < (1 << 10); ++i) {
            for(int j = 0; j < dig; ++j) {
                if(i == 0) {
                    for(int k = 1; k <= 9; ++k) {
                        dp[i | (1 << k)][j + 1][0] += dp[i][j][0];
                        dp[i | (1 << k)][j + 1][0] %= mod;
                    }
                    for(int k = 1; k < a[j] - '0'; ++k) {
                        dp[i | (1 << k)][j + 1][0] += dp[i][j][1];
                        dp[i | (1 << k)][j + 1][0] %= mod;
                    }
                }
                else {
                    for(int k = 0; k <= 9; ++k) {
                        dp[i | (1 << k)][j + 1][0] += dp[i][j][0];
                        dp[i | (1 << k)][j + 1][0] %= mod;
                    }
                    for(int k = 0; k < a[j] - '0'; ++k) {
                        dp[i | (1 << k)][j + 1][0] += dp[i][j][1];
                        dp[i | (1 << k)][j + 1][0] %= mod;
                    }
                }

                

                dp[i | (1 << (a[j] - '0'))][j + 1][1] += dp[i][j][1];
                dp[i | (1 << (a[j] - '0'))][j + 1][1] %= mod;
            }
        }
    }
    long calcSum(long ele) {
        int dig = a.length;

        sum = new long[1 << 10][dig + 1][2];

        long p10[] = new long[dig];
        p10[0] = 1L;
        for(int i = 1; i < dig; ++i) {
            p10[i] = p10[i - 1] * 10L % mod;
        }

        for(int i = 0; i < (1 << 10); ++i) {
            for(int j = 0; j < dig; ++j) {
                if(i == 0) {
                    for(int k = 1; k <= 9; ++k) {
                        sum[i | (1 << k)][j + 1][0] += sum[i][j][0] + dp[i][j][0] * (long)k % mod * p10[dig - 1 - j] % mod;
                        sum[i | (1 << k)][j + 1][0] %= mod;
                    }
                }
                else {
                    for(int k = 0; k <= 9; ++k) {
                        sum[i | (1 << k)][j + 1][0] += sum[i][j][0] + dp[i][j][0] * (long)k % mod * p10[dig - 1 - j] % mod;
                        sum[i | (1 << k)][j + 1][0] %= mod;
                    }
                }

                for(int k = 0; k < a[j] - '0'; ++k) {
                    sum[i | (1 << k)][j + 1][0] += sum[i][j][1] + dp[i][j][1] * (long)k % mod * p10[dig - 1 - j] % mod;
                    sum[i | (1 << k)][j + 1][0] %= mod;
                }

                sum[i | (1 << (a[j] - '0'))][j + 1][1] += sum[i][j][1] + dp[i][j][1] * (long)(a[j] - '0') % mod * p10[dig - 1 - j] % mod;
                sum[i | (1 << (a[j] - '0'))][j + 1][1] %= mod;
            }
        }

        //System.out.println(ele);

        long ans = 0;
        for(int i = 0; i < (1 << 10); ++i) {
            int cntDigs = 0;
            for(int j = 0; j < 10; ++j) {
                if((i >> j & 1) == 1)
                    cntDigs++;
            }

            if(cntDigs <= k) {
                // for(int j = 0; j <= dig; ++j) {
                //     for(int k = 0; k < 2; ++k)
                //         System.out.println(i + " " + j + " " + k + " " + dp[i][j][k] + " " + sum[i][j][k]);
                // }
                ans = (ans + sum[i][dig][0] + sum[i][dig][1]) % mod;
            }
        }

        return ans;
    }
    long solve(long i) {
        if(i == 0)
            return 0;
        calcDP(i);
        return calcSum(i);
    }
    int k;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        long l = sc.nextLong();
        long r = sc.nextLong();

        k = sc.nextInt();

        long ans = (solve(r) - solve(l - 1L) + mod) % mod;
        w.print(ans);

        w.close();    
    }
}