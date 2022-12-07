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
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    InputReader sc;
    PrintWriter out;
    int query(int a, int b, int c) {
        out.println("? " + (a + 1) + " " + (b + 1) + " " + (c + 1));
        out.flush();
        int val = sc.nextInt();
        return val;
    }
    void setAns(int flag0, int flag1, int blockIndex, int blockType, int[] ans) {
        for(int i = 0; i < 3; ++i)
            ans[3 * blockIndex + i] = blockType;
        if(flag0 != blockType && flag1 != blockType)
            ans[3 * blockIndex + 1] = blockType ^ 1;
        else if(flag0 != blockType)
            ans[3 * blockIndex + 0] = blockType ^ 1;
        else if(flag1 != blockType)
            ans[3 * blockIndex + 2] = blockType ^ 1;
    }
    void setBlock(int blockIndex, int blockType, int[] index, int[] ans) {
        int flag0 = query(blockIndex * 3, blockIndex * 3 + 1, index[blockType ^ 1]);
        int flag1 = query(blockIndex * 3 + 2, blockIndex * 3 + 1, index[blockType ^ 1]);
        setAns(flag0, flag1, blockIndex, blockType, ans);
    }
    void solve() {
        sc = new InputReader(System.in);
        out = new PrintWriter(System.out);

        int t = sc.nextInt();
        for(int x = 0; x < t; ++x) {
            int n = sc.nextInt();
            
            int type[] = new int[n / 3];
            for(int i = 0; i < n / 3; ++i) {
                type[i] = query(3 * i, 3 * i + 1, 3 * i + 2);
            }

            int block0 = -1;
            int block1 = -1;
            for(int i = 0; i < n / 3; ++i) {
                if(type[i] == 0)
                    block0 = i;
                else
                    block1 = i;
            }

            int ans[] = new int[n];

            int flag1 = 0;
            for(int i = 0; i < 3; ++i)
                flag1 |= query(block0 * 3, block0 * 3 + 1, block1 * 3 + i);
            int flag2 = 0;
            for(int i = 0; i < 3; ++i)
                flag2 |= query(block0 * 3 + 2, block0 * 3 + 1, block1 * 3 + i);

            setAns(flag1, flag2, block0, 0, ans);

            int index[] = new int[2];
            for(int i = 0; i < 3; ++i) {
                if(ans[3 * block0 + i] == 0) {
                    index[0] = 3 * block0 + i;
                    break;
                }
            }

            setBlock(block1, 1, index, ans);
            for(int i = 0; i < 3; ++i) {
                if(ans[3 * block1 + i] == 1) {
                    index[1] = 3 * block1 + i;
                    break;
                }
            }

            for(int i = 0; i < n / 3; ++i) {
                if(i != block0 && i != block1) {
                    setBlock(i, type[i], index, ans);
                }
            }

            List<Integer> imposters = new ArrayList<>();
            for(int i = 0; i < n; ++i) {
                if(ans[i] == 0)
                    imposters.add((i + 1));
            }
            out.print("! " + imposters.size() + " ");
            for(int imposter : imposters) {
                out.print(imposter + " ");
            }
            out.println();
            out.flush();
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