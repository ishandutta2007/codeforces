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

        int t = sc.nextInt();

        main : for(int x = 0; x < t; ++x) {
            char[] s = sc.next().toCharArray();
            int n = s.length;

            int freq[] = new int[26];
            for(int i = 0; i < n; ++i) {
                freq[s[i] - 'a']++;
            }

            ArrayList<Integer> list = new ArrayList<>();
            for(int i = 0; i < 26; ++i) {
                if(freq[i] > 0)
                    list.add(i);
            }

            if(list.size() == 2) {
                if(list.get(0) == list.get(1) - 1) {
                    w.println("No answer");
                    continue main;
                }
            }
            else if(list.size() == 3) {
                if(list.get(0) == list.get(1) - 1) {
                    if(list.get(1) == list.get(2) - 1) {
                        w.println("No answer");
                        continue main;
                    }

                    char p = (char)(list.get(0) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    p = (char)(list.get(2) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    p = (char)(list.get(1) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    w.println();
                    continue main;
                }
                else if(list.get(1) == list.get(2) - 1) {
                    char p = (char)(list.get(2) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    p = (char)(list.get(0) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    p = (char)(list.get(1) + 'a');
                    for(int i = 0; i < freq[p - 'a']; ++i)
                        w.print(p);
                    w.println();
                    continue main;
                }
            }

            for(int i = list.size() - 2; i >= 0; i -= 2) {
                char p = (char)(list.get(i) + 'a');
                for(int j = 0; j < freq[p - 'a']; ++j)
                    w.print(p);
            }
            for(int i = list.size() - 1; i >= 0; i -= 2) {
                char p = (char)(list.get(i) + 'a');
                for(int j = 0; j < freq[p - 'a']; ++j)
                    w.print(p);
            }
            w.println();
        }

        w.close();
    }
}