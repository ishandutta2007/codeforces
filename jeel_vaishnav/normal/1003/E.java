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
        if(level > farthestLevel) {
            farthestLevel = level;
            farthestNode = i;
        }
        for(int j : adj[i]) {
            if(j != par)
                dfs(j, i, level + 1);
        }
    }
    int farthestNode = 0, farthestLevel = 0;
    ArrayList<Integer> adj[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
 
        int n = sc.nextInt();
        int d = sc.nextInt();
        int k = sc.nextInt();

        if(n - 1 < d) {
            w.print("NO");
            w.close();
            return;
        }

        if(k == 1) {
            if(n == 2 && d == 1) {
                w.println("YES");
                w.print("1 2");
            }
            else
                w.print("NO");
            w.close();
            return;
        } 

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();        

        int last = 0, ptr = 1;

        int deg[] = new int[n];

        while(ptr <= d) {
            adj[ptr].add(last);
            adj[last].add(ptr);
            deg[ptr]++;
            deg[last]++;
            last++;
            ptr++;
        }

        int root = (d + 1) / 2;

        Queue<Integer> queue = new LinkedList<>();
        int vis[] = new int[n];

        queue.add(root);
        vis[root] = 1;

        while(ptr < n) {
            int cur = queue.poll();
            for(int j : adj[cur]) {
                if(vis[j] == 0) {
                    vis[j] = 1;
                    queue.add(j);
                }
            }
            while(ptr < n && deg[cur] < k) {
                adj[ptr].add(cur);
                adj[cur].add(ptr);
                vis[ptr] = 1;
                queue.add(ptr);
                deg[cur]++;
                deg[ptr]++;
                ptr++;
            }
        }

        dfs(root, -1, 0);
        farthestLevel = 0;
        dfs(farthestNode, -1, 0);

        if(farthestLevel == d) {
            w.println("YES");
            for(int i = 0; i < n; ++i) {
                for(int j : adj[i]) {
                    if(j > i) {
                        w.println((i + 1) + " " + (j + 1));
                    }
                }
            }
        }
        else
            w.print("NO");

        w.close();     
    }
}