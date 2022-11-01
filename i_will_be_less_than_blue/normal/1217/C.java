import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Objects;
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
        CTheNumberOfGoodSubstrings solver = new CTheNumberOfGoodSubstrings();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CTheNumberOfGoodSubstrings {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.next();
            int n = s.length();
            int[] left = new int[n];
            left[0] = 0;
            for (int i = 1; i < n; ) {
                int j = i;
                while (j < n && s.charAt(j - 1) == '0') {
                    left[j] = left[j - 1] + 1;
                    j++;
                }
                i = j + 1;
            }
            Set<IntIntPair> seenValues = new HashSet<>();
            int count = 0;
            for (int i = 1; i <= 19; i++) {
                for (int j = 0; j < s.length() - i + 1; j++) {
                    int value = Integer.parseInt(s.substring(j, j + i), 2);
                    if (i > value) continue;
                    IntIntPair ob = IntIntPair.of(i + j - value, i + j - 1);
                    if (!seenValues.contains(ob) && i + left[j] >= value) {
                        ++count;
                        seenValues.add(ob);
                    }
                }
            }
            out.printLine(count);
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