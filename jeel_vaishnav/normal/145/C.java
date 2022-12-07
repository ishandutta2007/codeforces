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

    boolean isLucky(int a) {
        while(a != 0) {
            int dig = a % 10;

            if(dig != 4 && dig != 7)
                return false;

            a /= 10;
        }
        return true;
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

    long getComb(int n, int r) {
        if(r > n)
            return 0;
        return fact[n] * factinv[r] % mod * factinv[n - r] % mod;
    }

    long fact[], factinv[];

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        fact = new long[100001];
        factinv = new long[100001];
        fact[0] = 1;
        factinv[0] = 1;
        for(int i = 1; i <= 100000; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            factinv[i] = fast_pow(fact[i], mod - 2);
        }

        int n = sc.nextInt();
        int k = sc.nextInt();

        int a[] = new int[n];
        int cnt = 0;
        HashMap<Integer, Long> map = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            if(isLucky(a[i])) {
                if(map.get(a[i]) == null)
                    map.put(a[i], 1L);
                else
                    map.put(a[i], map.get(a[i]) + 1L);
            }
            else
                cnt++;
        }

        int m = map.size();
        ArrayList<Long> list = new ArrayList<>();
        for(int i : map.keySet()) {
            list.add(map.get(i));
        }

        long dp[][] = new long[min(m, k)][m];
        long sum = 0;

        for(int i = 0; i < m; ++i) {
            dp[0][i] = list.get(i);
            sum = (sum + dp[0][i]) % mod;
        }

        long ans = (getComb(cnt, k) + sum * getComb(cnt, k - 1) % mod) % mod;

        for(int i = 1; i < min(m, k); ++i) {
            long csum = 0;
            for(int j = 0; j < m; ++j) {
                dp[i][j] = (sum - dp[i - 1][j] + mod) % mod * list.get(j) % mod;
                csum = (csum + dp[i][j]) % mod;
            }
            sum = csum * fast_pow((long)(i + 1), mod - 2) % mod;
            ans = (ans + sum * getComb(cnt, k - 1 - i) % mod) % mod;
        }

        w.print(ans);

        w.close();      
    }
}