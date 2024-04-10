import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.OptionalInt;
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
        ACards solver = new ACards();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACards {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int N = in.i();
            char[] a = in.next().toCharArray();
            int[] f = new int[26];
            for (char c : a) {
                f[c - 'a']++;
            }
            int z = 'z' - 'a';
            int e = 'e' - 'a';
            int r = 'r' - 'a';
            int o = 'o' - 'a';
            int n = 'n' - 'a';
            int ans = ArrayUtil.min(new int[]{f[o], f[n], f[e]});
            f[o] = Math.max(0, f[o] - ans);
            f[e] = Math.max(0, f[e] - ans);
            int zero = ArrayUtil.min(new int[]{f[z], f[e], f[r], f[o]});
            for (int i = 0; i < ans; i++) {
                out.print(1 + " ");
            }
            for (int i = 0; i < zero; i++) {
                out.print(0 + " ");
            }
        }

    }

    static class ArrayUtil {
        public static int min(int[] a) {
            return IntStream.of(a).min().orElse(-Cons.inf);
        }

    }

    static class Cons {
        public static final int inf = (int) 1e9 + 100;

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

        public void close() {
            writer.close();
        }

    }
}