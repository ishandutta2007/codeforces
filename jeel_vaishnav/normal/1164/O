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

        for(int x = 0; x < t; x++) {
            int n = sc.nextInt();

            int weight[][] = new int[n][n];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j)
                    weight[i][j] = sc.nextInt();
            }

            w.println("B");
            w.flush();

            char type = sc.next().charAt(0);
            int node = sc.nextInt() - 1;

            int situation = 0;
            if(node >= n)
                situation ^= 1;

            if(type == 'D') {
                situation ^= 1;
            }

            int preferences[][] = new int[2 * n][n];

            if(situation == 0) {
                for(int i = 0; i < n; ++i) {
                    Pair p[] = new Pair[n];
                    for(int j = 0; j < n; ++j) {
                        p[j] = new Pair(n + j, weight[i][j]);
                    }
                    Arrays.sort(p, new Comparator<Pair>() {
                        public int compare(Pair p1, Pair p2) {
                            return p1.val - p2.val;
                        }
                    });
                    for(int j = 0; j < n; ++j)
                        preferences[i][j] = p[j].ind;
                }

                for(int i = 0; i < n; ++i) {
                    Pair p[] = new Pair[n];
                    for(int j = 0; j < n; ++j) {
                        p[j] = new Pair(j, weight[j][i]);
                    }
                    Arrays.sort(p, new Comparator<Pair>() {
                        public int compare(Pair p1, Pair p2) {
                            return p2.val - p1.val;
                        }
                    });

                    for(int j = 0; j < n; ++j)
                        preferences[n + i][j] = p[j].ind;
                }
            }
            else {
                for(int i = 0; i < n; ++i) {
                    Pair p[] = new Pair[n];
                    for(int j = 0; j < n; ++j) {
                        p[j] = new Pair(n + j, weight[i][j]);
                    }
                    Arrays.sort(p, new Comparator<Pair>() {
                        public int compare(Pair p1, Pair p2) {
                            return p2.val - p1.val;
                        }
                    });
                    for(int j = 0; j < n; ++j)
                        preferences[i][j] = p[j].ind;
                }

                for(int i = 0; i < n; ++i) {
                    Pair p[] = new Pair[n];
                    for(int j = 0; j < n; ++j) {
                        p[j] = new Pair(j, weight[j][i]);
                    }
                    Arrays.sort(p, new Comparator<Pair>() {
                        public int compare(Pair p1, Pair p2) {
                            return p1.val - p2.val;
                        }
                    });

                    for(int j = 0; j < n; ++j)
                        preferences[n + i][j] = p[j].ind;
                }
            }

            int match[] = StableMarriage.findStableMarriage(preferences);
            while(node != -2) {
                w.println((match[node] + 1));
                w.flush();
                node = sc.nextInt() - 1; 
            }
        }

        w.close();
    }
}
class Pair {
    int ind, val;
    Pair(int a, int b) {
        ind = a;
        val = b;
    }
}
class StableMarriage {
    static int[] findStableMarriage(int[][] preferences) {
        // Also known as Gale-Shapley algorithm

        // 0 - (n - 1) ids are man, rest are woman
        // preferences is a 2n (first n man and last n woman) x n matrix which gives person id's sorted rank wise
        // match is an array of size 2*n - matched person for each id

        int n = preferences.length / 2;

        int[] match = new int[2 * n];
        Arrays.fill(match, -1);

        // A rank matrix of n x n, determines rank of each man for each woman
        int rank[][] = new int[n][n];
        for(int j = n; j < 2 * n; ++j) {
            for(int i = 0; i < n; ++i) {
                rank[j - n][preferences[j][i]] = i;
            }
        }

        Queue<Integer> notMatched = new LinkedList<>();
        for(int i = 0; i < n; ++i)
            notMatched.add(i);

        int nextRankToBeProposed[] = new int[n];

        while(!notMatched.isEmpty()) {
            int ind = notMatched.poll(); // current man who will propose

            while(true) {
                int j = preferences[ind][nextRankToBeProposed[ind]++]; // woman to be proposed

                if(match[j] == -1) { // if woman not matched yet
                    match[ind] = j;
                    match[j] = ind;
                    break;
                }
                else if(rank[j - n][match[j]] > rank[j - n][ind]) { // if this man more preferable
                    match[match[j]] = -1;
                    notMatched.add(match[j]); // previous man needs to propose again
                    match[ind] = j;
                    match[j] = ind;
                    break;
                }
            }
        }

        // if(!stable(preferences, match))
        //     System.out.println("Wrong code");

        return match;
    }
    static boolean stable(int[][] preferences, int[] match) {
        int n = match.length / 2;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(match[i] == j + n)
                    continue;

                int flag = 0;
                for(int k = 0; k < n; ++k) {
                    if(preferences[i][k] == match[i])
                        break;

                    if(preferences[i][k] == j + n) {
                        flag++;
                        break;
                    }
                }
                for(int k = 0; k < n; ++k) {
                    if(preferences[j + n][k] == match[j + n])
                        break;

                    if(preferences[j + n][k] == i) {
                        flag++;
                        break;
                    }
                }
                if(flag == 2)
                    return false;
            }
        }

        return true;
    }
}