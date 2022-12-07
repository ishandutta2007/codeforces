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
        EPolycarpAndSnakes solver = new EPolycarpAndSnakes();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPolycarpAndSnakes {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            main:
            for (int x = 0; x < t; ++x) {
                int n = sc.nextInt();
                int m = sc.nextInt();

                char[][] s = new char[n][];
                for (int i = 0; i < n; ++i)
                    s[i] = sc.next().toCharArray();

                int minX[] = new int[26];
                int minY[] = new int[26];
                int maxX[] = new int[26];
                int maxY[] = new int[26];

                Arrays.fill(minX, Integer.MAX_VALUE);
                Arrays.fill(maxX, Integer.MIN_VALUE);
                Arrays.fill(maxY, Integer.MIN_VALUE);
                Arrays.fill(minY, Integer.MAX_VALUE);

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (s[i][j] != '.') {
                            int ind = s[i][j] - 'a';
                            minX[ind] = Math.min(minX[ind], i);
                            maxX[ind] = Math.max(maxX[ind], i);
                            minY[ind] = Math.min(minY[ind], j);
                            maxY[ind] = Math.max(maxY[ind], j);
                        }
                    }
                }

                int cnt = 0;
                for (int i = 0; i < 26; ++i) {
                    if (minX[i] != Integer.MAX_VALUE) {
                        cnt = i + 1;
                    }
                }

                for (int i = 0; i < cnt; ++i) {
                    if (minX[i] == Integer.MAX_VALUE) {
                        minX[i] = minX[cnt - 1];
                        maxX[i] = minX[i];
                        minY[i] = minY[cnt - 1];
                        maxY[i] = minY[i];
                        continue;
                    }

                    if (minX[i] != maxX[i] && minY[i] != maxY[i]) {
                        out.println("NO");
                        continue main;
                    }

                    if (minX[i] != maxX[i]) {
                        for (int j = minX[i]; j <= maxX[i]; ++j) {
                            if (s[j][minY[i]] == '.' || s[j][minY[i]] - 'a' < i) {
                                out.println("NO");
                                continue main;
                            }
                        }
                    }

                    if (minY[i] != maxY[i]) {
                        for (int j = minY[i]; j <= maxY[i]; ++j) {
                            if (s[minX[i]][j] == '.' || s[minX[i]][j] - 'a' < i) {
                                out.println("NO");
                                continue main;
                            }
                        }
                    }
                }

                out.println("YES");
                out.println(cnt);
                for (int i = 0; i < cnt; ++i) {
                    out.println((minX[i] + 1) + " " + (minY[i] + 1) + " " + (maxX[i] + 1) + " " + (maxY[i] + 1));
                }
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}