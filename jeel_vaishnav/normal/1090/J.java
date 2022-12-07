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

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        int[] lcp = new int[t.length];
        KMP.createLCP(t, lcp);
        
        int[] z = ZAlgorithm.findZValue(t);

        long dp[] = new long[t.length];
        for(int i = 0; i < t.length; ++i) {
            if(i + 1 < t.length)
                dp[i] = z[i + 1];

            if(lcp[i] != -1)
                dp[i] = max(dp[i], dp[lcp[i]]);
        }

        long ans = (long)s.length * (long)t.length;
        int ptr = -1;
        for(int i = 0; i < s.length; ++i) {
            while(ptr != -1 && t[ptr + 1] != s[i])
                ptr = lcp[ptr];

            if(t[ptr + 1] == s[i]) {
                if(ptr + 1 == i) {
                    if(lcp[ptr + 1] != -1)
                        ans -= dp[lcp[ptr + 1]];
                }
                else
                    ans -= dp[ptr + 1];

                if(ptr + 1 == t.length - 1) {
                    ptr = lcp[ptr + 1];
                }
                else {
                    ptr++;
                }
            }
        }

        w.print(ans);

        w.close();
    }
}
class KMP {
    static int findMinInd(char[] s, char[] t) {
        int[] lcp = new int[t.length];

        createLCP(t, lcp);

        int j = 0, ans = 0;
        for(int i = 0; i < s.length; ++i) {
            while(j != 0 && s[i] != t[j])
                j = lcp[j - 1] + 1;

            if(s[i] == t[j]) {
                j++;
                
                if(j == t.length) {
                    return i;
                }
            }
        }

        return -1;
    }
    
    static int findSubstrings(char[] s, char[] t) {
        int[] lcp = new int[t.length];

        createLCP(t, lcp);

        int j = 0, ans = 0;
        for(int i = 0; i < s.length; ++i) {
            while(j != 0 && s[i] != t[j])
                j = lcp[j - 1] + 1;

            if(s[i] == t[j]) {
                j++;
                
                if(j == t.length) {
                    j = lcp[j - 1] + 1;
                    ans++;
                }
            }
        }

        return ans;
    }

    static void createLCP(char[] t, int[] lcp) {
        lcp[0] = -1;
        
        int j = 0;
        for(int i = 1; i < t.length; ++i) {
            while(j != 0 && t[i] != t[j]) 
                j = lcp[j - 1] + 1;

            if(t[i] == t[j]) {
                lcp[i] = j;
                j++;
            }
            else
                lcp[i] = -1;
        }
    }
}
class ZAlgorithm {
    // Z value (Z[i]) - length of longest common prefix of original string and suffix starting at ith index
    
    // Z value is obtained in O(n) using  box where we maintain l and r 

    // For string matching use P + $ + S and find all indices having value = length of P 
    // Here, P is pattern and S is string where pattern is to be found

    static boolean contains(char[] string, char[] pattern) {
        return (findSubstrings(string, pattern) > 0);
    }

    static int findSubstrings(char[] string, char[] pattern) {
        char[] s = new char[string.length + pattern.length + 1];

        // P + '$' + S
        for(int i = 0; i < pattern.length; ++i)
            s[i] = pattern[i];
        s[pattern.length] = '$';
        for(int i = 0; i < string.length; ++i)
            s[pattern.length + 1 + i] = string[i];

        int[] z = findZValue(s);

        int ans = 0;

        for(int i = pattern.length + 1; i < s.length; ++i) {
            // having longest common prefix equal to length of pattern
            if(z[i] == pattern.length)
                ans++;
        }

        return ans;
    }

    static int[] findZValue(char[] s) {
        int n = s.length;

        int[] z = new int[n];

        int l = 0, r = 0;

        // will be neglecting first
        for(int i = 1; i < n; ++i) {
            if(r < i) {
                // new range
                l = i;
                r = i - 1;

                while(r + 1 < n && s[r + 1] == s[r + 1 - l])
                    r++;

                z[i] = r - l + 1;
            }
            else if(r >= i) {
                //old range
                if(r - i + 1 <= z[i - l]) {
                    // can extend
                    l = i;

                    while(r + 1 < n && s[r + 1] == s[r + 1 - l])
                        r++;

                    z[i] = r - l + 1;
                }
                else {
                    // can't extend
                    z[i] = z[i - l];
                }
            }
        }

        return z;
    }    
}