import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.stream.LongStream;
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
        AThePartyAndSweets solver = new AThePartyAndSweets();
        solver.solve(1, in, out);
        out.close();
    }

    static class AThePartyAndSweets {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int m = in.i();
            long[] b = in.la(n);
            long[] g = in.la(m);
            long maxB = ArrayUtil.max(b);
            long minG = ArrayUtil.min(g);
            if (maxB > minG) {
                out.printLine(-1);
            } else {
                long sumB = ArrayUtil.sum(b);
                long sumG = ArrayUtil.sum(g);
                long ans = sumB * (long) m + sumG;
                if (maxB == minG) {
                    out.printLine(ans - maxB * (long) m);
                } else {
                    RadixSort.radixSort(b);
                    long nextMax = b[n - 2];
                    out.printLine(ans - maxB * (long) (m - 1) - nextMax);
                }
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

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class ArrayUtil {
        public static long min(long[] a) {
            return Arrays.stream(a).reduce(Cons.INF, Long::min);
        }

        public static long max(long[] a) {
            return Arrays.stream(a).reduce(0, Long::max);
        }

        public static long sum(long[] a) {
            return Arrays.stream(a).sum();
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

    static class Cons {
        public static final long INF = (long) 1e18 + 100;

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