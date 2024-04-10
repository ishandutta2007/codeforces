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
    
    public static void main(String args[]) throws Exception {
        new Thread(null, new Main(),"Main",1<<26).start();
    } 
    void dfsFindParent(int i, int par) {
        parent[i][0] = par;
        for(int k = 0; k < adj[i].length; ++k) {
            if(adj[i][k] != par)
                dfsFindParent(adj[i][k], i);
        }
    }
    int parent[][];
    int adj[][];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();
        int k = sc.nextInt();

        int u[] = new int[n - 1];
        int v[] = new int[n - 1];
        int deg[] = new int[n];
        adj =  new int[n][];
        for(int i = 0; i < n - 1; ++i) {
            u[i] = sc.nextInt() - 1;
            v[i] = sc.nextInt() - 1;
            deg[u[i]]++;
            deg[v[i]]++;
        } 

        for(int i = 0; i < n; ++i) {
            adj[i] = new int[deg[i]];
        } 

        int ptr[] = new int[n];
        for(int i = 0; i < n - 1; ++i) {
            adj[u[i]][ptr[u[i]]++] = v[i];
            adj[v[i]][ptr[v[i]]++] = u[i];
        }

        parent = new int[n][20];
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < 20; ++j)
                parent[i][j] = -1;

        dfsFindParent(n - 1, -1);
        for(int i = 1; i < 20; ++i) {
            for(int j = 0; j < n; ++j) {
                if(parent[j][i - 1] != -1)
                    parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }

        char vis[] = new char[n];
        for(int i = 0; i < n; ++i)
            vis[i] = '0';
        int alr = 1;
        vis[n - 1] = '1';

        int cnt, curNode;
        for(int i = n - 2; i >= 0; --i) {
            if(vis[i] == '1')
                continue;

            cnt = 1;
            curNode = i;
            for(int j = 19; j >= 0; --j) {
                if(parent[curNode][j] != -1 && vis[parent[curNode][j]] == '0') {
                    cnt += (1 << j);
                    curNode = parent[curNode][j];
                }
            }

            if(cnt + alr <= n - k) {
                curNode = i;
                alr += cnt;
                while(vis[curNode] == '0') {
                    vis[curNode] = '1';
                    curNode = parent[curNode][0];
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(vis[i] == '0') 
                w.print((i + 1) + " ");
        }

        w.close();
    }
}