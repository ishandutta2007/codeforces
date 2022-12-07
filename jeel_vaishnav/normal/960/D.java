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
    int msb(long num) {
        for(int i = 59; i >= 0; --i) {
            if((num >> i & 1) == 1)
                return i;
        }
        return 0;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        long shifts[] = new long[60];
        long subshifts[] = new long[60];
        long mod[] = new long[60];
        mod[0] = 1;
        for(int i = 1; i < 60; ++i)
            mod[i] = mod[i - 1] * 2L;

        int q = sc.nextInt();

        for(int i = 0; i < q; ++i) {
            int type = sc.nextInt();

            if(type == 1) {
                long x = sc.nextLong();
                long k = sc.nextLong();

                int level = msb(x);
                shifts[level] = (shifts[level] - k + mod[level]) % mod[level];
            }
            else if(type == 2) {
                long x = sc.nextLong();
                long k = sc.nextLong();
                int level = msb(x);

                subshifts[level] = (subshifts[level] + k + mod[level]) % mod[level];
            }
            else {
                long x = sc.nextLong();
                if(x == 1) {
                    w.println("1");
                    continue;
                }
                int level = msb(x);
                long processAdd = (x - shifts[level]) % mod[level];
                long processNode = mod[level] + processAdd;
                processAdd = (processNode + subshifts[level]) % mod[level];
                processNode = mod[level] + processAdd;
                while(level > 0) {
                    w.print(x + " ");
                    level--;
                    if(level != 0) {
                        processNode = processNode >> 1;
                        long xAdd = (processNode + shifts[level]) % mod[level];
                        x = mod[level] + xAdd;
                        processAdd = (processNode + subshifts[level]) % mod[level];
                        processNode = mod[level] + processAdd;
                    }
                }
                w.println("1");
            }
        }

        w.close();      
    }
}