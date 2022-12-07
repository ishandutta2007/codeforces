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
        
        Point p[] = new Point[n];
        for(int i = 0; i < n; ++i) 
            p[i] = new Point(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());

        int pminx[] = new int[n];
        int pminy[] = new int[n];
        int pmaxx[] = new int[n];
        int pmaxy[] = new int[n];

        pminx[0] = p[0].x1;
        pmaxx[0] = p[0].x2;
        pminy[0] = p[0].y1;
        pmaxy[0] = p[0].y2;

        for(int i = 1; i < n; ++i) {
            pminx[i] = max(pminx[i - 1], p[i].x1);
            pmaxx[i] = min(pmaxx[i - 1], p[i].x2);
            pminy[i] = max(pminy[i - 1], p[i].y1);
            pmaxy[i] = min(pmaxy[i - 1], p[i].y2);
        }

        int sminx[] = new int[n];
        int sminy[] = new int[n];
        int smaxx[] = new int[n];
        int smaxy[] = new int[n];

        sminx[n - 1] = p[n - 1].x1;
        smaxx[n - 1] = p[n - 1].x2;
        sminy[n - 1] = p[n - 1].y1;
        smaxy[n - 1] = p[n - 1].y2;

        for(int i = n - 2; i >= 0; --i) {
            sminx[i] = max(sminx[i + 1], p[i].x1);
            smaxx[i] = min(smaxx[i + 1], p[i].x2);
            sminy[i] = max(sminy[i + 1], p[i].y1);
            smaxy[i] = min(smaxy[i + 1], p[i].y2);
        }

        if(sminx[1] <= smaxx[1] && sminy[1] <= smaxy[1]) {
            w.print(sminx[1] + " " + sminy[1]);
            w.close();
            return;
        }

        if(pminx[n - 2] <= pmaxx[n - 2] && pminy[n - 2] <= pmaxy[n - 2]) {
            w.print(pminx[n - 2] + " " + pminy[n - 2]);
            w.close();
            return;
        }

        for(int i = 1; i <= n - 2; ++i) {
            int minx = max(sminx[i + 1], pminx[i - 1]);
            int maxx = min(smaxx[i + 1], pmaxx[i - 1]);
            int miny = max(sminy[i + 1], pminy[i - 1]);
            int maxy = min(smaxy[i + 1], pmaxy[i - 1]);

            if(minx <= maxx && miny <= maxy) {
                w.print(minx + " " + miny);
                w.close();
                return;
            }
        }

        w.close();   
    }
}
class Point {
    int x1, x2, y1, y2;
    Point(int a, int b, int c, int d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
}