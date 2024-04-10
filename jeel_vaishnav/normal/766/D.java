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
    void union(int i, int j, int invert) {
        if(set[i].size() < set[j].size()) {
            for(int k : set[i]) {
                set[j].add(k);
                par[k] = j;
                val[k] = invert * val[k];                
            }
        }
        else {
            for(int k : set[j]) {
                set[i].add(k);
                par[k] = i;
                val[k] = invert * val[k];
            }
        }
    }
    int par[];
    HashSet<Integer> set[];
    int val[]; 
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0; i < n; ++i)
            map.put(sc.next(), i);

        set = new HashSet[n];
        par = new int[n];
        for(int i = 0; i < n; ++i) {
            set[i] = new HashSet<>();
            par[i] = i;
            set[i].add(i);
        }

        val = new int[n];
        for(int i = 0; i < n; ++i)
            val[i] = 1;

        for(int i = 0; i < m; ++i) {
            int type = sc.nextInt();
            int u = map.get(sc.next());
            int v = map.get(sc.next());

            if(par[u] == par[v]) {
                if(type == 1) {
                    if(val[u] == val[v])
                        w.println("YES");
                    else
                        w.println("NO");
                }
                else {
                    if(val[u] != val[v])
                        w.println("YES");
                    else
                        w.println("NO");
                }
            }
            else {
                if(type == 1) {
                    if(val[u] == val[v])
                        union(par[u], par[v], 1);
                    else
                        union(par[u], par[v], -1);
                }
                else {
                    if(val[u] != val[v])
                        union(par[u], par[v], 1);
                    else
                        union(par[u], par[v], -1);
                }
                w.println("YES");
            }
        }

        for(int x = 0; x < q; ++x) {
            int u = map.get(sc.next());
            int v = map.get(sc.next());

            if(par[u] != par[v])
                w.println("3");
            else if(val[u] == val[v])
                w.println("1");
            else
                w.println("2");
        }

        w.close();      
    }
}