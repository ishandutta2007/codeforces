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

    void updateEdges(int low, int high, int pos, int u, int l, int r, long cost, int type) {
        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            if(type == 2) {
                edgeList.add(new Edge(u, pos, cost));
                adj[u].add(edgeListPtr++);
            }
            else {
                edgeList.add(new Edge(4 * n + pos, 4 * n + u, cost));
                adj[4 * n + pos].add(edgeListPtr++);
            }
            return;
        }

        int mid = (low + high) >> 1;
        updateEdges(low, mid, 2 * pos + 1, u, l, r, cost, type);
        updateEdges(mid + 1, high, 2 * pos + 2, u, l, r, cost, type);
    }
  
    void buildSegTree(int low, int high, int pos) {
        if(low == high) {
            mappedInd[low] = pos;
            return;
        }

        int mid = (low + high) >> 1;
        buildSegTree(low, mid, 2 * pos + 1);
        buildSegTree(mid + 1, high, 2 * pos + 2);

        edgeList.add(new Edge(pos, 2 * pos + 1, 0));
        edgeList.add(new Edge(pos, 2 * pos + 2, 0));
        adj[pos].add(edgeListPtr++);
        adj[pos].add(edgeListPtr++);

        edgeList.add(new Edge(4 * n + 2 * pos + 1, 4 * n + pos, 0));
        edgeList.add(new Edge(4 * n + 2 * pos + 2, 4 * n + pos, 0));
        adj[4 * n + 2 * pos + 1].add(edgeListPtr++);
        adj[4 * n + 2 * pos + 2].add(edgeListPtr++);
    }
    
    int mappedInd[];
    ArrayList<Edge> edgeList = new ArrayList<>();
    int edgeListPtr = 0;
    ArrayList<Integer> adj[];
    int n;

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt() - 1;

        mappedInd = new int[n];
        adj = new ArrayList[8 * n];
        for(int i = 0; i < 8 * n; ++i)
            adj[i] = new ArrayList<>();
        buildSegTree(0, n - 1, 0);

        for(int i = 0; i < n; ++i) {
            edgeList.add(new Edge(mappedInd[i], 4 * n + mappedInd[i], 0));
            edgeList.add(new Edge(4 * n + mappedInd[i], mappedInd[i], 0));
            adj[mappedInd[i]].add(edgeListPtr++);
            adj[4 * n + mappedInd[i]].add(edgeListPtr++);
        }

        for(int i = 0; i < m; ++i) {
            int type = sc.nextInt();

            if(type == 1) {
                int u = mappedInd[sc.nextInt() - 1];
                int v = mappedInd[sc.nextInt() - 1];
                long cost = sc.nextLong();

                edgeList.add(new Edge(u, v, cost));
                adj[u].add(edgeListPtr++);
            }
            else {
                int u = mappedInd[sc.nextInt() - 1];
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                long cost = sc.nextLong();

                updateEdges(0, n - 1, 0, u, l, r, cost, type);
            }
        }

        Dijkstra d = new Dijkstra(edgeList, adj, 8 * n);
        long[] ans = d.minCost(mappedInd[s]);

        for(int i = 0; i < n; ++i) {
            int u = mappedInd[i];

            if(ans[u] == Long.MAX_VALUE)
                w.print("-1 ");
            else
                w.print(ans[u] + " ");
        }

        w.close();
    }
}
class Edge {
    int u, v;
    long cost;
    Edge(int a, int b, long c) {
        u = a;
        v = b;
        cost = c;
    }
    int findAnother(int a) {
        if(u == a)
            return v;
        return u;
    } 
}
class Dijkstra {
    Edge e[];
    ArrayList<Integer> adj[];
    int n;

    Dijkstra(Edge[] e, ArrayList<Integer> adj[], int n) {
        this.e = e;
        this.adj = adj;
        this.n = n;
    }
    Dijkstra(ArrayList<Edge> e, ArrayList<Integer> adj[], int n) {
        this.adj = adj;
        this.n = n;

        this.e = new Edge[e.size()];
        for(int i = 0; i < this.e.length; ++i)
            this.e[i] = e.get(i);
    }

    long[] minCost(int source) {
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        queue.add(newPair(source, 0));

        long ans[] = new long[n];
        Arrays.fill(ans, Long.MAX_VALUE);
        ans[source] = 0;

        int vis[] = new int[n];        

        while(!queue.isEmpty()) {
            Pair curP = queue.poll();
            int ind = curP.ind;
            long cost = curP.cost;
            deletePair(curP);

            if(vis[ind] == 1) 
                continue;
            vis[ind] = 1;

            for(int eInd : adj[ind]) {
                int j = e[eInd].findAnother(ind);
                long extCost = e[eInd].cost;

                if(vis[j] == 0 && cost + extCost < ans[j]) {
                    ans[j] = cost + extCost;
                    queue.add(newPair(j, ans[j]));
                }
            }
        }

        return ans;
    }

    static class Pair implements Comparable<Pair> {
        int ind;
        long cost;
        Pair(int a, long b) {
            ind = a;
            cost = b;
        }
        public int compareTo(Pair p) {
            if(cost < p.cost)
                return -1;
            if(cost > p.cost)
                return 1;
            return 0;
        }
    }
    static ArrayList<Pair> pairList = new ArrayList<>();
    static int ptr = 0;
    static Pair newPair(int a, long b) {
        if(ptr == 0)
            return new Pair(a, b);

        ptr--;

        Pair curP = pairList.get(ptr);
        curP.ind = a;
        curP.cost = b;

        pairList.remove(ptr);

        return curP;
    }
    static void deletePair(Pair p) {
        pairList.add(p);
        ptr++;
    }
}