import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskF1 solver = new TaskF1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF1 {
        static final int mod = 998244353;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = new int[m];
            final int[] L = new int[n + 1];
            Arrays.fill(L, 1000 * 1000 * 1000);
            int[] R = new int[n + 1];
            Arrays.fill(R, -1000 * 1000 * 1000);
            for (int i = 0; i < m; ++i) {
                a[i] = in.nextInt();
                if (L[a[i]] > i) L[a[i]] = i;
                if (R[a[i]] < i) R[a[i]] = i;
            }
            RMQSparseTable rmq = new RMQSparseTable(a);
            for (int i = 1; i <= n; ++i) {
                if (R[i] < 0) {
                    out.printLine(0);
                    return;
                }
                int j = rmq.minPos(L[i], R[i]);
                if (a[j] < i) {
                    out.printLine(0);
                    return;
                }
            }

            int[] parent = new int[n + 1];
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j < i; ++j)
                    if (L[j] <= L[i] && R[i] <= R[j])
                        parent[i] = j;
            ArrayList<Integer>[] kids = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                kids[i] = new ArrayList<>();
            for (int i = 1; i <= n; ++i)
                kids[parent[i]].add(i);
            long res = 1;
            for (int i = 0; i < n; ++i) {
                if (kids[i].isEmpty()) continue;
                Collections.sort(kids[i], new Comparator<Integer>() {

                    public int compare(Integer x, Integer y) {
                        return Integer.compare(L[x], L[y]);
                    }
                });
                res *= calc(kids[i]);
                res %= mod;
            }
            out.printLine(res);
        }

        private long calc(ArrayList<Integer> _a) {
            int n = _a.size();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = _a.get(i);
            int[][] d = new int[n + 1][n + 1];
            for (int i = 0; i < n; ++i) {
                d[i + 1][i] = 1;
            }
            for (int len = 1; len <= n; ++len)
                for (int i = 0; i + len <= n; ++i) {
                    int j = i + len - 1;
                    if (len <= 1) {
                        d[i][j] = 1;
                        continue;
                    }
                    int pos = i;
                    for (int k = i; k <= j; ++k)
                        if (a[k] < a[pos])
                            pos = k;
                    long cl = 0;
                    for (int l = i; l <= pos; ++l) {
                        long val = l == i ? 1 : d[i][l - 1];
                        val *= l == pos ? 1 : d[l][pos - 1];
                        cl += val;
                        cl %= mod;
                    }
                    long cr = 0;
                    for (int r = pos; r <= j; ++r) {
                        long val = r == j ? 1 : d[r + 1][j];
                        val *= r == pos ? 1 : d[pos + 1][r];
                        cr += val;
                        cr %= mod;
                    }
                    d[i][j] = (int) ((cl * cr) % mod);
                }
            return d[0][n - 1];
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

    static class RMQSparseTable {
        int[] logTable;
        int[][] rmq;
        int[] a;

        public RMQSparseTable(int[] a) {
            this.a = a;
            int n = a.length;

            logTable = new int[n + 1];
            for (int i = 2; i <= n; i++)
                logTable[i] = logTable[i >> 1] + 1;

            rmq = new int[logTable[n] + 1][n];

            for (int i = 0; i < n; ++i)
                rmq[0][i] = i;

            for (int k = 1; (1 << k) < n; ++k) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    int x = rmq[k - 1][i];
                    int y = rmq[k - 1][i + (1 << k - 1)];
                    rmq[k][i] = a[x] <= a[y] ? x : y;
                }
            }
        }

        public int minPos(int i, int j) {
            int k = logTable[j - i];
            int x = rmq[k][i];
            int y = rmq[k][j - (1 << k) + 1];
            return a[x] <= a[y] ? x : y;
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