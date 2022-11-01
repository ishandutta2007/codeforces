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
 * @author sharoha
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        PythonIndentation solver = new PythonIndentation();
        solver.solve(1, in, out);
        out.close();
    }

    static class PythonIndentation {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            char[] chars = new char[n];
            for (int i = 0; i < n; i++) {
                chars[i] = in.c();
            }
            int[][] dp = new int[n + 1][n + 1];
            dp[0][0] = 1;
            for (int i = 1; i < n; i++) {
                if (chars[i - 1] == 'f') {
                    for (int j = 1; j < n; j++) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    int suff = 0;
                    for (int j = n - 1; j >= 0; j--) {
                        suff = (suff + dp[i - 1][j]) % Cons.MOD;
                        dp[i][j] = suff;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = (ans + dp[n - 1][i]) % Cons.MOD;
            }
            out.printLine(ans);
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

    static class InputReader {
        private final InputStream is;
        private final byte[] inbuf = new byte[1024];
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

        public char c() {
            return (char) skip();
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

    static interface Cons {
        int MOD = 1_000_000_007;

    }
}