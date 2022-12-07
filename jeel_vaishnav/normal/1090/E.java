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
    ArrayList<Step> possibles = new ArrayList<>();

    String findCell(int x, int y) {
        char[] ans = new char[2];
        ans[0] = (char)('a' + x);
        ans[1] = (char)('1' + y);
        return new String(ans);
    }
    void findPath(int i, int j, int k, int l) {
        if(i == k && j == l)
            return;
        path.add(new Move(p[k][l][i][j].parx, p[k][l][i][j].pary, i, j));
        findPath(p[k][l][i][j].parx, p[k][l][i][j].pary, k, l);
    }
    ArrayList<Move> path = new ArrayList<>();
    Stack<Move> stack = new Stack<>();
    ArrayList<Move> list = new ArrayList<>();
    int mat[][];
    int vis[][];
    Pair p[][][][];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        for(int i = -2; i <= 2; ++i) {
            for(int j = -2; j <= 2; ++j) {
                if(abs(i) + abs(j) == 3)
                    possibles.add(new Step(i, j));
            }
        }

        p = new Pair[8][8][8][8];
        int maxVal = 0;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                vis = new int[8][8];
                Queue<Cell> queue = new LinkedList<>();
                queue.add(new Cell(i, j, 0));
                vis[i][j] = 1;
                while(!queue.isEmpty()) {
                    Cell curC = queue.poll();
                    int x = curC.x;
                    int y = curC.y;
                    int ccost = curC.cost;

                    maxVal = max(maxVal, ccost);

                    for(Step s : possibles) {
                        int dx = s.dx;
                        int dy = s.dy;

                        if(x + dx >= 0 && x + dx < 8 && y + dy >= 0 && y + dy < 8 && vis[x + dx][y + dy] == 0) {
                            vis[x + dx][y + dy] = 1;
                            queue.add(new Cell(x + dx, y + dy, ccost + 1));
                            p[i][j][x + dx][y + dy] = new Pair(s, x, y);
                        }
                    }
                }
            }
        }

        //w.println(maxVal);

        int n = sc.nextInt();

        mat = new int[8][8];

        for(int i = 0; i < n; ++i) {
            char[] s = sc.next().toCharArray();

            mat[s[1] - '1'][s[0] - 'a'] = 1;
        }

        int ptr = 0;
        main : for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(ptr == n)
                    break main;
                ptr++;
                
                if(mat[i][j] == 1)
                    continue;

                int indx = -1, indy = -1;
                for(int k = j + 1; k < 8; ++k) {
                    if(mat[i][k] == 1) {
                        indx = i;
                        indy = k;
                    }
                }

                for(int k = i + 1; k < 8; ++k) {
                    for(int l = 0; l < 8; ++l) {
                        if(mat[k][l] == 1 && indx == -1) {
                            indx = k;
                            indy = l;
                        }
                    }
                }

                path = new ArrayList<>();
                findPath(i, j, indx, indy);

                for(Move s : path) {
                    stack.push(s);

                    if(mat[s.x1][s.y1] == 1) {
                        while(!stack.empty())
                            list.add(stack.pop());
                    }
                }

                mat[i][j] = 1;
                mat[indx][indy] = 0;
            }
        }

        w.println(list.size());
        for(Move i : list) {
            w.println(findCell(i.y1, i.x1) + "-" + findCell(i.y2, i.x2));
        }

        w.close();
    }
}
class Cell {
    int x, y, cost;
    Cell(int a, int b, int c) {
        x = a;
        y = b;
        cost = c;
    }
}
class Pair {
    Step s;
    int parx, pary;
    Pair(Step a, int x, int y) {
        s = a;
        parx = x;
        pary = y;
    }
}
class Step {
    int dx, dy;
    Step(int a, int b) {
        dx = a;
        dy = b;
    }
}
class Move {
    int x1, y1, x2, y2;
    Move(int a, int b, int c, int d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
}