import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.HashMap;
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
        HashMap<Integer, TaskD.Edge> d;
        int[] buf;
        int bl;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int q = in.nextInt();
            d = new HashMap<>();
            int last = 0;
            buf = new int[218 * 1000];
            for (int it = 0; it < q; ++it) {
                int ty = in.nextInt();
                if (ty == 1) {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    int val = in.nextInt();
                    l ^= last;
                    r ^= last;
                    val ^= last;
                    if (l > r) {
                        int tmp = l;
                        l = r;
                        r = tmp;
                    }
                    int oval = query(l, r);
                    if (oval == -1)
                        add(l, r, val);
                } else {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    l ^= last;
                    r ^= last;
                    if (l > r) {
                        int tmp = l;
                        l = r;
                        r = tmp;
                    }
                    last = query(l, r);
                    out.printLine(last);
                    if (last == -1) last = 1;
                }
            }
        }

        private void add(int l, int r, int val) {
            --l;
            if (!d.containsKey(l))
                d.put(l, new TaskD.Edge(l, 0));
            if (!d.containsKey(r))
                d.put(r, new TaskD.Edge(r, 0));
            TaskD.Edge el = get(l), er = get(r);
            Assert.assertTrue(el.x != er.x);
            val ^= el.val;
            val ^= er.val;
            TaskD.Edge leftRoot = d.get(el.x);
            leftRoot.x = er.x;
            leftRoot.val = val;
        }

        private TaskD.Edge get(int x) {
            int val = 0;
            bl = 0;
            while (true) {
                TaskD.Edge cur = d.get(x);
                if (cur.x == x) break;
                buf[bl++] = x;
                val ^= cur.val;
                x = cur.x;
            }
            int nval = 0;
            for (int i = bl - 1; i >= 0; --i) {
                int y = buf[i];
                TaskD.Edge e = d.get(y);
                nval ^= e.val;
                e.x = x;
                e.val = nval;
            }
//        Assert.assertTrue(val == nval);
            return new TaskD.Edge(x, val);
        }

        private int query(int l, int r) {
            --l;
            if (!d.containsKey(l) || !d.containsKey(r))
                return -1;
            TaskD.Edge el = get(l), er = get(r);
            if (el.x != er.x)
                return -1;
            return el.val ^ er.val;
        }

        static class Edge {
            int x;
            int val;

            public Edge(int x, int val) {
                this.x = x;
                this.val = val;
            }

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