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
    void solve2(int level, int val, int termParity, int ind) {
        if(level == pList.size()) {
            if(val == 1)
                return;
            if(termParity == 1)
                dp[ind] += cnt[val];
            else
                dp[ind] -= cnt[val];
            return;
        }

        solve2(level + 1, val, termParity, ind);
        solve2(level + 1, val * pList.get(level), termParity ^ 1, ind);
    }
    void solve3(int level, int val1, int val2, int ind) {
        if(level == pList.size()) {
            if(val2 == 1)
                return;
            if(dp2[val1] != -1 && dp[val2] != n) {
                if(dp2[ind] == -1)
                    dp2[ind] = dp2[val1] + 1;
                else
                    dp2[ind] = min(dp2[ind], dp2[val1] + 1);
            }
            return;
        }

        solve3(level + 1, val1, val2, ind);
        solve3(level + 1, val1 * pList.get(level), val2 / pList.get(level), ind);
    }
    void solve(int level, int val) {
        if(level == pList.size()) {
            cnt[val]++;
            return;
        }

        solve(level + 1, val);
        solve(level + 1, val * pList.get(level));
    }
    ArrayList<Integer> pList = new ArrayList<>();
    int cnt[] = new int[300001];
    int sieve[] = new int[300001];
    int dp[] = new int[300001];
    int dp2[] = new int[300001];
    int n;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();
        
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        for(int i = 2; i <= 300000; ++i) {
            if(sieve[i] == 0) {
                for(int j = i; j <= 300000; j += i)
                    sieve[j] = i;
            }
        }

        for(int i = 0; i < n; ++i) {
            pList.clear();

            int temp = a[i];
            while(temp != 1) {
                int curP = sieve[temp];
                pList.add(curP);

                while(temp % curP == 0)
                    temp /= curP;
            }

            solve(0, 1);
        }

        for(int i = 1; i <= 300000; ++i) {
            pList.clear();

            int temp = i;
            while(temp != 1) {
                int curP = sieve[temp];
                pList.add(curP);

                while(temp % curP == 0)
                    temp /= curP;
            }

            solve2(0, 1, 0, i);

            //if(i <= 10)
                //System.out.println(i + " " + dp[i] + " " + cnt[i]);
        }

        dp2 = new int[300001];
        Arrays.fill(dp2, -1);

        dp2[1] = 0;
        for(int i = 2; i <= 300000; ++i) {
            pList.clear();

            int temp = i;
            while(temp != 1) {
                int curP = sieve[temp];
                pList.add(curP);

                while(temp % curP == 0)
                    temp /= curP;
            }

            int fullVal = 1;
            for(int j : pList)
                fullVal *= j;

            solve3(0, 1, fullVal, i);
        }

        int ans = -1;

        for(int i = 0; i < n; ++i) {
            if(dp2[a[i]] != -1) {
                if(ans == -1)
                    ans = dp2[a[i]] + 1;
                else
                    ans = min(ans, dp2[a[i]] + 1);
            }
        }

        w.print(ans);

        w.close();
    } 
}