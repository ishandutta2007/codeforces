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
    long queryBit(long bit[], int ind) {
        if(ind == 0)
            return 0;

        long ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return ans;
    }
    void updateBit(long bit[], int ind, long val) {
        while(ind < bit.length) {
            bit[ind] += val;
            ind += Integer.lowestOneBit(ind);
        }
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        long t = sc.nextLong();

        Pair p[] = new Pair[n];

        long a[] = new long[2 * n + 1];
        for(int i = 1; i <= n; ++i) {
            a[i] = sc.nextLong();
            a[n + i] = a[i];
            p[i - 1] = new Pair(i, a[i]);
        }

        Arrays.sort(p, new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.val > p2.val)
                    return -1;
                if(p1.val < p2.val)
                    return 1;
                if(p1.ind < p2.ind)
                    return 1;
                if(p1.ind > p2.ind)
                    return -1;
                return 0;
            }
        });

        long[] bit = new long[2 * n + 1];
        long[] bit2 = new long[2 * n + 1];
 
        for(int i = 1; i <= 2 * n; ++i) {
            updateBit(bit, i, a[i]);
            updateBit(bit2, i, 1);
        }

        long ans = 0;
        int curInd = 0;
        long totalCost = queryBit(bit, n);
        for(int i = 0; i < n; ++i) {
            int ind = p[i].ind;
            long val = p[i].val;

            long start = 0, end = t / totalCost, cans = -1;
            long extMoves = 0;
            if(p[i].ind < curInd) {
                extMoves = queryBit(bit, n + p[i].ind) - queryBit(bit, curInd);
            }
            else {
                extMoves = queryBit(bit, p[i].ind) - queryBit(bit, curInd);
            }

            while(start <= end) {
                long mid = (start + end) >> 1;

                if(totalCost * mid + extMoves <= t) {
                    cans = mid;
                    start = mid + 1L;
                }
                else
                    end = mid - 1L;
            }

            if(cans != -1) {

                t -= cans * totalCost + extMoves;

                if(p[i].ind < curInd)
                    ans += queryBit(bit2, n + p[i].ind) - queryBit(bit2, curInd);
                else
                    ans += queryBit(bit2, p[i].ind) - queryBit(bit2, curInd);
                ans += cans * queryBit(bit2, n);
                curInd = p[i].ind;

            }

            totalCost -= p[i].val;
            updateBit(bit, p[i].ind, -p[i].val);
            updateBit(bit, p[i].ind + n, -p[i].val);
            updateBit(bit2, p[i].ind, -1);
            updateBit(bit2, p[i].ind + n, -1);
        }

        w.print(ans);

        w.close();    
    }
}
class Pair {
    int ind;
    long val;
    Pair(int a, long b) {
        ind = a;
        val = b;
    }
}