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
    public void run()
    {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);

        int n = sc.nextInt();

        char s[][] = new char[n][];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next().toCharArray();

        Queue<Integer> queue = new LinkedList<>();
        ArrayList<Integer> adj[] = new ArrayList[26];
        for(int i = 0; i < 26; ++i)
            adj[i] = new ArrayList<>();

        int inDegree[] = new int[26];
        for(int i = 0; i < n; ++i) {
            upper : for(int j = i + 1; j < n; ++j) {
                        for(int k = 0; k < min(s[i].length, s[j].length); ++k) {
                            if(s[i][k] != s[j][k]) {
                                adj[s[i][k] - 'a'].add(s[j][k] - 'a');
                                inDegree[s[j][k] - 'a']++;
                                continue upper;
                            }
                        }
                        if(s[i].length > s[j].length) {
                            w.print("Impossible");
                            w.close();
                            return;
                        }
                    }
        } 

        int cnt = 0;
        for(int i = 0; i < 26; ++i) {
            if(inDegree[i] == 0) {
                cnt++;
                queue.add(i);
            }
        }

        ArrayList<Character> topoSort = new ArrayList<>();
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            topoSort.add((char)('a' + cur));
            for(int j : adj[cur]) {
                inDegree[j]--;
                if(inDegree[j] == 0) {
                    cnt++;
                    queue.add(j);
                }
            }
        }

        if(cnt != 26)
            w.print("Impossible");
        else {
            for(char i : topoSort)
                w.print(i);
        }

        w.close();
    }
}