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
        BDreamoonLikesSequences solver = new BDreamoonLikesSequences();
        solver.solve(1, in, out);
        out.close();
    }

    static class BDreamoonLikesSequences {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            for (int x = 0; x < t; ++x) {
                long d = sc.nextLong();
                long m = sc.nextLong();

                int largestBit = 0;
                for (int i = 0; i < 40; ++i) {
                    if (((d >> i) & 1) == 1)
                        largestBit = i + 1;
                }

                long dp[][] = new long[largestBit + 1][largestBit + 1];
                dp[0][0] = 1;
                for (int i = 1; i <= largestBit; ++i) {
                    long possibleValues = (1 << (i - 1));
                    if (i == largestBit)
                        possibleValues = (d ^ (1 << (i - 1))) + 1;

                    dp[i][0] = 1;
                    for (int j = 1; j <= i; ++j) {
                        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * possibleValues % m) % m;
//                    out.println(i + " " + j + " " + dp[i][j]);
                    }
                }

                long ans = 0;
                for (int i = 1; i <= largestBit; ++i)
                    ans = (ans + dp[largestBit][i]) % m;

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