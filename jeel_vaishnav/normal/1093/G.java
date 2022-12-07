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
        
        public int nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            
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
    void querySegTree(int low, int high, int pos, int l, int r) {
        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            for(int mask = 0; mask < maxMask; ++mask) {
                val[mask][0] = min(val[mask][0], segTree[mask][pos][0]);
                val[mask][1] = max(val[mask][1], segTree[mask][pos][1]);
            }
            return;
        }

        int mid = (low + high) >> 1;
        querySegTree(low, mid, 2 * pos + 1, l, r);
        querySegTree(mid + 1, high, 2 * pos + 2, l, r);
    }
    void updateSegTree(int low, int high, int pos, int ind) {
        if(low > ind || high < ind)
            return;

        if(low == high) {
            for(int mask = 0; mask < maxMask; ++mask) {
                segTree[mask][pos][0] = indVal[mask];
                segTree[mask][pos][1] = indVal[mask];
            }
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind);

        for(int mask = 0; mask < maxMask; ++mask) {
            segTree[mask][pos][0] = min(segTree[mask][2 * pos + 1][0], segTree[mask][2 * pos + 2][0]);
            segTree[mask][pos][1] = max(segTree[mask][2 * pos + 1][1], segTree[mask][2 * pos + 2][1]);
        }
    }
    int maxMask;
    int val[][];
    int indVal[];
    int segTree[][][];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int k = sc.nextInt();
        maxMask = (1 << (k - 1));

        int set[][] = new int[maxMask][k];

        for(int i = 0; i < maxMask; ++i) {
            for(int j = 0; j < k; ++j) {
                if((i >> j & 1) == 1)
                    set[i][j] = 1;
                else
                    set[i][j] = -1;
            }
        }

        val = new int[maxMask][2];
        indVal = new int[maxMask];
        segTree = new int[maxMask][4 * n][2];

        for(int x = 0; x < n; ++x) {
            int a[] = new int[k];
            for(int i = 0; i < k; ++i)
                a[i] = sc.nextInt();

            for(int i = 0; i < maxMask; ++i) {
                indVal[i] = 0;
                for(int j = 0; j < k; ++j) {
                    indVal[i] += set[i][j] * a[j];
                }
            }
            updateSegTree(0, n - 1, 0, x);
        }

        int q = sc.nextInt();

        for(int x = 0; x < q; ++x) {
            int type = sc.nextInt();

            if(type == 1) {
                int ind = sc.nextInt() - 1;
                int a[] = new int[k];
                for(int i = 0; i < k; ++i)
                    a[i] = sc.nextInt();

                for(int i = 0; i < maxMask; ++i) {
                    indVal[i] = 0;
                    for(int j = 0; j < k; ++j) {
                        indVal[i] += set[i][j] * a[j];
                    }
                }
                updateSegTree(0, n - 1, 0, ind);
            }
            else {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;

                int ans = 0;

                for(int i = 0; i < maxMask; ++i) {
                    val[i][0] = Integer.MAX_VALUE;
                    val[i][1] = Integer.MIN_VALUE;
                }

                querySegTree(0, n - 1, 0, l, r);

                for(int i = 0; i < maxMask; ++i) {
                    ans = max(ans, val[i][1] - val[i][0]);
                }

                w.println(ans);
            }
        }

        w.close();
    }
}