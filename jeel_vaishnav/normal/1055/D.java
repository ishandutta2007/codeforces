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
    char[] dupli(char[] s) {
        char[] ans = new char[s.length];
        for(int i = 0; i < s.length; ++i)
            ans[i] = s[i];
        return ans;
    }
    void resolve(ArrayList<Character> left, ArrayList<Character> right) {
        char[] t1 = dupli(t);
        char[] r1 = dupli(r);

        t = new char[t1.length + left.size() + right.size()];
        r = new char[r1.length + left.size() + right.size()];

        int ptr = 0;
        for(int i = left.size() - 1; i >= 0; --i) {
            t[ptr] = left.get(i);
            r[ptr++] = left.get(i);
        }

        for(int i = 0; i < t1.length; ++i) {
            t[ptr] = t1[i];
            r[ptr++] = r1[i];
        }

        for(int i = 0; i < right.size(); ++i) {
            t[ptr] = right.get(i);
            r[ptr++] = right.get(i);
        }
    }
    char[] t = new char[1];
    char[] r = new char[1];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        char s[][] = new char[2 * n][];

        for(int i = 0; i < 2 * n; ++i)
            s[i] = sc.next().toCharArray();

        int changedFlag = 0;

        ArrayList<Character> left = new ArrayList<>();
        ArrayList<Character> right = new ArrayList<>();

        for(int i = 0; i < n; ++i) {
            int ind[] = new int[s[i].length];
            int flag = 0;
            int minInd = -1, maxInd = -1;
            for(int j = 0; j < s[i].length; ++j) {
                if(s[i][j] != s[n + i][j]) {
                    flag = 1;
                    if(minInd == -1)
                        minInd = j;
                    maxInd = j;
                }
            }

            if(flag == 1) {
                if(changedFlag == 0) {
                    t = new char[maxInd - minInd + 1];
                    r = new char[maxInd - minInd + 1];
                    int ptr = 0;
                    for(int j = minInd; j <= maxInd; ++j) {
                        r[ptr] = s[n + i][j];
                        t[ptr++] = s[i][j];
                    }
                    for(int j = minInd - 1; j >= 0; --j)
                        left.add(s[i][j]);
                    for(int j = maxInd + 1; j < s[i].length; ++j)
                        right.add(s[i][j]);
                    changedFlag = 1;
                }
                else if(maxInd - minInd + 1 != t.length) {
                    w.print("NO");
                    w.close();
                    return;
                }
                else {
                    int ptr = 0;
                    for(int j = minInd; j <= maxInd; ++j) {
                        if(s[i][j] != t[ptr] || s[n + i][j] != r[ptr]) {
                            w.print("NO");
                            w.close();
                            return;
                        }
                        ptr++;
                    }

                    int leftSize = 0;
                    for(int j = 0; j < left.size(); ++j) {
                        if(minInd - 1 - j < 0)
                            break;
                        if(left.get(j) != s[i][minInd - 1 - j])
                            break;
                        leftSize++;
                    }

                    while(left.size() != leftSize)
                        left.remove(left.size() - 1);

                    int rightSize = 0;
                    for(int j = 0; j < right.size(); ++j) {
                        if(maxInd + 1 + j >= s[i].length)
                            break;
                        if(right.get(j) != s[i][maxInd + 1 + j])
                            break;
                        rightSize++;
                    }

                    while(right.size() != rightSize)
                        right.remove(right.size() - 1);
                }
            }
        }

        resolve(left, right);

        KMP k = new KMP();

        int flag = 0;

        for(int i = 0; i < n; ++i) {
            int minInd = k.findMinInd(s[i], t);

            char[] a = new char[s[i].length];
            for(int j = 0; j < s[i].length; ++j)
                a[j] = s[i][j];

            if(minInd != -1) {
                int ptr = 0;
                for(int j = minInd - t.length + 1; j <= minInd; ++j) {
                    a[j] = r[ptr++];
                } 
            }

            for(int j = 0; j < s[i].length; ++j) {
                if(a[j] != s[n + i][j])
                    flag = 1;
            }
        }
        if(flag == 1) {
            w.print("NO");
        }
        else {
            w.println("YES");
            w.println(t);
            w.println(r);
        }

        w.close();
    }
}
class KMP {
    int findMinInd(char[] s, char[] t) {
        int[] lcp = new int[t.length];

        createLCP(t, lcp);

        int j = 0, ans = 0;
        for(int i = 0; i < s.length; ++i) {
            while(j != 0 && s[i] != t[j])
                j = lcp[j - 1] + 1;

            if(s[i] == t[j]) {
                j++;
                
                if(j == t.length) {
                    return i;
                }
            }
        }

        return -1;
    }

    void createLCP(char[] t, int[] lcp) {
        lcp[0] = -1;
        
        int j = 0;
        for(int i = 1; i < t.length; ++i) {
            while(j != 0 && t[i] != t[j]) 
                j = lcp[j - 1] + 1;

            if(t[i] == t[j]) {
                lcp[i] = j;
                j++;
            }
            else
                lcp[i] = -1;
        }
    }
}