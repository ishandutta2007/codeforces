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
    void permuteAndFind(int ind) {
        if(k == 0)
            return;
        if(ind == n) {
            char[] ans = new char[m];
            for(int i = 0; i < m; ++i)
                ans[i] = (char)(set[i] + '0');
            list.add(ans);
            k--;
            return;
        }
        for(Edge curE : adj[ind]) {
            if(k == 0)
                return;
            int j = curE.dest;
            int edgeInd = curE.ind;
            if(dist[ind] == dist[j] + 1) {
                set[edgeInd] = 1;
                permuteAndFind(ind + 1);
                set[edgeInd] = 0;
            }
        }
    }
    PrintWriter w = new PrintWriter(System.out);
    class Edge {
        int dest, ind;
        Edge(int a, int b) {
            dest = a;
            ind = b;
        }
    }
    ArrayList<Edge> adj[];
    int dist[];
    ArrayList<char[]> list = new ArrayList<>();
    int set[];
    int m;
    int n;
    int k;
    public void run() {
        InputReader sc = new InputReader(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u].add(new Edge(v, i));
            adj[v].add(new Edge(u, i));
        }

        dist = new int[n];
        Arrays.fill(dist, -1);
        int curDist = 0;
        dist[0] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        while(!queue.isEmpty()) {
            int len = queue.size();
            for(int x = 0; x < len; ++x) {
                int cur = queue.poll();
                for(Edge curE : adj[cur]) {
                    int j = curE.dest;
                    if(dist[j] == -1) {
                        dist[j] = curDist + 1;
                        queue.add(j);
                    }
                }
            }
            curDist++;
        }

        set = new int[m];
        permuteAndFind(1);

        w.println(list.size());
        for(char[] s : list) {
            for(char i : s)
                w.print(i);
            w.println();
        }

        w.close();      
    }
}