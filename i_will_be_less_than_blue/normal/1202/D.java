import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.BiPredicate;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.i();
            while (t-- > 0) {
                long n = in.l();
                solve(n, out);
            }
        }

        private void solve(long n, PrintWriter out) {
            if (n == 1) {
                out.println("1337");
                return;
            }
            long nc2 = findNc2(n, (a, b) -> (a * (a - 1)) <= 2 * b);
            long rem = n - (nc2 * (nc2 - 1) / 2);
            StringBuilder sb = new StringBuilder();
            sb.append('1');
            sb.append('3');
            sb.append('3');
            for (int i = 0; i < rem; i++) {
                sb.append('7');
            }
            for (int i = 0; i < nc2 - 2; i++) {
                sb.append('3');
            }
            sb.append('7');
            out.println(sb.toString());
        }

        private long findNc2(long n, BiPredicate<Long, Long> nc2) {
            long l = 1;
            long h = n;
            while (l <= h) {
                long m = l + (h - l) / 2;
                if (nc2.test(m, n)) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            return h;
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