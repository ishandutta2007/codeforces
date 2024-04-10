import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.l();
            long m = in.l();
            int q = in.i();
            while (q-- > 0) {
                int sx = in.i();
                long sy = in.l() - 1;
                int ex = in.i();
                long ey = in.l() - 1;
                long gcd = IntegerUtil.gcd(n, m);
                solve(sx, ex, n, m, sy, ey, gcd, out);
            }
        }

        private void solve(int sx, int ex, long n, long m, long sy, long ey, long gcd, PrintWriter out) {
            long size1 = n / gcd;
            long size2 = m / gcd;
            long group1 = groupNumber(sy, sx == 1 ? size1 : size2);
            long group2 = groupNumber(ey, ex == 1 ? size1 : size2);
            if (group1 == group2) out.println("YES");
            else out.println("NO");
        }

        private long groupNumber(long position, long size) {
            // ceil (x / y) = floor (x - 1 / y) + 1 , use this if x and y are very large and you want to avoid overflow
            return position / size;
        }

    }

    static class IntegerUtil {
        public static long gcd(long a, long b) {
            return (b == 0) ? a : gcd(b, a % b);
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
}