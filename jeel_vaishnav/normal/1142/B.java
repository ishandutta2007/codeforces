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
    int querySegTree(int low, int high, int pos, int l, int r) {
        if(low > r || high < l)
            return -1;

        if(low >= l && high <= r)
            return segTree[pos];

        int mid = (low + high) >> 1;
        int val1 = querySegTree(low, mid, 2 * pos + 1, l ,r);
        int val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
        return max(val1, val2);
    }
    void updateSegTree(int low, int high, int pos, int ind, int val) {
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
    int segTree[]; 
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
 
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();

        int permute[] = new int[n];
        int needed[] = new int[n + 1];
        for(int i = 0; i < n; ++i) {
            permute[i] = sc.nextInt();
            if(i != 0)
                needed[permute[i]] = permute[i - 1];
        }
        needed[permute[0]] = permute[n - 1];

        int a[] = new int[m];
        int par[][] = new int[m][18];

        segTree = new int[4 * m];
        Arrays.fill(segTree, -1);

        int ind[] = new int[n + 1];
        Arrays.fill(ind, -1);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < 18; ++j)
                par[i][j] = -1;
        }
        for(int i = 0; i < m; ++i) {
            a[i] = sc.nextInt();

            if(ind[needed[a[i]]] != -1) {
                par[i][0] = ind[needed[a[i]]]; 
            }   
            else
                par[i][0] = -1;

            for(int j = 1; j < 18; ++j) {
                if(par[i][j - 1] != -1) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }

            int dist = n - 1;
            int curNode = i;
            for(int j = 17; j >= 0; --j) {
                int curDist = 1 << j;
                if(curDist <= dist) {
                    if(par[curNode][j] == -1)
                        break;
                    dist -= curDist;
                    curNode = par[curNode][j];
                }
            }

            if(dist == 0)
                updateSegTree(0, m - 1, 0, i, curNode);

            ind[a[i]] = i;
        }

        for(int i = 0; i < q; ++i) {
            int l = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;

            int cans = querySegTree(0, m - 1, 0, l, r);
            if(cans >= l)
                w.print("1");
            else
                w.print("0");
        }
 
        w.close();
    }
}