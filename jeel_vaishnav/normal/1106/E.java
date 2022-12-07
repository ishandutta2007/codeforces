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
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        Envelope e[] = new Envelope[k];
        for(int i = 0; i < k; ++i)
            e[i] = new Envelope(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextLong());

        Arrays.sort(e, new Comparator<Envelope>() {
            public int compare(Envelope p1, Envelope p2) {
                if(p1.s < p2.s)
                    return -1;
                if(p1.s > p2.s)
                    return 1;
                return 0;
            }
        });

        long dp[][] = new long[n + 2][m + 1];
        for(int i = 0; i <= n + 1; ++i) {
            for(int j = 0; j <= m; ++j)
                dp[i][j] = Long.MAX_VALUE;
        }
        dp[0][0] = 0;

        PriorityQueue<Envelope> queue = new PriorityQueue<>(new Comparator<Envelope>() {
            public int compare(Envelope e1, Envelope e2) {
                if(e1.w > e2.w)
                    return -1;
                if(e1.w < e2.w)
                    return 1;
                if(e1.d > e2.d)
                    return -1;
                if(e1.d < e2.d)
                    return 1;
                return 0;
            }
        });

        int ptr = 0;
        for(int i = 0; i <= n; ++i) {
            while(ptr < k && e[ptr].s == i) {
                queue.add(e[ptr]);
                ptr++;
            }
            while(queue.size() != 0 && queue.peek().t < i)
                queue.poll();

            for(int j = 0; j < m; ++j) {
                if(dp[i][j] != Long.MAX_VALUE) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                }
            }

            if(!queue.isEmpty()) {
                Envelope curE = queue.peek();
                long coins = curE.w;
                int nextTime = curE.d + 1;
                for(int j = 0; j <= m; ++j) {
                    if(dp[i][j] != Long.MAX_VALUE)
                        dp[nextTime][j] = min(dp[nextTime][j], dp[i][j] + coins);
                }
            }
            else {
                for(int j = 0; j <= m; ++j) {
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                }
            }
        }

        long ans = Long.MAX_VALUE;
        for(int i = 0; i <= m; ++i)
            ans = min(ans, dp[n + 1][i]);

        w.print(ans);

        w.close();
    }
}
class Envelope {
    int s, t, d;
    long w;
    Envelope(int a, int b, int c, long e) {
        s = a - 1;
        t = b - 1;
        d = c - 1;
        w = e;
    }
}