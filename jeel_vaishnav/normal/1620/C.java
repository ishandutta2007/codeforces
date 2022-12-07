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
    void solve() {
        InputReader sc = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = sc.nextInt();
        for(int p = 0; p < t; ++p) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long x = sc.nextLong();

            char[] s = sc.next().toCharArray();

            List<Long> subtractions = new ArrayList<>();
            List<Long> possibility = new ArrayList<>();
            long curPossibility = 0;
            long cans = 1;
            long inf = (long)1e18 + 1;
            for(int i = n - 1; i >= 0; --i) {
                if(s[i] == 'a') {
                    subtractions.add(cans);
                    if(inf / cans < curPossibility + 1) {
                        cans = inf;
                    }
                    else {
                        cans *= (curPossibility + 1);
                    }

                    possibility.add(curPossibility);
                    curPossibility = 0;
                }
                else {
                    curPossibility += k;
                }
            }

            subtractions.add(cans);
            if(inf / cans < curPossibility + 1) {
                cans = inf;
            }
            else {
                cans *= (curPossibility + 1);
            }

            possibility.add(curPossibility);
            
            curPossibility = 0;

            long req = x - 1;
            List<Character> ans = new ArrayList<>();
            for(int i = possibility.size() - 1; i >= 0; --i) {
                ans.add('a');
                curPossibility = possibility.get(i);
                long curSubtraction = subtractions.get(i);

                // System.out.println(req + " " + curPossibility + " " + curSubtraction);

                if(curSubtraction <= req) {
                    long possibleSubtractions = min(curPossibility, req / curSubtraction);
                    for(long j = 0; j < possibleSubtractions; ++j) {
                        ans.add('b');
                    }
                    req -= curSubtraction * possibleSubtractions;
                }
            }

            char[] fans = new char[ans.size() - 1];
            for(int i = 1; i < ans.size(); ++i)
                fans[i - 1] = ans.get(i);

            out.println(new String(fans));
        }
        out.close();
    }
    public void run() {
        solve();
    }
}