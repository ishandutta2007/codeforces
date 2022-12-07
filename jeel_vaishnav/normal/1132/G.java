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
    void dfsPrecompute(int i) {
        inTime[i] = time++;

        for(int j : adj[i]) 
            dfsPrecompute(j);

        outTime[i] = time - 1;
    }
    void solveLazy(int low, int high, int pos) {
        segTree[pos] += lazy[pos];
        if(low != high) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    void updateSegTree(int low, int high, int pos, int l, int r, int val) {
        if(l > r)
            return;

        solveLazy(low, high, pos);

        if(low > r || high < l)
            return;

        if(low >= l && high <= r) {
            segTree[pos] += val;
            if(low != high) {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;
            }
            return;
        }

        int mid = (low + high) >> 1;
        updateSegTree(low, mid, 2 * pos + 1, l, r, val);
        updateSegTree(mid + 1, high, 2 * pos + 2, l, r, val);

        segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
    int segTree[], lazy[];
    int time = 0;
    int inTime[], outTime[];
    int adj[][];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int a[] = new int[n + 1];
        for(int i = 1; i <= n; ++i)
            a[i] = sc.nextInt();

        int deg[] = new int[n + 1];

        Stack stack = new Stack(n + 1);

        for(int i = n; i >= 1; --i) {
            while(!stack.empty() && a[stack.peek()] <= a[i])
                stack.pop();

            if(stack.empty()) 
                deg[0]++;
            else
                deg[stack.peek()]++;
            stack.push(i);
        }

        stack.clear();

        adj = new int[n + 1][];
        for(int i = 0; i <= n; ++i)
            adj[i] = new int[deg[i]];

        int ptr[] = new int[n + 1];

        for(int i = n; i >= 1; --i) {
            while(!stack.empty() && a[stack.peek()] <= a[i])
                stack.pop();

            if(stack.empty()) 
                adj[0][ptr[0]++] = i;
            else
                adj[stack.peek()][ptr[stack.peek()]++] = i;
            stack.push(i);
        }

        inTime = new int[n + 1];
        outTime = new int[n + 1];
        dfsPrecompute(0);

        n = n + 1;

        segTree = new int[4 * n];
        lazy = new int[4 * n];

        for(int i = 1; i < k; ++i) {
            updateSegTree(0, n - 1, 0, inTime[i], outTime[i], 1);
        }

        for(int i = k; i < n; ++i) {
            updateSegTree(0, n - 1, 0, inTime[i], outTime[i], 1);

            w.print(segTree[0] + " ");

            updateSegTree(0, n - 1, 0, inTime[i - k + 1], outTime[i - k + 1], -1);
        }

        w.close();
    }
}
class Stack {
    int size, ptr;
    int a[];
    Stack(int size) {
        this.size = size;
        a = new int[size];
        ptr = 0;
    }
    void push(int i) {
        a[ptr++] = i;
    }
    int peek() {
        return a[ptr - 1];
    }
    boolean empty() {
        return ptr == 0;
    }
    int pop() {
        ptr--;
        return a[ptr];
    }
    void clear() {
        ptr = 0;
    }
}