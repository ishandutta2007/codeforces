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
        
        int n = sc.nextInt() + 1;
        int m = sc.nextInt();
        int k = sc.nextInt();

        int isBlocked[] = new int[n];
        for(int i = 0; i < m; ++i) 
            isBlocked[sc.nextInt()] = 1;

        if(isBlocked[0] == 1) {
            w.print("-1");
            w.close();
            return;
        }

        int lastNotBlocked[] = new int[n];
        int curNotBlocked = 0;
        lastNotBlocked[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(isBlocked[i] == 0)
                curNotBlocked = i;
            lastNotBlocked[i] = curNotBlocked;
        }

        long cost[] = new long[k + 1];
        for(int i = 1; i <= k; ++i)
            cost[i] = sc.nextLong();

        long reqEle[] = new long[k + 1];
        main : for(int i = 1; i <= k; ++i) {
            int curEle = 0;
            int cans = 0;
            while(curEle < n - 1) {
                cans++;
                if(isBlocked[curEle] == 1) {
                    if(curEle - lastNotBlocked[curEle] >= i) {
                        reqEle[i] = -1;
                        continue main;
                    }
                    curEle = lastNotBlocked[curEle];
                }
                curEle += i;
            }
            reqEle[i] = cans;
        }

        long start = 0, end = (long)1e13, ans = -1;

        while(start <= end) {
            long mid = (start + end) >> 1;
            int flag = 0;
            for(int i = 1; i <= k; ++i) {
                long cReq = mid / cost[i];
                if(reqEle[i] != -1 && reqEle[i] <= cReq)
                    flag = 1;
            }
            if(flag == 0)
                start = mid + 1L;
            else {
                ans = mid;
                end = mid - 1L;
            }
        }

        w.print(ans);

        w.close();      
    }
}