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
    long queryBit(long[] bit, int ind) {
        long cans = 0;
        while(ind > 0) {
            cans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return cans;
    }
    void updateBit(long[] bit, int ind) {
        while(ind < bit.length) {
            bit[ind]++;
            ind += Integer.lowestOneBit(ind);
        }
    }
    long bit[][];
    public void run()
    {
        InputReader sc = new InputReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        double w = sc.nextDouble();
        double x[] = new double[n];
        double v[] = new double[n];

        Plane[] a = new Plane[n];
        TreeMap<Double, Integer> map = new TreeMap<>();

        for(int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
            v[i] = sc.nextDouble();
            a[i] = new Plane(x[i], v[i], w);
            map.put(a[i].time, 1);
            map.put(a[i].timef1, 1);
            map.put(a[i].timef2, 1);
        }

        int cur = 1;
        for(double i : map.keySet()) 
            map.put(i, cur++);

        for(int i = 0; i < n; ++i) {
            a[i].time = map.get(a[i].time);
            a[i].timef1 = map.get(a[i].timef1);
            a[i].timef2 = map.get(a[i].timef2);
        }

        Arrays.sort(a, new Comparator<Plane>() {
            public int compare(Plane p1, Plane p2) {
                if(p1.time > p2.time)
                    return -1;
                if(p1.time < p2.time)
                    return 1;
                return 0;
            }
        });

        bit = new long[3][cur];
        long ans = 0;

        for(int i = 0; i < n; ++i) {
            long cans = queryBit(bit[0], (int)a[i].timef1) + queryBit(bit[1], (int)a[i].timef2) - queryBit(bit[2], (int)min(a[i].timef1, a[i].timef2));
            ans += cans;
            updateBit(bit[0], (int)a[i].timef1);
            updateBit(bit[1], (int)a[i].timef2);
            updateBit(bit[2], (int)max(a[i].timef1, a[i].timef2));
        }

        pw.print(ans);

        pw.close();
    }
}
class Plane {
    double x, v, time, timef1, timef2;
    Plane(double a, double b, double w) {
        x = a;
        v = b;
        time = -x / v;
        timef1 = -x / (v + w);
        timef2 = -x / (v - w);
    }
}