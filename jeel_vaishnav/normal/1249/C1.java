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
        C2GoodNumbersHardVersion solver = new C2GoodNumbersHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2GoodNumbersHardVersion {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int q = sc.nextInt();

            long p3[] = new long[39];
            p3[0] = 1;
            for (int i = 1; i < 39; ++i)
                p3[i] = p3[i - 1] * 3L;

            for (int x = 0; x < q; ++x) {
                int sel[] = new int[39];
                long n = sc.nextLong();
                for (int i = 38; i >= 0; --i) {
                    if (n >= p3[i]) {
                        n -= p3[i];
                        sel[i] = 1;
                    }
                    if (n >= p3[i]) {
                        for (int j = i; j <= 38; ++j) {
                            if (sel[j] == 0) {
                                sel[j] = 1;
                                break;
                            } else
                                sel[j] = 0;
                        }
                        break;
                    }
                }

                long ans = 0;
                for (int i = 0; i < 39; ++i) {
                    if (sel[i] == 1)
                        ans += p3[i];
                }
                out.println(ans);
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