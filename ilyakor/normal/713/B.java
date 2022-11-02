import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        ArrayList<PointInt[]> al;
        TaskB.Interactor interactor;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            //for (int itt = 0; itt < 100; ++itt) {
            interactor = new TaskB.IOInteractor(new Scanner(in.getStream()), out.getWriter());//new TestInteractor(n);
            Assert.assertTrue(interactor.query(1, 1, n, n) == 2);
            int lx = 1, rx = n, ly = 1, ry = n;
            for (int it = 0; it < 20; ++it) {
                int tx = (lx + rx) / 2;
                if (interactor.query(1, 1, tx, n) >= 1)
                    rx = tx;
                else
                    lx = tx;
                int ty = (ly + ry) / 2;
                if (interactor.query(1, 1, n, ty) >= 1)
                    ry = ty;
                else
                    ly = ty;
            }
            al = new ArrayList<>();
            if (interactor.query(1, 1, lx, n) == 1 && interactor.query(lx + 1, 1, n, n) == 1) {
                dfs(1, 1, lx, n);
                dfs(lx + 1, 1, n, n);
            } else if (interactor.query(1, 1, rx, n) == 1 && interactor.query(rx + 1, 1, n, n) == 1) {
                dfs(1, 1, rx, n);
                dfs(rx + 1, 1, n, n);
            } else if (interactor.query(1, 1, n, ly) == 1 && interactor.query(1, ly + 1, n, n) == 1) {
                dfs(1, 1, n, ly);
                dfs(1, ly + 1, n, n);
            } else if (interactor.query(1, 1, n, ry) == 1 && interactor.query(1, ry + 1, n, n) == 1) {
                dfs(1, 1, n, ry);
                dfs(1, ry + 1, n, n);
            } else {
                throw new RuntimeException("WTF");
            }
            Assert.assertTrue(al.size() == 2);
            interactor.answer(al.get(0)[0].x, al.get(0)[0].y, al.get(0)[1].x, al.get(0)[1].y, al.get(1)[0].x, al.get(1)[0].y, al.get(1)[1].x, al.get(1)[1].y);
            //}
        }

        private void dfs(int x1, int y1, int x2, int y2) {
            int t;
            t = x1;
            for (int i = 0; i < 20; ++i) {
                int x = (t + x2) / 2;
                if (interactor.query(x1, y1, x, y2) == 1)
                    x2 = x;
                else
                    t = x;
            }
            if (interactor.query(x1, y1, t, y2) == 1)
                x2 = t;
            t = x2;
            for (int i = 0; i < 20; ++i) {
                int x = (t + x1) / 2;
                if (interactor.query(x, y1, x2, y2) == 1)
                    x1 = x;
                else
                    t = x;
            }
            if (interactor.query(t, y1, x2, y2) == 1)
                x1 = t;
            t = y1;
            for (int i = 0; i < 20; ++i) {
                int y = (t + y2) / 2;
                if (interactor.query(x1, y1, x2, y) == 1)
                    y2 = y;
                else
                    t = y;
            }
            if (interactor.query(x1, y1, x2, t) == 1)
                y2 = t;
            t = y2;
            for (int i = 0; i < 20; ++i) {
                int y = (t + y1) / 2;
                if (interactor.query(x1, y, x2, y2) == 1)
                    y1 = y;
                else
                    t = y;
            }
            if (interactor.query(x1, t, x2, y2) == 1)
                y1 = t;

            al.add(new PointInt[]{new PointInt(x1, y1), new PointInt(x2, y2)});
        }

        interface Interactor {
            int query(int x1, int y1, int x2, int y2);

            void answer(int x11, int y11, int x12, int y12,
                        int x21, int y21, int x22, int y22);

        }

        static class Query {
            int x1;
            int y1;
            int x2;
            int y2;

            public Query(int x1, int y1, int x2, int y2) {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                TaskB.Query query = (TaskB.Query) o;

                if (x1 != query.x1) return false;
                if (y1 != query.y1) return false;
                if (x2 != query.x2) return false;
                return y2 == query.y2;

            }


            public int hashCode() {
                int result = x1;
                result = 31 * result + y1;
                result = 31 * result + x2;
                result = 31 * result + y2;
                return result;
            }

        }

        static class IOInteractor implements TaskB.Interactor {
            Scanner in;
            PrintWriter out;
            HashMap<TaskB.Query, Integer> cache;

            public IOInteractor(Scanner in, PrintWriter out) {
                this.in = in;
                this.out = out;
                cache = new HashMap<>();
            }


            public int query(int x1, int y1, int x2, int y2) {
                TaskB.Query q = new TaskB.Query(x1, y1, x2, y2);
                if (cache.containsKey(q))
                    return cache.get(q);
                if (x1 > x2 || y1 > y2)
                    return 0;
                Assert.assertTrue(x1 >= 1 && y1 >= 1);
                out.println("? " + x1 + " " + y1 + " " + x2 + " " + y2);
                out.flush();
                int res = in.nextInt();
                cache.put(q, res);
                return res;
            }


            public void answer(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22) {
                out.println("! " + x11 + " " + y11 + " " + x12 + " " + y12 + " " + x21 + " " + y21 + " " + x22 + " " + y22);
                out.flush();
            }

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

        public InputStream getStream() {
            return stream;
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

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public PrintWriter getWriter() {
            return writer;
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
}