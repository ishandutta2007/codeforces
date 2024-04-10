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
    public void run() {
        InputReader sc= new InputReader(System.in);
        PrintWriter w= new PrintWriter(System.out);

        char[] s = sc.next().toCharArray();

        char[] t = sc.next().toCharArray();

        int cntbc[] = new int[s.length];
        if(s[0] == 'B' || s[0] == 'C')
            cntbc[0]++;
        for(int i = 1; i < s.length; ++i) {
            cntbc[i] = cntbc[i - 1];
            if(s[i] == 'B' || s[i] == 'C')
                cntbc[i]++;
        }

        int lastA[] = new int[s.length];
        if(s[0] == 'A')
            lastA[0]++;
        for(int i = 1; i < s.length; ++i) {
            if(s[i] == 'A') 
                lastA[i] = lastA[i - 1] + 1;
            else
                lastA[i] = 0;
        }

        int cntbc2[] = new int[t.length];
        if(t[0] == 'B' || t[0] == 'C')
            cntbc2[0]++;
        for(int i = 1; i < t.length; ++i) {
            cntbc2[i] = cntbc2[i - 1];
            if(t[i] == 'B' || t[i] == 'C')
                cntbc2[i]++;
        }

        int lastA2[] = new int[t.length];
        if(t[0] == 'A')
            lastA2[0] = 1;
        for(int i = 1; i < t.length; ++i) {
            if(t[i] == 'A')
                lastA2[i] = lastA2[i - 1] + 1;
            else
                lastA2[i] = 0;
        }

        int q = sc.nextInt();
        for(int x = 0; x < q; ++x) {
            int l1 = sc.nextInt() - 1;
            int r1 = sc.nextInt() - 1;
            int cntBC = cntbc[r1];
            if(l1 > 0)
                cntBC -= cntbc[l1 - 1];
            int clastA = lastA[r1];
            if(clastA > r1 - l1 + 1)
                clastA -= lastA[l1 - 1];

            int l2 = sc.nextInt() - 1;
            int r2 = sc.nextInt() - 1;
            int cntBC2 = cntbc2[r2];
            if(l2 > 0)
                cntBC2 -= cntbc2[l2 - 1];
            int clastA2 = lastA2[r2];
            if(clastA2 > r2 - l2 + 1)
                clastA2 -= lastA2[l2 - 1];
            if(cntBC2 < cntBC) {
                w.print("0");
                continue;
            }
            if((cntBC2 - cntBC) % 2 == 1) {
                w.print("0");
                continue;
            }
            if(clastA2 > clastA) {
                w.print("0");
                continue;
            }
            if(cntBC == cntBC2) {
                if((clastA - clastA2) % 3 == 0)
                    w.print("1");
                else
                    w.print("0");
            }
            else {
                if(cntBC == 0 && clastA == clastA2)
                    w.print("0");
                else  
                    w.print("1");
            }
        }

        w.close();      
    }
}