import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            if (isPrime(n)) {
                out.println(1);
                out.println(n);
                return;
            }
            if (n % 2 == 0) {
                for (int i = 1; i <= n; i = i + 2)
                    if (isPrime(i) && isPrime(n - i)) {
                        out.println(2);
                        out.print(i);
                        out.print(' ');
                        out.println(n - i);
                        return;
                    }
                throw new RuntimeException();
            } else {
                for (int i = 1; i <= n - 3; i = i + 2)
                    if (isPrime(i) && isPrime(n - i - 3)) {
                        out.println(3);
                        out.print(i);
                        out.print(' ');
                        out.print(n - i - 3);
                        out.print(' ');
                        out.println(3);
                        return;
                    }
            }
        }

        private static boolean isPrime(int n) {
            return (BigInteger.valueOf(n).isProbablePrime(22));
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
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

    }
}