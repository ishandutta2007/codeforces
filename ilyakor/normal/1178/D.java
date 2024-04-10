import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        HashSet<Integer> primeSet;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            primeSet = new HashSet<>();
            int[] primes = PrimesGenerator.getPrimesLinear(10000);
            for (int x : primes)
                primeSet.add(x);
            int n = in.nextInt();
            int m = calc(n);
            out.printLine(n + m);
            HashSet<ii> res = new HashSet<>();
            int[] deg = new int[n];
            for (int i = 0; i < n; ++i) {
                out.printLine((i + 1) + " " + ((i + 1) % n + 1));
                res.add(new ii(i, (i + 1) % n));
                ++deg[i];
                ++deg[(i + 1) % n];
            }
            for (int i = 0; i < m; ++i) {
                out.printLine((i + 1) + " " + ((n + 1) / 2 + i + 1));
                ii val = new ii(i, (n + 1) / 2 + i);
                if (res.contains(val)) throw new RuntimeException();
                res.add(val);
                ++deg[i];
                ++deg[(n + 1) / 2 + i];
            }
            for (int i = 0; i < n; ++i)
                if (deg[i] != 2 && deg[i] != 3)
                    throw new RuntimeException();
        }

        int calc(int n) {
            for (int i = 0; i * 2 <= n; ++i) {
                if (primeSet.contains(n + i))
                    return i;
            }
            throw new RuntimeException();
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

    static class PrimesGenerator {
        public static int[] getPrimesLinear(int n) {
            int[] lp = new int[n + 1];
            int[] primes = new int[n + 1];
            int cnt = 0;

            for (int i = 2; i <= n; ++i) {
                if (lp[i] == 0) {
                    lp[i] = i;
                    primes[cnt++] = i;
                }
                for (int j = 0; j < cnt && primes[j] <= lp[i] && i * primes[j] <= n; ++j) {
                    lp[i * primes[j]] = primes[j];
                }
            }

            return Arrays.copyOf(primes, cnt);
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
}