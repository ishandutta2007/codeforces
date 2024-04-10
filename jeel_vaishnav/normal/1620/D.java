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
    public int getColor(HashMap<Integer, Integer> map, int i) {
        if(map.containsKey(i))
            return map.get(i);
        return i;
    }
    void solve() {
        InputReader sc = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = sc.nextInt();
        for(int x = 0; x < t; ++x) {
            int n = sc.nextInt();

            int a[] = new int[n];
            for(int i = 0; i < n; ++i)
                a[i] = sc.nextInt();

            int modulo[] = new int[3];
            int pure[] = new int[3];
            for(int i = 0; i < n; ++i) {
                modulo[a[i] % 3] += 1;
                if(a[i] < 3)
                    pure[a[i]] += 1;
            }

            int pans = 0;
            for(int i = 0; i < n; ++i)
                pans = max(pans, a[i] / 3);
            if(modulo[1] == 0 && modulo[2] == 0) {
                out.println(pans);
            }
            else if((modulo[1] > 0 && modulo[2] == 0) || (modulo[1] == 0 && modulo[2] > 0)) {
                out.println(pans + 1);
            }
            else {
                pans = 0;
                for(int i = 0; i < n; ++i) {
                    pans = max(pans, (a[i] - 1) / 3);
                }
                if(pure[1] > 0)
                    out.println((pans + 2));
                else {
                    int cpans = 0;
                    for(int i = 0; i < n; ++i) {
                        if(a[i] % 3 == 1) {
                            cpans = max(cpans, (a[i] - 4) / 3);
                        }
                        else {
                            cpans = max(cpans, a[i] / 3);
                        }
                    }
                    pans = min(pans, cpans);
                    out.println((pans + 2));
                }
            }
        }
        out.close();
    }
    public void run() {
        solve();
    }
    class Query {
        int type;
        int val1, val2;
        Query(int a, int b) {
            type = a;
            val1 = b;
        }
        Query(int a, int b, int c) {
            type = a;
            val1 = b;
            val2 = c;
        }
    }
}