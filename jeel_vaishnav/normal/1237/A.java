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
        ABalancedRatingChanges solver = new ABalancedRatingChanges();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABalancedRatingChanges {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            int a[] = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextInt();

            int type[] = new int[n];
            int val[] = new int[n];
            int possum = 0, negsum = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] > 0) {
                    type[i] = 1;
                    val[i] = a[i];
                    possum += a[i] / 2;
                } else {
                    type[i] = -1;
                    val[i] = -a[i];
                    negsum += val[i] / 2;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (possum > negsum) {
                    if (type[i] == -1 && val[i] % 2 == 1) {
                        negsum++;
                        val[i]++;
                    }
                } else if (possum < negsum) {
                    if (type[i] == 1 && val[i] % 2 == 1) {
                        possum++;
                        val[i]++;
                    }
                }
            }

            for (int i = 0; i < n; ++i)
                out.println(type[i] * (val[i] / 2));
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