import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            int[] prime = SieveUtil.linearSieveStoresFirstPrime(10000)[0];
            int index = IntegerUtil.lowerBound(prime, n);
            int firstGreaterPrime = prime[index];
            out.println(firstGreaterPrime);
            int extraNeed = firstGreaterPrime - n;
            for (int i = 1; i <= n; i++) {
                int nd = (i + 1) % n == 0 ? n : (i + 1) % n;
                out.println(i + " " + nd);
            }
            int st = 2;
            int nd = n;
            while (extraNeed-- > 0) {
                out.println(st++ + " " + nd--);
            }
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

    static class IntegerUtil {
        public static int lowerBound(int[] a, int key) {
            int l = 0;
            int h = a.length;
            while (l < h) {
                int mid = (l + h) >> 1;
                if (key <= a[mid]) h = mid;
                else l = mid + 1;
            }
            return l;
        }

    }
}