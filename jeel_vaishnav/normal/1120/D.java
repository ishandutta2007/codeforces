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
    void solve(int i, int par) {
        req[i] = 0;

        for(int j : adj[i]) {
            if(j != par) {
                solve(j, i);

                if(req[i] == 0) {
                    req[i] = 1;
                    minInd[i] = minInd[j];
                    minV[i] = minV[j];
                }
                else {
                    if(minV[j] < minV[i]) {
                        for(int k : minInd[j])
                            select[k] = 1;
                        ans += minV[j];
                    }
                    else if(minV[j] == minV[i]) {
                        for(int k : minInd[j])
                            select[k] = 1;
                        ans += minV[j];
                        for(int k : minInd[i])
                            select[k] = 1;
                        minInd[i].clear();
                    }
                    else {
                        for(int k : minInd[i])
                            select[k] = 1;
                        ans += minV[i];
                        minV[i] = minV[j];
                        minInd[i] = minInd[j];
                    }
                }
            }
        }

        if(req[i] == 0) {
            req[i] = 1;
            minInd[i].add(i);
            minV[i] = c[i];
        }
        else {
            if(c[i] < minV[i]) {
                minV[i] = c[i];
                minInd[i].clear();
                minInd[i].add(i);
            }
            else if(c[i] == minV[i]) {
                minInd[i].add(i);
            }
            if(i == 0) {
                ans += minV[i];
                for(int k : minInd[i])
                    select[k] = 1;
            }
        }
    }
    ArrayList<Integer> adj[];
    long c[];
    int select[];
    long ans = 0;
    long minV[];
    ArrayList<Integer> minInd[];
    int req[]; 
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        c = new long[n];
        for(int i = 0; i < n; ++i)
            c[i] = sc.nextLong();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u].add(v);
            adj[v].add(u);
        }

        select = new int[n];
        minV = new long[n];
        minInd = new ArrayList[n];
        for(int i = 0; i < n; ++i) 
            minInd[i] = new ArrayList<>();
        req = new int[n];
        solve(0, -1);

        int cnt = 0;
        for(int i = 0; i < n; ++i) 
            cnt += select[i];

        w.print(ans + " ");
        w.println(cnt);
        for(int i = 0; i < n; ++i) {
            if(select[i] == 1)
                w.print((i + 1) + " ");
        }

        w.close();
    }
}