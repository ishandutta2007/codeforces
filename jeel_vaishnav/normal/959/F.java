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
    class Query {
        int ind;
        int l, x;
        Query(int a, int b, int c) {
            ind = a;
            l = b;
            x = c;
        } 
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int q = sc.nextInt();        

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        Query query[] = new Query[q];
        for(int i = 0; i < q; ++i)
            query[i] = new Query(i, sc.nextInt() - 1, sc.nextInt());
        Arrays.sort(query, new Comparator<Query>() {
            public int compare(Query q1, Query q2) {
                if(q1.l > q2.l)
                    return 1;
                if(q1.l < q2.l)
                    return -1;
                return 0;
            }
        });

        long mod = (long)1e9 + 7;
        long p2[] = new long[100001];
        p2[0] = 1;
        for(int i = 1; i <= 100000; ++i)
            p2[i] = p2[i - 1] * 2 % mod;

        int basis[] = new int[20];
        int cnt = 0, ptr = 0;
        long ans[] = new long[q];
        for(int i = 0; i < n; ++i) {
            //w.println(i);
            for(int j = 19; j >= 0; --j) {
                if((a[i] >> j & 1) == 1) {
                    if(basis[j] != 0)
                        a[i] ^= basis[j];
                    else {
                        basis[j] = a[i];
                        break;
                    }
                }
                if(j == 0)
                    cnt++;
            }


     main : while(ptr < q && query[ptr].l == i) {
                int x = query[ptr].x;
                //w.println(ptr);
                for(int j = 19; j >= 0; --j) {
                    //w.println(query[ptr].l + " " + j + " " + x);
                    if((x >> j & 1) == 1) {
                        if(basis[j] != 0)
                            x ^= basis[j];
                        else {
                            ptr++;
                            continue main;
                        }
                    }
                }

                ans[query[ptr].ind] = p2[cnt];
                ptr++;
            }
        }

        for(int i = 0; i < q; ++i)
            w.println(ans[i]);

        w.close();      
    }
}