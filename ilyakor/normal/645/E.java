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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final int mod = 1000 * 1000 * 1000 + 7;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            char[] s = in.nextToken().toCharArray();
            int m = s.length;
            char[] a = new char[n + m];
            int[] prev = new int[300];
            Arrays.fill(prev, -1);
            for (int i = 0; i < m; ++i) {
                a[i] = s[i];
                prev[s[i]] = i;
            }
            ArrayList<ComparablePair<Integer, Character>> order = new ArrayList<>();
            for (char c = 'a'; c < (char) ('a' + k); ++c) {
                order.add(new ComparablePair<Integer, Character>(prev[c], c));
            }
            Collections.sort(order);
            char[] vals = new char[k];
            for (int i = 0; i < k; ++i)
                vals[i] = order.get(i).second;
            for (int i = 0; i < n; ++i)
                a[m + i] = vals[i % k];
            long[] d = new long[m + n + 1];
            long[] sum = new long[m + n + 2];
            d[0] = 1;
            sum[1] = 1;
            Arrays.fill(prev, -1);
            for (int i = 0; i < n + m; ++i) {
                int l = prev[a[i]];
                int r = i - 1;
                ++l;
                ++r;
                long cur = sum[r + 1] - sum[l];
                cur %= mod;
                cur += mod;
                cur %= mod;
                d[i + 1] = cur;
                sum[i + 2] = (sum[i + 1] + d[i + 1]) % mod;
                prev[a[i]] = i;
            }
            long res = 0;
            for (int i = 0; i < d.length; ++i)
                res = (res + d[i]) % mod;
            out.printLine(res);
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

        public String nextToken() {
            int c = readSkipSpace();
            StringBuilder sb = new StringBuilder();
            while (!isSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
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
}