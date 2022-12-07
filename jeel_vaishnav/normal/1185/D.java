import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        DExtraElement solver = new DExtraElement();
        solver.solve(1, in, out);
        out.close();
    }

    static class DExtraElement {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            Pair p[] = new Pair[n];
            for (int i = 0; i < n; ++i)
                p[i] = new Pair(sc.nextLong(), i + 1);

            Arrays.sort(p, new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    if (o1.ele < o2.ele)
                        return -1;
                    if (o1.ele > o2.ele)
                        return 1;
                    return 0;
                }
            });

            if (n == 2) {
                out.print("1");
                return;
            }

            long diff = p[1].ele - p[0].ele;
            int flag = 0;
            int ind = -1;
            long lastEle = p[1].ele;
            for (int i = 2; i < n; ++i) {
                if (p[i].ele - lastEle != diff) {
                    flag++;
                    ind = p[i].ind;
                } else
                    lastEle = p[i].ele;
            }

            if (flag == 0) {
                out.print(p[n - 1].ind);
                return;
            } else if (flag == 1) {
                out.print(ind);
                return;
            }

            diff = p[2].ele - p[0].ele;
            flag = 0;
            lastEle = p[2].ele;

            for (int i = 3; i < n; ++i) {
                if (p[i].ele - lastEle != diff) {
                    flag = 1;
                    break;
                }
                lastEle = p[i].ele;
            }

            if (flag == 0) {
                out.print(p[1].ind);
                return;
            }

            diff = p[2].ele - p[1].ele;
            flag = 0;
            lastEle = p[2].ele;

            for (int i = 3; i < n; ++i) {
                if (p[i].ele - lastEle != diff) {
                    flag = 1;
                    break;
                }
                lastEle = p[i].ele;
            }

            if (flag == 0) {
                out.print(p[0].ind);
                return;
            }

            out.print("-1");
        }

        class Pair {
            long ele;
            int ind;

            Pair(long a, int b) {
                ele = a;
                ind = b;
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