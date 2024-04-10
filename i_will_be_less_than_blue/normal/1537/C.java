import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
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
        ChallengingCliffs solver = new ChallengingCliffs();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class ChallengingCliffs {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            Integer[] a = in.Ia(n);
            final Integer[] solve = solve(n, a);
            out.printLine(solve);
        }

        private Integer[] solve(int n, Integer[] input) {
            if (input.length == 1) {
                return input;
            }
            Arrays.sort(input);
            if (input.length == 2) {
                return input;
            }
            int min = Math.abs(input[1] - input[0]);
            int ind = 1;
            for (int i = 2; i < n; i++) {
                int cur = Math.abs(input[i] - input[i - 1]);
                if (min > cur) {
                    min = cur;
                    ind = i;
                }
            }
            ChallengingCliffs.Pair first = new ChallengingCliffs.Pair(input[ind], 0);
            ChallengingCliffs.Pair last = new ChallengingCliffs.Pair(input[ind - 1], n - 1);
            final List<ChallengingCliffs.Pair> valueIndList = new ArrayList<>(List.of(first, last));
            final TreeSet<ChallengingCliffs.Pair> treeSet = new TreeSet<>(Comparator.comparingInt(ChallengingCliffs.Pair::getVal));
            final Map<Integer, Long> collect = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (i != ind && i != (ind - 1))
                    collect.put(input[i], collect.getOrDefault(input[i], 0L) + 1);
            }
            collect.keySet()
                    .forEach(ele -> treeSet.add(new ChallengingCliffs.Pair(ele, collect.get(ele))));
            boolean turn = true;
            int i = 1;
            int j = n - 2;
            while (!treeSet.isEmpty()) {
                if (turn) {
                    final ChallengingCliffs.Pair ceiling = treeSet.ceiling(first);
                    if (ceiling != null) {
                        treeSet.remove(ceiling);
                        long curCount = ceiling.getCount() - 1;
                        if (curCount > 0) {
                            treeSet.add(new ChallengingCliffs.Pair(ceiling.getVal(), curCount));
                        }
                        valueIndList.add(new ChallengingCliffs.Pair(ceiling.getVal(), i++));
                        first = ceiling;
                    }
                } else {
                    final ChallengingCliffs.Pair floor = treeSet.floor(last);
                    if (floor != null) {
                        treeSet.remove(floor);
                        long curCount = floor.getCount() - 1;
                        if (curCount > 0) {
                            treeSet.add(new ChallengingCliffs.Pair(floor.getVal(), curCount));
                        }
                        valueIndList.add(new ChallengingCliffs.Pair(floor.getVal(), j--));
                        last = floor;
                    }
                }
                turn = !turn;
            }
            valueIndList.sort(Comparator.comparingLong(ele -> ele.count));
            return valueIndList.stream().mapToInt(ele -> ele.val).boxed().toArray(Integer[]::new);
        }

        static class Pair {
            int val;
            long count;

            public Pair(int val, long count) {
                this.val = val;
                this.count = count;
            }

            public int getVal() {
                return val;
            }

            public long getCount() {
                return count;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                ChallengingCliffs.Pair pair = (ChallengingCliffs.Pair) o;
                return val == pair.val;
            }

            public int hashCode() {
                return Objects.hash(val);
            }

            public String toString() {
                return "Pair{" +
                        "val=" + val +
                        ", count=" + count +
                        '}';
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public Integer[] Ia(int n) {
            Integer[] a = new Integer[n];
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
}