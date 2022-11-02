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
import java.util.ArrayList;

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
        InputReader in;
        OutputWriter out;
        ArrayList<Integer>[] g;
        boolean[] ours;
        boolean[] theirs;
        int[] p;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int testCount = in.nextInt();
            for (int i = 0; i < testCount; ++i) {
                doSolve();
            }
        }

        private void doSolve() {
            int n = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                g[x].add(y);
                g[y].add(x);
            }
            ours = new boolean[n];
            int k1 = in.nextInt();
            for (int i = 0; i < k1; ++i) {
                ours[in.nextInt() - 1] = true;
            }
            theirs = new boolean[n];
            int k2 = in.nextInt();
            for (int i = 0; i < k2; ++i)
                theirs[in.nextInt() - 1] = true;
            int root = -1;
            p = new int[n];
            for (int i = 0; i < n; ++i)
                if (ours[i]) {
                    root = i;
                    dfs(i, -1);
                    break;
                }
            int theirRoot = query1(root);
            if (theirs[theirRoot]) {
                answer(root);
                return;
            }

            int anyTheir = -1;
            for (int i = 0; i < n; ++i)
                if (theirs[i]) {
                    anyTheir = i;
                    break;
                }
            int ourTheir = query2(anyTheir);
            if (ours[ourTheir]) {
                answer(ourTheir);
                return;
            }
            int x = ourTheir;
            while (!ours[x]) x = p[x];
            int theirX = query1(x);
            if (theirs[theirX])
                answer(x);
            else
                answer(-1);
        }

        private int query1(int x) {
            Assert.assertTrue(x >= 0);
            out.printLine("A " + (x + 1));
            out.flush();
            return in.nextInt() - 1;
        }

        private int query2(int x) {
            Assert.assertTrue(x >= 0);
            out.printLine("B " + (x + 1));
            out.flush();
            return in.nextInt() - 1;
        }

        private void answer(int x) {
            if (x != -1) ++x;
            out.printLine("C " + x);
            out.flush();
        }

        private void dfs(int x, int par) {
            p[x] = par;
            for (int y : g[x])
                if (y != par) dfs(y, x);
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

        public void flush() {
            writer.flush();
        }

    }

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
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