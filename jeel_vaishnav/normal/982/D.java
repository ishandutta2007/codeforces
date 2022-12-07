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
    void updateSegTree(int low, int high, int pos, int ind) {
        if(low > ind || high < ind)
            return;
        if(low == high) {
            l[pos] = 1;
            r[pos] = 1;
            segTree[pos] = 0; 
            cnt[pos] = 0;
            return;
        }
        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, ind);
        updateSegTree(mid + 1, high, 2 * pos + 2, ind);
        if(l[2 * pos + 1] == mid - low + 1 && r[2 * pos + 2] == high - mid) {
            segTree[pos] = 0;
            l[pos] = high - low + 1;
            r[pos] = high - low + 1;
            cnt[pos] = 0;
        }
        else if(l[2 * pos + 1] == mid - low + 1) {
            if(l[2 * pos + 2] > 0) {
                l[pos] = l[2 * pos + 1] + l[2 * pos + 2];
            }
            else {
                l[pos] = l[2 * pos + 1];
            }
            segTree[pos] = segTree[2 * pos + 2];
            r[pos] = r[2 * pos + 2];
            cnt[pos] = cnt[2 * pos + 2];
        }
        else if(l[2 * pos + 2] == high - mid) {
            if(r[2 * pos + 1] > 0)
                r[pos] = l[2 * pos + 2] + r[2 * pos + 1];
            else
                r[pos] = l[2 * pos + 2];
            segTree[pos] = segTree[2 * pos + 1];
            l[pos] = l[2 * pos + 1];
            cnt[pos] = cnt[2 * pos + 1];
        }
        else {
            l[pos] = l[2 * pos + 1];
            r[pos] = r[2 * pos + 2];

            if(segTree[2 * pos + 1] == -1 || segTree[2 * pos + 2] == -1) {
                segTree[pos] = -1;
                cnt[pos] = 0;
                return;
            }

            int newSize = r[2 * pos + 1] + l[2 * pos + 2];

            segTree[pos] = segTree[2 * pos + 1];
            cnt[pos] = cnt[2 * pos + 1];

            if(segTree[2 * pos + 2] != 0) {
                cnt[pos] += cnt[2 * pos + 2];
                if(segTree[pos] != 0) {
                    if(segTree[pos] != segTree[2 * pos + 2]) {
                        segTree[pos] = -1;
                        cnt[pos] = 0;
                    }
                }
                else 
                    segTree[pos] = segTree[2 * pos + 2];
            }

            if(segTree[pos] == -1)
                return;

            if(newSize != 0) {
                cnt[pos]++;
                if(segTree[pos] != 0) {
                    if(segTree[pos] != newSize) {
                        segTree[pos] = -1;
                        cnt[pos] = 0;
                    }
                }
                else
                    segTree[pos] = newSize;
            }
        }
    }
    int segTree[], l[], r[], cnt[];
    class Pair {
        int ind;
        int val;
        Pair(int a, int b) {
            ind = a;
            val = b;
        }
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        Pair p[] = new Pair[n];

        for(int i = 0; i < n; ++i)
            p[i] = new Pair(i, sc.nextInt());

        PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {
            public int compare(Pair p1, Pair p2) {
                if(p1.val < p2.val)
                    return -1;
                if(p1.val > p2.val)
                    return 1;
                return 0;
            }
        });

        for(int i = 0; i < n; ++i)
            queue.add(p[i]);

        segTree = new int[4 * n];
        l = new int[4 * n];
        r = new int[4 * n];
        cnt = new int[4 * n];

        int k = 0, maxSegments = 0;
        while(!queue.isEmpty()) {
            Pair cur = queue.poll();
            updateSegTree(0, n - 1, 0, cur.ind);
            while(!queue.isEmpty() && queue.peek().val == cur.val) {
                cur = queue.poll();
                updateSegTree(0, n - 1, 0, cur.ind);
            }
            if(segTree[0] != -1) {
                int curSegments = cnt[0];
                if(cnt[0] == 0) {
                    if(l[0] == n)
                        curSegments = 1;
                    else if(l[0] > 0 && r[0] > 0) {
                        if(l[0] != r[0])
                            curSegments = 0;
                        else
                            curSegments = 2;
                    }
                    else {
                        curSegments = 1;
                    }
                }
                else {
                    if(l[0] > 0 && r[0] > 0) {
                        if(l[0] != segTree[0] || r[0] != segTree[0])
                            curSegments = 0;
                        else
                            curSegments = cnt[0] + 2;
                    }
                    else if(l[0] > 0) {
                        if(l[0] != segTree[0])
                            curSegments = 0;
                        else
                            curSegments = cnt[0] + 1;
                    }
                    else if(r[0] > 0) {
                        if(r[0] != segTree[0])
                            curSegments = 0;
                        else
                            curSegments = cnt[0] + 1;
                    }
                }
                if(curSegments > maxSegments) {
                    maxSegments = curSegments;
                    k = cur.val;
                }
            }
        }

        w.print((k + 1));

        w.close();      
    }
}