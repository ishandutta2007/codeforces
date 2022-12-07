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
    long querySegTree(int low, int high, int pos, int l, int r) {
        handleLazy(low, high, pos);

        if(low > r || high < l) 
            return Long.MAX_VALUE;

        if(low >= l && high <= r)
            return segTree[pos];

        int mid = (low + high) >> 1;
        long val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return min(val1, val2);
    }
    void handleLazy(int low, int high, int pos) {
        if(segTree[pos] != Long.MAX_VALUE) {
            segTree[pos] += lazy[pos];
        }
        if(low != high) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    void updateSegTreePoint(int low, int high, int pos, int ind, long val) {
        if(low > ind || high < ind)
            return;

        if(low == high) {
            segTree[pos] = val;
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTreePoint(low, mid, 2 * pos + 1, ind, val);
        updateSegTreePoint(mid + 1, high, 2 * pos + 2, ind, val);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    void updateSegTree(int low, int high, int pos, int l, int r, long val) {
        if(l > r)
            return;

        handleLazy(low, high, pos);

        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            lazy[pos] = val;
            handleLazy(low, high, pos);
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, l, r, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r, val);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    void dfsStart(int ind, long dist) {
        inTime[ind] = outTime[ind] = time++;
        
        if(adj[ind].size() == 0) {
            updateSegTreePoint(0, n - 1, 0, ind, dist);
            return;
        }

        for(Edge curE : adj[ind]) {
            int j = curE.dest;
            long weight = curE.weight;

            dfsStart(j, dist + weight);
        }

        outTime[ind] = time - 1;
    }
    void solve(int ind) {
        for(Query curQ : queries[ind]) {
            int cind = curQ.ind;
            int l = curQ.l;
            int r = curQ.r;

            ans[cind] = querySegTree(0, n - 1, 0, l, r);  
        }

        if(adj[ind].size() != 0) {
            for(Edge curE : adj[ind]) {
                int j = curE.dest;
                long weight = curE.weight;

                updateSegTree(0, n - 1, 0, 0, inTime[j] - 1, weight);
                updateSegTree(0, n - 1, 0, inTime[j], outTime[j], -weight);
                updateSegTree(0, n - 1, 0, outTime[j] + 1, n - 1, weight);

                solve(j);

                updateSegTree(0, n - 1, 0, 0, inTime[j] - 1, -weight);
                updateSegTree(0, n - 1, 0, inTime[j], outTime[j], weight);
                updateSegTree(0, n - 1, 0, outTime[j] + 1, n - 1, -weight);
            }
        }
    }
    long segTree[];
    long lazy[];
    ArrayList<Query> queries[];
    long ans[];
    ArrayList<Edge> adj[];
    int inTime[], outTime[];
    int time = 0;
    int n;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();
        int q = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 1; i < n; ++i) {
            int parent = sc.nextInt() - 1;
            long weight = sc.nextLong();

            adj[parent].add(new Edge(i, weight));
        }

        segTree = new long[4 * n];
        Arrays.fill(segTree, Long.MAX_VALUE);
        lazy = new long[4 * n];

        inTime = new int[n];
        outTime = new int[n];
        dfsStart(0, 0);
        
        ans = new long[q];
        queries = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            queries[i] = new ArrayList<>();

        for(int i = 0; i < q; ++i) {
            int ind = sc.nextInt() - 1;
            queries[ind].add(new Query(i, sc.nextInt() - 1, sc.nextInt() - 1));
        }

        solve(0);

        for(long i : ans)
            w.println(i);

        w.close();
    }
}
class Query {
    int ind, l, r;
    Query(int a, int b, int c) {
        ind = a;
        l = b;
        r = c;
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