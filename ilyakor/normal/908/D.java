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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int mod = 1000 * 1000 * 1000 + 7;
        int k;
        int pa;
        int pb;
        int[][] d;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            k = in.nextInt();
            pa = in.nextInt();
            pb = in.nextInt();
            int papb;
            {
                int den = IntegerUtils.pow(pa + pb, mod - 2, mod);
                pa = (int) (((long) pa * (long) den) % mod);
                pb = (int) (((long) pb * (long) den) % mod);
                papb = (int) ((pa * (long) IntegerUtils.pow(pb, mod - 2, mod)) % mod);
            }

            d = new int[k + 1][k];
            d[1][0] = 1;
            long res = 0;
            for (int x = 1; x <= k; ++x) {
                for (int cnt = 0; cnt < k; ++cnt) {
                    int cur = d[x][cnt];
                    if (cur == 0) continue;
                    if (x < k) {
                        int prob = (int) (((long) pa * (long) cur) % mod);
                        long sum = 0;
                        for (int nb = 0; ; ++nb) {
                            int ncnt = cnt + nb * x;
                            if (ncnt >= k) {
                                long val = cur - sum;
                                if (val < 0) val += mod;
                                res += val * (long) ncnt;
                                res %= mod;
                                break;
                            } else {
                                d[x + 1][ncnt] = (d[x + 1][ncnt] + prob) % mod;
                                sum += prob;
                                prob = (int) ((prob * (long) pb) % mod);
                            }
                        }
                    } else {
                        int val = cnt + k + papb;
                        val %= mod;
                        res += val * (long) cur;
                        res %= mod;
                    }
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

    static class IntegerUtils {
        public static int pow(long x, long y, int mod) {
            x %= mod;
            long res = 1;
            while (y > 0) {
                if (y % 2 == 1) {
                    --y;
                    res = (res * x) % mod;
                } else {
                    y /= 2;
                    x = (x * x) % mod;
                }
            }
            return (int) (res % mod);
        }

    }
}