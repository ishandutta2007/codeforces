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

        int m = sc.nextInt();
        int n = sc.nextInt();

        int a[] = new int[n];

        for(int i = 0; i < m; ++i) {
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            a[l]++;
            if(r < n)
                a[r]--;
        }

        for(int i = 1; i < n; ++i)
            a[i] = a[i - 1] + a[i];

        int smallestEle[] = new int[n];
        smallestEle[0] = a[0];
        int lis[] = new int[n];
        lis[0] = 1;
        int curLength = 1;

        for(int i = 1; i < n; ++i) {
            //w.println("LIS : " + i + " " + curLength + " " + smallestEle[curLength - 1]);
            if(a[i] >= smallestEle[curLength - 1]) 
                smallestEle[curLength++] = a[i];
            else {
                int start = 0, end = curLength - 2, pos = -1;
                while(start <= end) {
                    int mid = (start + end) >> 1;
                    if(a[i] >= smallestEle[mid]) {
                        pos = mid;
                        start = mid + 1;
                    }
                    else
                        end = mid - 1;
                }
                smallestEle[pos + 1] = a[i];
            }
            lis[i] = curLength;
        }

        smallestEle = new int[n];
        smallestEle[0] = a[n - 1];
        int lds[] = new int[n];
        lds[n - 1] = 1;
        curLength = 1;

        for(int i = n - 2; i >= 0; --i) {
            if(a[i] >= smallestEle[curLength - 1])
                smallestEle[curLength++] = a[i];
            else {
                int start = 0, end = curLength - 2, pos = -1;
                while(start <= end) {
                    int mid = (start + end) >> 1;
                    if(a[i] >= smallestEle[mid]) {
                        pos = mid;
                        start = mid + 1;
                    }
                    else
                        end = mid - 1;
                }
                smallestEle[pos + 1] = a[i];
            }
            lds[i] = curLength;
        }

        /*for(int i = 0; i < n; ++i)
            w.print(a[i] + " ");
        w.println();
        for(int i = 0; i < n; ++i)
            w.print(lis[i] + " ");
        w.println();
        for(int i = 0; i < n; ++i)
            w.print(lds[i] + " ");      
        w.println(); */

        int maxid = lds[0];

        for(int i = 1; i < n; ++i) 
            maxid = max(maxid, lis[i - 1] + lds[i]);

        w.print(maxid);

        w.close();      
    }
}