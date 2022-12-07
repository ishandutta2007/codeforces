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
    long[][] multiply(long[][] a, long[][] b) {
        long[][] ans = new long[k][k];
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < k; ++j) {
                for(int l = 0; l < k; ++l) {
                    ans[i][j] += a[i][l] * b[l][j] % newMod;
                }
                ans[i][j] %= newMod;
            }
        }

        return ans;
    }
    long[][] matmul(long[][] a, long b) {
        if(b == 0) {
            long ans[][] = new long[k][k];
            for(int i = 0; i < k; ++i)
                ans[i][i] = 1L;
            return ans;
        }

        long[][] val = matmul(a, b / 2);

        if(b % 2 == 0)
            return multiply(val, val);
        else
            return multiply(val, multiply(val, a));
    }
    long gcd(long a, long b) {
        if(a == 0)
            return b;
        return gcd(b % a, a);
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
    int k;
    long mod = (long)998244353;
    long newMod = (long)998244352;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        k = sc.nextInt();
        
        long mat[][] = new long[k][k];
        for(int i = 0; i < k - 1; ++i) {
            mat[i + 1][i] = 1;
        }

        for(int i = 0; i < k; ++i) {
            mat[k - 1 - i][k - 1] = sc.nextLong();
        }

        long n = sc.nextLong();
        long m = sc.nextLong();

        long fmat[][] = matmul(mat, n - 1L);

        long pow = fmat[k - 1][0];

        // generator for mod = 3
        long hn = BabyStepAlgorithm.solve(3L, m, mod);

        // pow * hk % (mod - 1L) = hn
        // pow * hk = hn + c * (mod - 1L)
        // pow * hk - newMod * c = hn 

        if(!ExtendedEuclidean.findSolution(pow, -newMod, hn)) {
            w.print("-1");
            w.close();
            return;
        }

        ExtendedEuclidean.make_positive_x();
        long x = ExtendedEuclidean.x;

        if(x < 0) {
            long reqV = (abs(x)- 1L) / mod + 1L;
            x += reqV * mod;
            x %= mod;
        }

        long ans = fast_pow(3L, x);
        w.println(ans);

        w.close();
    }
}
class ExtendedEuclidean {
    static long x, y, gcdV, a, b;
    static long gcd(long a, long b) {
        if(a == 0) {
            x = 0;
            y = 1;
            return b;
        }

        long ans = gcd(b % a, a);
        long tempX = x;
        x = y - b / a * x;
        y = tempX;
        return ans;
    }
    static boolean findSolution(long a, long b, long c) {
        // finds solution (x, y) for ax + by = c
        // if solution doesn't exist returns false else returns true

        ExtendedEuclidean.a = abs(a);
        ExtendedEuclidean.b = abs(b);

        gcdV = gcd(abs(a), abs(b));

        if(c % gcdV != 0)
            return false;

        x *= c / gcdV;
        y *= c / gcdV;

        if(a < 0)
            x *= -1;
        if(b < 0)
            y *= -1;

        return true;
    }
    static void make_positive_y() {
        long jumpx = b / gcdV;
        long jumpy = a / gcdV;

        if(y < 0) {
            long req = (-y - 1L) / jumpy + 1L;
            x -= req * jumpx;
            y += req * jumpy;
        }
    }
    static void make_positive_x() {
        long jumpx = b / gcdV;
        long jumpy = a / gcdV;

        if(x < 0) {
            long req = (-x - 1L) / jumpx + 1L;
            x += req * jumpx;
            y -= req * jumpy;
        }
    }
}
class BabyStepAlgorithm {
    static long solve(long a, long b, long m) {
        // returns x in a ^ x % m = b
        // returns -1 if solution doesnt exist
        // Complexity : O(root(m)log(m))

        // Let x = np - q
        // We equate a^(np) = b*a^q;

        long n = (long)sqrt(m);

        // val = a ^ n
        long val = 1L;
        for(int i = 0; i < n; ++i)
            val = val * a % m;

        // adding all values for a^(np)
        // range of p : [1, ceil(m / n)]
        long ul = (m - 1L) / n + 1L;

        // map of type (a^(np), p)
        TreeMap<Long, Long> map = new TreeMap<>();
        
        // cval = a^(ni)
        long cval = 1L;
        for(long i = 1; i <= ul; ++i) {
            cval = cval * val % m;
            map.put(cval, i);
        }

        // range of q : [0, n]
        // we iterate over possible 
        
        // cval = b * a^q
        cval = b;
        for(long i = 0; i <= n; ++i) {
            if(map.lowerKey(cval + 1L) != null) {
                long poss = map.lowerKey(cval + 1L);

                if(poss == cval) {
                    long p = map.get(poss);
                    long q = i;
                    return n * p - q;
                }
            }
            cval = cval * a % m;
        }

        return -1;
    }
}