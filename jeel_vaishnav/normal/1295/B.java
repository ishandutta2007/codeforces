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
        BInfinitePrefixes solver = new BInfinitePrefixes();
        solver.solve(1, in, out);
        out.close();
    }

    static class BInfinitePrefixes {
        int sign(long a) {
            return a < 0 ? -1 : 1;
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            for (int x = 0; x < t; ++x) {
                int n = sc.nextInt();
                long reqVal = sc.nextLong();

                char[] s = sc.next().toCharArray();

                if (reqVal < 0) {
                    reqVal = -reqVal;
                    for (int i = 0; i < s.length; ++i) {
                        if (s[i] == '0')
                            s[i] = '1';
                        else
                            s[i] = '0';
                    }
                }

                long totalChange = 0;
                for (int i = 0; i < s.length; ++i) {
                    if (s[i] == '0')
                        totalChange++;
                    else
                        totalChange--;
                }

                if (totalChange == 0) {
                    int curChange = 0;
                    int poss = 0;
                    for (int i = 0; i < s.length; ++i) {
                        if (curChange == reqVal)
                            poss++;
                        if (s[i] == '0')
                            curChange++;
                        else
                            curChange--;
                    }
                    if (poss != 0)
                        out.println("-1");
                    else
                        out.println("0");
                } else {
                    long curChange = 0;
                    long ans = 0;
                    for (int i = 0; i < s.length; ++i) {
                        if (reqVal - curChange == 0)
                            ans++;
                        else if (sign(reqVal - curChange) == sign(totalChange)) {
                            if (Math.abs(reqVal - curChange) % Math.abs(totalChange) == 0)
                                ans++;
                        }
                        if (s[i] == '0')
                            curChange++;
                        else
                            curChange--;
                    }
                    out.println(ans);
                }
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