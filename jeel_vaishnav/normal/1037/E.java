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
    class Edge {
        int u, v;
        Edge(int a, int b) {
            u = a;
            v = b;
        }
    }
    int friends[];
    int selected[];
    int cans = 0;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        
        int deg[] = new int[n];
        int ptr[] = new int[n];

        Edge edge[] = new Edge[m];
        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            edge[i] = new Edge(u, v);
            deg[u]++;
            deg[v]++;
        }

        HashSet<Integer> adj[] = new HashSet[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new HashSet<>();

        for(int i = 0; i < m; ++i) {
            int u = edge[i].u;
            int v = edge[i].v;

            adj[u].add(v);
            adj[v].add(u);
        }

        PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.deg < p2.deg)
                    return -1;
                if(p1.deg > p2.deg)
                    return 1;
                return 0;
            }
        });

        int vis[] = new int[n];
        selected = new int[n];
        for(int i = 0; i < n; ++i)
            queue.add(new Pair(i, deg[i]));

        int curDeg[] = new int[n];
        for(int i = 0; i < n; ++i)
            curDeg[i] = deg[i];
        
        while(!queue.isEmpty()) {
            Pair cur = queue.poll();
            int ind = cur.ind;
            if(vis[ind] == 1)
                continue;

            int cdeg = cur.deg;
            vis[ind] = 1;

            if(cdeg >= k) {
                selected[ind] = 1;
                cans++;
                continue;
            }

            for(int j : adj[ind]) {
                if(vis[j] == 0) {
                    curDeg[j]--;
                    queue.add(new Pair(j, curDeg[j]));
                }
            }
        }

        friends = new int[n];
        for(int i = 0; i < n; ++i) {
            if(selected[i] == 1) {
                for(int j : adj[i]) {
                    if(selected[j] == 1)
                        friends[i]++;
                }
            }
        }

        int ans[] = new int[m];
        ans[m - 1] = cans;

        for(int i = m - 1; i >= 1; --i) {
            int u = edge[i].u;
            int v = edge[i].v;

            adj[u].remove(v);
            adj[v].remove(u);

            if(selected[u] == 1 && selected[v] == 1) {
                friends[u]--;
                friends[v]--;
                Queue<Integer> cqueue = new LinkedList<>();
                if(friends[u] < k) {
                    cqueue.add(u);
                    selected[u] = 0;
                    cans--;
                }
                if(friends[v] < k) {
                    cqueue.add(v);
                    selected[v] = 0;
                    cans--;
                }
                while(!cqueue.isEmpty()) {
                    int cur = cqueue.poll();

                    for(int j : adj[cur]) {
                        if(selected[j] == 1) {
                            friends[j]--;
                            if(friends[j] < k) {
                                selected[j] = 0;
                                cans--;
                                cqueue.add(j);
                            }
                        }
                    }
                }
            }

            ans[i - 1] = cans;
        }

        for(int i = 0; i < m; ++i)
            w.println(ans[i]);

        w.close();   
    }
}
class Pair {
    int ind, deg;
    Pair(int a, int b) {
        ind = a;
        deg = b;
    }
}