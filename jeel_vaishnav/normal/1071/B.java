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
        int k = sc.nextInt();

        char[][] s = new char[n][n];
        for(int i = 0; i < n; ++i) {
            s[i] = sc.next().toCharArray();
        }

        int dp[][] = new int[n][n];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);

                if(s[i][j] == 'a')
                    dp[i][j]++;
            }
        }

        int maxDist = 0;
        ArrayList<Point> list = new ArrayList<>();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int reqK = i + j + 1 - dp[i][j];

                if(reqK <= k && maxDist < i + j + 1) {
                    maxDist = i + j + 1;
                    list.clear();
                    list.add(new Point(i, j));
                }
                else if(reqK <= k && maxDist == i + j + 1) {
                    list.add(new Point(i, j));
                }
            }
        }

        for(int i = 0; i < maxDist; ++i)
            w.print("a");

        if(k == 0 && s[0][0] != 'a') {
            w.print(s[0][0]);
            list.add(new Point(0, 0));
        }

        int vis[][] = new int[n][n];
        ArrayList<Point> temp = new ArrayList<>();
        for(Point p : list) {
            if(p.x + 1 < n && vis[p.x + 1][p.y] == 0) {
                temp.add(new Point(p.x + 1, p.y));
                vis[p.x + 1][p.y] = 1;
            }
            if(p.y + 1 < n && vis[p.x][p.y + 1] == 0) {
                temp.add(new Point(p.x, p.y + 1));
                vis[p.x][p.y + 1] = 1;
            }
            list = temp;
        } 

        while(list.size() > 0) {
            char minVal = 'z';
            for(Point p : list) {
                if(s[p.x][p.y] < minVal)
                    minVal = s[p.x][p.y]; 
            }

            temp = new ArrayList<>();

            for(Point p : list) {
                if(s[p.x][p.y] == minVal) {
                    if(p.x + 1 < n && vis[p.x + 1][p.y] == 0) {
                        temp.add(new Point(p.x + 1, p.y));
                        vis[p.x + 1][p.y] = 1;
                    }
                    if(p.y + 1 < n && vis[p.x][p.y + 1] == 0) {
                        temp.add(new Point(p.x, p.y + 1));
                        vis[p.x][p.y + 1] = 1;
                    }
                    list = temp;
                }
            }

            w.print(minVal);
            list = temp;
        }

        w.close();
    }
}
class Point {
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
    }
}