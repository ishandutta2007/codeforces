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
    void addQuery(ArrayList<Query> list, int u, int v) {
        int x1 = u / m;
        int y1 = u % m;
        int x2 = v / m;
        int y2 = v % m;

        if(x1 == x2 || y1 == y2)
            list.add(new Query(u, v));
        else {
            int intermediateInd;

            if(x1 < x2)
                intermediateInd = x1 * m + y2;
            else
                intermediateInd = x2 * m + y1;

            list.add(new Query(u, intermediateInd));
            list.add(new Query(intermediateInd, v));
        }
    }    
    int m;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        m = sc.nextInt();

        char[][] s = new char[n * m][];

        Point[] p = new Point[n * m];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                p[i * m + j] = new Point(i + 1, j + 1);
                s[i * m + j] = sc.next().toCharArray();
            }
        }

        char[][] a = new char[n * m][];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                a[i * m + j] = sc.next().toCharArray();
            }
        }

        int ind0 = 0, ind1 = m + 1, useInd = m;

        char[] temp = new char[s[ind0].length + s[ind1].length + s[useInd].length];
        for(int i = 0; i < s[ind0].length; ++i)
            temp[i] = s[ind0][i];
        for(int i = 0; i < s[ind1].length; ++i)
            temp[s[ind0].length + i] = s[ind1][i];
        for(int i = 0; i < s[useInd].length; ++i)
            temp[s[ind0].length + s[ind1].length + i] = s[useInd][i];

        s[useInd] = temp;

        ArrayList<Query> list = new ArrayList<>(); 
        for(int i = 0; i < s[ind1].length; ++i)
            list.add(new Query(ind1, useInd));
        for(int i = 0; i < s[ind0].length; ++i)
            list.add(new Query(ind0, useInd));

        int cnt0 = 0, cnt1 = 0;

        for(int i = 0; i < n * m; ++i) {
            if(i == ind1 || i == ind0)
                continue;
            for(int j = s[i].length - 1; j >= 0; --j) {
                if(s[i][j] == '0') {
                    cnt0++;
                    addQuery(list, i, ind0);
                }
                if(s[i][j] == '1') {
                    cnt1++;
                    addQuery(list, i, ind1);
                }
            }
        }      

        for(int i = n * m - 1; i >= 0; --i) {
            if(i == ind1 || i == ind0 || i == useInd)
                continue;
            for(int j = a[i].length - 1; j >= 0; --j) {
                if(a[i][j] == '0') {
                    cnt0--;
                    addQuery(list, ind0, i);
                }
                else {
                    cnt1--;
                    addQuery(list, ind1, i);
                }
            }
        }

        for(int j = a[ind0].length - 1; j >= 0; --j) {
            if(a[ind0][j] == '0') {
                list.add(new Query(ind0, useInd));
                list.add(new Query(useInd, ind0));
            }
            else {
                list.add(new Query(ind1, useInd));
                list.add(new Query(useInd, ind0));
            }
        }

        for(int j = a[ind1].length - 1; j >= 0; --j) {
            if(a[ind1][j] == '1') {
                list.add(new Query(ind1, useInd));
                list.add(new Query(useInd, ind1));
            }
            else {
                list.add(new Query(ind0, useInd));
                list.add(new Query(useInd, ind1));
            }
        }

        for(int j = a[useInd].length - 1; j >= 0; --j) {
            if(a[useInd][j] == '0')
                list.add(new Query(ind0, useInd));
            else
                list.add(new Query(ind1, useInd));
        }

        w.println(list.size());

        for(Query q : list) {
            int x1 = p[q.ind1].x;
            int y1 = p[q.ind1].y;
            int x2 = p[q.ind2].x;
            int y2 = p[q.ind2].y;
            w.println(x1 + " " + y1 + " " + x2 + " " + y2);
        }

        w.close();
    }
}
class Query {
    int ind1, ind2;
    Query(int a, int b) {
        ind1 = a;
        ind2 = b;
    }
}
class Point {
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
    }
}