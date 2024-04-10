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

        char[][] s = new char[n][];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next().toCharArray();

        int left[][] = new int[n][m];
        int right[][] = new int[n][m];
        int up[][] = new int[n][m];
        int down[][] = new int[n][m];

        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == '.') {
                    cnt = 0;
                }
                else {
                    cnt++;
                }

                if(cnt >= 2)
                    left[i][j] = cnt - 1;
            }

            cnt = 0;
            for(int j = m - 1; j >= 0; --j) {
                if(s[i][j] == '.') {
                    cnt = 0;
                }
                else {
                    cnt++;
                }

                if(cnt >= 2)
                    right[i][j] = cnt - 1;
            }
        }

        for(int j = 0; j < m; ++j) {
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if(s[i][j] == '.') {
                    cnt = 0;
                }
                else {
                    cnt++;
                }

                if(cnt >= 2)
                    up[i][j] = cnt - 1;
            }

            cnt = 0;
            for(int i = n - 1; i >= 0; --i) {
                if(s[i][j] == '.') {
                    cnt = 0;
                }
                else {
                    cnt++;
                }

                if(cnt >= 2)
                    down[i][j] = cnt - 1;
            }
        } 

        int lupd[][] = new int[n][m];
        int dupd[][] = new int[n][m];

        ArrayList<Pair> list = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int poss = min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j]));
                if(poss > 0) {
                    list.add(new Pair(i, j, poss));
                    lupd[i][j - poss]++;
                    if(j + poss + 1 < m)
                        lupd[i][j + poss + 1]--;

                    dupd[i - poss][j]++;
                    if(i + poss + 1 < n)
                        dupd[i + poss + 1][j]--;
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                lupd[i][j] = lupd[i][j] + lupd[i][j - 1];
            }
        }

        for(int j = 0; j < m; ++j) {
            for(int i = 1; i < n; ++i) {
                dupd[i][j] = dupd[i][j] + dupd[i - 1][j];
            }
        }

        int flag = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int upd = lupd[i][j] + dupd[i][j];
                if(s[i][j] == '*' && upd == 0)
                    flag = 1;
            }
        }

        if(flag == 1)
            w.print("-1");
        else {
            w.println(list.size());
            for(Pair i : list)
                w.println(i);
        }

        w.close();   
    }
}
class Pair {
    int x, y, s;
    Pair(int a, int b, int c) {
        x = a + 1;
        y = b + 1;
        s = c;
    }
    public String toString() {
        return x + " " + y + " " + s;
    }
}