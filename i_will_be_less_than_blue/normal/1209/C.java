import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        CPaintTheDigits solver = new CPaintTheDigits();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CPaintTheDigits {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            String s = in.next();
            int[] ans = new int[n];
            Arrays.fill(ans, -1);
            outer:
            for (int x = 0; x <= 9; x++) {
                int k = -1;
                for (int i = 0; i < s.length(); i++) {
                    if (x < (s.charAt(i) - '0')) {
                        k = i;
                        break;
                    }
                }
                for (int i = 0; i < s.length(); i++) {
                    if (x > (s.charAt(i) - '0')) {
                        ans[i] = 1;
                    } else if (x < (s.charAt(i) - '0')) {
                        ans[i] = 2;
                    } else {
                        if (k != -1) {
                            if (i <= k) {
                                ans[i] = 2;
                            } else {
                                ans[i] = 1;
                            }
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (ans[i] == -1) continue outer;
                }
                if (ifTrue(n, s, ans)) {
                    for (int i = 0; i < n; i++) {
                        out.print(ans[i]);
                    }
                    out.printLine();
                    return;
                }
                Arrays.fill(ans, -1);
            }
            out.printLine("-");
        }

        private boolean ifTrue(int n, String s, int[] ans) {
            StringBuilder a = new StringBuilder();
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if (ans[i] == 1) {
                    a.append(s.charAt(i));
                } else {
                    b.append(s.charAt(i));
                }
            }
            a.append(b);
            for (int i = 1; i < a.length(); i++) {
                if (a.charAt(i) < a.charAt(i - 1)) {
                    return false;
                }
            }
            return true;
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

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine() {
            writer.println();
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }
}