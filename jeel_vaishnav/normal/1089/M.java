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
    void dfs(int i) {
        vis[i] = 1;

        for(int j = 0; j < n; ++j) {
            if(adj[i][j] == 1 && vis[j] == 0)
                dfs(j);
        }

        topoSort.add(i);
    }
    void dfsFindScc(int i, int curOwner) {
        vis[i] = 1;
        owner[i] = curOwner;
        curScc.add(i);

        for(int j = 0; j < n; ++j) {
            if(revAdj[i][j] == 1 && vis[j] == 0)
                dfsFindScc(j, curOwner);
        }
    }
    ArrayList<Integer> topoSort = new ArrayList<>();
    int adj[][];
    int revAdj[][];
    int vis[];
    int n;
    int owner[];
    ArrayList<Integer> curScc = new ArrayList<>();
    ArrayList<ArrayList<Integer>> scc = new ArrayList<>();
    int cnt = 0;
    char mat[][][] = new char[18][4][300];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        for(int i = 0; i < 18; ++i) {
            for(int j = 0; j < 4; ++j)
                Arrays.fill(mat[i][j], '.');
        }

        n = sc.nextInt();

        adj = new int[n][n];
        revAdj = new int[n][n];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                adj[i][j] = sc.nextInt();
                revAdj[j][i] = adj[i][j]; 
            }
        }

        vis = new int[n];
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0)
                dfs(i);
        }

        vis = new int[n];
        owner = new int[n];
        for(int i = topoSort.size() - 1; i >= 0; --i) {
            int curEle = topoSort.get(i);
            if(vis[curEle] == 0) {
                curScc = new ArrayList<>();
                dfsFindScc(curEle, cnt++);
                scc.add(curScc);
            }
        }

        for(int i = 0; i < cnt; ++i) {
            for(int j = 0; j < 4; ++j) {
                for(int k = 0; k < 300; ++k) {
                    mat[2 * i + 1][j][k] = '#';
                }
            }
            for(int j : scc.get(i)) {
                mat[2 * i][0][j] = (char)('1' + j);
            }
        }

        int sccAdj[][] = new int[cnt][cnt];
        for(int i = 0; i < cnt; ++i) {
            ArrayList<Integer> adjList = scc.get(i);
            for(int j : adjList) {
                for(int k = 0; k < n; ++k) {
                    if(adj[j][k] == 1 && owner[k] != i) {
                        sccAdj[i][owner[k]] = 1;
                    }
                }
            }
        }

        int egdeInd = 10;

        for(int i = 0; i < cnt; ++i) {
            for(int j = 0; j < cnt; ++j) {
                if(sccAdj[i][j] == 1) {
                    for(int k = 2 * i + 1; k < 2 * j; ++k) {
                        for(int dx = -1; dx <= 1; ++dx) {
                            for(int dy = -1; dy <= 1; ++dy) {
                                mat[k][1 + dx][egdeInd + dy] = '#';
                            }
                        }
                        mat[k][1][egdeInd] = '.';
                    }
                    egdeInd += 3;
                }
            }
        }

        w.println("300 4 18");
        for(int i = 0; i < 18; ++i) {
            for(int j = 0; j < 4; ++j) {
                for(int k = 0; k < 300; ++k)
                    w.print(mat[i][j][k]);
                w.println();
            }
            w.println();
        }

        w.close();
    }
}