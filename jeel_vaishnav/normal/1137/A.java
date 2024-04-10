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
        int m = sc.nextInt();

        int a[][] = new int[n][m];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                a[i][j] = sc.nextInt();
        }

        int small[][] = new int[n][m];
        int large[][] = new int[n][m];

        for(int i = 0; i < n; ++i) {
            int arr[] = new int[m];
            for(int j = 0; j < m; ++j) {
                arr[j] = a[i][j];
            }
            Arrays.sort(arr);
            int cnt[] = new int[m];
            HashMap<Integer, Integer> smallVal = new HashMap<>();
            HashMap<Integer, Integer> largeVal = new HashMap<>();
            for(int j = 0; j < m; ++j) {
                if(j == 0)
                    cnt[j] = 1;
                else if(arr[j] != arr[j - 1])
                    cnt[j] = cnt[j - 1] + 1;
                else
                    cnt[j] = cnt[j - 1];
                smallVal.put(arr[j], cnt[j] - 1);
            }

            for(int j = m - 1; j >= 0; --j) {
                if(j == m - 1)
                    cnt[j] = 1;
                else if(arr[j] != arr[j + 1])
                    cnt[j] = cnt[j + 1] + 1;
                else
                    cnt[j] = cnt[j + 1];
                largeVal.put(arr[j], cnt[j] - 1);
            }

            for(int j = 0; j < m; ++j) {
                small[i][j] = smallVal.get(a[i][j]);
                large[i][j] = largeVal.get(a[i][j]);
            }
        }

        for(int i = 0; i < m; ++i) {
            int arr[] = new int[n];
            for(int j = 0; j < n; ++j) {
                arr[j] = a[j][i];
            }
            Arrays.sort(arr);
            int cnt[] = new int[n];
            HashMap<Integer, Integer> smallVal = new HashMap<>();
            HashMap<Integer, Integer> largeVal = new HashMap<>();
            for(int j = 0; j < n; ++j) {
                if(j == 0)
                    cnt[j] = 1;
                else if(arr[j] != arr[j - 1])
                    cnt[j] = cnt[j - 1] + 1;
                else
                    cnt[j] = cnt[j - 1];
                smallVal.put(arr[j], cnt[j] - 1);
            }

            for(int j = n - 1; j >= 0; --j) {
                if(j == n - 1)
                    cnt[j] = 1;
                else if(arr[j] != arr[j + 1])
                    cnt[j] = cnt[j + 1] + 1;
                else
                    cnt[j] = cnt[j + 1];
                largeVal.put(arr[j], cnt[j] - 1);
            }

            for(int j = 0; j < n; ++j) {
                small[j][i] = max(small[j][i], smallVal.get(a[j][i]));
                large[j][i] = max(large[j][i], largeVal.get(a[j][i]));
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int cans = small[i][j] + 1 + large[i][j];
                w.print(cans + " ");
            }
            w.println();
        }

        w.close();
    }
}