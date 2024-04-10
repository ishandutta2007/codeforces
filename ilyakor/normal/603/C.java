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
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = in.nextInt();
//        int[] d = new int[10000];
//        for (int i = 1; i < d.length; ++i) {
//            int val = 0;
//            if (d[i - 1] == val) ++val;
//            if (i % 2 == 0) {
//                if (d[i / 2] == val) ++val;
//                if (d[i - 1] == val) ++val;
//                if (d[i / 2] == val) ++val;
//            }
//            d[i] = val;
//            Assert.assertTrue(val == getVal1(i));
//        }
            int res = 0;
            if (k % 2 == 0) {
                for (int x : a) {
                    int val = 0;
                    if (x > 0) {
                        if (x == 1) val = 1;
                        else if (x == 2) val = 2;
                        else val = (x + 1) % 2;
                    }
                    res ^= val;
                }
            } else {
                for (int x : a) {
                    int val = getVal1(x);
                    res ^= val;
                }
            }
            out.printLine(res == 0 ? "Nicky" : "Kevin");
        }

        public int getVal1(int x) {
            int val;
            if (x == 0) {
                val = 0;
            } else if (x == 1) {
                val = 1;
            } else if (x == 2) {
                val = 0;
            } else if (x == 3) {
                val = 1;
            } else if (x % 2 == 1) {
                val = 0;
            } else {
                val = 1;
                int y = x;
                int cnt = 0;
                while (y % 2 == 0) {
                    y /= 2;
                    ++cnt;
                }
                if (y == 1 && cnt % 2 == 0) {
                    val = 2;
                }
                if (y == 3 && cnt % 2 == 1) {
                    val = 2;
                }
                if (y != 1 && y != 3 && cnt % 2 == 0) {
                    val = 2;
                }
            }
            return val;
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