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
        long weight;
        Edge(int a, int b, long c) {
            u = a;
            v = b;
            weight = c;
        }
        int findAnother(int a) {
            if(a == u)
                return v;
            return u;
        }
    }
    Edge e[];
    ArrayList<Integer> adj[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        e = new Edge[m];

        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            long weight = sc.nextLong();
            e[i] = new Edge(u, v, weight);
            adj[u].add(i);
            adj[v].add(i);
        }

        long ans[] = new long[n];
        Arrays.fill(ans, Long.MAX_VALUE);
        ans[0] = 0;
        PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.cost < p2.cost)
                    return -1;
                if(p1.cost > p2.cost)
                    return 1;
                return 0;
            }
        });
        queue.add(new Pair(0, -1, 0));

        ArrayList<Integer> list = new ArrayList<>();

        int visE[] = new int[m];

        int vis[] = new int[n];
        while(!queue.isEmpty()) {
            Pair curP = queue.poll();
            int ind = curP.ind;

            if(vis[ind] == 1)
                continue;

            vis[ind] = 1;
            if(curP.edgeNo != -1) {
                list.add(curP.edgeNo + 1);
                visE[curP.edgeNo] = 1;
            }

            long cost = curP.cost;

            for(int cind : adj[ind]) {
                Edge curE = e[cind];
                int j = curE.findAnother(ind);
                long ccost = curE.weight;

                if(ans[j] > cost + ccost) {
                    ans[j] = cost + ccost;
                    queue.add(new Pair(j, cind, ans[j]));
                }
            }
        }

        int len = min(k, list.size());
        w.println(len);
        for(int i = 0; i < len; ++i)
            w.print(list.get(i) + " ");

        w.close();
    }
}
class Pair {
    long cost;
    int edgeNo, ind;
    Pair(int a, int b, long c) {
        ind = a;
        edgeNo = b;
        cost = c;
    }
}