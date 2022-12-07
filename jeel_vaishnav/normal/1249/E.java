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
        EByElevatorOrStairs solver = new EByElevatorOrStairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class EByElevatorOrStairs {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            long c = sc.nextLong();
            long a[] = new long[n];
            long b[] = new long[n];
            for (int i = 0; i < n - 1; ++i)
                a[i] = sc.nextLong();
            for (int i = 0; i < n - 1; ++i)
                b[i] = sc.nextLong();
            long dp[][] = new long[n][2];
            dp[0][0] = 0;
            dp[0][1] = c;
            for (int i = 1; i < n; ++i) {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][0]) + a[i - 1];
                dp[i][1] = Math.min(dp[i - 1][1] + b[i - 1], dp[i - 1][0] + c + b[i - 1]);
            }
            for (int i = 0; i < n; ++i)
                out.print(Math.min(dp[i][0], dp[i][1]) + " ");
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