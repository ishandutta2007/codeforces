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
    long isPerfectSquare(long x) {
        long start = 2, end = (long)2e9, s = 2;

        while(start <= end) {
            long mid = (start + end) >> 1;
            if(mid * mid <= x) {
                s = mid;
                start = mid + 1L;
            }
            else
                end = mid - 1L;
        }

        if(s * s == x) return s;

        return -1;
    }

    long isPerfect4(long x) {
        long start = 2, end = (long)44721, s = 2;

        while(start <= end) {
            long mid = (start + end) >> 1;
            if(mid * mid * mid * mid <= x) {
                s = mid;
                start = mid + 1L;
            }
            else
                end = mid - 1L;
        }

        if(s * s * s * s == x)
            return s;
        return -1;
    }

    long isPerfectCube(long x) {
        long start = 2, end = (long)1500000, s = 2;

        while(start <= end) {
            long mid = (start + end) >> 1;
            if(mid * mid * mid <= x) {
                s = mid;
                start = mid + 1L;
            }
            else
                end = mid - 1L;
        }

        if(s * s * s == x)
            return s;
        return -1;
    }

    void addMap(HashMap<Long, Integer> map, long val, int cnt) {
        if(map.get(val) == null)
            map.put(val, cnt);
        else
            map.put(val, map.get(val) + cnt);
    }

    long gcd(long a, long b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        HashMap<Long, Integer> freqM = new HashMap<>();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextLong();
            addMap(freqM, a[i], 1);
        }

        n = freqM.size();
        a = new long[n];
        int freq[] = new int[n];
        int ptr = 0;
        for(long i : freqM.keySet()) {
            a[ptr++] = i;
            freq[ptr - 1] = freqM.get(i);
        }

        HashMap<Long, Integer> map = new HashMap<>();

        HashSet<Long> prime[] = new HashSet[n];
        for(int i = 0; i < n; ++i)
            prime[i] = new HashSet<>();

        int vis[] = new int[n];

        for(int i = 0; i < n; ++i) {
            if(isPerfect4(a[i]) != -1) {
                long p = isPerfect4(a[i]);
                for(int j = 0; j < i; ++j) {
                    if(vis[j] == 0) {
                        long cval = gcd(a[i], a[j]);
                        if(cval != a[i] && cval != 1) {
                            if(!prime[j].contains(cval)) {
                                prime[j].add(cval);
                                addMap(map, cval, freq[j]);
                            }
                        }
                    }
                }

                vis[i] = 1;

                addMap(map, p, 4 * freq[i]);
            }
            else if(isPerfectCube(a[i]) != -1) {
                long c = isPerfectCube(a[i]);

                for(int j = 0; j < i; ++j) {
                    if(vis[j] == 0) {
                        long cval = gcd(a[i], a[j]);
                        if(cval != a[i] && cval != 1) {
                            if(!prime[j].contains(cval)) {
                                prime[j].add(cval);
                                addMap(map, cval, freq[j]);
                            }
                        }
                    }
                }

                vis[i] = 1;
                addMap(map, c, 3 * freq[i]);
            }
            else if(isPerfectSquare(a[i]) != -1) {
                long s = isPerfectSquare(a[i]);

                for(int j = 0; j < i; ++j) {
                    if(vis[j] == 0) {
                        long cval = gcd(a[i], a[j]);
                        if(cval != a[i] && cval != 1) {
                            if(!prime[j].contains(cval)) {
                                prime[j].add(cval);
                                addMap(map, cval, freq[j]);
                            }
                        }
                    }
                }

                vis[i] = 1;
                addMap(map, s, 2 * freq[i]);
            }
            else {
                for(int j = 0; j < i; ++j) {
                    if(vis[j] == 0) {
                        long cval = gcd(a[i], a[j]);
                        if(cval != a[i] && cval != 1) {
                            if(!prime[j].contains(cval)) {
                                prime[j].add(cval);
                                addMap(map, cval, freq[j]);
                            }
                        }
                    }
                }

                for(long j : map.keySet()) {
                    if(a[i] % j == 0) {
                        prime[i].add(j);
                    }
                }

                for(long j : prime[i])
                    addMap(map, j, freq[i]);
            }
        }

        long ans = 1;
        long mod = (long)998244353;
        for(long i : map.keySet()) {
            ans = ans * (long)(map.get(i) + 1) % mod;
        }

        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                int leftPrimes = 2 - prime[i].size();
                for(int j = 0; j < leftPrimes; ++j)
                    ans = ans * (freq[i] + 1L) % mod;
            }
        }

        w.print(ans);

        w.close();
    }
}