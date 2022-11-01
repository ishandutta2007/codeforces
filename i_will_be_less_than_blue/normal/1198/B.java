import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BWelfareState solver = new BWelfareState();
        solver.solve(1, in, out);
        out.close();
    }

    static class BWelfareState {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int[] a = in.ia(n);
            int q = in.i();
            List<IntKPair<IntIntPair>> queryList = new ArrayList<IntKPair<IntIntPair>>();
            for (int i = 0; i < q; i++) {
                int type = in.i();
                if (type == 1) {
                    queryList.add(IntKPair.of(type, IntIntPair.of(in.i(), in.i())));
                } else {
                    queryList.add(IntKPair.of(type, IntIntPair.of(in.i(), 0)));
                }
            }
            Collections.reverse(queryList);
            boolean[] flag = new boolean[n];
            int maxSoFar = -1;
            for (IntKPair pair : queryList) {
                IntIntPair p = (IntIntPair) pair.nd;
                if (pair.st == 2) {
                    maxSoFar = Math.max(maxSoFar, p.st);
                } else {
                    if (!flag[p.st - 1]) {
                        a[p.st - 1] = Math.max(p.nd, maxSoFar);
                        flag[p.st - 1] = true;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (!flag[i]) {
                    a[i] = Math.max(a[i], maxSoFar);
                }
            }
            out.printLine(a);
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class IntIntPair {
        public int st;
        public int nd;

        public static IntIntPair of(int st, int nd) {
            return new IntIntPair(st, nd);
        }

        private IntIntPair(int st, int nd) {
            this.st = st;
            this.nd = nd;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            IntIntPair intIntPair = (IntIntPair) o;
            return st == intIntPair.st &&
                    nd == intIntPair.nd;
        }

        public int hashCode() {
            return Objects.hash(st, nd);
        }

        public String toString() {
            return "(" + st + " " + nd + ")";
        }

    }

    static class IntKPair<K> {
        public int st;
        public K nd;

        public static <K> IntKPair<K> of(int st, K nd) {
            return new IntKPair<>(st, nd);
        }

        private IntKPair(int st, K nd) {
            this.st = st;
            this.nd = nd;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            IntKPair<?> intKPair = (IntKPair<?>) o;
            return st == intKPair.st &&
                    Objects.equals(nd, intKPair.nd);
        }

        public int hashCode() {
            return Objects.hash(st, nd);
        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int[] ia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i();
            return a;
        }

        public int i() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}