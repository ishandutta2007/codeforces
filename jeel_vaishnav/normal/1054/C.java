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
    void dfs(int i) {
        vis[i] = 2;
        for(int j : adj[i]) {
            if(vis[j] == 2)
                cycle = 1;
            if(vis[j] == 0)
                dfs(j);
        }
        vis[i] = 1;
    }
    int vis[];
    int cycle = 0;
    ArrayList<Integer> adj[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        
        int l[] = new int[n];
        int r[] = new int[n];

        for(int i = 0; i < n; ++i) 
            l[i] = sc.nextInt();

        for(int i = 0; i < n; ++i)
            r[i] = sc.nextInt();

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        int deg[] = new int[n];

        for(int i = 0; i < n; ++i) {
            int cnt = r[i];
            for(int j = i + 1; j < n; ++j) {
                if(r[j] < cnt) {
                    cnt--;
                    adj[i].add(j);
                    deg[j]++;
                }
                else if(r[j] > cnt) {
                    adj[j].add(i);
                    deg[i]++;
                }
            }
        }

        for(int i = n - 1; i >= 0; --i) {
            int cnt = l[i];
            for(int j = i - 1; j >= 0; --j) {
                if(l[j] < cnt) {
                    cnt--;
                    adj[i].add(j);
                    deg[j]++;
                }
                else if(l[j] > cnt) {
                    adj[j].add(i);
                    deg[i]++;
                }
            }
        }

        vis = new int[n];
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                dfs(i);
            }
        }

        if(cycle == 1)
            w.print("NO");
        else {
            Queue<Integer> queue = new LinkedList<>();
            int a[] = new int[n];
            Arrays.fill(a, -1);
            for(int i = 0; i < n; ++i) {
                if(deg[i] == 0) {
                    a[i] = 1;
                    queue.add(i);
                }
            }

            while(!queue.isEmpty()) {
                int curInd = queue.poll();

                for(int j : adj[curInd]) {
                    deg[j]--;

                    if(deg[j] == 0) {
                        a[j] = a[curInd] + 1;
                        queue.add(j);
                    }
                }
            }

            int newL[] = new int[n];
            int newR[] = new int[n];
            int flag = 0;

            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(a[j] > a[i])
                        newR[i]++;
                }
                for(int j = i - 1; j >= 0; --j) {
                    if(a[j] > a[i])
                        newL[i]++;
                }

                if(newL[i] != l[i] || newR[i] != r[i])
                    flag = 1;
            }

            if(flag == 1)
                w.print("NO");
            else {
                w.println("YES");
                for(int i = 0; i < n; ++i)
                    w.print(a[i] + " ");
            }
        }

        w.close();
    }
}