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

    void dfs(int i, int edgeNo) {
        vis[i] = 1;

        if(edgeNo != -1)
            list.add(edgeNo);

        for(int ind : adj[i]) {
            int j = e[ind].findAnother(i);
            if(vis[j] == 0) {
                if(j == s) {
                    sInd = ind;
                }
                else if(j == t) {
                    tInd = ind;
                }
                else {
                    dfs(j, ind);
                }
            }
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
            return u;
        }
        public String toString() {
            return (u + 1) + " " + (v + 1);
        }
    }

    Edge e[];
    ArrayList<Integer> adj[];
    int s, t;
    int vis[];
    ArrayList<Integer> list = new ArrayList<>();
    ArrayList<Integer> unionsList = new ArrayList<>();
    ArrayList<Integer> uniontList = new ArrayList<>();
    int sInd = -1, tInd = -1;
    
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        e = new Edge[m];

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;

            e[i] = new Edge(u, v);

            adj[u].add(i);
            adj[v].add(i);
        }

        s = sc.nextInt() - 1;
        t = sc.nextInt() - 1;
        int ds = sc.nextInt();
        int dt = sc.nextInt();

        vis = new int[n];
        int col = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0 && i != s && i != t) {
                col++;
                sInd = -1;
                tInd = -1;

                dfs(i, -1);

                if(sInd != -1 && tInd != -1) {
                    unionsList.add(sInd);
                    uniontList.add(tInd);
                }
                else if(sInd != -1) {
                    ds--;
                    list.add(sInd);
                }
                else {
                    dt--;
                    list.add(tInd);
                }
            }
        }

        if(ds <= 0 || dt <= 0) {
            w.print("No");
            w.close();
            return;
        }

        if(unionsList.size() == 0) {
            w.println("Yes");
            for(int i : list) {
                w.println(e[i]);
            }
            w.println((s + 1) + " " + (t + 1));
            w.close();
            return;
        }

        if(unionsList.size() + 1 > ds + dt) {
            w.print("No");
            w.close();
            return;
        }

        list.add(unionsList.get(0));
        list.add(uniontList.get(0));
        ds--;
        dt--;

        for(int i = 1; i < unionsList.size(); ++i) {
            if(ds > 0) {
                list.add(unionsList.get(i));
                ds--;
            }
            else {
                list.add(uniontList.get(i));
            }
        }

        w.println("Yes");
        for(int i : list)
            w.println(e[i]);

        w.close();
    }
}