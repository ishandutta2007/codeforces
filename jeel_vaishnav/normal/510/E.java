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

        int sieve[] = new int[20001];
        for(int i = 2; i <= 20000; ++i) {
            if(sieve[i] == 0) {
                for(int j = i; j <= 20000; j += i) {
                    sieve[j] = i;
                }
            }
        }

        int cntOdd = 0, cntEven = 0;
        int a[] = new int[n + 1];
        for(int i = 1; i <= n; ++i) {
            a[i] = sc.nextInt();

            if(a[i] % 2 == 0)
                cntEven++;
            else
                cntOdd++;
        }

        if(cntOdd != cntEven) {
            w.print("Impossible");
            w.close();
            return;
        }

        int source = 0, sink = n + 1;
        ArrayList<Edge> edge = new ArrayList<>();
        for(int i = 1; i <= n; ++i) {
            if(a[i] % 2 == 0)
                edge.add(new Edge(-1, i, n + 1, 2));
            else
                edge.add(new Edge(-1, 0, i, 2));
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                if(sieve[a[i] + a[j]] == a[i] + a[j]) {
                    if(a[i] % 2 == 0)
                        edge.add(new Edge(-1, j, i, 1));
                    else
                        edge.add(new Edge(-1, i, j, 1));
                }
            }
        }

        Graph g = new Graph(n + 2, true, true);
        g.addEdges(edge);

        if(g.maxFlow() == n) {
            g.solve(w);
        } 
        else
            w.print("Impossible");

        w.close();    
    }
    class Graph {
        //default source : 0 sink : n - 1
        boolean isWeighted, isDirected;
        int n;
        int source, sink;
        InputReader sc;
        Edge edge[];
        int adj[][];
        int vis[];

        void dfs(int i, ArrayList<Integer> clist, ArrayList<Integer> e[]) {
            clist.add(i);
            vis[i] = 1;
            for(int j : e[i]) {
                if(vis[j] == 0)
                    dfs(j, clist, e);
            }
        }

        void solve(PrintWriter w) {
            ArrayList<Integer> e[] = new ArrayList[n];
            for(int i = 0; i < n; ++i)
                e[i] = new ArrayList<>();
            for(int i = 0; i < edge.length; ++i) {
                if(edge[i].u >= 1 && edge[i].u <= n - 2 && edge[i].v >= 1 && edge[i].v <= n - 2 && edge[i].flow == 1) {
                    e[edge[i].u].add(edge[i].v);
                    e[edge[i].v].add(edge[i].u);
                }
            }

            vis = new int[n];
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            for(int i = 1; i < n - 1; ++i) {
                if(vis[i] == 0) {
                    ArrayList<Integer> clist = new ArrayList<>();
                    dfs(i, clist, e);
                    list.add(clist);
                }
            }

            w.println(list.size());
            for(ArrayList<Integer> i : list) {
                w.print(i.size() + " ");
                for(int j : i)
                    w.print(j + " ");
                w.println();
            }
        }

        Graph(int n, boolean isWeighted, boolean isDirected) {
            this.n = n;
            this.isWeighted = isWeighted;
            this.isDirected = isDirected;

            source = 0;
            sink = n - 1;
        }
        
        Graph(int n, boolean isWeighted, boolean isDirected, InputReader sc) {
            this.n = n;
            this.isWeighted = isWeighted;
            this.isDirected = isDirected;
            this.sc = sc;

            source = 0;
            sink = n - 1;
        }

        void addEdges(ArrayList<Edge> e) {
            int deg[] = new int[n]; 

            int m = e.size();

            edge = new Edge[m];
            for(int i = 0; i < m; ++i) {
                int u = e.get(i).u;
                int v = e.get(i).v;

                long weight;
                if(isWeighted)
                    weight = e.get(i).capacity;
                else
                    weight = 1L;

                edge[i] = new Edge(i, u, v, weight);

                deg[u]++;
                deg[v]++;
            }

            adj = new int[n][];
            for(int i = 0; i < n; ++i)
                adj[i] = new int[deg[i]]; 

            int ptr[] = new int[n];
            for(int i = 0; i < m; ++i) {
                int u = edge[i].u;
                int v = edge[i].v;

                adj[u][ptr[u]++] = i;
                adj[v][ptr[v]++] = i;
            }
        }

        void addEdges(Edge e[]) {
            int deg[] = new int[n]; 

            int m = e.length;

            edge = new Edge[m];
            for(int i = 0; i < m; ++i) {
                int u = e[i].u;
                int v = e[i].v;

                long weight;
                if(isWeighted)
                    weight = e[i].capacity;
                else
                    weight = 1L;

                edge[i] = new Edge(i, u, v, weight);

                deg[u]++;
                deg[v]++;
            }

            adj = new int[n][];
            for(int i = 0; i < n; ++i)
                adj[i] = new int[deg[i]]; 

            int ptr[] = new int[n];
            for(int i = 0; i < m; ++i) {
                int u = edge[i].u;
                int v = edge[i].v;

                adj[u][ptr[u]++] = i;
                adj[v][ptr[v]++] = i;
            }
        }

        void scanEdges(int m) {
            int deg[] = new int[n]; 

            edge = new Edge[m];
            for(int i = 0; i < m; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;

                long weight;
                if(isWeighted)
                    weight = sc.nextLong();
                else
                    weight = 1L;

                edge[i] = new Edge(i, u, v, weight);

                deg[u]++;
                deg[v]++;
            }

            adj = new int[n][];
            for(int i = 0; i < n; ++i)
                adj[i] = new int[deg[i]]; 

            int ptr[] = new int[n];
            for(int i = 0; i < m; ++i) {
                int u = edge[i].u;
                int v = edge[i].v;

                adj[u][ptr[u]++] = i;
                adj[v][ptr[v]++] = i;
            }
        }

        void setSource(int source) {
            this.source = source;
        }

        void setSink(int sink) {
            this.sink = sink;
        }

        void findLevels(int[] level) {
            Arrays.fill(level, -1);

            Queue<Integer> queue = new LinkedList<>();
            queue.add(source);
            level[source] = 0;

            while(!queue.isEmpty()) {
                int cur = queue.poll();
                int curLevel = level[cur];

                for(int i : adj[cur]) {
                    Edge curE = edge[i];
                    int j = curE.findAnother(cur);

                    if(curE.findPossibleFlowFrom(cur) > 0 && level[j] == -1) {
                        level[j] = curLevel + 1;
                        queue.add(j);
                    }
                }
            }
        }

        long sendFlow(int i, long curFlow, int[] level, int[] ptr) {
            if(i == sink)
                return curFlow;

            long sentFlow = 0;

            for(; ptr[i] < adj[i].length; ++ptr[i]) {
                Edge curE = edge[adj[i][ptr[i]]];
                int j = curE.findAnother(i);

                if(curE.findPossibleFlowFrom(i) > 0 && level[j] == level[i] + 1) {
                    long possFlow = min(curE.findPossibleFlowFrom(i), curFlow - sentFlow);
                    long curSentFlow = sendFlow(j, possFlow, level, ptr);

                    sentFlow += curSentFlow;
                    curE.useFlow(i, curSentFlow);
                }

                if(curFlow == sentFlow)
                    return sentFlow;
            }

            return sentFlow;
        }

        long maxFlow() {
            long ans = 0;

            while(true) {
                int[] level = new int[n];
                findLevels(level);

                if(level[sink] == -1)
                    return ans;

                int[] ptr = new int[n];
                ans += sendFlow(source, Long.MAX_VALUE, level, ptr);
            }
        }
    }
    class Edge {
        int ind, u, v;
        long capacity, flow;

        Edge(int a, int b, int c, long d) {
            ind = a;
            u = b;
            v = c;
            capacity = d;
        }

        int findAnother(int a) {
            if(u == a)
                return v;
            return u;
        }

        long findPossibleFlowFrom(int a) {
            if(a == u)
                return capacity - flow;
            return flow;
        }

        void useFlow(int a, long val) {
            if(a == u) 
                flow += val;
            else
                flow -= val;
        }
    }
}