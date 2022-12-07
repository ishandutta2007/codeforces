import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DAlmostAllDivisors solver = new DAlmostAllDivisors();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAlmostAllDivisors {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            int sieve[] = new int[1000001];
            int ind[] = new int[1000001];
            ArrayList<Long> primes = new ArrayList<>();
            for (int i = 2; i <= 1000000; ++i) {
                if (sieve[i] == 0) {
                    primes.add((long) i);
                    ind[i] = primes.size() - 1;
                    for (int j = i; j <= 1000000; j += i)
                        sieve[j] = i;
                }
            }

            main:
            for (int x = 0; x < t; ++x) {
                int n = sc.nextInt();

                long div[] = new long[n];
                for (int i = 0; i < n; ++i) {
                    div[i] = sc.nextLong();
                }

                long[] temp = (long[]) div.clone();

                int cnt[] = new int[primes.size()];
                for (int i = 0; i < n; ++i) {
                    while (div[i] != 1) {
                        int curP = sieve[(int) div[i]];
                        int curInd = ind[curP];
                        int curCnt = 0;
                        while (div[i] % curP == 0) {
                            div[i] /= curP;
                            curCnt++;
                        }

                        cnt[curInd] = Math.max(cnt[curInd], curCnt);
                    }
                }

                long req = 1;
                for (int i = 0; i < primes.size(); ++i) {
                    req *= (cnt[i] + 1);

                    if (req - 2 > n) {
                        out.println("-1");
                        continue main;
                    }
                }

                long val = 1L;
                int cntP = 0;
                long lastPrime = -1, cntLastPrime = 0;
                for (int i = 0; i < primes.size(); ++i) {
                    if (cnt[i] > 0) {
                        for (int j = 0; j < cnt[i]; ++j)
                            val *= primes.get(i);
                        cntP++;
                        lastPrime = primes.get(i);
                        cntLastPrime = cnt[i] + 1;
                    }
                }

                if (cntP == 1) {
                    val *= lastPrime;
                    req /= cntLastPrime;
                    req *= (cntLastPrime + 1);
                }

                if (req - 2 != n) {
                    out.println("-1");
                    continue main;
                }

                int flag = 0;
                for (int i = 0; i < n; ++i) {
                    if (temp[i] == val)
                        flag = 1;
                }

                if (flag == 1)
                    out.println("-1");
                else
                    out.println(val);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;

            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}