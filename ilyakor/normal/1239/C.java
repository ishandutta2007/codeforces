import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        int[] q;
        int ql;
        int qr;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int p = in.nextInt();
            ArrayList<ii> wants = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                wants.add(new ii(in.nextInt(), i));
            Collections.sort(wants);
            TreeSet<Integer> missing = new TreeSet<>();
            SegmentTreeFastIntervalSetMax tree = new SegmentTreeFastIntervalSetMax(n + 10);
            q = new int[n + 10];
            ql = 0;
            qr = 0;
            long qt = 0;
            long[] res = new long[n];
            int pos = 0;
            int rem = n;
            long T = 0;
            while (rem > 0) {
                if (pos < wants.size() || qr > ql) {
                    long wantsVal = (pos < wants.size() ? wants.get(pos).first : Long.MAX_VALUE);
                    long qVal = qr > ql ? (long) (qt + p + 1) : Long.MAX_VALUE;
                    if (wantsVal < qVal) {
                        int ind = wants.get(pos).second;
                        ++pos;
                        tree.set(ind + 1, n - ind);
                        T = wantsVal;
                    } else {
                        int ind = q[ql];
                        qt += p;
                        res[ind] = qt;
                        ++ql;
                        missing.remove(ind);
                        --rem;
                        T = qt;
                    }
                }

                {
                    int prefix = missing.isEmpty() ? n : missing.first();
                    int ind = tree.queryMax(1, prefix + 1);
                    if (ind > 0) {
                        ind = n - ind;
                        tree.set(ind + 1, 0);
                        if (ql == qr) qt = T;
                        //T = qt;
                        q[qr++] = ind;
                        missing.add(ind);
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                out.print(res[i] + " ");
            }
            out.printLine();
        }

    }

    static class SegmentTreeFastIntervalSetMax {
        final int n;
        final int[] t;
        final int[] m;
        final boolean[] h;
        final int[] q;

        public SegmentTreeFastIntervalSetMax(int n) {
            this.n = n;
            t = new int[2 * n];
            m = new int[2 * n];
            h = new boolean[2 * n];
            q = new int[2 * n];
            for (int i = n; i < 2 * n; i++)
                q[i] = 1;
            for (int i = 2 * n - 1; i > 1; i -= 2)
                q[i >> 1] = q[i] + q[i ^ 1];
        }

        void modifierHelper(int i, int p) {
            t[i] = p;
            m[i] = p;
            h[i] = true;
        }

        void pop(int i) {
            if (h[i >> 1]) {
                t[i >> 1] = m[i >> 1];
            } else {
                t[i >> 1] = Math.max(t[i], t[i ^ 1]);
            }
        }

        void popUp(int i) {
            for (; i > 1; i >>= 1)
                pop(i);
        }

        void push(int i) {
            if (h[i >> 1]) {
                modifierHelper(i, m[i >> 1]);
                modifierHelper(i ^ 1, m[i >> 1]);
                h[i >> 1] = false;
            }
        }

        void pushDown(int i) {
            int k;
            for (k = 0; (i >> k) > 0; k++)
                ;
            for (k -= 2; k >= 0; k--)
                push(i >> k);
        }

        public void modifySet(int a, int b, int v) {
            a += n;
            b += n;
            pushDown(a);
            pushDown(b);
            int ta = a;
            int tb = b;

            for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
                if ((a & 1) != 0)
                    modifierHelper(a, v);
                if ((b & 1) == 0)
                    modifierHelper(b, v);
            }

            popUp(ta);
            popUp(tb);
        }

        public int queryMax(int a, int b) {
            a += n;
            b += n;
            pushDown(a);
            pushDown(b);

            int res = 0;
            for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
                if ((a & 1) != 0)
                    res = Math.max(res, t[a]);
                if ((b & 1) == 0)
                    res = Math.max(res, t[b]);
            }
            return res;
        }

        public void set(int i, int v) {
            modifySet(i, i, v);
        }

    }

    static class ii implements Comparable<ii> {
        public int first;
        public int second;

        public ii() {
        }

        public ii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            ii ii = (ii) o;

            if (first != ii.first) return false;
            if (second != ii.second) return false;

            return true;
        }

        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }

        public int compareTo(ii o) {
            if (first != o.first) {
                return first < o.first ? -1 : 1;
            }
            if (second != o.second) {
                return second < o.second ? -1 : 1;
            }
            return 0;
        }

        public String toString() {
            return "{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
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
}