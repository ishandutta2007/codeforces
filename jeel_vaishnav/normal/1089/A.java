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
    void findWays(int pos, int len, int totalA, int totalB) {
        if(pos == len) {
            int total[] = new int[2];
            total[0] = totalA;
            total[1] = totalB;
            int cnt[] = new int[2];
            for(int i = 0; i < len; ++i) {
                cnt[winner[i]]++;
            }

            if(max(cnt[0], cnt[1]) != 3)
                return;

            if(cnt[0] > cnt[1] && winner[len - 1] != 0)
                return;

            if(cnt[1] > cnt[0] && winner[len - 1] != 1)
                return;

            int scores[][] = new int[2][len];

            for(int i = 0; i < len; ++i) {
                if(i == 4) {
                    scores[winner[i]][i] += 15;
                    total[winner[i]] -= 15;
                }
                else {
                    scores[winner[i]][i] += 25;
                    total[winner[i]] -= 25;
                }
            }

            //System.out.println(winner[0] + " " + winner[1] + " " + winner[2] + " " + cnt[0] + " " + cnt[1] + " " + total[0] + " " + total[1]);

            if(total[0] < 0 || total[1] < 0)
                return;

            int possExt[] = new int[2];
            for(int i = 0; i < len; ++i) {
                if(i == 4) {
                    possExt[winner[i] ^ 1] += 13;
                }
                else {
                    possExt[winner[i] ^ 1] += 23;
                }
            }

            int both = max(0, max(total[0] - possExt[0], total[1] - possExt[1]));
            int bothFlag = 0;

            if(both > 0) {
                bothFlag = 1;
            }

            int hasOneFull = 0;
            total[0] -= both;
            total[1] -= both;

            if(total[0] < 0 || total[1] < 0)
                return;

            for(int i = len - 1; i >= 0; --i) {
                if(winner[i] == 1) {
                    if(i == 4) {
                        int poss = min(13, total[0]);
                        total[0] -= poss;
                        scores[0][i] += poss;
                        if(poss == 13 && hasOneFull == 0) {
                            hasOneFull = 1;
                            scores[0][i] += both;
                            scores[1][i] += both; 
                        }
                    }
                    else {
                        int poss = min(23, total[0]);
                        total[0] -= poss;
                        scores[0][i] += poss;
                        if(poss == 23 && hasOneFull == 0) {
                            hasOneFull = 1;
                            scores[0][i] += both;
                            scores[1][i] += both; 
                        }
                    }
                }
                else {
                    if(i == 4) {
                        int poss = min(13, total[1]);
                        total[1] -= poss;
                        scores[1][i] += poss;
                        if(poss == 13 && hasOneFull == 0) {
                            hasOneFull = 1;
                            scores[0][i] += both;
                            scores[1][i] += both; 
                        }
                    }
                    else {
                        int poss = min(23, total[1]);
                        total[1] -= poss;
                        scores[1][i] += poss;
                        if(poss == 23 && hasOneFull == 0) {
                            hasOneFull = 1;
                            scores[0][i] += both;
                            scores[1][i] += both; 
                        }
                    }
                }
            }

            if(bothFlag == 1 && hasOneFull == 0)
                return;

            if(total[0] != 0 || total[1] != 0)
                return;

            int curScore = cnt[0] - cnt[1];
            if(curScore > score) {
                score = curScore;
                scoreA = cnt[0];
                scoreB = cnt[1];
                ans = new Tests();
                for(int i = 0; i < len; ++i) {
                    ans.list.add(new Test(scores[0][i], scores[1][i]));
                }
            }

            return;
        }
        winner[pos] = 0;
        findWays(pos + 1, len, totalA, totalB);
        winner[pos] = 1;
        findWays(pos + 1, len, totalA, totalB);
    }
    int winner[] = new int[5];
    int score;
    int scoreA, scoreB;
    Tests ans;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int t = sc.nextInt();

        for(int x = 0; x < t; ++x) {
            int total[] = new int[2];
            total[0] = sc.nextInt();
            total[1] = sc.nextInt();

            score = Integer.MIN_VALUE;

            findWays(0, 3, total[0], total[1]);
            findWays(0, 4, total[0], total[1]);
            findWays(0, 5, total[0], total[1]);

            if(score == Integer.MIN_VALUE) {
                w.println("Impossible");
            }
            else {
                w.println(scoreA + ":" + scoreB);
                for(Test i : ans.list) {
                    w.print(i.scoreA + ":" + i.scoreB + " ");
                }
                w.println();
            }
        }

        w.close();
    }
}
class Tests {
    ArrayList<Test> list = new ArrayList<>();
}
class Test {
    int scoreA, scoreB;
    Test(int a, int b) {
        scoreA = a;
        scoreB = b;
    }
}