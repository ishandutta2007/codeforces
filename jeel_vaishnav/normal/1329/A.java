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
 * @author Corona
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ADreamoonLikesColoring solver = new ADreamoonLikesColoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADreamoonLikesColoring {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int l[] = new int[m];
            for (int i = 0; i < m; ++i)
                l[i] = sc.nextInt();

            long sum = 0;
            for (int i = 0; i < m; ++i)
                sum += l[i];

            if (sum < n) {
                out.print("-1");
                return;
            }

            int minReq[] = new int[m];
            minReq[0] = 0;
            for (int i = 1; i < m; ++i) {
                minReq[i] = Math.min(minReq[i - 1] + l[i - 1], n - 1);
            }

            int p[] = new int[m];
            int lastInd = n;
            for (int i = m - 1; i >= 0; --i) {
                int reqInd = Math.min(n - l[i], lastInd - 1);
                if (reqInd < 0) {
                    out.print("-1");
                    return;
                }

                if (minReq[i] < reqInd)
                    reqInd = minReq[i];
                p[i] = reqInd;
                lastInd = reqInd;
            }

            for (int i = 0; i < m; ++i)
                out.print((p[i] + 1) + " ");
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