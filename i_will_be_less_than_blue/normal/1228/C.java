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
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
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
        CPrimesAndMultiplication solver = new CPrimesAndMultiplication();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPrimesAndMultiplication {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            ModUtil mod = new ModUtil();
            long x = in.l();
            long n = in.l();
            int[] prime = SieveUtil.linearSieve(1000005);
            List<Long> primeFactor = numberOfFactors(x, prime);
            long ans = 1;
            for (Long aLong : primeFactor) {
                long pow = getExpo(n, aLong);
                ans = mod.mod(ans * mod.modPow(aLong, pow));
            }
            out.printLine(ans);
        }

        private long getExpo(long n, Long aLong) {
            BigInteger nBig = BigInteger.valueOf(n);
            BigInteger b = BigInteger.valueOf(aLong);
            int pow = 1;
            BigInteger ans = BigInteger.ZERO;
            while (b.pow(pow).compareTo(nBig) <= 0) {
                ans = ans.add(nBig.divide(b.pow(pow)));
                ++pow;
            }
            return ans.longValue();
        }

        public List<Long> numberOfFactors(long b, int[] prime) {
            List<Long> list = new ArrayList<>();
            for (int p : prime) {
                if (b % p == 0) {
                    list.add((long) p);
                    while (b % p == 0) {
                        b /= p;
                    }
                }
            }
            if (BigInteger.valueOf(b).isProbablePrime(1)) {
                list.add(b);
            }
            return list;
        }

    }

    static class SieveUtil {
        private static ArrayList<Integer> primes = new ArrayList<>();

        public static int[] linearSieve(int N) {
            boolean[] composite = new boolean[N];
            Arrays.fill(composite, false);
            composite[0] = composite[1] = true;
            for (int i = 2; i < N; i++) {
                if (!composite[i]) primes.add(i);
                for (int j = 0; j < primes.size() && i * primes.get(j) < N; j++) {
                    composite[i * primes.get(j)] = true;
                    if (i % primes.get(j) == 0) break;
                }
            }
            int[] prime = new int[N];
            int j = 0;
            for (int i = 0; i < N; i++) {
                if (!composite[i]) prime[j++] = i;
            }
            prime = Arrays.copyOf(prime, j);
            return prime;
        }

    }

    static class IntegerUtil {
        public static boolean isPrime(long val) {
            return BigInteger.valueOf(val).isProbablePrime(1);
        }

    }

    static class ModUtil {
        private static final int DEFAULT_MOD = 1_000_000_007;
        private final long mod;

        private ModUtil(long mod, boolean unsafe) {
            if (!unsafe && !IntegerUtil.isPrime(mod)) {
                throw new RuntimeException("This class is designed for primes!");
            }
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
}