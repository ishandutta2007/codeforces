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
    void buildSegTree(int low, int high, int pos) {
        if(low == high) {
            wasteTime[pos] = 1;
            return;
        }

        int mid = (low + high) >> 1;
        buildSegTree(low, mid, 2 * pos + 1);
        buildSegTree(mid + 1, high, 2 * pos + 2);

        wasteTime[pos] = wasteTime[2 * pos + 1] + wasteTime[2 * pos + 2];
    }
    Pair querySegTree(int low, int high, int pos, int l, int r) {
        if(low > r || high < l)
            return null;

        if(low >= l && high <= r)
            return new Pair(extTime[pos], wasteTime[pos]);

        int mid = (low + high) >> 1;
        Pair p1 = querySegTree(low, mid, 2 * pos + 1, l, r);
        Pair p2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);

        if(p1 == null)
            return p2;
        if(p2 == null)
            return p1;

        Pair p = new Pair(0, 0);
        if(p2.wasteTime >= p1.extTime) {
            p.wasteTime = p1.wasteTime + p2.wasteTime - p1.extTime;
            p.extTime = p2.extTime;
        }
        else {
            p.extTime = p2.extTime + p1.extTime - p2.wasteTime;
            p.wasteTime = p1.wasteTime;
        }

        return p;
    }
    void updateSegTree(int low, int high, int pos, int ind, long duration) {
        if(low > ind || high < ind)
            return;

        if(low == high) {
            if(duration == 0) {
                extTime[pos] = 0;
                wasteTime[pos] = 1;
            }
            else {
                extTime[pos] = duration - 1L;
                wasteTime[pos] = 0;
            }
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind, duration);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind, duration);

        if(wasteTime[2 * pos + 2] >= extTime[2 * pos + 1]) {
            wasteTime[pos] = wasteTime[2 * pos + 1] + wasteTime[2 * pos + 2] - extTime[2 * pos + 1];
            extTime[pos] = extTime[2 * pos + 2];
        }
        else {
            extTime[pos] = extTime[2 * pos + 2] + extTime[2 * pos + 1] - wasteTime[2 * pos + 2];
            wasteTime[pos] = wasteTime[2 * pos + 1];
        }
    }
    class Pair {
        long extTime;
        long wasteTime;

        Pair(long a, long b) {
            extTime = a;
            wasteTime = b;
        }
    }
    long extTime[], wasteTime[];
    int n = 1000001;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int q = sc.nextInt();

        extTime = new long[4 * n];
        wasteTime = new long[4 * n];
        long duration[] = new long[1000001];

        buildSegTree(0, n - 1, 0);

        int time[] = new int[q];

        for(int x = 0; x < q; ++x) {
            char type = sc.next().charAt(0);

            if(type == '+') {
                time[x] = sc.nextInt();
                duration[time[x]] = sc.nextLong();

                updateSegTree(0, n - 1, 0, time[x], duration[time[x]]);
            }
            else if(type == '-') {
                int ind = sc.nextInt() - 1;
                duration[time[ind]] = 0;

                updateSegTree(0, n - 1, 0, time[ind], 0);
            }
            else {
                int ctime = sc.nextInt();

                Pair p = querySegTree(0, n - 1, 0, 0, ctime - 1);

                long ans = p.extTime + duration[ctime];
                w.println(ans);
            }
        }

        w.close();
    }
}