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
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt() - 1;
        int d = sc.nextInt() - 1;

        char[][] s = new char[50][50];

        for(int i = 0; i < 50; ++i) {
            for(int j = 0; j < 50; ++j)
                s[i][j] = '.';
        }

        //fill C and D
        for(int i = 0; i < 50; ++i) {
            if(i % 2 == 0) {
                for(int j = 0; j < 25; ++j)
                    s[i][j] = 'D';
                for(int j = 25; j < 50; ++j)
                    s[i][j] = 'C';
            }
            else {
                for(int j = 0; j < 25; j += 2) {
                    s[i][j] = 'D';
                }
                for(int j = 25; j < 50; j += 2) {
                    s[i][j] = 'C';
                }
            }
        }

        //fill C
        for(int i = 1; i < 50 && c > 0; i += 2) {
            for(int j = 1; j < 25 && c > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'C';
                    c--;
                }
            }
        }

        //fill d
        for(int i = 1; i < 50 && d > 0; i += 2) {
            for(int j = 26; j < 50 && d > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'D';
                    d--;
                }
            }
        }

        //fill a
        for(int i = 1; i < 50 && a > 0; i += 2) {
            for(int j = 1; j < 25 && a > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'A';
                    a--;
                }
            }
        }
        for(int i = 1; i < 50 && a > 0; i += 2) {
            for(int j = 26; j < 50 && a > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'A';
                    a--;
                }
            }
        }

        //fill B
        for(int i = 1; i < 50 && b > 0; i += 2) {
            for(int j = 1; j < 25 && b > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'B';
                    b--;
                }
            }
        }
        for(int i = 1; i < 50 && b > 0; i += 2) {
            for(int j = 26; j < 50 && b > 0; j += 2) {
                if(s[i][j] != '.')
                    continue;
                else {
                    s[i][j] = 'B';
                    b--;
                }
            }
        }

        for(int i = 0; i < 50; ++i) {
            for(int j = 0; j < 25; ++j) {
                if(s[i][j] == '.')
                    s[i][j] = 'D';
            }
            for(int j = 25; j < 50; ++j) {
                if(s[i][j] == '.')
                    s[i][j] = 'C';
            }
        }

        w.println("50 50");
        for(int i = 0; i < 50; ++i)
            w.println(s[i]);

        w.close();      
    }
}