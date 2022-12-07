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
    // for changing datatype find char change to int and change 46th line
    void findLCP(char[] s) {
        int n = s.length;
        
        for(int i = 0; i < n; ++i) 
            rankOf[rankedAt[i]] = i;

        lcp = new int[n - 1];

        int k = 0;
        for(int i = 0; i < n; ++i) {
            if(rankOf[i] == n - 1)
                continue;
            int nextInd = rankedAt[rankOf[i] + 1];
            while(max(nextInd, i) + k < n && s[nextInd + k] == s[i + k])
                k++;
            lcp[rankOf[i]] = k;
            if(k > 0)
                k--;
        }
    }

    void findSuffixArray(char[] s) {
        int n = s.length;

        rankedAt = new int[n];
        rankOf = new int[n];

        //used integer for stable sorting so that similar characters with smaller length comes first
        Integer[] tempRankedAt = new Integer[n];
        for(int i = 0; i < n; ++i)
            tempRankedAt[i] = n - 1 - i;

        Arrays.sort(tempRankedAt, new Comparator<Integer>() {
            public int compare(Integer i1, Integer i2) {
                if(s[i1] < s[i2])
                    return -1;
                if(s[i1] > s[i2])
                    return 1;
                return 0;
            }
        });

        for(int i = 0; i < n; ++i) {
            rankedAt[i] = tempRankedAt[i];
            rankOf[i] = s[i] - 'a';
        }

        for(int len = 1; len < n; len *= 2) {
            int[] prevRankOf = rankOf.clone();
            for(int i = 0; i < n; ++i) {
                if(i == 0)
                    rankOf[rankedAt[i]] = i;
                else {
                    // No need to check rankedAt[i] as their prev ranks are same so ofc the one at higher rank will have larger string
                    if(rankedAt[i - 1] + len < n && prevRankOf[rankedAt[i]] == prevRankOf[rankedAt[i - 1]] && prevRankOf[rankedAt[i] + len / 2] == prevRankOf[rankedAt[i - 1] + len / 2])
                        rankOf[rankedAt[i]] = rankOf[rankedAt[i - 1]];
                    else
                        rankOf[rankedAt[i]] = i;
                }
            }
            int[] curRank = new int[n];
            for(int i = 0; i < n; ++i)
                curRank[i] = i;
            int[] prevRankedAt = rankedAt.clone();
            //radix sort
            for(int i = 0; i < n; ++i) {
                int ind = prevRankedAt[i] - len;
                if(ind >= 0) 
                    rankedAt[curRank[rankOf[ind]]++] = ind;
            }
        }
    }

    int[] rankedAt, rankOf, lcp;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();
        long k = sc.nextLong();

        findSuffixArray(s);
        findLCP(s);

        int n = s.length;

        long subStrings = (long)n * (long)(n + 1L) / 2L;
        if(subStrings < k) {
            w.print("No such line.");
            w.close();
            return;
        }

        ArrayList<Integer> adj[] = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        for(int i = 0; i < n - 1; ++i)
            adj[lcp[i]].add(i);

        long len[] = new long[n];
        for(int i = 0; i < n; ++i) {
            int ind = rankedAt[i];
            len[i] = s.length - ind;
            if(i != 0)
                len[i] += len[i - 1];
        }

        int l = 0, r = n - 1;
        ArrayList<Integer> indices = adj[0];
        for(int i = 0; i < n; ++i) {
            indices.add(r);
            int prev = l - 1;
            int cur = l - 1;
            for(int j : indices) {
                long curSize = len[j];
                if(prev != -1)
                    curSize -= len[prev];

                curSize -= i * (j - prev);

                cur = j;

                if(curSize >= k) {
                    break;
                }
                else {
                    k -= curSize;
                    prev = cur; 
                }
            }

            l = prev + 1;
            r = cur;
            if(k <= (r - l + 1)) {
                int ind = rankedAt[l];
                for(int j = 0; j <= i; ++j) {
                    w.print(s[ind + j]);
                }
                w.close();
                return;
            }
            k -= (r - l + 1);

            indices.clear();
            for(int j : adj[i + 1]) {
                if(j >= l && j <= r)
                    indices.add(j);
            }
        }

        w.close();
    }
}