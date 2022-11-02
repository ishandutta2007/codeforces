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
            int a00 = in.nextInt();
            int a01 = in.nextInt();
            int a10 = in.nextInt();
            int a11 = in.nextInt();
            int cnt0 = triang(a00);
            int cnt1 = triang(a11);
            if (cnt0 == -1 || cnt1 == -1) {
                out.printLine("Impossible");
                return;
            }
            if (a00 == 0 && a01 == 0 && a10 == 0) {
                for (int i = 0; i < cnt1; ++i)
                    out.print("1");
                out.printLine();
                return;
            }
            if (a11 == 0 && a01 == 0 && a10 == 0) {
                for (int i = 0; i < cnt0; ++i)
                    out.print("0");
                out.printLine();
                return;
            }
            long numPairs = a01 + a10;
            if (numPairs != (long) cnt0 * (long) cnt1) {
                out.printLine("Impossible");
                return;
            }
            int rem1 = cnt1;
            int pos = 0;
            while (pos < cnt0 || rem1 > 0) {
                if (pos < cnt0 && a01 >= rem1) {
                    out.print("0");
                    ++pos;
                    a01 -= rem1;
                } else {
                    out.print("1");
                    --rem1;
                }
            }
            out.printLine();
        }

        private int triang(int n) {
            int res = 1;
            while (res * (res - 1) / 2 < n) ++res;
            if (res * (res - 1) / 2 != n) return -1;
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