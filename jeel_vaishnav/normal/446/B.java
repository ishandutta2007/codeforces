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
        int k = sc.nextInt();

        long p = sc.nextLong();

        long mat[][] = new long[n][m];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                mat[i][j] = sc.nextLong();
        }

        // find k best columns and add it to an array and find prefic sum for further use
        PriorityQueue<Long> queue = new PriorityQueue<>(new Comparator<Long>() {

            public int compare(Long l1, Long l2) {

                if(l1 > l2)
                    return -1;

                if(l1 < l2)
                    return 1;

                return 0;
            }
        });

        for(int j = 0; j < m; ++j) {

            long sum = 0;

            for(int i = 0; i < n; ++i) 
                sum += mat[i][j];

            queue.add(sum);
        }

        long col[] = new long[k + 1];
        col[0] = 0;

        for(int i = 1; i <= k; ++i) {

            col[i] = queue.poll();

            queue.add(col[i] - (long)n * p);

            col[i] = col[i - 1] + col[i];
        }

        // try finding 1 -> k best rows and fining relevant columns
        queue.clear();

        for(int i = 0; i < n; ++i) {

            long sum = 0;

            for(int j = 0; j < m; ++j)
                sum += mat[i][j];

            queue.add(sum);
        }

        long row = 0;
        long ans = Long.MIN_VALUE;

        for(int i = 0; i <= k; ++i) {

            long cans = row + col[k - i] - p * i * (k - i);

            ans = max(ans, cans);

            long crow = queue.poll();
            queue.add(crow - (long)m * p);

            row += crow;
        }

        w.print(ans);

        w.close();      
    }
}