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
        try {
        InputReader sc = new InputReader(new FileInputStream("input.txt"));
        PrintWriter w = new PrintWriter(new File("output.txt"));

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        int freq[] = new int[26];
        for(int i = 0; i < t.length; ++i) {
            freq[t[i] - 'A']++;
        }

        int freq2[] = new int[26];
        for(int i = 0; i < s.length; ++i) {
            freq2[s[i] - 'A']++;
        }

        int cnt[] = new int[26];
        int req[] = new int[26];
        int moves = 0;
        for(int i = 0; i < 26; ++i) {
            if(freq2[i] > freq[i]) {
                cnt[i] = freq2[i] - freq[i];
                moves += cnt[i];
            }
            if(freq2[i] < freq[i])
                req[i] = freq[i] - freq2[i];
        }

        int curInd[] = new int[26];
        Arrays.fill(curInd, 1);
        int ind[] = new int[s.length];
        for(int i = s.length - 1; i >= 0; --i) {
            ind[i] = curInd[s[i] - 'A'];
            curInd[s[i] - 'A']++;
        }

        for(int i = 0; i < 26; ++i) {
            int rightCnt = 0;
            for(int j = i + 1; j < 26; ++j)
                rightCnt += cnt[j];
            if(freq[i] > freq2[i]) {
                for(int j = 0; j < s.length && req[i] > 0 && rightCnt > 0; ++j) {
                    if(s[j] - 'A' > i && cnt[s[j] - 'A'] > 0) {
                        cnt[s[j] - 'A']--;
                        s[j] = (char)('A' + i);
                        req[i]--;
                        rightCnt--;
                    }
                    else if(ind[j] <= cnt[s[j] - 'A']) {
                        cnt[s[j] - 'A']--;
                        s[j] = (char)('A' + i);
                        req[i]--;
                    }
                }
            }
        }

        for(int i = 25; i >= 0; --i) {
            for(int j = s.length - 1; j >= 0 && req[i] > 0; --j) {
                if(cnt[s[j] - 'A'] > 0) {
                    cnt[s[j] - 'A']--;
                    s[j] = (char)('A' + i);
                    req[i]--;
                }
            }
        }

        w.println(moves);
        w.print(s);

        w.close(); }catch(Exception e) {System.out.println(e.toString());}     
    }
}