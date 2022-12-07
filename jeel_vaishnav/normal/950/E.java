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
    void dfsFindSCC(int i, ArrayList<Integer> list, int par) {
        vis[i] = 1;
        parent[i] = par;
        for(int j : rev[i].keySet()) {
            if(vis[j] == 0)
                dfsFindSCC(j, list, par);
        }
        list.add(i);
    }
    void dfsFindTopo(int i) {
        vis[i] = 1;
        for(int j : adj[i].keySet()) {
            if(vis[j] == 0)
                dfsFindTopo(j);
        }
        topoSort.add(i);
    }
    HashMap<Integer, Integer> adj[];
    HashMap<Integer, Integer> rev[];
    ArrayList<Integer> topoSort = new ArrayList<>();
    int vis[];
    int parent[];
    public void run() {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int h = sc.nextInt();

        parent = new int[n];

        adj = new HashMap[n];
        for(int i = 0; i < n; ++i)
            adj[i] = new HashMap<>();

        rev = new HashMap[n];
        for(int i = 0; i < n; ++i)
            rev[i] = new HashMap<>();

        int a[] = new int[n];

        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        for(int i = 0; i < m; ++i) {
            int c1 = sc.nextInt() - 1;
            int c2 = sc.nextInt() - 1;

            if((a[c1] + 1) % h == a[c2]) {
                adj[c1].put(c2, 1);
                rev[c2].put(c1, 1);
            }
            if((a[c2] + 1) % h == a[c1]) {
                adj[c2].put(c1, 1);
                rev[c1].put(c2, 1);
            }
        }

        vis = new int[n];
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) 
                dfsFindTopo(i);
        }

        ArrayList<ArrayList<Integer>> scc = new ArrayList<>();

        int cnt = 0;
        vis = new int[n];
        for(int i = topoSort.size() - 1; i >= 0; --i) {
            int ele = topoSort.get(i);
            if(vis[ele] == 0) {
                scc.add(new ArrayList<>());
                dfsFindSCC(ele, scc.get(scc.size() - 1), cnt++);
            }
        }

        int ans = n + 1;
        ArrayList<Integer> anslist = new ArrayList<>();

        main : for(ArrayList<Integer> i : scc) {
            int par = parent[i.get(0)];
            for(int j : i) {
                for(int k : adj[j].keySet()) {
                    if(parent[k] != par)
                        continue main;
                }
            }   
            if(i.size() < ans) {
                ans = i.size();
                anslist = i;
            }
        }

        w.println(ans);
        for(int i : anslist)
            w.print((i + 1) + " ");

        w.close();      
    }
}