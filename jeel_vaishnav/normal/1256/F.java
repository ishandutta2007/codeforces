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
        FEqualizingTwoStrings solver = new FEqualizingTwoStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class FEqualizingTwoStrings {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int q = sc.nextInt();

            main:
            for (int x = 0; x < q; ++x) {
                int n = sc.nextInt();
                char[] s = sc.next().toCharArray();
                char[] t = sc.next().toCharArray();

                int freq[] = new int[26];
                for (int i = 0; i < n; ++i) {
                    freq[s[i] - 'a']++;
                    freq[t[i] - 'a']--;
                }

                for (int i = 0; i < 26; ++i) {
                    if (freq[i] != 0) {
                        out.println("NO");
                        continue main;
                    }
                }

                for (int i = 0; i < n; ++i)
                    freq[s[i] - 'a']++;
                for (int i = 0; i < 26; ++i) {
                    if (freq[i] > 1) {
                        out.println("YES");
                        continue main;
                    }
                }

                int cnt[] = new int[26];
                int map[] = new int[26];
                for (int i = 0; i < n; ++i) {
                    map[t[i] - 'a'] = i;
                }
                int swaps = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = map[s[i] - 'a']; j < 26; ++j)
                        swaps += cnt[j];
                    cnt[map[s[i] - 'a']]++;
                }
                if (swaps % 2 == 0)
                    out.println("YES");
                else
                    out.println("NO");
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