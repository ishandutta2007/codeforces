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
        BAlyonaAndANarrowFridge solver = new BAlyonaAndANarrowFridge();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAlyonaAndANarrowFridge {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            long h = in.l();
            long[] a = in.la(n);
            long left = 0;
            long right = n;
            while (left <= right) {
                long m = left + (right - left) / 2;
                if (ok(a, m, h)) left = m + 1;
                else right = m - 1;
            }
            out.printLine(right);
        }

        private boolean ok(long[] a, long m, long h) {
            long[] b = Arrays.copyOf(a, (int) m);
            RadixSort.radixSort(b);
            ArrayUtil.reverse(b, 0, (int) m - 1);
            long sum = 0;
            for (int i = 0; i < m; i += 2) {
                sum += b[i];
            }
            return sum <= h;
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class ArrayUtil {
        public static void reverse(long[] a, int l, int r) {
            while (l < r) {
                long temp = a[l];
                a[l++] = a[r];
                a[r--] = temp;
            }
        }

    }

    static class RadixSort {
        public static long[] radixSort(long[] f) {
            return radixSort(f, f.length);
        }

        public static long[] radixSort(long[] f, int n) {
            long[] to = new long[n];
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] & 0xffff)]++] = f[i];
                long[] d = f;
                f = to;
                to = d;
            }
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] >>> 16 & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] >>> 16 & 0xffff)]++] = f[i];
                long[] d = f;
                f = to;
                to = d;
            }
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] >>> 32 & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] >>> 32 & 0xffff)]++] = f[i];
                long[] d = f;
                f = to;
                to = d;
            }
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] >>> 48 & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] >>> 48 & 0xffff)]++] = f[i];
                long[] d = f;
                f = to;
                to = d;
            }
            return f;
        }

    }
}