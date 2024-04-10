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
    long mod = (long)1e9 + 7;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        int k = sc.nextInt();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int leftInd[] = new int[n];
        Arrays.fill(leftInd, -1);

        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < n; ++i) {
            while(!stack.empty() && a[stack.peek()] < a[i])
                stack.pop();
            if(!stack.empty())
                leftInd[i] = stack.peek();
            stack.push(i);
        }

        int rightInd[] = new int[n];
        Arrays.fill(rightInd, n);

        stack = new Stack<>();
        for(int i = n - 1; i >= 0; --i) {
            while(!stack.empty() && a[stack.peek()] <= a[i])
                stack.pop();
            if(!stack.empty())
                rightInd[i] = stack.peek();
            stack.push(i);
        }

        int poss = 0;
        long cval = k;
        long list[];
        while(cval <= n) {
            poss++;
            cval += k - 1;
        }

        list = new long[poss];
        cval = k;
        for(int i = 0; i < poss; ++i) {
            list[i] = cval;
            cval += k - 1;
        }

        long prefixSum[] = new long[poss];
        prefixSum[0] = list[0];
        for(int i = 1; i < poss; ++i)
            prefixSum[i] = (prefixSum[i - 1] + list[i]) % mod;

        long prefix[] = new long[poss];
        for(int i = 0; i < poss; ++i) {
            long size = 2 * list[i] - 1;
            long req = list[i];
            prefix[i] = size - req + 1;
        }

        for(int i = 1; i < poss; ++i)
            prefix[i] = (prefix[i - 1] + prefix[i]) % mod;

        long ans = 0;

        for(int i = 0; i < n; ++i) {
            int lind, uind;
            int ind = i;
            long val = a[i];

            lind = leftInd[i];
            uind = rightInd[i];

            int size = uind - lind - 1;
            int lsize = ind - lind;
            int rsize = uind - ind;
            int minSize = min(lsize, rsize);
            int maxSize = max(lsize, rsize);

            int start = 0, end = poss - 1, indans = poss;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(list[mid] > minSize) {
                    indans = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            if(indans != 0)
                ans = (ans + prefix[indans - 1] * val % mod) % mod;

            if(indans == poss) 
                continue;

            int l1 = indans;
            if(list[l1] > size) 
                continue;

            start = 0;
            end = poss - 1;
            indans = poss;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(list[mid] > maxSize) {
                    indans = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            int l = indans;
            if(l != l1) {
                long ele = l - l1;
                ans = (ans + ele * minSize % mod * val % mod) % mod;
            }

            if(l == poss)
                continue;

            if(list[l] > size)
                continue;

            start = 0;
            end = poss - 1;
            indans = -1;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(list[mid] <= size) {
                    indans = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }

            if(indans == -1)
                continue;

            long cans = 0;

            if(indans >= l) {
                long ele = indans - l + 1;
                long ccans = ele * size % mod;
                ccans = (ccans + ele) % mod;
                long sub = prefix[indans];
                if(l != 0)
                    sub = (sub - prefix[l - 1] + mod) % mod;
                ccans = (ccans - sub + mod) % mod;
                cans = (ccans + cans) % mod;
            }

            ans = (ans + cans * val % mod) % mod;        
        }

        w.print(ans);

        w.close();   
    }
}

class Pair {
    int ind;
    long val;
    Pair(int a, long b) {
        ind = a;
        val = b;
    }
}