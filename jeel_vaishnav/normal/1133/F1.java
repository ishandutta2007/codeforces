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
    void union(int i, int j) {
        par[i] = j;
    }
    int findSet(int i) {
        if(par[i] == i)
            return i;

        par[i] = findSet(par[i]);
        return par[i];
    }
    int par[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        Edge e[] = new Edge[m];
        int deg[] = new int[n];
        for(int i = 0; i < m; ++i) {
            e[i] = new Edge(sc.nextInt() - 1, sc.nextInt() - 1);
            deg[e[i].u]++;
            deg[e[i].v]++;
        }

        int maxind = 0;
        for(int i = 1; i < n; ++i) {
            if(deg[i] > deg[maxind])
                maxind = i;
        }

        int d = deg[maxind];
        final int maxInd = maxind;

        par = new int[n];
        for(int i = 0; i < n; ++i)
            par[i] = i;

        Arrays.sort(e, new Comparator<Edge>() {
            public int compare(Edge e1, Edge e2) {
                boolean check1 = (e1.u == maxInd) || (e1.v == maxInd);
                boolean check2 = (e2.u == maxInd) || (e2.v == maxInd);

                if(check1 == check2)
                    return 0;
                if(!check1)
                    return -1;
                if(!check2)
                    return 1;

                return 0;
            }
        });

        int cnt = 0;
        int alr[] = new int[m];
        ArrayList<Edge> ans = new ArrayList<>();
        for(int i = 0; i < m; ++i) {
            int u = findSet(e[i].u);
            int v = findSet(e[i].v);

            if(u != v) {
                alr[i] = 1;
                union(u, v);
                ans.add(e[i]);
                if(e[i].u == maxInd || e[i].v == maxInd)
                    cnt++;
            }
        }

        if(cnt > d) {
            w.print("NO");
            w.close();
            return;
        }

        for(int i = 0; i < m; ++i) {
            if((e[i].u == maxInd || e[i].v == maxInd) && cnt < d && alr[i] == 0) {
                cnt++;
                ans.add(e[i]);
            } 
        }

        Collections.sort(ans, new Comparator<Edge>() {
            public int compare(Edge e1, Edge e2) {
                boolean check1 = (e1.u == maxInd) || (e1.v == maxInd);
                boolean check2 = (e2.u == maxInd) || (e2.v == maxInd);

                if(check1 == check2)
                    return 0;
                if(check1)
                    return -1;
                if(check2)
                    return 1;

                return 0;
            }
        });

        for(int i = 0; i < n; ++i)
            par[i] = i;

        int check[] = new int[ans.size()];
        for(int i = 0; i < ans.size(); ++i) {
            Edge curE = ans.get(i);
            int u = findSet(curE.u);
            int v = findSet(curE.v);

            if(!(curE.u == maxInd || curE.v == maxInd)) {
                if(u != v) {
                    check[i] = 1;
                    union(u, v);
                }
                else
                    check[i] = 0;
            }
            else {
                check[i] = 1;
                union(u, v);
            }
        }

        for(int i = 0; i < ans.size(); ++i) {
            Edge curE = ans.get(i);

            if(check[i] == 1)
                w.println(curE);
        }

        w.close();
    }
}
class Edge {
    int u, v;
    Edge(int b, int c) {
        u = b;
        v = c;
    }
    public String toString() {
        return (u + 1) + " " + (v + 1);
    }
}