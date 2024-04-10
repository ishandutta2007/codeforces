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
    void dfs(int i, int par) {
        vis[i] = 1;
        if(par != -1) {
            if(a[i] < maxInd)
                ans.add(new Step(1, i, par));
            else
                ans.add(new Step(2, i, par));
        }
        if(i - 1 >= 0 && vis[i - 1] == 0 && a[i - 1] != maxInd)
            dfs(i - 1, i);
        if(i + 1 < n && vis[i + 1] == 0 && a[i + 1] != maxInd)
            dfs(i + 1, i);
    }
    int a[];
    int vis[];
    int maxInd;
    int n;
    ArrayList<Step> ans;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        n = sc.nextInt();

        a = new int[n];
        int freq[] = new int[200001];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            freq[a[i]]++;
        }

        maxInd = 0;
        for(int i = 1; i <= 200000; ++i) {
            if(freq[i] > freq[maxInd]) {
                maxInd = i;
            }
        }

        vis = new int[n];
        ans = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            if(a[i] == maxInd) {
                dfs(i, -1);
            }
        }

        w.println(ans.size());
        for(Step s : ans)
            w.println(s);
 
        w.close();
    }
}
class Step {
    int type, i, j;
    public String toString() {
        return type + " " + (i + 1) + " " + (j + 1);
    }
    Step(int a, int b, int c) {
        type = a;
        i = b;
        j = c;
    }
}