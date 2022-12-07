import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        CPlatformsJumping solver = new CPlatformsJumping();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPlatformsJumping {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int d = sc.nextInt();

            int c[] = new int[m];
            for (int i = 0; i < m; ++i) {
                c[i] = sc.nextInt();
            }
            int plank[] = new int[n];
            Arrays.fill(plank, -1);
            int last[] = new int[m];
            int ind = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < c[i]; ++j) {
                    plank[ind] = i;
                    ind++;
                }
                last[i] = ind - 1;
            }
            int lastPlank = m - 1;
            int lastStep = n;
            for (int i = n - 1; i >= 0; --i) {
                if ((lastStep - i) == d && plank[i] == -1) {
                    int curPlank = lastPlank;

                    if (curPlank == -1) {
                        out.print("NO");
                        return;
                    }

                    lastPlank--;

                    for (int j = 0; j < c[curPlank]; ++j)
                        plank[last[curPlank] - j] = -1;
                    for (int j = 0; j < c[curPlank]; ++j) {
                        plank[i - j] = curPlank;
                    }
                }
                if (plank[i] != -1)
                    lastStep = i;
            }

            out.println("YES");
            for (int i = 0; i < n; ++i) {
                out.print((plank[i] + 1) + " ");
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