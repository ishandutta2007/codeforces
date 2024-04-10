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
    boolean check(char a, char b) {
        return (a == '0' && b == '9') || (a == '9' && b == '0');
    }
    void solve(int i, int step) {
        if(moves.size() == (int)1e5)
            return;

        if(step == 1 && s[i + 1] == '9') {
            solve(i + 1, -1);
        }
        else if(step == -1 && s[i + 1] == '0') {
            solve(i + 1, 1);
        }

        if(moves.size() == (int)1e5)
            return;

        moves.add(new Move(i, step));
        s[i] += step;
        s[i + 1] += step;
    }
    char[] s;
    ArrayList<Move> moves = new ArrayList<>();
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        char[] tempS = new char[n];
        char[] tempT = new char[n];
        for(int i = 0; i < n; ++i) {
            tempS[i] = s[i];
            tempT[i] = t[i];
        }


        int ind = -1;
        long ans = 0;
        int flag = 0;
        main : for(int i = 0; i < n - 1; ++i) {
            while(s[i] != t[i]) {
                if(s[i] < t[i]) {
                    if(s[i + 1] == '9') {
                        if(ind <= i)
                            ind = i + 1;

                        while(ind + 1 < n && check(s[ind + 1], s[ind]))
                            ind++;
                        if(ind == n - 1) {
                            flag = 1;
                            break;
                        }
                        if(s[ind] == '0')
                            s[ind + 1]++;
                        else
                            s[ind + 1]--;
                        s[i + 1]--;
                        ans += (long)(ind - i);
                    }
                    ans++;
                    s[i]++;
                    s[i + 1]++;
                }
                else {
                    if(s[i + 1] == '0') {
                        if(ind <= i)
                            ind = i + 1;

                        while(ind + 1 < n && check(s[ind + 1], s[ind]))
                            ind++;
                        if(ind == n - 1) {
                            flag = 1;
                            break;
                        }
                        if(s[ind] == '0')
                            s[ind + 1]++;
                        else
                            s[ind + 1]--;
                        s[i + 1]++;
                        ans += (long)(ind - i);
                    }
                    ans++;
                    s[i]--;
                    s[i + 1]--;
                }
            }
        }

        if(flag == 1 || s[n - 1] != t[n - 1]) {
            w.print("-1");
            w.close();
            return;
        }

        s = tempS;
        t = tempT;

        w.println(ans);
        for(int i = 0; i < n - 1; ++i) {
            while(s[i] < t[i] && moves.size() != (int)1e5)
                solve(i, 1);
            while(s[i] > t[i] && moves.size() != (int)1e5)
                solve(i, -1);
        }
        for(Move m : moves)
            w.println(m);

        w.close();
    }
}
class Move {
    int ind, step;
    Move(int a, int b) {
        ind = a;
        step = b;
    }
    public String toString() {
        return (ind + 1) + " " + step;
    }
}