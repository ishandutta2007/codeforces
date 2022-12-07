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
    class DynamicBiconnectivity {
        class Move {
            int child, par, prevRank;
            Move(int a, int b, int c) {
                child = a;
                par = b;
                prevRank = c;
            }
        }
        
        class Edge {
            int u, v;
            Edge(int a, int b) {
                u = a;
                v = b;
            }
        }

        void rollback(LinkedList<Move> list) {
            while(list.size() > 0) {
                Move m = list.getLast();
                
                int child = m.child;
                int parent = m.par;

                unrollOperation(child, parent);

                rank[parent] = m.prevRank;
                par[child] = child;

                list.removeLast();
            }
        }

        void combine(int u, int v, LinkedList<Move> list) {
            if(rank[u] > rank[v]) {
                list.add(new Move(v, u, rank[u]));

                combineOperation(v, u);

                par[v] = u;
            }
            else {
                list.add(new Move(u, v, rank[v]));
                
                combineOperation(u, v);
                
                if(rank[v] == rank[u])
                    rank[v]++;

                par[u] = v;
            }
        }
        
        int find(int i) {
            if(par[i] == i)
                return i;
            return find(par[i]);
        }

        void dfsSolve(int low, int high, int pos) {
            LinkedList<Move> list = new LinkedList<>();

            for(Edge e : segTree[pos]) {
                int u = find(e.u);
                int v = find(e.v);

                if(u != v) {
                    combine(u, v, list);
                }
            }

            if(low != high) {
                int mid = (low + high) >> 1;
                dfsSolve(low, mid, 2 * pos + 1);
                dfsSolve(mid + 1, high, 2 * pos + 2);
            }
            else
                ans[low] = getAns(low);

            rollback(list);
        }

        void dfsAddEdge(int low, int high, int pos, int l, int r, Edge e) {
            if(low > r || high < l)
                return;

            if(low >= l && high <= r) {
                segTree[pos].add(e);
                return;
            }

            int mid = (low + high) >> 1;
            dfsAddEdge(low, mid, 2 * pos + 1, l, r, e);
            dfsAddEdge(mid + 1, high, 2 * pos + 2, l, r, e);
        }

        int n, q;
        ArrayList<Edge> segTree[];
        int par[], rank[];

        DynamicBiconnectivity(int n, int q) {
            this.n = n;
            this.q = q;

            segTree = new ArrayList[4 * q];
            for(int i = 0; i < 4 * q; ++i)
                segTree[i] = new ArrayList<>();

            par = new int[n];
            rank = new int[n];
            for(int i = 0; i < n; ++i) {
                par[i] = i;
                rank[i] = 0;
            }

            initialize();
        }

        void addEdge(int l, int r, int u, int v) {
            Edge e = new Edge(u, v);
            dfsAddEdge(0, q - 1, 0, l, r, e);
        }

        void solve() {
            dfsSolve(0, q - 1, 0);
        }

        // Provide the necessary changes below
        long ans[];
        long cntX[], cntY[];
        long cans = 0;

        void initialize() {
            ans = new long[q];

            cntX = new long[n];
            cntY = new long[n];
            for(int i = 0; i < n; ++i) {
                if(i < 300000)
                    cntX[i] = 1;
                else
                    cntY[i] = 1;
            }
        }

        long getAns(int ind) {
            return cans;
        }

        void unrollOperation(int child, int parent) {
            // Reverse steps of combine Opr, nullifying the changes made
            cntX[parent] -= cntX[child];
            cntY[parent] -= cntY[child];

            cans -= cntX[parent] * cntY[child] + cntX[child] * cntY[parent];
        }

        void combineOperation(int child, int parent) {
            cans += cntX[parent] * cntY[child] + cntX[child] * cntY[parent];

            cntX[parent] += cntX[child];
            cntY[parent] += cntY[child];
        }
        // DynamicBiconnectivity(int n, int q) - Number of nodes and queries
        // addEdge(l, r, u, v) - to add edge from u to v in the range l to r
        // solve() - to solve and find ans for each query
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int q = sc.nextInt();

        DynamicBiconnectivity db = new DynamicBiconnectivity(600000, q);

        TreeMap<Integer, Integer> map[] = new TreeMap[300000];
        for(int i = 0; i < 300000; ++i)
            map[i] = new TreeMap<>();

        for(int x = 0; x < q; ++x) {
            int indx = sc.nextInt() - 1;
            int indy = sc.nextInt() + 299999;

            if(map[indx].get(indy) != null) {
                db.addEdge(map[indx].get(indy), x - 1, indx, indy);
                map[indx].remove(indy);
            }
            else
                map[indx].put(indy, x);
        }
        for(int i = 0; i < 300000; ++i) {
            for(int j : map[i].keySet()) 
                db.addEdge(map[i].get(j), q - 1, i, j);
        }      

        db.solve();

        for(long i : db.ans)
            w.print(i + " ");

        w.close();
    }
}