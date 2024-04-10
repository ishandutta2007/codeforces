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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            long[] a = in.la(n);
            Fenwick f = new Fenwick(n);
            for (int i = 1; i <= n; i++) {
                f.add(i - 1, i);
            }
            int[] list = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int ind = f.indexWithGivenCumFreq(a[i]);
                f.add(ind, -(ind + 1));
                list[i] = ind + 1;
            }
            out.printLine(list);
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

        public long[] la(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = l();
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

        public long l() {
            long num = 0;
            int b;
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

    static class Fenwick {
        public final long[] bit;
        public final int size;

        public Fenwick(int[] a) {
            this(a.length);
            for (int i = 0; i < a.length; i++) {
                this.add(i, a[i]);
            }
        }

        public Fenwick(long[] a) {
            this(a.length);
            for (int i = 0; i < a.length; i++)
                this.add(i, a[i]);
        }

        public Fenwick(int size) {
            bit = new long[size + 1];
            this.size = size + 1;
        }

        public void add(int i, long delta) {
            for (++i; i < size; i += (i & -i)) {
                bit[i] += delta;
            }
        }

        public int indexWithGivenCumFreq(long v) {
            int i = 0, n = size;
            for (int b = Integer.highestOneBit(n); b != 0; b >>= 1) {
                if ((i | b) < n && bit[i | b] <= v) {
                    i |= b;
                    v -= bit[i];
                }
            }
            return i;
        }

    }
}