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
        
        int edge[][] = new int[n][n];
        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            edge[u][v] = 1;
            edge[v][u] = 1;
        }

        long dp[][] = new long[1 << n][n];
        long ans = 0;
        for(int i = 0; i < n; ++i) {
            int startInd = n - 1 - i;
            for(int j = 1; j < (1 << (n - 1 - i)); ++j)
                for(int k = 0; k < n; ++k)
                    dp[j][k] = 0;

            for(int j = 1; j <= (1 << (n - 1 - i)) - 1; ++j) {
                int cntBits = 0, ind = -1;
                for(int k = 0; k < n - 1 - i; ++k) {
                    if((j >> k & 1) == 1) {
                        cntBits++;
                        ind = k;
                    }
                }

                if(cntBits == 1 && edge[startInd][ind] == 1)
                    dp[j][ind] = 1;

                for(int k = 0; k < n - 1 - i; ++k) {
                    if((j >> k & 1) == 0)
                        continue;

                    for(int l = 0; l < n - 1 - i; ++l) {
                        if((j >> l & 1) == 1)
                            continue;

                        int newMask = j ^ (1 << l);
                        if(edge[k][l] == 1)
                            dp[newMask][l] += dp[j][k];
                    }
                }

                if(cntBits > 1) {
                    for(int k = 0; k < n - 1 - i; ++k) {
                        if((j >> k & 1) == 0)
                            continue;
                        if(edge[k][startInd] == 1)
                            ans += dp[j][k];
                    }
                }
            }
        }

        ans /= 2L;
        w.print(ans);

        w.close();
    }
}