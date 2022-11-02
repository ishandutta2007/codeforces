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
import java.util.ArrayList;
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
        boolean[] can;
        int[] st;
        int ss;
        int[] u;
        int[] rc;
        int[] v;
        int gen;
        ArrayList<Integer>[][] bads;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int k = in.nextInt();
            int n = in.nextInt();
            PointInt[] b = new PointInt[k];
            PointInt[] a = new PointInt[n];
            for (int i = 0; i < k; ++i)
                b[i] = new PointInt(in.nextInt(), in.nextInt());
            for (int i = 0; i < n; ++i)
                a[i] = new PointInt(in.nextInt(), in.nextInt());
            bads = new ArrayList[k][n];
            can = new boolean[n];
            for (int i = 0; i < k; ++i)
                for (int j = 0; j < n; ++j) {
                    bads[i][j] = new ArrayList<>();
                    for (int t = 0; t < n; ++t)
                        if (t != j && pointOnSeg(b[i], a[j], a[t]))
                            bads[i][j].add(t);
                    if (bads[i][j].isEmpty())
                        can[j] = true;
                }
            st = new int[n + 10];
            u = new int[n];
            rc = new int[n];
            v = new int[k];
            gen = 1;
            for (int i = 0; i < n; ++i) {
                if (can[i]) continue;
                ss = 0;
                ++gen;
                st[ss++] = i;
                u[i] = gen;
                rc[i] = 1;
                Arrays.fill(v, -1);
                can[i] = dfs();
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (can[i]) ++res;
            }
            out.printLine(res);
        }

        private boolean dfs() {
            if (ss == 0) {
                for (int i = 0; i < v.length; ++i) {
                    if (v[i] != -1)
                        can[v[i]] = true;
                }
                return true;
            }
            int cnt = 0;
            for (int i = 0; i < v.length; ++i)
                if (v[i] == -1)
                    ++cnt;
            if (cnt < ss) return false;
            int x = st[ss - 1];
            --ss;
            for (int i = 0; i < v.length; ++i)
                if (v[i] == -1) {
                    ArrayList<Integer> b = bads[i][x];
                    if (b.size() > v.length) continue;
                    v[i] = x;
                    for (int w : b) {
                        if (u[w] == gen)
                            ++rc[w];
                        else {
                            u[w] = gen;
                            rc[w] = 1;
                            st[ss++] = w;
                        }
                    }
                    if (ss <= cnt) {
                        if (dfs())
                            return true;
                    }
                    for (int w : b) {
                        --rc[w];
                        if (rc[w] == 0) {
                            u[w] = 0;
                            --ss;
                        }
                    }
                    v[i] = -1;
                }
            st[ss++] = x;
            return false;
        }

        private boolean pointOnSeg(PointInt p1, PointInt p2, PointInt q) {
            if (p1.subtract(q).cross(p2.subtract(q)) != 0)
                return false;
            return p1.subtract(q).scalar(p2.subtract(q)) <= 0;
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

    static class PointInt {
        public int x;
        public int y;

        public PointInt(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public PointInt() {
            x = 0;
            y = 0;
        }

        public long cross(PointInt p) {
            return (long) x * (long) p.y - (long) y * (long) p.x;
        }

        public long scalar(PointInt p) {
            return (long) x * (long) p.x + (long) y * (long) p.y;
        }

        public PointInt subtract(PointInt p) {
            return new PointInt(x - p.x, y - p.y);
        }

    }
}