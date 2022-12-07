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
    int costx(char a, int reqX) {
        if(a == 'U') {
            return -1;
        }
        else if(a == 'D') {
            return 1;
        }
        return 0;
    }
    int costy(char a, int reqX) {
        if(a == 'R') {
            return -1;
        }
        else if(a == 'L') {
            return 1;
        }
        return 0;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        char[] s = sc.next().toCharArray();

        int x = sc.nextInt();
        int y = sc.nextInt();

        int reqDist = abs(x) + abs(y);

        if(reqDist > n) {
            w.println("-1");
            w.close();
            return;
        }

        int curx = 0, cury = 0;
        for(int i = 0; i < s.length; ++i) {
            if(s[i] == 'L')
                curx--;
            else if(s[i] == 'R')
                curx++;
            else if(s[i] == 'U')
                cury++;
            else
                cury--;
        }

        if(curx == x && cury == y) {
            w.print("0");
            w.close();
            return;
        }

        if((abs(x) + abs(y)) % 2 != n % 2) {
            w.print("-1");
            w.close();
            return;
        }

        int temp = x;
        x = y;
        y = temp;

        temp = curx;
        curx = cury;
        cury = temp;

        int reqX = x - curx, reqY = y - cury;
        int r = -1;
        int delx = curx, dely = cury;
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; ++i) {
            while(r + 1 < n && abs(delx - x) + abs(dely - y) > r - i + 1) {
                delx += costx(s[r + 1], reqX);
                dely += costy(s[r + 1], reqY);
                r++;
            }

            if(abs(delx - x) + abs(dely - y) > r - i + 1)
                break;

            ans = min(ans, r - i + 1);
            delx -= costx(s[i], reqX);
            dely -= costy(s[i], reqY);
        }

        if(ans != Integer.MAX_VALUE)
            w.print(ans);
        else
            w.print("-1");

        w.close();    
    }
}