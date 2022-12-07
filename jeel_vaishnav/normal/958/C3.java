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
    int lis(int[] a) {
        int lis = 0;
        int b[] = new int[a.length];
        for(int i = 0; i < a.length; ++i) {
            int start = 0, end = lis - 1, ans = -1;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(b[mid] <= a[i]) {
                    ans = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            b[ans + 1] = a[i];
            lis = max(lis, ans + 2);
            if(i == a.length - 1) {
                return ans + 2;
            }
        }
        return 0;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        int p = sc.nextInt();

        int a[] = new int[n];

        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt() % p;

        if(n < p * (k - 2) + 1) {
             int dp[][][] = new int[n][k][p];

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < k; ++j) {
                    for(int l = 0; l < p; ++l)
                        dp[i][j][l] = Integer.MAX_VALUE;
                }
            }

            dp[0][0][a[0]] = 0;

            for(int i = 1; i < n; ++i) {
                for(int j = 0; j < k; ++j) {
                    for(int l = 0; l < p; ++l) 
                        dp[i][j][l] = dp[i - 1][j][(l - a[i] + p) % p];
                    int minV = Integer.MAX_VALUE;
                    for(int l = 0; l < p; ++l) {
                        if(j != 0 && dp[i - 1][j - 1][l] != Integer.MAX_VALUE)
                            minV = min(minV, dp[i - 1][j - 1][l] + l);
                    }
                    if(j != 0 && minV != Integer.MAX_VALUE)
                        dp[i][j][a[i]] = min(dp[i][j][a[i]], minV);
                }
            }

            int ans = Integer.MAX_VALUE;
            for(int i = 0; i < p; ++i) {
                if(dp[n - 1][k - 1][i] != Integer.MAX_VALUE) {
                    ans = min(ans, dp[n - 1][k - 1][i] + i);
                }
            }

            w.print(ans);
        }
        else {
            int freq[] = new int[p];
            int prefix[] = new int[n];
            prefix[0] = a[0];
            for(int i = 1; i < n; ++i)
                prefix[i] = (prefix[i - 1] + a[i]) % p;
            for(int i = 0; i < n; ++i) {
                freq[prefix[i]]++;
            }
            int minAns = Integer.MAX_VALUE;
            for(int i = 0; i < p; ++i) {
                if(freq[i] >= k - 1) {
                    int cans = (prefix[n - 1] - i + p) % p + i;
                    minAns = min(cans, minAns);
                }
            }
            if(lis(prefix) == k)
                minAns = prefix[n - 1];

            w.print(minAns);
        }
        
        w.close();     
    }
}