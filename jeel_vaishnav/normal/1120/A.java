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

        int m = sc.nextInt();
        int k = sc.nextInt();
        int n = sc.nextInt();
        int s = sc.nextInt();

        int a[] = new int[m];
        for(int i = 0; i < m; ++i)
            a[i] = sc.nextInt();

        int reqFreq[] = new int[500001];
        int b[] = new int[s];
        for(int i = 0; i < s; ++i) {
            b[i] = sc.nextInt();
            reqFreq[b[i]]++;
        }

        int req = n * k;
        int size = m - (n - 1) * k;

        int curFreq[] = new int[500001];
        int score = 0;
        for(int i = 0; i <= 500000; ++i) {
            if(reqFreq[i] == 0) {
                score++;
            }
        }
        for(int i  = 0; i < size - 1; ++i) {
            curFreq[a[i]]++;
            if(reqFreq[a[i]] == curFreq[a[i]])
                score++;
        }

        for(int i = size - 1; i < m; ++i) {
            curFreq[a[i]]++;
            if(reqFreq[a[i]] == curFreq[a[i]])
                score++;

            int ind = i - size + 1;

            if(score == 500001 && ind % k == 0) {
                ArrayList<Integer> ans = new ArrayList<>();
                int left = k - s;
                for(int j = ind; j <= i; ++j) {
                    if(reqFreq[a[j]] > 0) {
                        reqFreq[a[j]]--;
                    }
                    else if(left > 0)
                        left--;
                    else
                        ans.add((j + 1));
                }

                w.println(ans.size());
                for(int j : ans)
                    w.print(j + " ");
                w.close();
                return;
            }

            if(reqFreq[a[ind]] == curFreq[a[ind]])
                score--;
            curFreq[a[ind]]--;
        }

        w.print("-1");

        w.close();
    }
}