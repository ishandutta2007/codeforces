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
    void remMap(TreeMap<Long, Integer> map, long key, int val) {
        if(map.get(key) == val)
            map.remove(key);
        else
            map.put(key, map.get(key) - val);
    }
    void addMap(TreeMap<Long, Integer> map, long key, int val) {
        if(map.get(key) == null)
            map.put(key, val);
        else
            map.put(key, map.get(key) + val);
    }
    long highest(TreeMap<Long, Integer> map) {
        if(map.size() == 0)
            return 0;
        return map.lastKey();
    }
    long solve(TreeMap<Long, Integer> map[]) {
        long ans = 0;
        for(int i = 0; i < map.length; ++i) {
            ans += highest(map[i]);
        }
        return ans;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        long k = sc.nextLong();

        long a[][] = new long[n][m];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                a[i][j] = sc.nextLong();
            }
        }

        int r = -1;
        int ans = 0;
        
        TreeMap<Long, Integer> map[] = new TreeMap[m];
        for(int i = 0; i < m; ++i)
            map[i] = new TreeMap<>();

        long freq[] = new long[m];

        for(int i = 0; i < n; ++i) {
            if(r < i) {
                r++;
                for(int j = 0; j < m; ++j) {
                    addMap(map[j], a[r][j], 1);
                }
            }

            while(r + 1 < n && solve(map) <= k) {
                r++;
                for(int j = 0; j < m; ++j) {
                    addMap(map[j], a[r][j], 1);
                }
            }

            if(solve(map) <= k) {
                int cans = r - i + 1;
                if(ans < cans) {
                    ans = cans;
                    for(int j = 0; j < m; ++j) {
                        freq[j] = highest(map[j]);
                    }
                }
            }
            else {
                int cans = r - i;
                if(ans < cans) {
                    ans = cans;
                    for(int j = 0; j < m; ++j) {
                        remMap(map[j], a[r][j], 1);
                    }
                    for(int j = 0; j < m; ++j) {
                        freq[j] = highest(map[j]);
                    }
                    for(int j = 0; j < m; ++j) {
                        addMap(map[j], a[r][j], 1);
                    }
                }
            }

            for(int j = 0; j < m; ++j)
                remMap(map[j], a[i][j], 1);
        }

        for(long i : freq)
            w.print(i + " ");

        w.close();
    }
}