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
    int maxBit(int i) {
        for(int j = 19; j >= 0; --j) {
            if((i >> j & 1) == 1)
                return j;
        }
        return -1;
    }
    int cntBits(int i) {
        int ans = 0;
        for(int j = 0; j < 20; ++j) {
            if((i >> j & 1) == 1)
                ans++;
        }
        return ans;
    }
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        HashMap<String, Integer> map = new HashMap<>();
        int ptr = 0;

        int mask[] = new int[1 << 20];
        for(int i = 0; i < (1 << 20); ++i)
            mask[i] = (1 << 20) - 1;

        int allowed1[] = new int[1 << 20];
        int allowed2[] = new int[1 << 20];
        int cans[] = new int[1 << 20];
        int max[] = new int[1 << 20];

        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i < n; ++i) {
            int type = sc.nextInt();

            if(type == 1) {
                for(int j : set) {
                    for(int k : set) {
                        if(j != k) {
                            if(min(j, k) < 20 && max(j, k) >= 20) {
                                mask[min(j, k)] &= (((1 << 20) - 1) ^ (1 << (max(j, k) - 20)));
                            }
                            else if(j < 20) {
                                int cmask = (1 << j) + (1 << k);
                                allowed1[cmask] = 1;
                            }
                            else {
                                int cmask = (1 << (j - 20)) + (1 << (k - 20));
                                allowed2[cmask] = 1;
                            }
                        }
                    }
                }
                set.clear();
            }
            else {
                String s = sc.next();

                if(map.get(s) == null)
                    map.put(s, ptr++);

                set.add(map.get(s));
            }
        }

        for(int j : set) {
            for(int k : set) {
                if(j != k) {
                    if(min(j, k) < 20 && max(j, k) >= 20) {
                        //w.println(min(j, k) + " " + mask[min(j, k)] + " " + max(j, k) + " " + (((1 << 20) - 1) ^ (1 << (max(j, k) - 21))));
                        mask[min(j, k)] &= (((1 << 20) - 1) ^ (1 << (max(j, k) - 20)));
                        //w.println(min(j, k) + " " + mask[min(j, k)]);
                    }
                    else if(j < 20) {
                        int cmask = (1 << j) + (1 << k);
                        allowed1[cmask] = 1;
                    }
                    else {
                        int cmask = (1 << (j - 20)) + (1 << (k - 20));
                        allowed2[cmask] = 1;
                    }
                }
            }
        }

        for(int i = 1; i < (1 << 20); ++i) {
            for(int j = 0; j < 20; ++j) {
                if((i >> j & 1) == 1) {
                    int newMask = i ^ (1 << j);
                    allowed1[i] |= allowed1[newMask];
                    allowed2[i] |= allowed2[newMask];
                }
            }
        }

        if(m <= 20) {
            int ans = 0;
            for(int i = 0; i < (1 << m); ++i) {
                if(allowed1[i] == 0)
                    ans = max(ans, cntBits(i));
            }

            w.print(ans);
            w.close();
            return;
        }

        int ans = 0;
        for(int i = 0; i < (1 << 20); ++i) {
            if(allowed1[i] == 0)
                ans = max(ans, cntBits(i));
        }

        for(int i = 1; i < (1 << 20); ++i) {
            if(allowed2[i] == 0 && maxBit(i) + 20 < m) {
                max[i] = cntBits(i);
            }
        }

        for(int i = 1; i < (1 << 20); ++i) {
            for(int j = 0; j < 20; ++j) {
                if((i >> j & 1) == 1)
                    max[i] = max(max[i], max[i ^ (1 << j)]);
            }
        }

        ans = max(ans, max[(1 << 20) - 1]);

        for(int i = 1; i < (1 << 20); ++i) {
            if(allowed1[i] == 0) {
                int curMask = (1 << 20) - 1;
                int ccans = cntBits(i);
                for(int j = 0; j < 20; ++j) {
                    if((i >> j & 1) == 1)
                        curMask &= mask[j];
                }

                ccans += max[curMask];
                ans = max(ans, ccans);
            }
        }

        w.print(ans);

        w.close();
    }
}