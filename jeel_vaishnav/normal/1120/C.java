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
    int[] kmp(char[] pattern, char[] text) {
        int n = pattern.length;

        int[] lps = new int[n];
        lps[0] = -1;
        int j = -1;
        for(int i = 1; i < n; ++i) {
            while(j != -1 && pattern[j + 1] != pattern[i]) {
                j = lps[j];
            }

            if(pattern[j + 1] == pattern[i]) {
                j = j + 1;
                lps[i] = j;
            }
            else {
                j = -1;
                lps[i] = -1;
            }
        }

        int m = text.length;
        int[] ans = new int[m];
        j = -1;
        for(int i = 0; i < m; ++i) {
            if(j == n - 1)
                j = lps[j];

            while(j != -1 && pattern[j + 1] != text[i])
                j = lps[j];

            if(pattern[j + 1] == text[i]) {
                j = j + 1;
                ans[i] = j;
            }
            else {
                j = -1;
                ans[i] = -1;
            }
        }

        return ans;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        char[] s = sc.next().toCharArray();

        int dp[] = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = a;

        for(int i = 0; i < n - 1; ++i) {
            dp[i + 1] = min(dp[i + 1], dp[i] + a);

            char[] pattern = new char[n - i - 1];
            for(int j = i + 1; j < n; ++j) {
                pattern[j - i - 1] = s[j];
            }
            char[] text = new char[i + 1];
            for(int j = 0; j <= i; ++j)
                text[j] = s[j];

            int[] ans = kmp(pattern, text);
            int maxV = -1;
            for(int j = 0; j <= i; ++j) {
                maxV = max(maxV, ans[j]);
            }

            if(maxV != -1) {
                dp[i + 1 + maxV] = min(dp[i + 1 + maxV], dp[i] + b);
            }
        }

        w.print(dp[n - 1]);
        
        w.close();
    }
}