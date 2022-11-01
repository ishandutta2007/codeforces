import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        B1TheDoctorMeetsVaderEasy solver = new B1TheDoctorMeetsVaderEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class B1TheDoctorMeetsVaderEasy {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int s = in.i();
            int b = in.i();
            int[] a = in.ia(s);
            IntIntPair[] baseGold = new IntIntPair[b];
            for (int i = 0; i < b; i++) {
                int x = in.i();
                int y = in.i();
                baseGold[i] = IntIntPair.of(x, y);
            }
            Arrays.sort(baseGold, Comparator.comparingInt(e -> e.st));
            for (int i = 1; i < b; i++) {
                baseGold[i].nd += baseGold[i - 1].nd;
            }
            for (int ele : a) {
                out.print(findAns(baseGold, ele) + " ");
            }
        }

        private int findAns(IntIntPair[] baseGold, int key) {
            int l = 0;
            int h = baseGold.length - 1;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if (baseGold[m].st > key) h = m - 1;
                else l = m + 1;
            }
            if (l == 0) return 0;
            return baseGold[l - 1].nd;
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

    static class IntIntPair {
        public int st;
        public int nd;

        public static IntIntPair of(int st, int nd) {
            return new IntIntPair(st, nd);
        }

        private IntIntPair(int st, int nd) {
            this.st = st;
            this.nd = nd;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            IntIntPair intIntPair = (IntIntPair) o;
            return st == intIntPair.st &&
                    nd == intIntPair.nd;
        }

        public int hashCode() {
            return Objects.hash(st, nd);
        }

        public String toString() {
            return "(" + st + " " + nd + ")";
        }

    }
}