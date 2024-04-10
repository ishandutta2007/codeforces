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
    long querySegTree2(int low, int high, int pos, int l, int r) {
        if(low > r || high < l)
            return Long.MAX_VALUE;

        if(low >= l && high <= r)
            return segTree2[pos];

        int mid = (low + high) >> 1;
        long val1 = querySegTree2(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree2(mid + 1, high, 2 * pos + 2, l, r);
        return min(val1, val2);
    }
    void updateSegTree2(int low, int high, int pos, int ind, long val) {
        if(low > ind || high < ind)
            return;

        if(low == high) {
            segTree2[pos] = val;
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree2(low, mid, 2 * pos + 1, ind, val);
        updateSegTree2(mid + 1, high, 2 * pos + 2, ind, val);

        segTree2[pos] = min(segTree2[2 * pos + 1], segTree2[2 * pos + 2]);
    }
    long querySegTree(int low, int high, int pos, int l, int r) {
        if(low > r || high < l)
            return 0;

        if(low >= l && high <= r)
            return segTree[pos];

        int mid = (low + high) >> 1;
        long val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        long val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return max(val1, val2);
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
    long segTree[], segTree2[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        long t = sc.nextLong();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();

        int rank[] = new int[n];
        for(int i = 0; i < n; ++i)
            rank[i] = sc.nextInt() - 1;

        for(int i = 1; i < n; ++i) {
            if(rank[i] < rank[i - 1]) {
                w.print("No");
                w.close();
                return;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(rank[i] < i) {
                w.print("No");
                w.close();
                return;
            }

            if(i == n - 1 && rank[i] != n - 1) {
                w.print("No");
                w.close();
                return;
            }
            else if(i != n - 1 && rank[i + 1] != rank[i] && rank[i] != i) {
                w.print("No");
                w.close();
                return;
            }
        }

        ArrayList<Long> ans = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            long curVal = a[i] + t;
            if(i != n - 1 && rank[i + 1] == rank[i])
                curVal = a[i + 1] + t;
            if(i != 0 && ans.get(ans.size() - 1) >= curVal)
                curVal = ans.get(ans.size() - 1) + 1L;
            
            long reqVal = Long.MAX_VALUE;
            if(rank[i] != n - 1) {
                reqVal = a[rank[i] + 1] + t;
            }

            if(curVal >= reqVal) {
                w.print("No");
                w.close();
                return;
            }
            ans.add(curVal);
        }

        w.println("Yes");
        for(long i : ans)
            w.print(i + " ");

        w.close();   
    }
}