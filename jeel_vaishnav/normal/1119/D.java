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
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        
        long s[] = new long[n];
        for(int i = 0; i < n; ++i)
            s[i] = sc.nextLong();

        Arrays.sort(s);

        TreeMap<Long, Long> cntMap = new TreeMap<>();
        TreeMap<Long, Long> sumMap = new TreeMap<>();

        for(int i = 1; i < n; ++i) {
            long diff = s[i] - s[i - 1];
            if(cntMap.get(diff) == null) {
                cntMap.put(diff, 1L);
                sumMap.put(diff, diff);
            }
            else {
                cntMap.put(diff, cntMap.get(diff) + 1);
                sumMap.put(diff, sumMap.get(diff) + diff);
            }
        }

        long alrCnt = 0, alrSum = 0;
        for(long i : cntMap.keySet()) {
            alrCnt += cntMap.get(i);
            alrSum += sumMap.get(i);

            cntMap.put(i, alrCnt);
            sumMap.put(i, alrSum);
        }

        int q = sc.nextInt();

        BigInteger N = new BigInteger(String.valueOf(n));

        for(int x = 0; x < q; ++x) {
            long l = sc.nextLong();
            long r = sc.nextLong();

            long size = r - l + 1;
            BigInteger Size = new BigInteger(String.valueOf(size));
            BigInteger Ans = Size.multiply(N);

            if(cntMap.lowerKey(size + 1) != null) {
                long cnt = cntMap.get(cntMap.lowerKey(size + 1));
                long sum = sumMap.get(cntMap.lowerKey(size + 1));

                BigInteger Cnt = new BigInteger(String.valueOf(cnt));
                BigInteger Sum = new BigInteger(String.valueOf(sum));

                BigInteger Rem = Cnt.multiply(Size).subtract(Sum);
                Ans = Ans.subtract(Rem);
            }

            w.print(Ans + " ");
        }

        w.close();
    }
}