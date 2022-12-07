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
    void updateBit(int ind, int val) {
        while(ind < bit.length) {
            if(bit[ind] == 0)
                bit[ind] = val;
            else if(r[val - 1] > r[bit[ind] - 1])
                bit[ind] = val;
            ind += Integer.lowestOneBit(ind);
        }
    }

    int queryBit(int ind) {
        int cans = 0;
        while(ind > 0) {
            if(cans == 0)
                cans = bit[ind];
            else if(bit[ind] != 0 && r[bit[ind] - 1] > r[cans - 1])
                cans = bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return cans;
    } 
    int n;
    int l[], r[];
    int bit[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int n = sc.nextInt();

        l = new int[n];
        r = new int[n];

        TreeMap<Integer, Integer> map = new TreeMap<>();

        for(int i = 0; i < n; ++i) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
            map.put(l[i], 1);
            map.put(r[i], 1);
        }

        int cur = 1;
        for(int i : map.keySet()) {
            map.put(i, cur++);
        }

        bit = new int[cur];
        for(int i = 0; i < n; ++i) {
            l[i] = map.get(l[i]);
            r[i] = map.get(r[i]);

            int maxInd = queryBit(l[i]);
            if(maxInd != 0 && r[maxInd - 1] >= r[i]) {
                w.print((i + 1) + " " + maxInd);
                w.close();
                return;
            }

            updateBit(l[i], i + 1);
        }

        bit = new int[cur];
        for(int i = n - 1; i >= 0; --i) {
            int maxInd = queryBit(l[i]);
            if(maxInd != 0 && r[maxInd - 1] >= r[i]) {
                w.print((i + 1) + " " + maxInd);
                w.close();
                return;
            }

            updateBit(l[i], i + 1);
        }

        w.print("-1 -1");

        w.close();
    }
}