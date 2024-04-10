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
        new Thread(null, new Main(),"Main",1<<27).start();
    }
    class Point {
        long x, y;
        Point(long a, long b) {
            x = a;
            y = b;
        }
    }
    int orientation(Point p1, Point p2, Point p3) { 
        long val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y); 
       
        if (val == 0) return 0;  

        return (val > 0) ? 1 : -1;  
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
 
        int n = sc.nextInt();

        Point temp[] = new Point[n];
        HashMap<Long, Long> map = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            long x = sc.nextLong();
            long y = sc.nextLong() - x * x;
            temp[i] = new Point(x, y);
            if(map.get(x) == null)
                map.put(x, y);
            else if(map.get(x) < y)
                map.put(x, y);
        }

        n = map.size();
        Point p[] = new Point[n];
        int ptr = 0;
        for(Point curP : temp) {
            if(map.get(curP.x) == curP.y)
                p[ptr++] = curP;
        }

        Arrays.sort(p, new Comparator<Point>() {
            public int compare(Point p1, Point p2) {
                if(p1.x < p2.x)
                    return -1;
                if(p1.x > p2.x)
                    return 1;
                return 0;
            }
        });

        Pair stack[] = new Pair[n];
        ptr = 0;
        int connect[] = new int[n];
        stack[ptr++] = new Pair(0, -1);
        connect[0] = -1;
        for(int i = 1; i < n; ++i) {
            while(ptr >= 2) {
                if(orientation(p[stack[ptr - 2].ind], p[stack[ptr - 1].ind], p[i]) < 0)
                    ptr--;
                else
                    break;
            }

            connect[i] = stack[ptr - 1].ind;

            stack[ptr] = new Pair(i, ptr - 1);
            ptr++;
        }

        long ans = 0;
        ptr = 0;
        stack[ptr++] = new Pair(n - 1, -1);
        for(int i = n - 2; i >= 0; --i) {
            while(ptr >= 2) {
                if(orientation(p[stack[ptr - 2].ind], p[stack[ptr - 1].ind], p[i]) > 0)
                    ptr--;
                else
                    break;
            }

            if(ptr == 1) {
                stack[ptr] = new Pair(i, 0);
                ptr++;
            }
            else {
                if(orientation(p[stack[ptr - 2].ind], p[stack[ptr - 1].ind], p[i]) == 0)
                    stack[ptr] = new Pair(i, stack[ptr - 1].parStackInd);
                else
                    stack[ptr] = new Pair(i, ptr - 1);
                ptr++;
            }

            if(!(ptr >= 3 && orientation(p[stack[ptr - 3].ind], p[stack[ptr - 2].ind], p[stack[ptr - 1].ind]) == 0)) {
                if(connect[i] == -1) {
                    ans++;
                }
                else if(orientation(p[connect[i]], p[i], p[stack[ptr - 2].ind]) >= 0) {
                    ans++;
                }
            }
        }

        w.print(ans);
    
        w.close();
    }
}
class Pair {
    int ind, parStackInd;
    Pair(int a, int b) {
        ind = a;
        parStackInd = b;
    }
}