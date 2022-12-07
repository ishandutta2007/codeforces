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
 * @author Sanket Makani
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ProblemA1DeathStarsEasy solver = new ProblemA1DeathStarsEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class ProblemA1DeathStarsEasy {
        public void solve(int testNumber, InputReader sc, PrintWriter w) {
            int n = sc.nextInt();

            char map1[][] = new char[n][n];
            char map2[][] = new char[n][n];

            for (int i = 0; i < n; i++)
                map1[i] = sc.next().toCharArray();
            for (int i = 0; i < n; i++)
                map2[i] = sc.next().toCharArray();
            int flag = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[i][j])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;


            //90 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[j][n - i - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //180 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - i - 1][n - j - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //270 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - j - 1][i])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            flipVertically(map2);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[i][j])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;


            //90 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[j][n - i - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //180 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - i - 1][n - j - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //270 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - j - 1][i])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            flipVertically(map2);

            flipHorizontally(map2);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[i][j])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;


            //90 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[j][n - i - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //180 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - i - 1][n - j - 1])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            flag = 0;

            //270 degree
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map1[i][j] != map2[n - j - 1][i])
                        flag++;
                }
            }

            if (flag == 0) {
                w.println("Yes");
                return;
            }

            w.println("No");
        }

        private void flipHorizontally(char[][] map2) {
            int n = map2.length;
            char copy[][] = new char[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    copy[i][j] = map2[i][j];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map2[i][j] = copy[i][n - j - 1];
                }
            }
        }

        private void flipVertically(char[][] map2) {
            int n = map2.length;
            char copy[][] = new char[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    copy[i][j] = map2[i][j];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map2[i][j] = copy[n - i - 1][j];
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