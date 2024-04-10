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
            long[] X = new long[n];
            long[] Y = new long[n];
            for (int i = 0; i < n; ++i) {
                X[i] = in.nextLong();
                Y[i] = in.nextLong();
            }
            int ind1 = 0;
            int ind2 = 1;
            for (int i = 1; i < n; ++i) {
                long l1 = (X[ind2] - X[ind1]) * (X[ind2] - X[ind1]) + (Y[ind2] - Y[ind1]) * (Y[ind2] - Y[ind1]);
                long l2 = (X[i] - X[ind1]) * (X[i] - X[ind1]) + (Y[i] - Y[ind1]) * (Y[i] - Y[ind1]);
                if (l2 < l1) {
                    ind2 = i;
                }
            }
            int ind3 = 0;
            while (ind3 == ind1 || ind3 == ind2) ++ind3;
            long bestArea = Long.MAX_VALUE;
            for (int i = 0; i < n; ++i) {
                if (i == ind1) continue;
                if (i == ind2) continue;
                long dx1 = X[ind1] - X[i];
                long dy1 = Y[ind1] - Y[i];
                long dx2 = X[ind2] - X[i];
                long dy2 = Y[ind2] - Y[i];
                long area = Math.abs(dx1 * dy2 - dx2 * dy1);
                if (area == 0) continue;
                if (area < bestArea) {
                    bestArea = area;
                    ind3 = i;
                }
            }
            out.printLine((ind1 + 1) + " " + (ind2 + 1) + " " + (ind3 + 1));
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

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
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