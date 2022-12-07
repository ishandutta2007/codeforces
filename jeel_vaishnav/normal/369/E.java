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
    long queryBit(int ind) {
        long ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return ans;
    }
    void updateBit(int ind) {
        while(ind < bit.length) {
            bit[ind]++;
            ind += Integer.lowestOneBit(ind);
        }
    }
    long bit[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<Integer> adj[] = new ArrayList[1000001];
        for(int i = 0; i <= 1000000; ++i) {
            adj[i] = new ArrayList<>();
        }

        for(int i = 0; i < n; ++i) 
            adj[sc.nextInt()].add(sc.nextInt());

        ArrayList<Query> list[] = new ArrayList[1000001];
        for(int i = 0; i <= 1000000; ++i)
            list[i] = new ArrayList<>();

        for(int i = 0; i < m; ++i) {
            ArrayList<Integer> clist = new ArrayList<>();
            int cnt = sc.nextInt();
            clist.add(0);
            for(int j = 0; j < cnt; ++j) {
                clist.add(sc.nextInt());
            }
            clist.add(1000001);

            for(int j = 1; j < clist.size(); ++j) {
                int curL = clist.get(j - 1) + 1;
                int curR = clist.get(j) - 1;

                list[curL - 1].add(new Query(curR, -1, i));
                list[curR].add(new Query(curR, 1, i));
            }
        }

        bit = new long[1000001];
        long ans[] = new long[m];
        for(int i = 1; i <= 1000000; ++i) {
            for(int j : adj[i])
                updateBit(j);

            for(Query curQ : list[i]) {
                ans[curQ.ind] += curQ.type * queryBit(curQ.r);
            }
        }

        for(long i : ans)
            w.println((n - i));

        w.close();
    }
}
class Query {
    int r, type, ind;
    Query(int a, int b, int c) {
        r = a;
        type = b;
        ind = c;
    }
}