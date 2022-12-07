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

    void dfs(int i) {
        vis[i] = 1;

        for(Edge curE : adj[i]) {
            int j = curE.dest;
            long w = curE.weight;

            if(vis[j] == 0)
                dfs(j);

            dp[i][0] = (dp[i][0] + dp[j][1] * w % mod) % mod;
            dp[i][1] = (dp[i][1] + dp[j][0] * w % mod) % mod;
        }
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
    long fact[], factinv[];
    ArrayList<Edge> adj[];
    long dp[][];
    int vis[];

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int p = sc.nextInt();
        int q = sc.nextInt();
        int n = sc.nextInt() + 2;
        
        fact = new long[199999];
        factinv = new long[199999];

        fact[0] = 1;
        factinv[0] = 1;

        for(int i = 1; i < 199999; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            factinv[i] = fast_pow(fact[i], mod - 2);
        }

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        Pair pair[] = new Pair[n];
        pair[0] = new Pair(1, 1);
        pair[n - 1] = new Pair(p, q);

        for(int i = 1; i < n - 1; ++i)
            pair[i] = new Pair(sc.nextInt(), sc.nextInt());

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j)
                    continue;

                if(pair[i].x <= pair[j].x && pair[i].y <= pair[j].y) {
                    int delx = pair[j].x - pair[i].x, dely = pair[j].y - pair[i].y;
                    long weight = fact[delx + dely] * factinv[delx] % mod * factinv[dely] % mod;

                    adj[i].add(new Edge(j, weight));
                }
            }
        }

        dp = new long[n][2];
        dp[n - 1][0] = 1L;

        vis = new int[n];

        dfs(0);

        long ans = (dp[0][1] - dp[0][0] + mod) % mod;

        w.print(ans);

        w.close();      
    }
}
class Pair {
    int x, y;
    Pair(int a, int b) {
        x = a;
        y = b;
    }
}
class Edge {
    int dest;
    long weight;
    Edge(int a, long b) {
        dest = a;
        weight = b;
    }
}