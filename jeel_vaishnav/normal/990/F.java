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
    int dfs(int i, int ind, int type) {
        vis[i] = 1;
        int val = 0;

        for(int k = 0; k < v[i].adj.size(); ++k) {
            Edge p = v[i].adj.get(k);
            int j = v[i].adj.get(k).dest;
            int nind = v[i].adj.get(k).ind;
            int ntype = v[i].adj.get(k).type;
            if(vis[j] == 0) {
                val += dfs(j, nind, ntype);
            } 
        }
        if(ind != -1)
            cost[ind] = type * (s[i] + val);
        return s[i] + val;
    }
    int[] s;
    int cost[];
    Vertex v[];
    int vis[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        s = new int[n];
        for(int i = 0; i < n; ++i)
            s[i] = sc.nextInt();

        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += s[i];

        if(sum != 0) {
            w.print("Impossible");
            w.close();
            return;
        }

        int m = sc.nextInt();
        v = new Vertex[n];
        for(int i = 0; i < n; ++i)
            v[i] = new Vertex();
        for(int i = 0; i < m; ++i) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            v[a].adj.add(new Edge(b, i, 1));
            v[b].adj.add(new Edge(a, i, -1));
        }

        w.println("Possible");

        vis = new int[n];
        cost = new int[m];
        dfs(0, -1, 0);
        for(int i : cost) {
            w.println(i);
        }        

        w.close();      
    }
}
class Vertex {
    ArrayList<Edge> adj = new ArrayList<>();
}
class Edge {
    int dest;
    int ind;
    int type;
    Edge(int a, int b, int c) {
        dest = a;
        ind = b;
        type = c;
    }
}