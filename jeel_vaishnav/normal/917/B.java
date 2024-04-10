import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Main implements Runnable
{
    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
        
        public int read()
        {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars)
            {
                curChar = 0;
                try 
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt()
        {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
            
            int sgn = 1;
            
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do 
            {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
            
            return res * sgn;
        }
        
        public long nextLong() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do 
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') 
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') 
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) 
                {
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
        
        public String readString() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do 
            {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) 
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next() 
        {
            return readString();
        }
        
        public interface SpaceCharFilter 
        {
            public boolean isSpaceChar(int ch);
        }
    }
    
    public static void main(String args[]) throws Exception
    {
        new Thread(null, new Main(),"Main",1<<26).start();
    }
    HashMap<Long, Integer> map = new HashMap<>();
    int play(int i, int j, int turn, char alr) {
        if(dp[i][j][turn][alr] != -1)
            return dp[i][j][turn][alr];
        HashMap<Integer, Integer> cmap = new HashMap<>();
        if(turn == 0) {
            for(Edge k : adj[i]) {
                if(k.c >= alr) 
                    cmap.put(play(k.dest, j, turn ^ 1, k.c), 1);
            }
        } 
        else {
            for(Edge k : adj[j]) {
                if(k.c >= alr) 
                    cmap.put(play(i, k.dest, turn ^ 1, k.c), 1);
            }
        }
        for(int p = 0; p < 1000; ++p) {
            if(cmap.get(p) == null) {
                dp[i][j][turn][alr] = p;
                return dp[i][j][turn][alr];
            }
        }
        return 0;
    }
    class Edge {
        int dest;
        char c;
        Edge(int a, char x) {
            dest = a;
            c = x;
        }
    }
    ArrayList<Edge> adj[];
    int dp[][][][];
    public void run()
    {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        dp = new int[n][n][2][130];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < 2; ++k) {
                    for(int l = 0; l < 130; ++l)
                        dp[i][j][k][l] = -1;
                }
            }
        }

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < m; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            char c = sc.next().charAt(0);
            adj[u].add(new Edge(v, c));
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int val = play(i, j, 0, '0');
                if(val != 0)
                    w.print('A');
                else
                    w.print('B');
            }
            w.println();
        }

        /*for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < 2; ++k) {
                    w.println(i + " " + j + " " + k + " 0 " + dp[i][j][k]['0']);
                    for(int l = 'a'; l <= 'c'; ++l)
                        w.println(i + " " + j + " " + k + " " + l + " " + dp[i][j][k][l]);
                }
            }
        }*/

        w.close();      
    }
}