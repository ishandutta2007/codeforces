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
    long fast_pow(long a, long b) {
        if(b == 0)
            return 1L;

        long val = fast_pow(a, b / 2);

        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    long mod = (long)1e9 + 7;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        TreeMap<Long, Integer> bmap = new TreeMap<>();
        TreeMap<Long, Integer> smap = new TreeMap<>();
        TreeMap<Long, Integer> dmap = new TreeMap<>();

        int ext = 0;

        for(int i = 0; i < n; ++i) {
            String s = sc.next();
            long val = sc.nextLong();

            if(s.equals("ADD")) {
                if(bmap.size() != 0 && val < bmap.lastKey())
                    bmap.put(val, 1);
                else if(smap.size() != 0 && val > smap.firstKey())
                    smap.put(val, 1);
                else
                    dmap.put(val, 1);
            }
            else {
                if(bmap.get(val) != null) {
                    if(bmap.lastKey() == val) {
                        bmap.remove(val);
                        for(long j : dmap.keySet()) {
                            smap.put(j, 1);
                        }
                        dmap.clear();
                    }
                    else {
                        w.print("0");
                        w.close();
                        return;
                    }
                }
                else if(smap.get(val) != null) {
                    if(smap.firstKey() == val) {
                        smap.remove(val);
                        for(long j : dmap.keySet()) {
                            bmap.put(j, 1);
                        }
                        dmap.clear();
                    }
                    else {
                        w.print("0");
                        w.close();
                        return;
                    }
                }
                else {
                    ext++;
                    dmap.remove(val);

                    long temp = val;
                    while(dmap.lowerKey(temp) != null) {
                        temp = dmap.lowerKey(temp);
                        dmap.remove(temp);
                        bmap.put(temp, 1);
                    }

                    temp = val;
                    while(dmap.higherKey(temp) != null) {
                        temp = dmap.higherKey(temp);
                        dmap.remove(temp);
                        smap.put(temp, 1);
                    }
                }
            }
        }

        long ans = fast_pow(2, ext);

        ans = (ans * (long)(dmap.size() + 1)) % mod;

        w.print(ans);

        w.close();   
    }
}