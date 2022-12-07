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
    long fastpow(long a, long b) {
        if(b == 0)
            return 1;
        long val = fastpow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    long mod = (long)1e6 + 3;
    public void run() {
        // InputReader sc = new InputReader(System.in);
        // PrintWriter w = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        
        long mat[][] = new long[11][12];

        for(int i = 0; i < 11; ++i) {
            long val = 1;
            for(int j = 0; j < 11; ++j) {
                mat[i][j] = val;
                val = val * i % mod;
            }

            System.out.println("? " + i);
            System.out.flush();
            mat[i][11] = sc.nextLong();
        }

        // System.out.println("MAIN:");
        // for(int i = 0; i < 11; ++i) {
        //     for(int j = 0; j < 12; ++j)
        //         System.out.print(mat[i][j] + " ");
        //     System.out.println();
        // }

        for(int i = 0; i < 11; ++i) {
            if(mat[i][i] == 0) {
                int ind = -1;
                for(int j = i + 1; j < 11; ++j) {
                    if(mat[i][j] != 0)
                        ind = j;
                }

                if(ind == -1) {
                    System.out.println("FAIL1");
                    System.out.flush();
                    return;
                }

                for(int j = 0; j < 12; ++j) {
                    long temp = mat[ind][j];
                    mat[ind][j] = mat[i][j];
                    mat[i][j] = temp;
                }
            }

            long reqProd[] = new long[1000003];
            Arrays.fill(reqProd, -1);
            long val = mat[i][i];
            reqProd[0] = 0;
            long curProd = 1;
            while(reqProd[(int)val] == -1) {
                reqProd[(int)val] = curProd;
                curProd = (curProd + 1) % mod;
                val = (val + mat[i][i]) % mod;
            }

            for(int j = 0; j < 1000003; ++j) {
                if(reqProd[j] == -1) {
                    System.out.println("FAIL2" + mat[i][i] + " " + j);
                    System.out.flush();
                    return;
                }
            }

            for(int j = i + 1; j < 11; ++j) {
                long prod = reqProd[(int)mat[j][i]];
                for(int k = i; k < 12; ++k) {
                    mat[j][k] = (mat[j][k] - mat[i][k] * prod % mod + mod) % mod;
                }
            }

            long div = fastpow(mat[i][i], mod - 2);
            for(int j = i; j < 12; ++j) {
                mat[i][j] = mat[i][j] * div % mod;
            }
        }

        long sol[] = new long[11];
        sol[10] = mat[10][11];
        for(int i = 9; i >= 0; --i) {
            sol[i] = mat[i][11];
            for(int j = i + 1; j < 11; ++j)
                sol[i] = (sol[i] - mat[i][j] * sol[j] % mod + mod) % mod;
        }

        // for(int j = 0; j < 11; ++j) {
        //     System.out.println(j + " " + sol[j]);
        // }

        long ans = -1;
        for(int i = 0; i < 1000003; ++i) {
            long cans = 0;
            long curv = 1;
            for(int j = 0; j < 11; ++j) {
                cans = (cans + curv * sol[j] % mod) % mod;
                curv = curv * i % mod;
            }

            if(cans == 0) {
                ans = i;
                break;
            }
        }

        System.out.println("! " + ans);
        System.out.flush();

        //w.close();
    }
}