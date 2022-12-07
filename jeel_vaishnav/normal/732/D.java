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
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int b[] = new int[n];
        for(int i = 0; i < n; ++i)
            b[i] = sc.nextInt() - 1;

        int a[] = new int[m];
        for(int i = 0; i < m; ++i)
            a[i] = sc.nextInt();

        int start = 0, end = n - 1, ans = -1;

        while(start <= end) {
            int mid = (start + end) >> 1;

            int day[] = new int[m];
            Arrays.fill(day, Integer.MAX_VALUE);

            int vis[] = new int[m];
            int visd[] = new int[mid + 1];

            Pair p[] = new Pair[m];
            int ptr = m - 1;

            for(int i = mid; i >= 0; --i) {
                if(b[i] != -1 && day[b[i]] == Integer.MAX_VALUE) {
                    day[b[i]] = i;
                    p[ptr--] = new Pair(a[b[i]], i);
                }
            }

            if(ptr != -1) {
                start = mid + 1;
                continue;
            }

            ptr = 0;
            for(int i = 0; i <= mid && ptr < m; ++i) {
                if(visd[i] == 1)
                    continue;

                visd[i] = 1;
                p[ptr].left--;

                if(p[ptr].left == 0) {
                    if(visd[p[ptr].day] == 0) {
                        visd[p[ptr].day] = 1;
                        vis[ptr] = 1;
                    }
                    ptr++;
                }       
            }

            int flag = 0;
            for(int i = 0; i < m; ++i) {
                if(vis[i] == 0)
                    flag = 1;
            }

            if(flag == 0) {
                ans = mid + 1;
                end = mid - 1;
            }
            else 
                start = mid + 1;
        }
        
        w.print(ans);

        w.close();      
    }
}
class Pair {
    int left;
    int day;
    Pair(int a, int b) {
        left = a;
        day = b;
    }
}