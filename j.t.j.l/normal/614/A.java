import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
    
    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
        	BigInteger l = in.nextBigInteger(), r = in.nextBigInteger(), k = in.nextBigInteger();
        	BigInteger j = k;
        	k = BigInteger.ONE;
        	while(k.compareTo(l) == -1)
        		k = k.multiply(j);
        	if (k.compareTo(r) == 1)
        		out.println(-1);
        	else{
	        	out.print(k);
	        	k = k.multiply(j);
	        	while(k.compareTo(r) != 1){
	        		out.print(' ');
	        		out.print(k);
	        		k = k.multiply(j);
	        	}
	        	out.println();
        	}
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
        
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        
        public BigInteger nextBigInteger() {
        	return new BigInteger(next());
        }
    }
	
}