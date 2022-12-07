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
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CObtainTheString solver = new CObtainTheString();
        solver.solve(1, in, out);
        out.close();
    }

    static class CObtainTheString {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            for (int x = 0; x < t; ++x) {
                char[] s = sc.next().toCharArray();
                char[] p = sc.next().toCharArray();

                int lastInd[] = new int[26];
                int nextInd[][] = new int[s.length][26];
                Arrays.fill(lastInd, -1);
                for (int i = s.length - 1; i >= 0; --i) {
                    for (int j = 0; j < 26; ++j)
                        nextInd[i][j] = lastInd[j];
                    lastInd[s[i] - 'a'] = i;
                }

                int ptr = 0;
                int ans = 0;
                while (ptr < p.length) {
                    int curInd = lastInd[p[ptr] - 'a'];

                    if (curInd == -1) {
                        ans = -1;
                        break;
                    }

                    ans++;

                    while (ptr < p.length) {
                        if (curInd == -1) {
                            break;
                        }

                        ptr++;

                        if (ptr < p.length)
                            curInd = nextInd[curInd][p[ptr] - 'a'];
                    }
                }

                out.println(ans);
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