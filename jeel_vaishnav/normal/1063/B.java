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
        int m = sc.nextInt();

        int r = sc.nextInt() - 1;
        int c = sc.nextInt() - 1;

        int x = sc.nextInt();
        int y = sc.nextInt();

        int minMoves[][] = new int[n][m];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                minMoves[i][j] = -1;
        }

        char[][] s = new char[n][m];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next().toCharArray();

        Queue<Pair> queue0 = new LinkedList<>();
        Queue<Pair> queue1 = new LinkedList<>();

        int cans = 0;
        queue0.add(new Pair(r, c));

        while(!(queue0.isEmpty() && queue1.isEmpty())) {
            if(queue0.isEmpty()) {
                cans++;
                queue0 = queue1;
                queue1 = new LinkedList<>();
            }

            Pair cur = queue0.poll();

            int i = cur.x;
            int j = cur.y;

            if(minMoves[i][j] != -1)
                continue;

            minMoves[i][j] = cans;

            if(i - 1 >= 0 && minMoves[i - 1][j] == -1 && s[i - 1][j] != '*') {
                queue0.add(new Pair(i - 1, j));
            }
            if(i + 1 < n && minMoves[i + 1][j] == -1 && s[i + 1][j] != '*') {
                queue0.add(new Pair(i + 1, j));
            }
            if(j - 1 >= 0 && minMoves[i][j - 1] == -1 && s[i][j - 1] != '*') {
                queue1.add(new Pair(i, j - 1));
            }
            if(j + 1 < m && minMoves[i][j + 1] == -1 && s[i][j + 1] != '*') {
                queue1.add(new Pair(i, j + 1));
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(minMoves[i][j] != -1) {
                    int leftMoves = 0, rightMoves = 0;

                    if(j > c)
                        rightMoves = j - c;
                    else
                        leftMoves = c - j;

                    int remMoves = minMoves[i][j] - leftMoves - rightMoves;
                    leftMoves += remMoves / 2;
                    rightMoves += remMoves / 2;

                    if(leftMoves <= x && rightMoves <= y)
                        ans++;
                }
            }
        }

        w.print(ans);

        w.close();
    }
}
class Pair {
    int x, y;
    Pair(int a, int b) {
        x = a;
        y = b;
    }
}