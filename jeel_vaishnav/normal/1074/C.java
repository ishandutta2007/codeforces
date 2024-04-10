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
    long md(Point p1, Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        Point p[] = new Point[n];
        long minX = Long.MAX_VALUE, minY = Long.MAX_VALUE;
        long maxX = Long.MIN_VALUE, maxY = Long.MIN_VALUE;

        for(int i = 0; i < n; ++i) {
            p[i] = new Point(sc.nextLong(), sc.nextLong());
            maxX = max(maxX, p[i].x);
            minX = min(minX, p[i].x);
            maxY = max(maxY, p[i].y);
            minY = min(minY, p[i].y);
        }

        ArrayList<Point> list = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            if(p[i].x == maxX || p[i].x == minX || p[i].y == minY || p[i].y == maxY)
                list.add(p[i]); 
        }

        if(list.size() == 2) {
            long ans1 = 2L * md(list.get(0), list.get(1));
            for(int i = 3; i <= n; ++i)
                w.print(ans1 + " ");
            w.close();
            return;
        }

        long ans1 = 0;
        for(int i = 0; i < list.size(); ++i) {
            Point p1 = list.get(i);
            for(int j = i + 1; j < list.size(); ++j) {
                Point p2 = list.get(j);
                for(int k = j + 1; k < list.size(); ++k) {
                    Point p3 = list.get(k);
                    long cans = md(p1, p2) + md(p2, p3) + md(p3, p1);
                    ans1 = max(ans1, cans);
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            long x = p[i].x;
            long y = p[i].y;
            long cans = max(abs(x - maxX) + abs(y - maxY), abs(x - minX) + abs(y - maxY));
            cans = max(cans, abs(x - maxX) + abs(y - minY));
            cans = max(cans, abs(x - minX) + abs(y - minY));
            ans1 = max(ans1, 2L * cans);
        }

        w.print(ans1 + " ");

        if(n >= 4) {
            if(list.size() == 3) {
                for(int i = 4; i <= n; ++i)
                    w.print(ans1 + " ");
            }
            else {
                long ans2 = 0;
                for(int i = 0; i < list.size(); ++i) {
                    Point p1 = list.get(i);
                    for(int j = i + 1; j < list.size(); ++j) {
                        Point p2 = list.get(j);
                        for(int k = j + 1; k < list.size(); ++k) {
                            Point p3 = list.get(k);
                            for(int l = k + 1; l < list.size(); ++l) {
                                Point p4 = list.get(l);
                                long cans = md(p1, p2) + md(p2, p3) + md(p3, p4) + md(p4, p1);
                                ans2 = max(ans2, cans);
                            }
                        }
                    }
                }
                for(int i = 4; i <= n; ++i)
                    w.print(ans2 + " ");
            }
        }

        w.close();
    }
}
class Point {
    long x, y;
    Point(long a, long b) {
        x = a;
        y = b;
    }
}