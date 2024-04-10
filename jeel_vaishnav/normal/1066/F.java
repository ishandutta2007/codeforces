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
    long getDist(Point p1, Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();

        TreeMap<Long, ArrayList<Point>> map = new TreeMap<>();

        Point p[] = new Point[n];
        for(int i = 0; i < n; ++i) {
            p[i] = new Point(sc.nextLong(), sc.nextLong());
            long level = max(p[i].x, p[i].y);
            if(map.get(level) == null)
                map.put(level, new ArrayList<>());
            map.get(level).add(p[i]);
        }

        for(long i : map.keySet()) {
            ArrayList<Point> list = map.get(i);

            Collections.sort(list, new Comparator<Point>() {
                public int compare(Point p1, Point p2) {
                    if(p1.y < p2.y)
                        return -1;
                    if(p1.y > p2.y)
                        return 1;
                    if(p1.x > p2.x)
                        return -1;
                    if(p1.x < p2.x)
                        return 1;
                    return 0;
                }
            });
        }

        long prevDp[], dp[];
        
        ArrayList<Point> prevList = new ArrayList<>();
        prevList.add(new Point(0, 0));

        prevDp = new long[1];
        prevDp[0] = 0;

        for(long i : map.keySet()) {
            ArrayList<Point> list = map.get(i);

            Point firstP = list.get(0);
            Point lastP = list.get(list.size() - 1);

            long firstVal = Long.MAX_VALUE;
            long lastVal = Long.MAX_VALUE;

            for(int j = 0; j < prevList.size(); ++j) {
                long curFirstVal = getDist(prevList.get(j), firstP) + prevDp[j];
                long curLastVal = getDist(prevList.get(j), lastP) + prevDp[j];
                firstVal = min(firstVal, curFirstVal);
                lastVal = min(lastVal, curLastVal);
            }

            dp = new long[list.size()];
            for(int j = 0; j < list.size(); ++j) {
                long val1 = firstVal + getDist(firstP, lastP) + getDist(lastP, list.get(j));
                long val2 = lastVal + getDist(lastP, firstP) + getDist(firstP, list.get(j));

                dp[j] = min(val1, val2);
            }       


            prevDp = dp;
            prevList = list;
        }

        long ans = Long.MAX_VALUE;
        for(int i = 0; i < prevDp.length; ++i)
            ans = min(ans, prevDp[i]);

        w.print(ans);

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