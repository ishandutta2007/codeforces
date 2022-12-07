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
    long getHash(long[][] hash, int charInd, int l, int r, long mod, long[] p26) {
        if(l == 0)
            return hash[r][charInd];

        long ans = (hash[r][charInd] - hash[l - 1][charInd] * p26[r - l + 1] % mod + mod) % mod;
        return ans;
    }
    long mod1 = (long)1e9 + 7;
    long mod2 = (long)1e9 + 9;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        long p26m1[] = new long[200001];
        long p26m2[] = new long[200001];

        p26m1[0] = 1;
        p26m2[0] = 1;
        for(int i = 1; i <= 200000; ++i) {
            p26m1[i] = p26m1[i - 1] * 26L % mod1;
            p26m2[i] = p26m2[i - 1] * 26L % mod2;
        }

        int n = sc.nextInt();
        int m = sc.nextInt();

        char[] s = sc.next().toCharArray();
        int maxInd[][] = new int[s.length][26];

        Arrays.fill(maxInd[0], -1);
        maxInd[0][s[0] - 'a'] = 0;

        for(int i = 1; i < s.length; ++i) {
            for(int j = 0; j < 26; ++j)
                maxInd[i][j] = maxInd[i - 1][j];
            maxInd[i][s[i] - 'a'] = i;
        }

        long hash1[][] = new long[s.length][26];
        long hash2[][] = new long[s.length][26];

        hash1[0][s[0] - 'a'] = 1;
        hash2[0][s[0] - 'a'] = 1;

        for(int i = 1; i < s.length; ++i) {
            for(int j = 0; j < 26; ++j) {
                hash1[i][j] = hash1[i - 1][j] * 26 % mod1;
                hash2[i][j] = hash2[i - 1][j] * 26 % mod2;
            }
            hash1[i][s[i] - 'a'] = (hash1[i][s[i] - 'a'] + 1) % mod1;
            hash2[i][s[i] - 'a'] = (hash2[i][s[i] - 'a'] + 1) % mod2;
        }

        for(int p = 0; p < m; ++p) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            int len = sc.nextInt();

            int l1 = x;
            int l2 = y;
            int r1 = x + len - 1;
            int r2 = y + len - 1;
            int flag = 0;

            for(int i = 0; i < 26; ++i) {
                int possInd = maxInd[r1][i];
                if(possInd == -1 || possInd < l1)
                    continue;
                int mappingInd = possInd - l1 + l2;
                
                long hash1m1 = getHash(hash1, i, l1, r1, mod1, p26m1);
                long hash2m1 = getHash(hash1, s[mappingInd] - 'a', l2, r2, mod1, p26m1);
                long hash1m2 = getHash(hash2, i, l1, r1, mod2, p26m2);
                long hash2m2 = getHash(hash2, s[mappingInd] - 'a', l2, r2, mod2, p26m2);

                if(!(hash1m1 == hash2m1 && hash1m2 == hash2m2))
                    flag = 1;
            }

            if(flag == 0)
                w.println("YES");
            else
                w.println("NO");
        }
        
        w.close();     
    }
}