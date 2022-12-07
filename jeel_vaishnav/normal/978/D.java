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

    int findCost(int diff, int[] a, int n, int dec) {
        int[] b = new int[n];
        for(int i = 0; i < n; ++i)
            b[i] = a[i];
        int ans = 0;
        for(int i = 2; i < n; ++i) {
            int curdiff = b[i] - b[i - 1];
            if(diff - curdiff == -1) {
                ans++;
                b[i]--;
            }
            else if(diff - curdiff == 1) {
                ans++;
                b[i]++;
            }
            else if(diff - curdiff != 0) {
                return Integer.MAX_VALUE - dec;
            }
        }
        return ans;
    }

    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        
        int[] a = new int[n];

        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
        }

        if(n <= 2) {
            w.print("0");
            w.close();
            return;
        }

        int ans = Integer.MAX_VALUE;

        //no + no
        ans = min(ans, findCost(a[1] - a[0], a, n, 0));

        //no + 1inc
        a[1]++;
        ans = min(ans, findCost(a[1] - a[0], a, n, 1) + 1);

        //1inc + 0inc
        a[0]++;
        ans = min(ans, findCost(a[1] - a[0], a, n, 2) + 2);

        //1inc + 0dec
        a[0] -= 2;
        ans = min(ans, findCost(a[1] - a[0], a, n, 2) + 2);

        //no + 0dec
        a[1]--;
        ans = min(ans, findCost(a[1] - a[0], a, n, 1) + 1);

        //1dec + 0dec
        a[1]--;
        ans = min(ans, findCost(a[1] - a[0], a, n, 2) + 2);

        //1dec + no
        a[0]++;
        ans = min(ans, findCost(a[1] - a[0], a, n, 1) + 1);

        //1dec+ 0inc
        a[0]++;
        ans = min(ans, findCost(a[1] - a[0], a, n, 2) + 2);

        //no + 0inc
        a[1]++;
        ans = min(ans, findCost(a[1] - a[0], a, n, 1) + 1);

        if(ans == Integer.MAX_VALUE)
            w.print("-1");
        else
            w.print(ans);

        w.close();      
    }
}