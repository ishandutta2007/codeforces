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
        A2HeidiLearnsHashingMedium solver = new A2HeidiLearnsHashingMedium();
        solver.solve(1, in, out);
        out.close();
    }

    static class A2HeidiLearnsHashingMedium {
        int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            char[] s = sc.next().toCharArray();

            int zflag = 0;
            for (int i = 0; i < s.length; ++i) {
                if (s[i] == '1')
                    zflag = 1;
            }

            if (zflag == 0) {
                out.print(n);
                return;
            }

            int poss[] = new int[n + 1];

            for (int i = 1; i <= n; ++i) {
                if (n % i == 0) {
                    int flag = 0;
                    for (int j = 0; j < i; ++j) {
                        int cnt = 0;
                        for (int k = j; k < n; k += i) {
                            if (s[k] == '1')
                                cnt++;
                        }
                        if (cnt % 2 == 1)
                            flag = 1;
                    }
                    poss[i] = flag ^ 1;
                }
            }

            int ans = 0;
            for (int i = 1; i < n; ++i) {
                int cv = gcd(i, n);
                ans += poss[cv];
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}