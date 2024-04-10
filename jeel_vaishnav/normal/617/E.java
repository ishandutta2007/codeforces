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
    void upd(int ind, int type) {
        if(type == 1) {
            ans += freq[pref[ind] ^ k];
            freq[pref[ind]]++;
        }
        else {
            freq[pref[ind]]--;
            ans -= freq[pref[ind] ^ k];
        }
    }
    int pref[];
    long freq[] = new long[1 << 20];
    int blockSize = 300;
    long ans = 0;
    int k;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        k = sc.nextInt();

        int a[] = new int[n + 1];
        for(int i = 1; i <= n; ++i)
            a[i] = sc.nextInt();

        pref = new int[n + 1];
        for(int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] ^ a[i];

        Query q[] = new Query[m];
        for(int i = 0; i < m; ++i)
            q[i] = new Query(i, sc.nextInt() - 1, sc.nextInt(), blockSize);

        Arrays.sort(q, new Comparator<Query>() {
            public int compare(Query q1, Query q2) {
                if(q1.blockNo < q2.blockNo)
                    return -1;
                if(q1.blockNo > q2.blockNo)
                    return 1;
                if(q1.r < q2.r)
                    return -1;
                if(q1.r > q2.r)
                    return 1;
                return 0;
            }
        });

        long fans[] = new long[m];
        int l = 0, r = -1;
        for(int i = 0; i < m; ++i) {
            while(q[i].l > l) {
                upd(l, -1);
                l++;
            }

            while(q[i].l < l) {
                l--;
                upd(l, 1);
            }
            
            while(q[i].r > r) {
                r++;
                upd(r, 1);
            }

            while(q[i].r < r) {
                upd(r, -1);
                r--;
            }


            fans[q[i].ind] = ans;
        }
        
        for(long i : fans)
            w.println(i);

        w.close();
    }
}
class Query {
    int ind, l, r, blockNo;
    Query(int a, int b, int c, int blockSize) {
        ind = a;
        l = b;
        r = c;
        blockNo = b / blockSize;
    }
}