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
        ASinglePush solver = new ASinglePush();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASinglePush {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            main:
            for (int x = 0; x < t; ++x) {
                int n = sc.nextInt();

                int a[] = new int[n];
                for (int i = 0; i < n; ++i)
                    a[i] = sc.nextInt();
                int b[] = new int[n];
                for (int i = 0; i < n; ++i)
                    b[i] = sc.nextInt();

                int req[] = new int[n];
                for (int i = 0; i < n; ++i)
                    req[i] = b[i] - a[i];

                int flag = 0, reqVal = -1;
                for (int i = 0; i < n; ++i) {
                    if (req[i] < 0) {
                        out.println("NO");
                        continue main;
                    }

                    if (req[i] != 0) {
                        if (flag == 0) {
                            flag = 1;
                            reqVal = req[i];
                        } else if (flag == 1) {
                            if (req[i] != reqVal) {
                                out.println("NO");
                                continue main;
                            }
                        } else {
                            out.println("NO");
                            continue main;
                        }
                    } else {
                        if (flag == 1)
                            flag = 2;
                    }
                }
                out.println("YES");
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