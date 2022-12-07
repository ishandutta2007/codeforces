import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        EGoshaIsHunting solver = new EGoshaIsHunting();
        solver.solve(1, in, out);
        out.close();
    }

    static class EGoshaIsHunting {
        void resolve(double[] dp, int[] cnta, int[] cntb, int ind, double newVal, int newCnta, int newCntb) {
            if (newVal > dp[ind]) {
                dp[ind] = newVal;
                cnta[ind] = newCnta;
                cntb[ind] = newCntb;
            } else if (newVal == dp[ind] && cnta[ind] > newCnta) {
                cntb[ind] = newCntb;
                cnta[ind] = newCnta;
            } else if (newVal == dp[ind] && cnta[ind] == newCnta && cntb[ind] > newCntb)
                cntb[ind] = newCntb;
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();

            double p[] = new double[n + 1];
            for (int i = 1; i <= n; ++i)
                p[i] = sc.nextDouble();

            double u[] = new double[n + 1];
            for (int i = 1; i <= n; ++i)
                u[i] = sc.nextDouble();

            double starta = 0.0, enda = 10.0;
            double ans = 0.0;
            for (int i = 0; i < 100; ++i) {
                double mida = (starta + enda) * 0.5;

                double startb = 0.0, endb = 1.0;
                double cans = 0.0;
                int canscnta = -1;
                for (int j = 0; j < 100; ++j) {
                    double midb = (startb + endb) * 0.5;

                    double dp[] = new double[n + 1];
                    int cntb[] = new int[n + 1];
                    int cnta[] = new int[n + 1];

                    for (int k = 1; k <= n; ++k) {
                        dp[k] = dp[k - 1];
                        cntb[k] = cntb[k - 1];
                        cnta[k] = cnta[k - 1];

                        resolve(dp, cnta, cntb, k, dp[k - 1] + p[k] - mida, cnta[k - 1] + 1, cntb[k - 1]);
                        resolve(dp, cnta, cntb, k, dp[k - 1] + u[k] - midb, cnta[k - 1], cntb[k - 1] + 1);
                        resolve(dp, cnta, cntb, k, dp[k - 1] + u[k] + p[k] - u[k] * p[k] - mida - midb, cnta[k - 1] + 1, cntb[k - 1] + 1);
                    }

                    if (cntb[n] > b) {
                        startb = midb;
                    } else {
                        endb = midb;
                        cans = dp[n] + midb * b;
                        canscnta = cnta[n];
                    }
                }

                if (canscnta > a) {
                    starta = mida;
                } else {
                    ans = cans + mida * a;
                    enda = mida;
                }
            }

            out.print(ans);
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

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
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