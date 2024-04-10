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
    void merge(int[] lseg, int[] rseg, int[] ans) {
        ans[0] = max(lseg[0], rseg[0]);
        ans[0] = max(ans[0], lseg[1] + rseg[2]);
        ans[0] = max(ans[0], lseg[2] + rseg[3]);

        ans[1] = max(lseg[1], rseg[1]);
        ans[1] = max(ans[1], lseg[2] + rseg[4]);

        ans[2] = max(lseg[2], rseg[2]);

        ans[3] = max(lseg[3], rseg[3]);
        ans[3] = max(ans[3], lseg[4] + rseg[2]);

        ans[4] = max(lseg[4], rseg[4]);
    }
    void updateSegTree(int low, int high, int pos, int l, int r, int val) {
        handleLazy(low, high, pos);

        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            lazy[pos] += val;
            handleLazy(low, high, pos);
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, l, r, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r, val);
        merge(segTree[2 * pos + 1], segTree[2 * pos + 2], segTree[pos]);
    }
    void handleLazy(int low, int high, int pos) {
        segTree[pos][1] -= lazy[pos];
        segTree[pos][2] += lazy[pos];
        segTree[pos][3] -= lazy[pos];
        segTree[pos][4] -= 2 * lazy[pos];

        if(low != high) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }

        lazy[pos] = 0;
    }
    int segTree[][];
    int lazy[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int q = sc.nextInt();

        char[] s = sc.next().toCharArray();
        n = s.length;

        segTree = new int[4 * n][5];
        lazy = new int[4 * n];
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(')
                updateSegTree(0, n - 1, 0, i, n - 1, 1);
            else
                updateSegTree(0, n - 1, 0, i, n - 1, -1);
        }

        w.println(segTree[0][0]);
        for(int x = 0; x < q; ++x) {
            int ind1 = sc.nextInt() - 1;
            int ind2 = sc.nextInt() - 1;


            char temp = s[ind2];
            s[ind2] = s[ind1];
            s[ind1] = temp;

            if(s[ind1] == '(')
                updateSegTree(0, n - 1, 0, ind1, n - 1, 2);
            else
                updateSegTree(0, n - 1, 0, ind1, n - 1, -2);

            if(s[ind2] == '(')
                updateSegTree(0, n - 1, 0, ind2, n - 1, 2);
            else
                updateSegTree(0, n - 1, 0, ind2, n - 1, -2);

            w.println(segTree[0][0]);
        }

        w.close();
    }
}