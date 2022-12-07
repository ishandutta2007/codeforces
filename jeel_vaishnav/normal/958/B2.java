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
    PriorityQueue<Integer> dfs(int i, int par) {
        ArrayList<PriorityQueue<Integer>> list = new ArrayList<>();
        PriorityQueue<Integer> largestQueue = new PriorityQueue<>();
        int largestSize = 0;
        for(int j : adj[i]) {
            if(j != par) {
                PriorityQueue<Integer> cur = dfs(j, i);
                if(cur.size() > largestSize) {
                    if(largestSize != 0)
                        list.add(largestQueue);
                    largestQueue = cur;
                    largestSize = cur.size();
                }
                else {
                    list.add(cur);
                }
            }
        }

        if(largestSize == 0) {
            PriorityQueue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {
                public int compare(Integer i1, Integer i2) {
                    if(i1 > i2)
                        return -1;
                    if(i1 < i2)
                        return 1;
                    return 0;
                }
            });
            queue.add(1);
            cntLeaf++;
            return queue;
        }

        PriorityQueue<Integer> queue = largestQueue;
        for(int j = 0; j < list.size(); ++j) {
            PriorityQueue<Integer> cur = list.get(j);
            while(cur.size() != 0)
                queue.add(cur.poll());
        } 
        int maxV = queue.poll();
        queue.add(maxV + 1);
        return queue;
    }
    void dfsFindLevel(int i, int par, int level) {
        if(level > maxLevel) {
            maxLevel = level;
            maxNode = i;
        }
        for(int j : adj[i]) {
            if(j != par)
                dfsFindLevel(j, i, level + 1);
        }
    }
    ArrayList<Integer> adj[];
    int cntLeaf = 0;
    int maxLevel = -1, maxNode = -1;
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj[u].add(v);
            adj[v].add(u);
        }

        dfsFindLevel(0, -1, 0);

        PriorityQueue<Integer> queue = dfs(maxNode, -1);
        int maxV = queue.poll();
        queue.add(maxV - 1);

        int cans = 1;
        for(int i = 0; i < cntLeaf; ++i) {
            w.print(cans + " ");
            cans += queue.poll();
        }

        for(int i = cntLeaf; i < n; ++i)
            w.print(cans + " ");

        w.close();      
    }
}