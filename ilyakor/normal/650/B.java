import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            int T = in.nextInt();
            char[] s = in.nextToken().toCharArray();
            int[] d = new int[n];
            for (int i = 0; i < n; ++i) {
                d[i] = a;
                if (s[i] == 'w')
                    d[i] += b;
            }
            d[0] -= a;
            if (d[0] + 1 > T) {
                out.printLine(0);
                return;
            }
            int res = 0;
            for (int it = 0; it < 2; ++it) {
                int l = 0, lval = d[0] + 1;
                while (l < n && lval <= T) {
                    ++l;
                    lval += d[n - l] + 1;
                }
                if (l == n && lval <= T) {
                    res = l;
                    break;
                }
                int r = 0, rval = 0;
                while (l > 0) {
                    lval -= d[n - l] + 1;
                    --l;
                    while (r < n && lval + rval + a * l <= T) {
                        ++r;
                        rval += d[r] + 1;
                    }
                    int cnt = l + 1;
                    if (r > 0) {
                        if (lval + rval + a * l <= T)
                            cnt += r;
                        else
                            cnt += r - 1;
                    }
                    if (cnt > n) cnt = n;
                    if (res < cnt) res = cnt;
                }

                for (int i = 1; i < (n + 1) / 2; ++i) {
                    int j = n - i;
                    int tmp = d[i];
                    d[i] = d[j];
                    d[j] = tmp;
                }
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
}