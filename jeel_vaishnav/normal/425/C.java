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
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int e = sc.nextInt();

        int maxPoss = s / e;

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int cnt[] = new int[100001];

        int b[] = new int[m];
        for(int i = 0; i < m; ++i) {
            b[i] = sc.nextInt();
            cnt[b[i]]++;
        }

        int ind[][] = new int[100001][];
        for(int i = 0; i <= 100000; ++i) {
            ind[i] = new int[cnt[i]];
        }

        int ptr[] = new int[100001];
        for(int i = 0; i < m; ++i)
            ind[b[i]][ptr[b[i]]++] = i;

        int dp[][] = new int[n + 1][maxPoss + 1];
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= maxPoss; ++j)
                dp[i][j] = Integer.MAX_VALUE;
        }
        dp[0][0] = -1;

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < maxPoss; ++j) {
                if(dp[i - 1][j] == Integer.MAX_VALUE)
                    break;

                int cval = a[i - 1];
                int start = 0, end = ind[cval].length - 1, cind = -1;
                int lim = dp[i - 1][j];
                while(start <= end) {
                    int mid = (start + end) >> 1;
                    if(ind[cval][mid] > lim) {
                        cind = mid;
                        end = mid - 1;
                    }
                    else
                        start = mid + 1;
                }
                if(cind != -1)
                    dp[i][j + 1] = ind[cval][cind];
            }
            for(int j = 0; j <= maxPoss; ++j) {
                if(dp[i - 1][j] == Integer.MAX_VALUE)
                    break;
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }

            for(int j = 0; j <= maxPoss; ++j) {
                if(dp[i][j] == Integer.MAX_VALUE)
                    break;
                int curCost = e * j + dp[i][j] + 1 + i;
                if(curCost <= s) {
                    ans = max(ans, j);
                }
            }
        }

        w.print(ans);

        w.close();
    }
}