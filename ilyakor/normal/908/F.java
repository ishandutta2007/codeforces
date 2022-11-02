import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int inf = 1010 * 1000 * 1000;
        int[] a;
        int[] type;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            a = new int[n];
            type = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                char c = in.nextToken().charAt(0);
                if (c == 'R') type[i] = 0;
                else if (c == 'B') type[i] = 1;
                else {
                    Assert.assertTrue(c == 'G');
                    type[i] = 2;
                }
            }

            long res = 0;

            int pg = -inf;
            int l0 = inf, r0 = -inf, g0 = 0;
            int l1 = inf, r1 = -inf, g1 = 0;
            for (int i = 0; i < n; ++i) {
                if (type[i] == 0) {
                    if (l0 == inf) l0 = a[i];
                    else g0 = Math.max(g0, a[i] - r0);
                    r0 = a[i];
                    continue;
                }
                if (type[i] == 1) {
                    if (l1 == inf) l1 = a[i];
                    else g1 = Math.max(g1, a[i] - r1);
                    r1 = a[i];
                    continue;
                }

                if (pg == -inf) {
                    if (l0 != inf) res += a[i] - l0;
                    if (l1 != inf) res += a[i] - l1;
                    pg = a[i];
                    l0 = inf;
                    r0 = -inf;
                    g0 = 0;
                    l1 = inf;
                    r1 = -inf;
                    g1 = 0;
                    continue;
                }

                int delta = a[i] - pg;
                boolean connect = false;
                if (l0 == inf || l1 == inf) {
                    connect = true;
                } else {
                    int save0 = Math.max(g0, Math.max(l0 - pg, a[i] - r0));
                    int save1 = Math.max(g1, Math.max(l1 - pg, a[i] - r1));
                    if (save0 + save1 > delta) connect = true;
                }
                if (connect) {
                    res += delta;
                    if (l0 != inf)
                        res += delta - Math.max(g0, Math.max(l0 - pg, a[i] - r0));
                    if (l1 != inf)
                        res += delta - Math.max(g1, Math.max(l1 - pg, a[i] - r1));
                } else {
                    res += delta;
                    res += delta;
                }

                pg = a[i];
                l0 = inf;
                r0 = -inf;
                g0 = 0;
                l1 = inf;
                r1 = -inf;
                g1 = 0;
            }
            if (pg == -inf) {
                if (l0 != inf) res += r0 - l0;
                if (l1 != inf) res += r1 - l1;
            } else {
                if (l0 != inf)
                    res += r0 - pg;
                if (l1 != inf)
                    res += r1 - pg;
            }

            out.printLine(res);
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

        public String nextToken() {
            int c = readSkipSpace();
            StringBuilder sb = new StringBuilder();
            while (!isSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
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

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }
}