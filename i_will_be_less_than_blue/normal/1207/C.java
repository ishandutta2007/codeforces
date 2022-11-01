import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        GasPipeline solver = new GasPipeline();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class GasPipeline {
        private long[][] dp;
        private boolean[] bad;
        private long a;
        private long b;
        private int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.i();
            a = in.l();
            b = in.l();
            String s = in.next();
            bad = new boolean[n];
            for (int i = 1; i < n - 1; i++) {
                if (s.charAt(i) == '0' && s.charAt(i - 1) == '1' && s.charAt(i + 1) == '1')
                    bad[i] = true;
            }
            dp = new long[2][n]; // first index denotes the last selected height of the pipe, which can be 1 or 2[ only 2 possible values]
            for (int i = 0; i < 2; i++) {
                Arrays.fill(dp[i], Cons.INF);
            }
            out.println(doDp(0, 0, s));
        }

        private long doDp(int cur, int ind, String s) {
            if (ind == n) return cur == 0 ? b : Cons.INF;
            // because of step 34 and 37, since we call for both height at current index
            // it might be possible that some assignment might not be valid
            // Case is, when we assign height 0 to current ind, but the value here is 1 which is
            // prohibited as per question
            if (cur == 0 && s.charAt(ind) == '1') return Cons.INF;
            // 1) Following condition gives correct answer,
            // Logically thinking, it says that if previous index is 1, then we can not assign height 2 here
            // which is not the case always
            if (ind > 0 && s.charAt(ind - 1) == '1' && cur == 0) return Cons.INF;
            if (dp[cur][ind] != Cons.INF) return dp[cur][ind];
            long ans = Cons.INF;
            if (cur == 0) {
                // if cur assigned height is 1[cur == 0 means height 1] than assign
                // height 1, and height 2 to current index and select the minimum
                long left = doDp(1, ind + 1, s) + 2 * a + b;
                long right = doDp(0, ind + 1, s) + a + b;
                ans = Math.min(left, right);
            } else {
                long left = doDp(1, ind + 1, s) + 2 * b + a;
                long right = doDp(0, ind + 1, s) + 2 * b + 2 * a;
                ans = Math.min(left, right);
            }
            return dp[cur][ind] = ans;
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
        public static long INF = (long) 1e18 + 100;

    }
}