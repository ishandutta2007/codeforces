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
        new Thread(null, new Main(),"Main",1<<27).start();
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();
        int n = s.length;

        int flag = 0;
        for(int i = 1; i < s.length; ++i) {
            if(s[i] != s[0])
                flag = 1;
        }

        if(flag == 0) {
            w.print("Impossible");
            w.close();
            return;
        }

        if(n % 2 == 1) {
            flag = 0;
            for(int i = 0; i < s.length; ++i) {
                if(i != s.length / 2 && s[i] != s[0]) {
                    flag = 1;
                }
            }
            if(flag == 0) {
                w.print("Impossible");
                w.close();
                return;
            }
        }

        int dp[][] = new int[n][n];
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == s[i + 1])
                dp[i][i + 1] = 1;
        }

        for(int len = 3; len <= n; ++len) {
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1;
            }
        }

        for(int i = 0; i < s.length - 1; ++i) {
            if(i < s.length / 2) {
                int lastIdx = 2 * (i + 1) - 1;
                if(dp[0][i] == 0 && dp[0][lastIdx] == 1 && (lastIdx + 1 > n - 1 || dp[lastIdx + 1][n - 1] == 1)) {
                    w.print("1");
                    w.close();
                    return;
                }
            }
            else {
                int len = s.length - i - 1;
                int firstIdx = s.length - 2 * len;
                if(dp[i + 1][n - 1] == 0 && dp[0][firstIdx - 1] == 1 && dp[firstIdx][n - 1] == 1) {
                    w.print("1");
                    w.close();
                    return;
                }
            }
        }

        w.print("2");
        
        w.close();
    }
}