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
    void relax(int i, int j, int k) {
        dp[i][j][k] = Integer.MAX_VALUE;

        if(i - 1 >= 0) {
            int ind1 = dp[i - 1][j][k];
            if(ind1 <= n - 2)
                dp[i][j][k] = min(dp[i][j][k], nextInd[ind1 + 1][words[0][i - 1] - 'a']);
        }

        if(j - 1 >= 0) {
            int ind2 = dp[i][j - 1][k];
            if(ind2 <= n - 2)
                dp[i][j][k] = min(dp[i][j][k], nextInd[ind2 + 1][words[1][j - 1] - 'a']);
        }

        if(k - 1 >= 0) {
            int ind3 = dp[i][j][k - 1];
            if(ind3 <= n - 2)
                dp[i][j][k] = min(dp[i][j][k], nextInd[ind3 + 1][words[2][k - 1] - 'a']);
        }
    }
    int n;
    int dp[][][];
    int nextInd[][];
    char[][] words;
    int len[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();
        int q = sc.nextInt();

        char[] s = sc.next().toCharArray();

        nextInd = new int[n][26];
        int lastInd[] = new int[26];
        Arrays.fill(lastInd, Integer.MAX_VALUE);

        for(int i = n - 1; i >= 0; --i) {
            lastInd[s[i] - 'a'] = i;
            for(int j = 0; j < 26; ++j) {
                nextInd[i][j] = lastInd[j];
            }
        }

        dp = new int[251][251][251];
        words = new char[3][251];
        len = new int[3];

        dp[0][0][0] = -1;
        for(int x = 0; x < q; ++x) {
            char type = sc.next().charAt(0);
            int ind = sc.nextInt() - 1;

            if(type == '+') {
                char a = sc.next().charAt(0);

                words[ind][len[ind]] = a;
                len[ind]++;

                if(ind == 0) { 
                    int i = len[ind];
                    for(int j = 0; j <= len[1]; ++j) {
                        for(int k = 0; k <= len[2]; ++k) {
                            relax(i, j, k);
                        }
                    }
                }
                else if(ind == 1) {
                    int j = len[ind];
                    for(int i = 0; i <= len[0]; ++i) {
                        for(int k = 0; k <= len[2]; ++k) {
                            relax(i, j, k);
                        }
                    }
                }
                else {
                    int k = len[ind];
                    for(int i = 0; i <= len[0]; ++i) {
                        for(int j = 0; j <= len[1]; ++j) {
                            relax(i, j, k);
                        }
                    }
                }

                if(dp[len[0]][len[1]][len[2]] != Integer.MAX_VALUE) {
                    w.println("YES");
                }
                else
                    w.println("NO");
            }
            else {
                len[ind]--;

                if(dp[len[0]][len[1]][len[2]] != Integer.MAX_VALUE) {
                    w.println("YES");
                }
                else
                    w.println("NO");
            }
        }

        w.close();
    }
}