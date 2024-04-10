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
    void solve(int i, int max) {
        queue.clear();

        for(Pair curP : storeQueue[i]) {
            queue.add(curP);
        }

        storeQueue[i].clear();

        while(!queue.isEmpty()) {
            Pair curP = queue.poll();

            if(curP.moves == max) {
                curP.moves = 0;
                storeQueue[i].add(curP);
                continue;
            }

            int x = curP.x;
            int y = curP.y;
            int moves = curP.moves;

            if(x - 1 >= 0 && mat[x - 1][y] == '.') {
                mat[x - 1][y] = (char)(i + '1');
                queue.add(new Pair(x - 1, y, moves + 1));
            } 
            if(x + 1 < n && mat[x + 1][y] == '.') {
                mat[x + 1][y] = (char)(i + '1');
                queue.add(new Pair(x + 1, y, moves + 1));
            } 
            if(y - 1 >= 0 && mat[x][y - 1] == '.') {
                mat[x][y - 1] = (char)(i + '1');
                queue.add(new Pair(x, y - 1, moves + 1));
            }
            if(y + 1 < m && mat[x][y + 1] == '.') {
                mat[x][y + 1] = (char)(i + '1');
                queue.add(new Pair(x, y + 1, moves + 1));
            }
        }
    }
    boolean check() {
        for(int i = 0; i < p; ++i) {
            if(!storeQueue[i].isEmpty())
                return true;
        }
        return false;
    }
    char mat[][];
    int n;
    int m;
    int p;
    Queue<Pair> queue = new LinkedList<>();
    Queue<Pair> storeQueue[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt();

        int s[] = new int[p];
        for(int i = 0; i < p; ++i)
            s[i] = sc.nextInt();

        mat = new char[n][m];
        for(int i = 0; i < n; ++i)
            mat[i] = sc.next().toCharArray();

        storeQueue = new Queue[p];
        for(int i = 0; i < p; ++i) {
            storeQueue[i] = new LinkedList<>();
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] >= '0' && mat[i][j] <= '9')
                    storeQueue[mat[i][j] - '1'].add(new Pair(i, j, 0));
            }
        }

        while(check()) {
            for(int i = 0; i < p; ++i) 
                solve(i, s[i]);
        }

        int cnt[] = new int[p];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] >= '0' && mat[i][j] <= '9')
                    cnt[mat[i][j] - '1']++;
            }
        }

        for(int i = 0; i < p; ++i)
            w.print(cnt[i] + " ");

        w.close();
    }
}
class Pair {
    int x, y, moves;
    Pair(int a, int b, int c) {
        x = a;
        y = b;
        moves = c;
    }
}