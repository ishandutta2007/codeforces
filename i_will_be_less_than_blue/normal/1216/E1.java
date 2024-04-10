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
 *
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        E2NumericalSequenceHardVersion solver = new E2NumericalSequenceHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E2NumericalSequenceHardVersion {
        private long[] dp = new long[20];
        private long[] sum = new long[11];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int t = in.i();
            for (int i = 1; i < 20; i++) {
                long numOfTerms = i * 9 * (long) Math.pow(10, i - 1);
                dp[i] = numOfTerms + dp[i - 1];
            }
            for (int i = 1; i < 11; i++) {
                long numOfTerms = 9 * (long) Math.pow(10, i - 1);
                sum[i] = sum[i - 1] + (numOfTerms) * (dp[i - 1] + i + dp[i]) / 2;
            }
            while (t-- > 0) {
                long k = in.l();
                solve(k, out);
            }
        }

        private void solve(long k, OutputWriter out) {
            int block = 1;
            for (int i = 1; i < 11; i++) {
                if (k <= sum[i]) {
                    block = i;
                    break;
                }
            }
            k -= sum[block - 1];
            long s = dp[block - 1] + block;
            long l = 1;
            long h = (long) 1e8;
            while (l <= h) {
                long m = l + (h - l) / 2;
                if (m * 2 * s + m * (m - 1) * block < 2 * k) l = m + 1;
                else h = m - 1;
            }
            l = h;
            k -= (l) * (s + s + (l - 1) * block) / 2;
            // Now problem transformed to
            // find kth digit in the sequence 123...10111213...100101..
            findKthDigit(k, out);
        }

        private void findKthDigit(long k, OutputWriter out) {
            int u = 1;
            for (int i = 1; i < 20; i++) {
                if (k <= dp[i]) {
                    u = i;
                    break;
                }
            }
            k -= dp[u - 1];
            long pow = (long) Math.pow(10, u - 1);
            long num = pow + ((k - 1) / u);
            String s = String.valueOf(num);
            int pos = k % u == 0 ? u : (int) (k % u);
            out.printLine(s.charAt(pos - 1));
            out.flush();
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

        public void printLine(char i) {
            writer.println(i);
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
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