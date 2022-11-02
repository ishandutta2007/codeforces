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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.nextInt();
            int k = in.nextInt();
            int n = in.nextInt();
            int s = in.nextInt();
            int[] a = new int[m];
            for (int i = 0; i < m; ++i) {
                a[i] = in.nextInt();
            }
            int[] next = new int[m];
            int[] pos = new int[570 * 1000];
            Arrays.fill(pos, m);
            for (int i = m - 1; i >= 0; --i) {
                next[i] = pos[a[i]];
                pos[a[i]] = i;
            }

            int[] right = new int[570 * 1000];
            int[] B = new int[570 * 1000];
            Arrays.fill(right, -1);
            int R = -1;
            for (int i = 0; i < s; ++i) {
                int x = in.nextInt();
                ++B[x];
                if (right[x] == -1) right[x] = pos[x];
                else if (right[x] < m) right[x] = next[right[x]];
                if (right[x] > R) R = right[x];
            }
            int res = m + 1, lx = -1, rx = -1;
            for (int i = 0; i <= m; ++i) {
                int r = Math.max(R, i + k - 1);
                if (r < m) {
                    int pref = i / k;
                    int suf = (m - 1 - r) / k;
                    if (pref + suf + 1 >= n) {
                        int cur = r - i + 1 - k + i % k;
                        if (res > cur) {
                            res = cur;
                            lx = i;
                            rx = r;
                        }
                    }
                }
                if (i < m) {
                    int x = a[i];
                    if (right[x] == -1) right[x] = pos[x];
                    else if (right[x] < m) right[x] = next[right[x]];
                    if (right[x] > R) R = right[x];
                }
            }
            if (res > m) res = -1;
            out.printLine(res);
            if (res != -1) {
                int need = res;
                for (int i = 0; i < lx % k; ++i) {
                    out.print((i + 1) + " ");
                    --need;
                }
                for (int i = lx; i <= rx; ++i) {
                    if (B[a[i]] > 0) {
                        --B[a[i]];
                    } else if (need > 0) {
                        --need;
                        out.print((i + 1) + " ");
                    }
                }
                out.printLine();
                if (need != 0) throw new RuntimeException();
            }
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