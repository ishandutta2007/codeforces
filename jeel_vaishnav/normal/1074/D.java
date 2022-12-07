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
    void union(long a, long b, long val) {
        par.put(b, a);
        map.put(b, val);
    }
    long findSet(long a) {
        if(par.get(a) == a)
            return a;
        long curP = findSet(par.get(a));
        if(curP != par.get(a)) {
            map.put(a, map.get(a) ^ map.get(par.get(a)));
            par.put(a, curP);
        }
        return par.get(a);
    }
    HashMap<Long, Long> map = new HashMap<>();
    HashMap<Long, Long> par = new HashMap<>();
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int q = sc.nextInt();

        long last = 0;

        for(int x = 0; x < q; ++x) {
            int type = sc.nextInt();

            if(type == 1) {
                long l = sc.nextLong() ^ last;
                long r = sc.nextLong() ^ last;

                long val = sc.nextLong() ^ last;

                if(l > r) {
                    long temp = l;
                    l = r;
                    r = temp;
                }
                r++;

                if(map.get(l) == null) {
                    par.put(l, l);
                    map.put(l, 0L);
                }
                if(map.get(r) == null) {
                    par.put(r, r);
                    map.put(r, 0L);
                }
                if(findSet(l) != findSet(r))
                    union(findSet(l), findSet(r), map.get(l) ^ map.get(r) ^ val);
            }
            else {
                long l = sc.nextLong() ^ last;
                long r = sc.nextLong() ^ last;

                if(l > r) {
                    long temp = l;
                    l = r;
                    r = temp;
                }
                r++;

                if(map.get(l) == null || map.get(r) == null || findSet(l) != findSet(r)) {
                    w.println("-1");
                    last = 1;
                }
                else {
                    w.println(map.get(l) ^ map.get(r));
                    last = map.get(l) ^ map.get(r);
                }
            }
        }

        w.close();
    }
}