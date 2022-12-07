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
        long r = sc.nextLong();

        long l[] = new long[n];
        for(int i = 0; i < n; ++i)
            l[i] = sc.nextLong();

        long t[] = new long[n];
        for(int i = 0; i < n; ++i) {
            t[i] = sc.nextLong();

            if(t[i] < l[i]) {
                w.print("-1");
                w.close();
                return;
            }
        }

        ArrayList<Long> time = new ArrayList<>();
        long startTime = 0, endJuiceTime = 0, ans = 0;

        for(int i = 0; i < n; ++i) {
            long juiceTimeReq = 0;
            if(t[i] < 2L * l[i])
                juiceTimeReq = 2L * l[i] - t[i];

            if(max(0, endJuiceTime - startTime) >= juiceTimeReq) {
                long totalJuiceTime = max(0, endJuiceTime - startTime);

                if(totalJuiceTime >= l[i]) {
                    startTime = startTime + l[i];
                }
                else {
                    startTime = max(startTime, endJuiceTime) + (l[i] - totalJuiceTime) * 2L;
                }
            }
            else {
                long totalJuiceTime = max(0, endJuiceTime - startTime);
                juiceTimeReq -= totalJuiceTime;

                long endTime = startTime + t[i];
                for(long j = endTime - juiceTimeReq; j < endTime && time.size() <= 200000; j += r) {
                    time.add(j);
                    endJuiceTime = j + r;
                    ans++;
                }

                if(endJuiceTime < endTime) {
                    long start = max(endTime - juiceTimeReq, endJuiceTime);
                    long reqJuice = (endTime - start - 1L) / r + 1L;
                    ans += reqJuice;
                    endJuiceTime = start + reqJuice * r;
                }

                startTime = endTime;
            }
        }

        w.println(ans);
        if(ans <= 100000) {
            for(long x : time) {
                w.print(x + " ");
            }
        } 

        w.close();
    }
}