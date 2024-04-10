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
        DMinimumEulerCycle solver = new DMinimumEulerCycle();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMinimumEulerCycle {
        long getValue(long batch, long ind, long n) {
            long lastValue = (batch - 1) * (2 * (n - 1) + 1 - (batch - 1));

            long curInd = ind - lastValue;

            if (curInd % 2 == 1)
                return batch;
            else
                return batch + curInd / 2;
        }

        long getBatch(long ind, long n) {
            long l = 1, r = n - 1, ans = n - 1;

            while (l <= r) {
                long mid = (l + r) >> 1;
                long value = mid * (2 * (n - 1) + 1 - mid);

                if (value >= ind) {
                    ans = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }

            return ans;
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            for (int x = 0; x < t; ++x) {
                long n = sc.nextLong();
                long l = sc.nextLong();
                long r = sc.nextLong();

                long tot = n * (n - 1) + 1;

                for (long i = l; i <= r; ++i) {
                    if (i == tot)
                        out.print("1 ");
                    else if (i == tot - 1)
                        out.print(n + " ");
                    else {
                        long batch = getBatch(i, n);
                        out.print(getValue(batch, i, n) + " ");
                    }
                }

                out.println();
            }
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