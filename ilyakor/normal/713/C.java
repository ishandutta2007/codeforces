import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final long inf = (long) (1E18);

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = in.nextInt() - i;
            long[][] d = new long[n][n];
            for (int i = 0; i < d.length; ++i)
                Arrays.fill(d[i], inf);
            for (int i = 0; i < n; ++i)
                d[0][i] = Math.abs(a[i] - a[0]);
            long res = inf;
            ArrayList<ii> inds = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                inds.add(new ii(a[i], i));
            Collections.shuffle(inds);
            Collections.sort(inds);
            for (int i = 0; i < n - 1; ++i) {
                ArrayList<ComparablePair<Integer, Long>> vals = new ArrayList<>();
                for (int j = 0; j < n; ++j) {
                    if (d[i][j] == inf) continue;
                    d[i + 1][j] = Math.min(d[i + 1][j], d[i][j] + Math.abs(a[i + 1] - a[j]));
                    vals.add(new ComparablePair<>(a[j], d[i][j]));
                }
                Collections.shuffle(vals);
                Collections.sort(vals);
                long mv = inf;
                int u = 0;
                for (ii entry : inds) {
                    while (u < vals.size() && vals.get(u).first <= entry.first) {
                        mv = Math.min(mv, vals.get(u).second);
                        ++u;
                    }
                    d[i + 1][entry.second] = Math.min(d[i + 1][entry.second], mv + (long) Math.abs(a[i + 1] - a[entry.second]));
                }
            }
            for (int i = 0; i < n; ++i)
                res = Math.min(res, d[n - 1][i]);
            out.printLine(res);
        }

    }

    static class Pair<P, Q> {
        public P first;
        public Q second;

        public Pair() {
        }

        public Pair(P first, Q second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
            if (second != null ? !second.equals(pair.second) : pair.second != null) return false;

            return true;
        }


        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

    }

    static class ii implements Comparable<ii> {
        public int first;
        public int second;

        public ii() {
        }

        public ii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            ii ii = (ii) o;

            if (first != ii.first) return false;
            if (second != ii.second) return false;

            return true;
        }

        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }

        public int compareTo(ii o) {
            if (first != o.first) {
                return first < o.first ? -1 : 1;
            }
            if (second != o.second) {
                return second < o.second ? -1 : 1;
            }
            return 0;
        }


        public String toString() {
            return "{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buffer = new byte[10000];
        private int cur;
        private int count;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (count == -1) {
                throw new InputMismatchException();
            }
            try {
                if (cur >= count) {
                    cur = 0;
                    count = stream.read(buffer);
                    if (count <= 0)
                        return -1;
                }
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            return buffer[cur++];
        }

        public int readSkipSpace() {
            int c;
            do {
                c = read();
            } while (isSpace(c));
            return c;
        }

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
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

    static class ComparablePair<P extends Comparable, Q extends Comparable> extends Pair<P, Q> implements Comparable<Pair<P, Q>> {
        public ComparablePair() {
        }

        public ComparablePair(P first, Q second) {
            super(first, second);
        }

        public int compareTo(Pair<P, Q> other) {
            int valP = first.compareTo(other.first);
            if (valP != 0) return valP;
            return second.compareTo(other.second);
        }

    }
}