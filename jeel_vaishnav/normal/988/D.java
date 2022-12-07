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

        long x[] = new long[n];
        HashMap<Long, Integer> map = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            long a = sc.nextLong();

            if(map.get(a) == null)
                map.put(a, 1);
            else
                map.put(a, map.get(a) + 1);
        }

        int ans = 0;
        ArrayList<Long> ansC = new ArrayList<>();;
        for(long i : map.keySet()) {
            if(map.get(i) > ans) {
                ans = map.get(i);
                ansC = new ArrayList<>();
                for(int j = 0; j < map.get(i); ++j)
                    ansC.add(i);
            }
            for(int p = 0; p <= 30; ++p) {
                long findVal1 = i - (1L << p);
                long findVal2 = i + (1L << p);
                if(map.get(findVal2) != null && map.get(findVal1) != null) {
                    int cans = map.get(i) + map.get(findVal1) + map.get(findVal2);
                    if(cans > ans) {
                        ans = cans;
                        ansC = new ArrayList<>();
                        for(int j = 0; j < map.get(i); ++j)
                            ansC.add(i);
                        for(int j = 0; j < map.get(findVal1); ++j)
                            ansC.add(findVal1);
                        for(int j = 0; j < map.get(findVal2); ++j)
                            ansC.add(findVal2);
                    }
                }
                else if(map.get(findVal1) != null) {
                    int cans = map.get(i) + map.get(findVal1);
                    if(cans > ans) {
                        ans = cans; 
                        ansC = new ArrayList<>();
                        for(int j = 0; j < map.get(i); ++j)
                            ansC.add(i);
                        for(int j = 0; j < map.get(findVal1); ++j)
                            ansC.add(findVal1);
                    }
                }
                else if(map.get(findVal2) != null) {
                    int cans = map.get(i) + map.get(findVal2);
                    if(cans > ans) {
                        ans = cans;
                        ansC = new ArrayList<>();
                        for(int j = 0; j < map.get(i); ++j)
                            ansC.add(i);
                        for(int j = 0; j < map.get(findVal2); ++j)
                            ansC.add(findVal2); 
                    }
                }
            }
        }

        w.println(ans);
        for(long i : ansC)
            w.print(i + " ");

        w.close();      
    }
}