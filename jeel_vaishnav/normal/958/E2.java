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
    class Pair {
        int ind;
        long val;
        Pair(int a, long c) {
            ind = a;
            val = c;
        }
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int k = sc.nextInt();
        int n = sc.nextInt();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();

        Arrays.sort(a);

        Pair pair[] = new Pair[n - 1];
        for(int i = 0; i < n - 1; ++i) {
            pair[i] = new Pair(i, a[i + 1] - a[i]);
        }

        Arrays.sort(pair, new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.val > p2.val)
                    return 1;
                if(p1.val < p2.val)
                    return -1;
                return 0;
            }
        });

        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < min(n - 1, 2 * k); ++i) {
            map.put(pair[i].ind, 1);
            map.put(pair[i].ind + 1, 1);
        }

        int m = map.size();
        long t[] = new long[m];

        int cur = 0;
        for(int i : map.keySet()) {
            t[cur++] = a[i];
        }
        Arrays.sort(t);

        long dp[][] = new long[3][k + 1];

        for(int i = 0; i < 3; ++i)
            for(int j = 0; j <= k; ++j)
                dp[i][j] = Long.MAX_VALUE; 

        for(int i = 1; i < m; ++i) {
            dp[2][1] = min(dp[1][1], t[i] - t[i - 1]);
            for(int j = 2; j <= k; ++j) {
                dp[2][j] = dp[1][j];
                if(i >= 2 && dp[0][j - 1] != Long.MAX_VALUE) {
                    dp[2][j] = min(dp[2][j], dp[0][j - 1] + t[i] - t[i - 1]);
                }
            }
            for(int j = 0; j <= k; ++j) {
                dp[0][j] = dp[1][j];
                dp[1][j] = dp[2][j];
                dp[2][j] = Long.MAX_VALUE;
            }
        }

        long ans = dp[1][k];

        w.print(ans);

        w.close();      
    }
}