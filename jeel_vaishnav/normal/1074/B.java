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
        dist[i] = level;
        for(int j : adj[i]) {
            if(j != par)
                dfs(j, i, level + 1);
        }
    }
    int dist[];
    ArrayList<Integer> adj[];
    public void run() {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for(int x = 0; x < t; ++x) {
            int n = sc.nextInt();

            adj = new ArrayList[n + 1];
            for(int i = 1; i <= n; ++i)
                adj[i] = new ArrayList<>();

            for(int i = 0; i < n - 1; ++i) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }

            int k1 = sc.nextInt();
            int node1[] = new int[k1];
            for(int i = 0; i < k1; ++i)
                node1[i] = sc.nextInt();

            int k2 = sc.nextInt();
            int node2[] = new int[k2];
            for(int i = 0; i < k2; ++i)
                node2[i] = sc.nextInt();

            System.out.println("B " + node2[0]);
            System.out.flush();

            int node = sc.nextInt();

            dist = new int[n + 1];
            dfs(node, -1, 0);

            int ind = -1;
            for(int i = 0; i < k1; ++i) {
                if(ind == -1)
                    ind = node1[i];
                else if(dist[ind] > dist[node1[i]])
                    ind = node1[i];
            }

            System.out.println("A " + ind);
            System.out.flush();

            node = sc.nextInt();
            int flag = 0;
            for(int i = 0; i < k2; ++i) {
                if(node2[i] == node)
                    flag = 1;
            }

            if(flag == 0)
                System.out.println("C -1");
            else
                System.out.println("C " + ind);
            System.out.flush();
        }
    }
}