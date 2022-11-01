import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        CSaveTheNature solver = new CSaveTheNature();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CSaveTheNature {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            List<Long> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(in.l() / 100);
            }
            list.sort((x, y) -> Long.compare(y, x));
            long[] xa = in.la(2);
            long[] yb = in.la(2);
            long k = in.l();
            //  swap the array if a > b
            if (xa[0] > yb[0]) {
                long[] temp = xa;
                xa = yb;
                yb = temp;
            }
            doBinrarySearch(out, n, list, xa, yb, k);
        }

        private void doBinrarySearch(OutputWriter out, int n, List<Long> list, long[] xa, long[] yb, long k) {
            int l = 0;
            int h = n;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if (ok(m, list, k, xa, yb)) h = m - 1;
                else l = m + 1;
            }
            if (l == n + 1) {
                out.printLine(-1);
            } else {
                out.printLine(l);
            }
        }

        private boolean ok(int m, List<Long> list, long k, long[] xa, long[] yb) {
            long curSum = 0;
            long mul = IntegerUtil.lcm(xa[1], yb[1]);
            int cur = 0;
            for (long i = mul; i <= m; i += mul) {
                curSum += list.get(cur++) * (xa[0] + yb[0]);
                if (curSum >= k) return true;
            }
            for (long i = yb[1]; i <= m; i += yb[1]) {
                if (i % mul != 0) {
                    curSum += list.get(cur++) * yb[0];
                    if (curSum >= k) return true;
                }
            }
            for (long i = xa[1]; i <= m; i += xa[1]) {
                if (i % mul != 0) {
                    curSum += list.get(cur++) * xa[0];
                    if (curSum >= k) return true;
                }
            }

//        List<Long> mulFactor = new ArrayList<>();
//        for (int i = 1; i <= m; i++) {
//            long p = 0;
//            if (i % xa[1] == 0) p += xa[0];
//            if (i % yb[1] == 0) p += yb[0];
//            mulFactor.add(p);
//        }
//        mulFactor.sort(Comparator.reverseOrder());
//        for (int i = 0; i < m; i++) {
//            curSum += list.get(i) * mulFactor.get(i);
//        }
//        return curSum >= k;
            return false;
        }

    }

    static class IntegerUtil {
        public static long gcd(long a, long b) {
            return (b == 0) ? a : gcd(b, a % b);
        }

        public static long lcm(long a, long b) {
            return (a / gcd(a, b)) * b;
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
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

        public void printLine(int i) {
            writer.println(i);
        }

    }
}