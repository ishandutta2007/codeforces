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
    void dfsDirectEdges(int i) {
        vis[i] = 1;

        for(int ind : indices[i]) {
            if(visE[ind] == 1)
                continue;

            visE[ind] = 1;

            edge[ind].make(edge[ind].findAnother(i), i);

            if(vis[edge[ind].findAnother(i)] == 0)
                dfsDirectEdges(edge[ind].findAnother(i));
        }
    }
    void dfs(int i) {
        vis[i] = 1;
        cnt++;

        for(int ind : indices[i]) {
            if(isBridge[ind] == 1)
                continue;

            if(vis[edge[ind].findAnother(i)] == 0)
                dfs(edge[ind].findAnother(i));
        }
    }
    void dfsFindBridge(int i, int par) {
        visTime[i] = time++;
        lowTime[i] = visTime[i];

        for(int ind : indices[i]) {

            if(visTime[edge[ind].findAnother(i)] == 0) {
                dfsFindBridge(edge[ind].findAnother(i), i);
                lowTime[i] = min(lowTime[i], lowTime[edge[ind].findAnother(i)]);
            }
            else if(edge[ind].findAnother(i) != par)
                lowTime[i] = min(lowTime[i], visTime[edge[ind].findAnother(i)]);

            if(lowTime[edge[ind].findAnother(i)] > visTime[i])
                isBridge[ind] = 1;
        }
    }
    int indices[][];
    Edge edge[];
    int isBridge[];
    int visTime[], lowTime[];
    int time = 1;
    int vis[];
    int visE[];
    int cnt = 0;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        edge = new Edge[m];

        indices = new int[n][];
        int deg[] = new int[n];
        for(int i = 0; i < m; ++i) {
            edge[i] = new Edge(sc.nextInt() - 1, sc.nextInt() - 1);
            deg[edge[i].u]++;
            deg[edge[i].v]++;
        }
        for(int i = 0; i < n; ++i)
            indices[i] = new int[deg[i]];
        int ptr[] = new int[n];
        for(int i = 0; i < m; ++i) {
            int u = edge[i].u;
            int v = edge[i].v;
            indices[u][ptr[u]++] = i;
            indices[v][ptr[v]++] = i;
        }

        visTime = new int[n];
        lowTime = new int[n];
        isBridge = new int[m];

        dfsFindBridge(0, -1);

        vis = new int[n];
        int maxCnt = 0, maxNode = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                cnt = 0;
                dfs(i);
                if(cnt > maxCnt) {
                    maxCnt = cnt;
                    maxNode = i;
                }
            }
        }

        vis = new int[n];
        visE = new int[m];
        dfsDirectEdges(maxNode);

        w.println(maxCnt);
        for(int i = 0; i < m; ++i)
            w.println(edge[i]);

        w.close();      
    }
}
class Edge {
    int u, v;
    Edge(int a, int b) {
        u = a;
        v = b;
    }
    int findAnother(int a) {
        if(u == a)
            return v;
        else
            return u;
    }
    void make(int a, int b) {
        if(u != a) {
            int temp = u;
            u = v;
            v = temp;
        }
    }
    public String toString() {
        return (u + 1) + " " + (v + 1);
    }
}