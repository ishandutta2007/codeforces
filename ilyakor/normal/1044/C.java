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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] X = new int[n];
            int[] Y = new int[n];
            int mx = Integer.MAX_VALUE, Mx = Integer.MIN_VALUE;
            int my = Integer.MAX_VALUE, My = Integer.MIN_VALUE;
            int mxi = -1, Mxi = -1, myi = -1, Myi = -1;
            for (int i = 0; i < n; ++i) {
                X[i] = in.nextInt();
                Y[i] = in.nextInt();
                if (X[i] < mx) {
                    mx = X[i];
                    mxi = i;
                }
                if (X[i] > Mx) {
                    Mx = X[i];
                    Mxi = i;
                }
                if (Y[i] < my) {
                    my = Y[i];
                    myi = i;
                }
                if (Y[i] > My) {
                    My = Y[i];
                    Myi = i;
                }
            }
            int res = 2 * (My - my + Mx - mx);
            int res3 = 0;
            int[] inds = new int[]{mxi, myi, Mxi, Myi};
            for (int i = 0; i < n; ++i) {
                for (int ji = 0; ji < inds.length; ++ji)
                    for (int ki = ji; ki < inds.length; ++ki) {
                        int j = inds[ji], k = inds[ki];
                        int cur = calc(X[i], X[j]) + calc(X[j], X[k]) + calc(X[k], X[i]) + calc(Y[i], Y[j]) + calc(Y[j], Y[k]) + calc(Y[k], Y[i]);
                        if (cur > res3) res3 = cur;
                    }
            }
            out.print(res3);
            for (int i = 4; i <= n; ++i)
                out.print(" " + res);
            out.printLine();
        }

        private int calc(int x1, int x2) {
            if (x1 >= x2) return x1 - x2;
            return x2 - x1;
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