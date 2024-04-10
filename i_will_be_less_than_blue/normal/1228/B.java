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
import java.math.BigInteger;
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
        BFillingTheGrid solver = new BFillingTheGrid();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFillingTheGrid {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int h = in.i();
            int w = in.i();
            boolean[][] row = new boolean[h][w];
            boolean[][] col = new boolean[h][w];
            int[] r = in.ia(h);
            int[] c = in.ia(w);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < r[i]; j++) {
                    row[i][j] = true;
                }
            }
            for (int i = 0; i < w; i++) {
                if (c[i] == 0 && row[0][i]) {
                    out.printLine(0);
                    return;
                }
                for (int j = 0; j < c[i]; j++) {
                    if (i == 0 && !row[j][0]) {
                        out.printLine(0);
                        return;
                    }
                    if ((i > 0 && row[j][i - 1] && !row[j][i])) {
                        out.printLine(0);
                        return;
                    }
                    col[j][i] = true;
                }
                if (c[i] < h && row[c[i]][i]) {
                    out.printLine(0);
                    return;
                }
            }
            for (int i = 0; i < r.length; i++) {
                if (i > 0 && r[i] < w && row[i][r[i]]) {
                    row[i][r[i] + 1] = true;
                }
            }
            for (int i = 0; i < w; i++) {
                if (i > 0 && c[i] < h && col[c[i]][i]) {
                    col[c[i] + 1][i] = true;
                }
            }
            ModUtil mod = new ModUtil();
            long ans = 1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (i > 0 && j > 0 && !row[i][j - 1] && !col[i - 1][j]) {
                        ans = mod.mod(ans * 2);
                    }
                }
            }
            out.printLine(ans);
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

    static class IntegerUtil {
        public static boolean isPrime(long val) {
            return BigInteger.valueOf(val).isProbablePrime(1);
        }

    }

    static class ModUtil {
        private static final int DEFAULT_MOD = 1_000_000_007;
        private final long mod;

        private ModUtil(long mod, boolean unsafe) {
            if (!unsafe && !IntegerUtil.isPrime(mod)) {
                throw new RuntimeException("This class is designed for primes!");
            }
            this.mod = mod;
        }

        public ModUtil(long mod) {
            this(mod, false);
        }

        public ModUtil() {
            this(DEFAULT_MOD, true);
        }

        public long mod(long x) {
            x %= mod;
            return x < 0 ? x + mod : x;
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
}