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
    void solve(int i, int par, int prevCol) {
        long sum[] = new long[4];
        // 0 : 0, 1 : 1, 2 : 0 -> 1, 3 : 1 -> 0
        for(Pair curP : adj[i]) {
            int j = curP.dest;
            int col = curP.col;
            if(j != par) {
                solve(j, i, col);
                ans += 2L * dp[j][0];
                ans += 2L * dp[j][1];
                ans += dp[j][2];
                ans += dp[j][3];

                ans += dp[j][0] * sum[0];
                ans += dp[j][0] * sum[1];
                ans += dp[j][0] * sum[3];

                ans += dp[j][1] * sum[1];

                ans += dp[j][2] * sum[1];

                ans += sum[0] * dp[j][0];
                ans += sum[0] * dp[j][1];
                ans += sum[0] * dp[j][3];

                ans += sum[1] * dp[j][1];

                ans += sum[2] * dp[j][1];
                
                for(int k = 0; k < 4; ++k)
                    sum[k] += dp[j][k];
            }
        }

        if(prevCol == 0) {
            dp[i][0] = sum[0] + 1;
            dp[i][1] = 0;
            dp[i][2] = 0;
            dp[i][3] = sum[1] + sum[3];
        }
        else {
            dp[i][0] = 0;
            dp[i][3] = 0;
            dp[i][1] = sum[1] + 1;
            dp[i][2] = sum[0] + sum[2];
        }
    }
    ArrayList<Pair> adj[];
    long dp[][];
    long ans = 0;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int col = sc.nextInt();
            adj[u].add(new Pair(v, col));
            adj[v].add(new Pair(u, col));
        }

        dp = new long[n][4];
        solve(0, -1, -1);

        w.print(ans);

        w.close();
    }
}
class Pair {
    int dest, col;
    Pair(int a, int b) {
        dest = a;
        col = b;
    }
}