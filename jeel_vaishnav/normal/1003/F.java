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
    long mod1 = 1400305337;
    long mod2 = 1824261409;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
 
        HashMap<String, Long> map = new HashMap<>();
        
        int n = sc.nextInt();
        int length[] = new int[n];
        long a[] = new long[n];
        long ptr = 1;
        int len = n - 1;
        for(int i = 0; i < n; ++i) {
            String s = sc.next();
            len += s.length();
            if(map.get(s) == null)
                map.put(s, ptr++);
            length[i] = s.length();
            a[i] = map.get(s);
        }

        HashMap<Long, TreeMap<Integer, Integer>> lmap1 = new HashMap<>();
        HashMap<Long, Integer> lmap2 = new HashMap<>();

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            long mul1 = 1L, mul2 = 1L;
            long hash1 = 0, hash2 = 0;
            int tlen = 0;
            for(int j = i; j < n; ++j) {
                tlen += length[j];
                hash1 = (hash1 + mul1 * a[j] % mod1) % mod1;
                hash2 = (hash2 + mul2 * a[j] % mod2) % mod2;
                if(lmap1.get(hash1) != null && lmap2.get(hash2) != null) {
                    TreeMap<Integer, Integer> cmap = lmap1.get(hash1);
                    if(cmap.lowerKey(i) != null) {
                        int cans = cmap.get(cmap.lowerKey(i)) + tlen - 1;
                        cmap.put(j, cans);
                        ans = max(ans, cans);
                    }
                    else {
                        cmap.put(j, tlen - 1);
                    }
                }
                else {
                    lmap1.put(hash1, new TreeMap<>());
                    lmap1.get(hash1).put(j, tlen - 1);
                    lmap2.put(hash2, tlen - 1);
                }
                mul1 = (mul1 * (long)539) % mod1;
                mul2 = (mul2 * (long)473) % mod2;
            }
        }

        if(ans == 0)
            w.print(len);
        else {
            int fans = len - ans;
            w.print(fans);
        }

        w.close();     
    }
}
class Pair {
    int ind;
    int val;
    Pair(int a, int b) {
        ind = a;
        val = b;
    }
}