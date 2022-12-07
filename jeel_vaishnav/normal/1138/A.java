import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ASushiForTwo solver = new ASushiForTwo();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASushiForTwo {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            int a[] = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextInt();

            int prefix[] = new int[n];
            prefix[0] = 1;
            for (int i = 1; i < n; ++i) {
                if (a[i] != a[i - 1])
                    prefix[i] = 1;
                else
                    prefix[i] = prefix[i - 1] + 1;
            }

            int suffix[] = new int[n];
            suffix[n - 1] = 1;
            for (int i = n - 2; i >= 0; --i) {
                if (a[i] != a[i + 1])
                    suffix[i] = 1;
                else
                    suffix[i] = suffix[i + 1] + 1;
            }

            int ans = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (a[i] != a[i + 1]) {
                    ans = Math.max(ans, 2 * Math.min(prefix[i], suffix[i + 1]));
                }
            }

            out.print(ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
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

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}