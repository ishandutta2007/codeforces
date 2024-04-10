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
    void dfs(int i, int par, int level) {
        for(Query curQ : adjQ[i]) {
            int dist = curQ.dist;
            int maxLevel = min(maxDist, dist + level);
            long val = curQ.val;

            updateBit(maxLevel, val);
        }

        ans[i] = queryBit(maxDist) - queryBit(level - 1);

        for(int j : adj[i]) {
            if(j != par)
                dfs(j, i, level + 1);
        }

        for(Query curQ : adjQ[i]) {
            int dist = curQ.dist;
            int maxLevel = min(maxDist, dist + level);
            long val = curQ.val;

            updateBit(maxLevel, -val);
        }
    }
    long queryBit(int ind) {
        long ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        } 
        return ans;
    }
    void updateBit(int ind, long val) {
        while(ind < bit.length) {
            bit[ind] += val;
            ind += Integer.lowestOneBit(ind);
        }
    }
    long ans[];
    long bit[];
    ArrayList<Integer> adj[];
    int maxDist;
    ArrayList<Query> adjQ[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        maxDist = n;

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u].add(v);
            adj[v].add(u);
        }

        int q = sc.nextInt();
        adjQ = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adjQ[i] = new ArrayList<>();

        for(int i = 0; i < q; ++i) {
            int u = sc.nextInt() - 1;
            adjQ[u].add(new Query(sc.nextInt(), sc.nextLong()));
        }

        bit = new long[maxDist + 1];
        ans = new long[n];
        dfs(0, -1, 1);

        for(long i : ans)
            w.print(i + " ");

        w.close();
    }
}
class Query {
    int dist;
    long val;
    Query(int a, long b) {
        dist = a;
        val = b;
    }
}