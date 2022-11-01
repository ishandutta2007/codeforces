import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.LongStream;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
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
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            long x = in.l();
            List<Triplet<Long, Long, Long>> pair = new ArrayList<>();
            boolean allS = false;
            boolean anyGreaterX = false;
            for (int i = 0; i < n; i++) {
                long u = in.l();
                long v = in.l();
                if (u > v) allS = true;
                if (u >= x) anyGreaterX = true;
                pair.add(Triplet.of(u, v, u - v));
            }
            if (anyGreaterX) {
                out.printLine(1);
                return;
            }
            if (!allS) {
                out.printLine(-1);
                return;
            }
            Comparator<Triplet<Long, Long, Long>> c = Comparator.comparing(Triplet<Long, Long, Long>::getRd).reversed().thenComparing(Triplet::getSt);
            pair.sort(c);
            long max = pair.stream().mapToLong(Triplet::getSt).reduce(0L, Long::max);
            Triplet p = pair.get(0);
            long ans = myAns((long) p.st, (long) p.nd, x, max);
            out.printLine(ans);
        }

        private long myAns(long st, long nd, long x, long max) {
            long l = 0;
            long h = (long) 1e9 + 5;
            while (l <= h) {
                long m = l + (h - l) / 2;
                if (x - m * st + m * nd <= max) h = m - 1;
                else l = m + 1;
            }
            return l + 1;
        }

    }

    static class Triplet<A, B, C> {
        public A st;
        public B nd;
        public C rd;

        public static <A, B, C> Triplet<A, B, C> of(A st, B nd, C rd) {
            return new Triplet<>(st, nd, rd);
        }

        private Triplet(A st, B nd, C rd) {
            this.st = st;
            this.nd = nd;
            this.rd = rd;
        }

        public A getSt() {
            return st;
        }

        public C getRd() {
            return rd;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Triplet<?, ?, ?> triplet = (Triplet<?, ?, ?>) o;
            return Objects.equals(st, triplet.st) &&
                    Objects.equals(nd, triplet.nd) &&
                    Objects.equals(rd, triplet.rd);
        }

        public int hashCode() {
            return Objects.hash(st, nd, rd);
        }

        public String toString() {
            return "Triplet{" +
                    "st=" + st +
                    ", nd=" + nd +
                    ", rd=" + rd +
                    '}';
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

        public void printLine(long i) {
            writer.println(i);
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }
}