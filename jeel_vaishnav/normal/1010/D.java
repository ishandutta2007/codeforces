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
    void dfsCheckSignificance(int i, int significant) {
        sig[i] = significant;
        if(node[i].type.equals("IN")) {
            return;
        }
        else if(node[i].type.equals("NOT")) {
            dfsCheckSignificance(node[i].val[0], significant);
            return;
        }
        else if(node[i].type.equals("AND")) {
            if(val[i] == 0 && val[i] == val[node[i].val[0]] && val[i] == val[node[i].val[1]])
                return;

            if(val[i] == 1) {
                dfsCheckSignificance(node[i].val[0], significant);
                dfsCheckSignificance(node[i].val[1], significant);
                return;
            }

            if(val[i] == val[node[i].val[0]])
                dfsCheckSignificance(node[i].val[0], significant);
            else 
                dfsCheckSignificance(node[i].val[0], 0);

            if(val[i] == val[node[i].val[1]])
                dfsCheckSignificance(node[i].val[1], significant);
            else 
                dfsCheckSignificance(node[i].val[1], 0);
        }
        else if(node[i].type.equals("OR")) {
            if(val[i] == 1 && val[i] == val[node[i].val[0]] && val[i] == val[node[i].val[1]])
                return;

            if(val[i] == 0) {
                dfsCheckSignificance(node[i].val[0], significant);
                dfsCheckSignificance(node[i].val[1], significant);
                return;
            }

            if(val[i] == val[node[i].val[0]])
                dfsCheckSignificance(node[i].val[0], significant);
            else 
                dfsCheckSignificance(node[i].val[0], 0);

            if(val[i] == val[node[i].val[1]])
                dfsCheckSignificance(node[i].val[1], significant);
            else 
                dfsCheckSignificance(node[i].val[1], 0);
        }
        else {
            dfsCheckSignificance(node[i].val[0], significant);
            dfsCheckSignificance(node[i].val[1], significant);
            return;
        }
    }
    void dfsFindVal(int i) {
        if(node[i].type.equals("IN")) {
            val[i] = node[i].val[0];
            return;
        }
        else if(node[i].type.equals("NOT")) {
            dfsFindVal(node[i].val[0]);
            val[i] = 1 ^ val[node[i].val[0]];
            return;
        }
        else if(node[i].type.equals("XOR")) {
            dfsFindVal(node[i].val[0]);
            dfsFindVal(node[i].val[1]);
            val[i] = val[node[i].val[1]] ^ val[node[i].val[0]];
            return;
        }
        else if(node[i].type.equals("OR")) {
            dfsFindVal(node[i].val[0]);
            dfsFindVal(node[i].val[1]);
            val[i] = val[node[i].val[1]] | val[node[i].val[0]];
            return;
        }
        else {
            dfsFindVal(node[i].val[0]);
            dfsFindVal(node[i].val[1]);
            val[i] = val[node[i].val[1]] & val[node[i].val[0]];
            return;
        }
    }
    int val[];
    int sig[];
    Node node[];
    public void run() {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();
        node = new Node[n];

        for(int i = 0; i < n; ++i) {
            String type = sc.next();
            int val[] = new int[2];
            if(type.equals("IN"))
                val[0] = sc.nextInt();
            else if(type.equals("NOT"))
                val[0] = sc.nextInt() - 1;
            else {
                for(int j = 0; j < 2; ++j)
                    val[j] = sc.nextInt() - 1;
            }
            node[i] = new Node(type, val);
        }

        val = new int[n];
        dfsFindVal(0);

        sig = new int[n];
        dfsCheckSignificance(0, 1);

        for(int i = 0; i < n; ++i) {
            if(node[i].type.equals("IN"))
                w.print(sig[i] ^ val[0]);        
        }
 
        w.close();   
    }
}
class Node {
    String type;
    int val[] = new int[2];
    Node(String a, int[] val) {
        type = a;
        this.val = val;
    }
}