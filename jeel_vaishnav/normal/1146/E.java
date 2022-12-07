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
    void resolve(int low, int high, int pos) {
        handle(low, high, pos);

        if(low == high) {
            int curVal = low - ADD;
            if(overRide[pos] != -1)
                sign[low] = overRide[pos];
            else {
                sign[low] = (low < ADD ? 0 : 1);
                if(swap[pos] == 1)
                    sign[low] ^= 1;
            }
            return;
        }

        int mid = (low + high) >> 1;
        resolve(low, mid, 2 * pos + 1);
        resolve(mid + 1, high, 2 * pos + 2);
    }
    void updateSegTree(int low, int high, int pos, int l, int r, int type, int val) {
        if(l > r)
            return;
        // 1 : overRide, 0 : swap
        // 0 : -ve, 1 : +ve

        handle(low, high, pos);

        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            //System.out.println("Added : " + (low - ADD) + " " + (high - ADD) + " " + type + " " + val + " " + swap[pos] + " " + overRide[pos]);
            if(type == 1) {
                swap[pos] = -1;
                overRide[pos] = val;
            }
            else {
                if(overRide[pos] == -1) {
                    if(swap[pos] == -1)
                        swap[pos] = val;
                    else
                        swap[pos] ^= val;
                }
                else {
                    overRide[pos] ^= val;
                }
            }
            handle(low, high, pos);
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, l, r, type, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r, type, val); 
    }
    void handle(int low, int high, int pos) {
        // int cval = low - ADD;
        // int cval2 = high - ADD;

        // if(cval >= -5 && cval <= 5 && cval2 >= -5 && cval2 <= 5) {
        //     System.out.println(cval + " " + cval2 + " " + swap[pos] + " " + overRide[pos]);
        // }
        if(low != high) {
            if(overRide[pos] != -1) {
                swap[2 * pos + 1] = -1;
                swap[2 * pos + 2] = -1;
                overRide[2 * pos + 1] = overRide[pos];
                overRide[2 * pos + 2] = overRide[pos];
            }
            else {
                if(swap[pos] != -1) {
                    if(overRide[2 * pos + 1] == -1) {
                        if(swap[2 * pos + 1] == -1)
                            swap[2 * pos + 1] = swap[pos];
                        else
                            swap[2 * pos + 1] ^= swap[pos];
                    }
                    else {
                        overRide[2 * pos + 1] ^= swap[pos];
                    }
                    if(overRide[2 * pos + 2] == -1) {
                        if(swap[2 * pos + 2] == -1)
                            swap[2 * pos + 2] = swap[pos];
                        else
                            swap[2 * pos + 2] ^= swap[pos];
                    }
                    else {
                        overRide[2 * pos + 2] ^= swap[pos];
                    }
                }
            }

            overRide[pos] = -1;
            swap[pos] = -1;
        }
    }
    int sign(int val) {
        return (val < 0 ? -1 : 1);
    }
    int overRide[], swap[];
    int sign[];
    final int ADD = 100010;
    final int N = 2 * ADD + 1;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int q = sc.nextInt();

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        overRide = new int[4 * N];
        swap = new int[4 * N];
        Arrays.fill(overRide, -1);
        Arrays.fill(swap, -1);

        for(int x = 0; x < q; ++x) {
            char type = sc.next().charAt(0);
            int val = sc.nextInt();

            if(type == '>')
                val = val + 1;
            else
                val = val - 1;

            if(val == 0) {
                if(type == '>') {
                    updateSegTree(0, N - 1, 0, 0, ADD - 1, 1, 0);
                    updateSegTree(0, N - 1, 0, ADD + 1, N - 1, 1, 0);
                }
                else {
                    updateSegTree(0, N - 1, 0, 0, ADD - 1, 1, 1);
                    updateSegTree(0, N - 1, 0, ADD + 1, N - 1, 1, 1);
                }
            }
            else {
                if(type == '>') {
                    if(val > 0) {
                        val = abs(val);
                        updateSegTree(0, N - 1, 0, 0, ADD - val, 1, 0);
                        updateSegTree(0, N - 1, 0, ADD + val, N - 1, 1, 0);
                    }
                    else {
                        val = abs(val);
                        updateSegTree(0, N - 1, 0, ADD + val + 1, N - 1, 1, 0);
                        updateSegTree(0, N - 1, 0, 0, ADD - val - 1, 1, 0);
                        updateSegTree(0, N - 1, 0, ADD - val, ADD + val, 0, 1);
                    }
                }
                else {
                    if(val < 0) {
                        val = abs(val);
                        updateSegTree(0, N - 1, 0, 0, ADD - val, 1, 1);
                        updateSegTree(0, N - 1, 0, ADD + val, N - 1, 1, 1);
                    }
                    else {
                        val = abs(val);
                        updateSegTree(0, N - 1, 0, 0, ADD - val - 1, 1, 1);
                        updateSegTree(0, N - 1, 0, ADD + val + 1, N - 1, 1, 1);
                        updateSegTree(0, N - 1, 0, ADD - val, ADD + val, 0, 1);
                    }
                }
            }
        }


        sign = new int[N];
        resolve(0, N - 1, 0);  

        for(int i = 0; i < n; ++i) {
            int val = abs(a[i]) * (sign[a[i] + ADD] == 0 ? -1 : 1);
            w.print(val + " ");
        }

        w.close();
    }
}