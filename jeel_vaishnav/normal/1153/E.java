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
    boolean hasOneInside(int x1, int y1, int x2, int y2) {
        System.out.println("? " + x1 + " " + y1 + " " + x2 + " " + y2);
        System.out.flush();
        int val = sc.nextInt();

        return val % 2 == 1;
    }
    Scanner sc;
    public void run() {
        sc = new Scanner(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        int row[] = new int[2];
        int col[] = new int[2];
        int rowFlag = 0, colFlag = 0;

        for(int i = 1; i <= n; ++i) {
            if(hasOneInside(i, 1, i, n)) {
                if(rowFlag == 0) {
                    rowFlag = 1;
                    row[0] = i;
                }
                else
                    row[1] = i;
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(hasOneInside(1, i, n, i)) {
                if(colFlag == 0) {
                    colFlag = 1;
                    col[0] = i;
                }
                else
                    col[1] = i;
            }
        }

        if(rowFlag == 1 && colFlag == 1) {
            if(hasOneInside(row[0], col[0], row[0], col[0])) {
                System.out.println("! " + row[0] + " " + col[0] + " " + row[1] + " " + col[1]);
                System.out.flush();
            }
            else if(hasOneInside(row[0], col[1], row[0], col[1])) {
                System.out.println("! " + row[0] + " " + col[1] + " " + row[1] + " " + col[0]);
                System.out.flush();
            }
        }
        else if(rowFlag == 1) {
            int start = 1, end = n;
            while(end - start > 0) {
                int mid = (start + end) >> 1;
                if(hasOneInside(row[0], start, row[0], mid)) {
                    end = mid;
                }
                else 
                    start = mid + 1;
            }
            System.out.println("! " + row[0] + " " + start + " " + row[1] + " " + start);
            System.out.flush();
        }
        else {
            int start = 1, end = n;
            while(end - start > 0) {
                int mid = (start + end) >> 1;
                if(hasOneInside(start, col[0], mid, col[0])) {
                    end = mid;
                }
                else 
                    start = mid + 1;
            }
            System.out.println("! " + start + " " + col[0] + " " + start + " " + col[1]);
            System.out.flush();
        }

        w.close();
    }
}