import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private static final int MAX = (int) 1e6 + 6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            long[] array = in.la(n);
            long gcd = gcdOfArray(array);
            int[] prime = SieveUtil.linearSieveStoresFirstPrime(MAX)[0];
            out.println(IntegerUtil.numberOfFactors(gcd, prime));
        }

        private long gcdOfArray(long[] array) {
            long gcd = array[0];
            for (long l : array) {
                gcd = IntegerUtil.gcd(gcd, l);
            }
            return gcd;
        }

    }

    static class SieveUtil {
        public static int[][] linearSieveStoresFirstPrime(int N) {
            int[] store = new int[N];
            int[] prime = new int[N];
            int k = 0;
            Arrays.fill(store, 0);
            store[1] = 1;
            for (int i = 2; i < N; i++) {
                if (store[i] == 0) {
                    prime[k++] = i;
                    store[i] = i;
                }
                for (int j = 0; j < k && i * prime[j] < N && prime[j] <= store[i]; j++) {
                    store[i * prime[j]] = prime[j];
                    if (i % prime[j] == 0) break;
                }
            }
            prime = Arrays.copyOf(prime, k);
            return new int[][]{prime, store};
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

        public long[] la(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = l();
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

    static class IntegerUtil {
        public static long numberOfFactors(long b, int[] prime) {
            long ans = 1;
            for (int p : prime) {
                long count = 0;
                if (b % p == 0) {
                    while (b % p == 0) {
                        b /= p;
                        count++;
                    }
                }
                ans *= (count + 1);
            }
            if (BigInteger.valueOf(b).isProbablePrime(1)) ans *= 2;
            return ans;
        }

        public static long gcd(long a, long b) {
            return (b == 0) ? a : gcd(b, a % b);
        }

    }
}