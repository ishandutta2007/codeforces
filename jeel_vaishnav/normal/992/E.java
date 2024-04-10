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
    int querySegTree(int low, int high, int pos, int l, long val) {
        if(segTree[pos] < val)
            return -1;
        if(low == high) 
            return low;
        int mid = (low + high) >> 1;
        int ind = -1;        
        if(l <= mid && segTree[2 * pos + 1] >= val)
            ind = querySegTree(low, mid, 2 * pos + 1, l, val);
        if(ind == -1)
            return querySegTree(mid + 1, high, 2 * pos + 2, l, val);
        return ind;
    }
    void updateSegTree(int low, int high, int pos, int ind, long val) {
        if(low > ind || high < ind)
            return;
        if(low == high) {
            segTree[pos] = val;
            return;
        }
        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
        segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    long queryBit(int ind) {
        long ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return ans;
    }
    void updateBit(int ind, long val) {
        while(ind < bit.length) {
            bit[ind] += val;
            ind += Integer.lowestOneBit(ind);
        }
    }
    long bit[];
    long segTree[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int q = sc.nextInt();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();       

        bit = new long[n + 1];
        segTree = new long[4 * n];

        for(int i = 0; i < n; ++i) {
            updateBit(i + 1, a[i]);
            updateSegTree(0, n - 1, 0, i, a[i]);
        }

        for(int i = 0; i < q; ++i) {
            int qind = sc.nextInt() - 1;
            long val = sc.nextLong();
            updateBit(qind + 1, -a[qind]);
            a[qind] = val; 
            updateBit(qind + 1, a[qind]);
            updateSegTree(0, n - 1, 0, qind, val);
            long prefixsum = 0;
            int ans = -1, l = 0;
            while(prefixsum <= (long)1e9 && l <= n - 1) {
                int ind = querySegTree(0, n - 1, 0, l, prefixsum);
                if(ind == -1)
                    break;
                long pfsum = queryBit(ind);
                if(a[ind] == pfsum) {
                    ans = ind + 1;
                    break;
                }
                prefixsum = queryBit(ind + 1);
                l = ind + 1;
            }
            w.println(ans);
        }

        w.close();      
    }
}