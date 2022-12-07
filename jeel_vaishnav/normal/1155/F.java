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
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int adj[][] = new int[n][n];
        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int cntBits[] = new int[1 << n];
        for(int i = 0; i < (1 << n); ++i) {
            for(int j = 0; j < n; ++j) {
                if((i >> j & 1) == 1)
                    cntBits[i]++;
            }
        }

        int dp[][][] = new int[n][n][1 << n];
        int parDp[][][] = new int[n][n][1 << n];
        for(int k = 1; k < (1 << n); ++k) {
            int cnt = 0, ind = -1;
            for(int i = 0; i < n; ++i) {
                if((k >> i & 1) == 1) {
                    cnt++;
                    ind = i;
                }
            }

            if(cnt == 1) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        if(i != j && adj[i][ind] == 1 && adj[ind][j] == 1) {
                            dp[i][j][k] = 1;
                            parDp[i][j][k] = -1;
                        }
                    }
                }
            }
            else {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        for(int l = 0; l < n; ++l) {
                            if((k >> l & 1) == 1) {
                                if(adj[i][l] == 1 && dp[l][j][k ^ (1 << l)] == 1) {
                                    dp[i][j][k] = 1;
                                    parDp[i][j][k] = l;
                                }
                            }
                        }
                    } 
                }
            }
        }

        int cost[] = new int[1 << n];
        Arrays.fill(cost, Integer.MAX_VALUE);
        int parCost[][] = new int[1 << n][3];
        for(int i = 1; i < (1 << n); ++i) {
            int cnt = 0, ind = -1;
            for(int j = 0; j < n; ++j) {
                if((i >> j & 1) == 1) {
                    cnt++;
                    ind = j;
                }
            }
            
            if(cnt == 1) {
                cost[i] = 0;
                parCost[i][0] = -1;
            }
            else {
                for(int mask = (i - 1) & i; mask != 0; mask = (mask - 1) & i) {
                    if(cost[mask] == Integer.MAX_VALUE)
                        continue;
                    int addMask = i ^ mask;
                    int newCost = cost[mask] + cntBits[addMask] + 1;
                    if(cost[i] > newCost) {
                        main : for(int j = 0; j < n; ++j) {
                            if((mask >> j & 1) == 1) {
                                for(int k = 0; k < n; ++k) {
                                    if((mask >> k & 1) == 1) {
                                        if(dp[j][k][addMask] == 1) {
                                            cost[i] = newCost;
                                            parCost[i][0] = addMask;
                                            parCost[i][1] = j;
                                            parCost[i][2] = k;
                                            break main;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } 
        }

        w.println(cost[(1 << n) - 1]);
        HashSet<Edge> ans = new HashSet<>();
        int curMask = (1 << n) - 1;

        main : while(parCost[curMask][0] != -1) {
            int addMask = parCost[curMask][0];
            int u = parCost[curMask][1];
            int v = parCost[curMask][2];
            int cmask = addMask;

            while(parDp[u][v][cmask] != -1) {
                int l = parDp[u][v][cmask];
                ans.add(new Edge(u, l));
                u = l;
                cmask ^= (1 << l);
            }

            int ind = -1;
            for(int l = 0; l < n; ++l) {
                if((cmask >> l & 1) == 1)
                    ind = l;
            }

            ans.add(new Edge(u, ind));
            if(u != v)
                ans.add(new Edge(v, ind));

            curMask ^= addMask;
        }

        for(Edge e : ans)
            w.println(e);
        
        w.close();
    }
}
class Edge {
    int u, v;
    Edge(int a, int b) {
        u = a;
        v = b;
    }
    public String toString() {
        return (u + 1) + " " + (v + 1);
    }
}