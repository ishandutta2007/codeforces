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
    void startDeleting(int i, int par) {
        list.add(i);
        for(int j : v[i].adj.keySet()) {
            if(j != par) {
                startDeleting(j, i);
            }
        }
    }
    boolean dfs(int i, int par) {
        ArrayList<Integer> suc = new ArrayList<>();
        for(int j : v[i].adj.keySet()) {
            if(j != par) {
                boolean cond = dfs(j, i);
                if(cond) {
                    suc.add(j);
                }
            } 
        }
        if(suc.size() % 2 == v[i].adj.size() % 2) {
            list.add(i);
            for(int j : suc) {
                v[i].adj.remove(j);
            }
            for(int j : v[i].adj.keySet()) {
                if(j != par) {
                    v[j].adj.remove(i);
                    startDeleting(j, i);
                }
            }
            return true;
        }
        else {
            for(int j : suc) {
                v[i].adj.remove(j);
            }
            return false;
        }
    }

    class Vertex {
        TreeMap<Integer, Integer> adj = new TreeMap<>();
    }

    Vertex v[];
    ArrayList<Integer> list = new ArrayList<>();

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        v = new Vertex[n];

        for(int i = 0; i < n; ++i)
            v[i] = new Vertex();

        ArrayList<Integer> root = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            int par = sc.nextInt() - 1;
            if(par == -1) {
                root.add(i);
            }
            else {
                v[par].adj.put(i, 1);
                v[i].adj.put(par, 1);
            }
        }

        boolean ans = true;
        for(int i : root) {
            ans &= dfs(i, -1);
        }

        if(ans) {
            w.println("YES");
            for(int i : list)
                w.println((i + 1));
        }
        else 
            w.println("NO");


        w.close();      
    }
}