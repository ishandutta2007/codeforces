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
    Pair dfs(int i, int level, long csum) {
        psum[level] = csum + w[i];

        Pair ansP = null;
        int curDepth = 0;

        for(int j : adj[i]) {
            Pair curP = dfs(j, level + 1, psum[level]);

            int start = 0, end = level, ans = level;
            while(start <= end) {
                int mid = (start + end) >> 1;

                if(level - mid > curP.remLength) {
                    start = mid + 1;
                    continue;
                }

                if(psum[level] - psum[mid] > curP.remDist) {
                    start = mid + 1;
                }
                else {
                    ans = mid;
                    end = mid - 1;
                }
            }

            if(level - ans > curDepth) {
                ansP = curP;
                curDepth = level - ans;
            }
        }

        if(ansP == null) {
            cnt++;
            return new Pair(l - 1, s - w[i]);
        }
        else {
            ansP.remLength--;
            ansP.remDist -= w[i];
            return ansP;
        }
    }
    long psum[];
    int adj[][];
    long l;
    long s;
    long w[];
    int cnt = 0;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        
        l = sc.nextLong();
        s = sc.nextLong();

        w = new long[n];
        int flag = 0;
        for(int i = 0; i < n; ++i) {
            w[i] = sc.nextLong();
            if(w[i] > s)
                flag = 1;
        }

        if(flag == 1) {
            pw.print("-1");
            pw.close();
            return;
        }

        int p[] = new int[n];
        int deg[] = new int[n];
        for(int i = 1; i < n; ++i) {
            p[i] = sc.nextInt() - 1;
            deg[p[i]]++;
        }

        adj = new int[n][];
        for(int i = 0; i < n; ++i)
            adj[i] = new int[deg[i]];

        int ptr[] = new int[n];
        for(int i = 1; i < n; ++i)
            adj[p[i]][ptr[p[i]]++] = i;

        psum = new long[n + 1];

        dfs(0, 1, 0);

        pw.print(cnt);

        pw.close();
    }
}
class Pair {
    long remLength, remDist;
    Pair(long a, long b) {
        remLength = a;
        remDist = b;
    }
}