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
    int[] findZValue(char[] s) {
        int[] z = new int[s.length];

        int l = 0, r = 0;
        for(int i = 1; i < s.length; ++i) {
            if(i > r) {
                l = i;
                r = i - 1;

                while(r + 1 < s.length && s[r + 1] == s[r + 1 - l])
                    r++;
                
                z[i] = r - l + 1;
            } 
            else {
                if(r - i + 1 <= z[i - l]) {
                    l = i;
                    
                    while(r + 1 < s.length && s[r + 1] == s[r + 1 - l])
                        r++;

                    z[i] = r - l + 1;
                }   
                else
                    z[i] = z[i - l];
            }
        } 

        return z;
    }
    int[] solve(char[] l, char[] a) {
        char[] s = new char[a.length + l.length + 1];
        for(int i = 0; i < l.length; ++i)
            s[i] = l[i];
        s[l.length] = '$';
        for(int i = 0; i < a.length; ++i)
            s[l.length + 1 + i] = a[i];

        int[] z = findZValue(s);

        int[] ans = new int[a.length];
        for(int i = 0; i < a.length; ++i)
            ans[i] = z[l.length + 1 + i];

        return ans;
    }
    int compare(char[] l, char[] a, int[] z, int ind) {
        if(z[ind] == l.length)
            return 0;

        if(l[z[ind]] > a[ind + z[ind]])
            return 1;

        return -1;
    }
    long mod = (long)998244353;
    long dp[], sum[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        char[] a = sc.next().toCharArray();
        char[] l = sc.next().toCharArray();
        char[] r = sc.next().toCharArray();

        int[] zla = solve(l, a);
        int[] zra = solve(r, a);

        boolean canBeZero = (l.length == 1 && l[0] == '0');

        int n = a.length;
        dp = new long[n + 1];
        sum = new long[n + 1];
        long[] actdp = new long[n + 1];

        dp[0] = 1L;
        sum[0] = 1L;
        actdp[0] = 1L;

        for(int i = 0; i < n; ++i) {
            if(canBeZero && a[i] == '0')
                dp[i + 1] = dp[i];

            if(l.length == r.length && i - l.length + 1 >= 0) {
                if(compare(l, a, zla, i - l.length + 1) <= 0 && compare(r, a, zra, i - l.length + 1) >= 0)
                    dp[i + 1] = (dp[i + 1] + actdp[i - l.length + 1]) % mod;
            }
            else {
                if(i - l.length + 1 >= 0 && compare(l, a, zla, i - l.length + 1) <= 0)
                    dp[i + 1] = (dp[i + 1] + actdp[i - l.length + 1]) % mod;

                if(i - l.length >= 0)
                    dp[i + 1] = (dp[i + 1] + sum[i - l.length]) % mod;

                if(i - r.length + 1 >= 0)
                    dp[i + 1] = (dp[i + 1] - sum[i - r.length + 1] + mod) % mod;

                if(i - r.length + 1 >= 0 && compare(r, a, zra, i - r.length + 1) >= 0)
                    dp[i + 1] = (dp[i + 1] + actdp[i - r.length + 1]) % mod;
            }

            if(i + 1 < n && a[i + 1] != '0') {
                sum[i + 1] = (sum[i] + dp[i + 1]) % mod;
                actdp[i + 1] = dp[i + 1];
            }
            else if(i + 1 < n)
                sum[i + 1] = sum[i];
        }

        w.print(dp[n]);
                
        w.close();
    }
}