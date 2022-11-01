import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Map;
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
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BMicroWorld solver = new BMicroWorld();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMicroWorld {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int k = in.i();
            int[] a = in.ia(n);
            RadixSort.radixSort(a);
            Map<Integer, Integer> freq = ArrayUtil.countFrequencyOfEveryElement(a);
            int count = n;
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i - 1] && a[i] <= a[i - 1] + k) {
                    count -= freq.get(a[i - 1]);
                }
            }
            out.printLine(count);
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

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class RadixSort {
        public static int[] radixSort(int[] f) {
            return radixSort(f, f.length);
        }

        public static int[] radixSort(int[] f, int n) {
            // credits uwi
            int[] to = new int[n];
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] & 0xffff)]++] = f[i];
                int[] d = f;
                f = to;
                to = d;
            }
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] >>> 16 & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] >>> 16 & 0xffff)]++] = f[i];
                int[] d = f;
                f = to;
                to = d;
            }
            return f;
        }

    }

    static class ArrayUtil {
        public static HashMap<Integer, Integer> countFrequencyOfEveryElement(int[] a) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int t : a) {
                if (map.containsKey(t)) {
                    map.put(t, map.get(t) + 1);
                } else {
                    map.put(t, 1);
                }
            }
            return map;
        }

    }
}