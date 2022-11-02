import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public static final long inf = (long) (1E18);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int start = in.nextInt() - 1;
            int finish = in.nextInt() - 1;
            int[] X = new int[n + 1];
            for (int i = 0; i < n; ++i)
                X[i] = in.nextInt();
            X[n] = X[n - 1];
            int[] outLeft = new int[n];
            int[] outRight = new int[n];
            int[] inLeft = new int[n];
            int[] inRight = new int[n];
            for (int i = 0; i < n; ++i)
                inLeft[i] = in.nextInt();
            for (int i = 0; i < n; ++i)
                inRight[i] = in.nextInt();
            for (int i = 0; i < n; ++i)
                outLeft[i] = in.nextInt();
            for (int i = 0; i < n; ++i)
                outRight[i] = in.nextInt();
            long[] d = new long[n + 1];
            Arrays.fill(d, inf);
            d[0] = 0;
            for (int i = 0; i < n; ++i) {
                long[] nd = new long[n + 1];
                Arrays.fill(nd, inf);
                for (int toLeft = 0; toLeft <= n; ++toLeft) {
                    if (d[toLeft] == inf) continue;
                    int toRight = toLeft;
                    if (i > start) ++toRight;
                    if (i > finish) --toRight;
                    if (toRight < 0 || toRight > n - i) continue;
                    if (toLeft == 0 && toRight == 0 && i > 0) continue;
                    for (int inc = -1; inc <= 1; ++inc) {
                        if (inc == 0 && i != start) continue;
                        if (inc != 0 && i == start) continue;
                        for (int ou = -1; ou <= 1; ++ou) {
                            if (ou == 0 && i != finish) continue;
                            if (ou != 0 && i == finish) continue;

                            if (ou == -1 && toLeft == 0) continue;
                            if (inc == -1 && toRight == 0) continue;

                            long val = d[toLeft];
                            if (inc == -1) val += inLeft[i];
                            if (inc == 1) val += inRight[i];
                            if (ou == -1) val += outLeft[i];
                            if (ou == 1) val += outRight[i];
                            int deltaLeft = sgn(ou + inc);
                            int deltaRight = sgn(ou + inc);
                            if (inc == 0) {
                                deltaRight = ou == 1 ? 1 : 0;
                                deltaLeft = ou == -1 ? -1 : 0;
                            }
                            if (ou == 0) {
                                deltaRight = inc == -1 ? -1 : 0;
                                deltaLeft = inc == 1 ? 1 : 0;
                            }

                            int newToLeft = toLeft + deltaLeft;
                            int newToRight = toRight + deltaRight;
                            if (newToLeft < 0) continue;
                            if (newToRight < 0) continue;
                            val += (long) (newToLeft + newToRight) * (long) (X[i + 1] - X[i]);
                            if (nd[newToLeft] > val)
                                nd[newToLeft] = val;
                        }
                    }
                }
                d = nd;
            }
            out.printLine(d[0]);
        }

        private int sgn(int x) {
            if (x == 0) return 0;
            return x > 0 ? 1 : -1;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buffer = new byte[10000];
        private int cur;
        private int count;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (count == -1) {
                throw new InputMismatchException();
            }
            try {
                if (cur >= count) {
                    cur = 0;
                    count = stream.read(buffer);
                    if (count <= 0)
                        return -1;
                }
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            return buffer[cur++];
        }

        public int readSkipSpace() {
            int c;
            do {
                c = read();
            } while (isSpace(c));
            return c;
        }

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}