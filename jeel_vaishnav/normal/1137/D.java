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
    boolean contains(char[] s, int i) {
        for(int j = 0; j < s.length; ++j) {
            if(s[j] - '0' == i) 
                return true;
        }
        return false;
    }
    boolean isTogetherStored(int[] a) {
        int k = cache.length;

        boolean mainFlag = false;

        for(int i = 0; i < k; ++i) {
            int flag = 0;
            char[] s = cache[i];
            for(int j = 0; j < a.length; ++j) {
                if(!contains(s, a[j]))
                    flag = 1;
            }
            if(flag == 0) {
                mainFlag = true;
            }
        }

        return mainFlag;
    }
    boolean isTogether(int[] a) {
        int k = sc.nextInt();
        cache = new char[k][];

        boolean mainFlag = false;

        for(int i = 0; i < k; ++i) {
            int flag = 0;
            char[] s = sc.next().toCharArray();
            cache[i] = s;
            for(int j = 0; j < a.length; ++j) {
                if(!contains(s, a[j]))
                    flag = 1;
            }
            if(flag == 0) {
                mainFlag = true;
            }
        }

        return mainFlag;
    }
    char[][] cache;
    void move(int[] a) {
        System.out.print("next ");
        for(int i : a)
            System.out.print(i + " ");
        System.out.println();
        System.out.flush();
    }
    InputReader sc;
    public void run() {
        sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int step = 1;
        while(true) {
            if(step % 2 == 1) {
                int[] arr = new int[]{0};
                move(arr);
            }
            else {
                int[] arr = new int[]{0, 1};
                move(arr);
            }

            int[] arr = new int[]{0, 1};
            if(isTogether(arr))
                break;

            step++;
        }

        while(true) {
            int[] arr = new int[]{0, 2};
            move(arr);

            arr = new int[]{0, 1};
            if(isTogether(arr))
                break;
        }

        while(true) {
            int[] arr = new int[]{2, 3, 4, 5, 6, 7, 8, 9};
            move(arr);

            if(isTogether(arr)) {
                break;
            }
        }

        int[] temp = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        while(!isTogetherStored(temp)) {
            int[] arr = new int[]{0, 1};
            move(arr);

            isTogether(arr);
        }

        System.out.println("done");
        System.out.flush();

        w.close();
    }
}