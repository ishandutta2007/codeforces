import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Collections;
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
            final long[] X = new long[n];
            final long[] Y = new long[n];
            ArrayList<Integer> a = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                X[i] = x;
                Y[i] = y - (long) x * (long) x;
                a.add(i);
            }
            Collections.sort(a, new Comparator<Integer>() {

                public int compare(Integer ind1, Integer ind2) {
                    int res = Long.compare(X[ind1], X[ind2]);
                    if (res != 0) return res;
                    return Long.compare(Y[ind1], Y[ind2]);
                }
            });


            int[] st = new int[n + 10];
            int ss = 0;
            for (int i1 = 0; i1 < a.size(); i1++) {
                int i = a.get(i1);
                if (i1 + 1 < a.size() && X[i] == X[a.get(i1 + 1)])
                    continue;
                while (ss >= 2 && bad(X[st[ss - 2]], Y[st[ss - 2]], X[st[ss - 1]], Y[st[ss - 1]], X[i], Y[i]))
                    --ss;
                st[ss++] = i;
            }
            out.printLine(Math.max(0, ss - 1));
        }

        private boolean bad(long x1, long y1, long x2, long y2, long x3, long y3) {
            long dx1 = x2 - x1;
            long dy1 = y2 - y1;
            long dx2 = x3 - x2;
            long dy2 = y3 - y2;
            return dx1 * dy2 - dx2 * dy1 >= 0;
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