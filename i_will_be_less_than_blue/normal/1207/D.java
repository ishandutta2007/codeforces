import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.function.Function;
import java.util.Objects;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final long MOD = 998244353L;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            List<Point> input = IntStream.range(0, n)
                .mapToObj(e -> new Point(in.l(), in.l()))
                .collect(Collectors.toList());
            ModUtil m = new ModUtil(MOD);
            Factorial f = m.getFactorial(n + 1);
            //sort by x
            Map<Long, Long> frequencyX = input.stream()
                .sorted(Comparator.comparingLong(e -> e.x))
                .map(e -> e.x)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

            long ans1 = frequencyX.values().stream().reduce(1L, (a, b) -> m.mod(a * f.fact(b)));

            Map<Long, Long> frequencyY = input.stream()
                .sorted(Comparator.comparingLong(e -> e.y))
                .map(e -> e.y)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

            long ans2 = frequencyY.values().stream().reduce(1L, (a, b) -> m.mod(a * f.fact(b)));

            Map<Point, Long> frequencyPair = input.stream()
                .sorted(Comparator.comparing(e -> e.x * 1_000_000L + e.y))
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

            long ans3 = frequencyPair.values().stream().reduce(1L, (a, b) -> m.mod(a * f.fact(b)));
            input.sort(Comparator.comparing(e -> e.x * 1_000_000L + e.y));
            //check if it is not sorted by pairs elements
            boolean isAnySmaller = IntStream.range(1, n).anyMatch(i -> input.get(i).y < input.get(i - 1).y);
            long ans = f.fact(n);
//        ans += MOD - ans1;
//        ans += MOD - ans2;
//        ans += isAnySmaller ? 0 : ans3;
            out.println(m.mod(ans - ans1 - ans2 + (isAnySmaller ? 0 : ans3)));
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

    static class ModUtil {
        private static final int DEFAULT_MOD = 1_000_000_007;
        private final long mod;

        private ModUtil(long mod, boolean unsafe) {
        /*if (!unsafe && !IntMath.isPrime(mod)) {
            throw new RuntimeException("This class is designed for primes!");
        }*/
            this.mod = mod;
        }

        public ModUtil(long mod) {
            this(mod, false);
        }

        public ModUtil() {
            this(DEFAULT_MOD, true);
        }

        public long mod(long x) {
            x %= mod;
            return x < 0 ? x + mod : x;
        }

        public long inv(long x) {
            return modPow(x, mod - 2);
            //return mod(LongEuclidSolver.solve(x, mod).x);
        }

        public long modPow(long base, long exp) {
            long res = 1L;
            while (exp > 0) {
                if (exp % 2 == 1)
                    res = (res * base) % mod;
                base = (base * base) % mod;
                exp >>= 1;
            }
            return res;
        }

        public Factorial getFactorial(int n) {
            return new Factorial(this, n);
        }

    }

    static class Factorial {
        private final ModUtil mod;
        private final long[] natural;
        private final long[] reverse;

        public Factorial(ModUtil mod, int max) {
            this.mod = mod;
            this.natural = new long[max];
            this.reverse = new long[max];
            natural[0] = 1;
            for (int i = 1; i < max; i++) {
                natural[i] = mod.mod(natural[i - 1] * i);
            }
            reverse[max - 1] = mod.inv(natural[max - 1]);
            for (int i = max - 1; i > 0; i--) {
                reverse[i - 1] = mod.mod(reverse[i] * i);
            }
        }

        public long fact(long x) {
            return natural[(int) x];
        }

    }

    static class Point {
        public long x;
        public long y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x &&
                y == point.y;
        }

        public int hashCode() {
            return Objects.hash(x, y);
        }

    }
}