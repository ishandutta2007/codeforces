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
    void union(int i, int j) {
        i = findSet(i);
        j = findSet(j);

        if(i == j)
            return;

        par[i] = j;
        size[j] += size[i];
    }
    int findSet(int i) {
        if(par[i] == i)
            return i;

        par[i] = findSet(par[i]);
        return par[i];
    }

    int par[], size[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int a = sc.nextInt();
        int b = sc.nextInt();

        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        ArrayList<Edge> adj[] = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int weight = sc.nextInt();

            adj[u].add(new Edge(v, weight));
            adj[v].add(new Edge(u, weight));
        }

        par = new int[n];
        size = new int[n];
        for(int i = 0; i < n; ++i) {
            par[i] = i;
            size[i] = 1;
        }

        for(int i = 0; i < n; ++i) {
            for(Edge curP : adj[i]) {
                int j = curP.dest;
                if(curP.weight == a)
                    union(i, j);
            }
        }

        int bit[] = new int[n];
        Arrays.fill(bit, -1);
        int ptr = 0;
        for(int i = 0; i < n; ++i) {
            if(findSet(i) == i && size[i] >= 4) 
                bit[i] = ptr++;
        }

        int cost[][] = new int[n][1 << ptr];
        for(int i = 0; i < n; ++i)
            Arrays.fill(cost[i], Integer.MAX_VALUE);

        int vis[][] = new int[n][1 << ptr];

        int ans[] = new int[n];
        Arrays.fill(ans, Integer.MAX_VALUE);

        PriorityQueue<Tuple> queue = new PriorityQueue<>(new Comparator<Tuple>() {
            public int compare(Tuple t1, Tuple t2) {
                return t1.cost - t2.cost;
            }
        });

        int mask = 0;
        if(bit[par[0]] != -1)
            mask |= (1 << bit[par[0]]);

        queue.add(new Tuple(0, mask, 0));
        cost[0][mask] = 0;

        while(!queue.isEmpty()) {
            Tuple curT = queue.poll();

            int ind = curT.ind;
            mask = curT.mask;

            if(vis[ind][mask] == 1)
                continue;

            int ccost = cost[ind][mask];

            vis[ind][mask] = 1;
            ans[ind] = min(ans[ind], ccost);

            int oldComp = par[ind];

            for(Edge curE : adj[ind]) {
                int j = curE.dest;
                int weight = curE.weight;

                int newComp = par[j];

                if(newComp == oldComp) {
                    if(weight == b)
                        continue;

                    int ncost = ccost + weight;
                    if(ncost < cost[j][mask]) {
                        cost[j][mask] = ncost;
                        queue.add(new Tuple(j, mask, ncost));
                    }
                }
                else {
                    if(bit[newComp] != -1 && (mask >> bit[newComp] & 1) == 1)
                        continue;

                    int cmask = mask;
                    if(bit[newComp] != -1)
                        cmask |= (1 << bit[newComp]);

                    int ncost = ccost + weight;
                    if(ncost < cost[j][cmask]) {
                        cost[j][cmask] = ncost;
                        queue.add(new Tuple(j, cmask, ncost));
                    } 
                } 
            }
        }

        for(int i : ans)
            w.print(i + " ");        

        w.close();
    }
}
class Tuple {
    int mask, ind, cost;
    Tuple(int a, int b, int c) {
        ind = a;
        mask = b;
        cost = c;
    }
}
class Edge {
    int dest, weight;
    Edge(int a, int b) {
        dest = a;
        weight = b;
    } 
}