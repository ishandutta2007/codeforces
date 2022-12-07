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
        int k = sc.nextInt();

        int[] freq = new int[100001];
        for(int i = 0; i < n * k; ++i) 
            freq[sc.nextInt()]++;

        ArrayList<Integer> adj[] = new ArrayList[100001];
        for(int i = 0; i <= 100000; ++i)
            adj[i] = new ArrayList<>();
        for(int i = 0; i < n; ++i)
            adj[sc.nextInt()].add(i);

        int[] h = new int[k + 1];
        for(int i = 1; i <= k; ++i)
            h[i] = sc.nextInt();

        int ans = 0;

        for(int i = 1; i <= 100000; ++i) {
            if(adj[i].size() == 0)
                continue;

            int a[] = new int[adj[i].size() + 1];
            int m = 1;
            for(int j : adj[i]) {
                a[m++] = j;
            }

            int cnt = freq[i];

            int dp[][] = new int[m][cnt + 1];

            for(int j = 0; j < cnt; ++j)
                dp[0][j] = -1;
            dp[0][cnt] = 0;

            for(int j = 1; j < m; ++j) {
                for(int p = 0; p <= cnt; ++p)
                    dp[j][p] = -1;
                for(int p = 0; p <= cnt; ++p) {
                    for(int l = 0; l <= min(p, k); ++l) {
                        if(dp[j - 1][p] == -1)
                            dp[j][p - l] = max(dp[j][p - l], -1);
                        else
                            dp[j][p - l] = max(dp[j][p - l], dp[j - 1][p] + h[l]);
                    }
                }
            }

            int cans = 0;
            for(int j = 0; j <= cnt; ++j) {
                cans = max(cans, dp[m - 1][j]);
            }

            ans += cans;
        }

        w.print(ans);

        w.close();      
    }
}