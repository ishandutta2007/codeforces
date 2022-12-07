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
        BEmailFromPolycarp solver = new BEmailFromPolycarp();
        solver.solve(1, in, out);
        out.close();
    }

    static class BEmailFromPolycarp {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int tc = sc.nextInt();

            main:
            for (int x = 0; x < tc; ++x) {
                char[] s = sc.next().toCharArray();
                char[] t = sc.next().toCharArray();

                ArrayList<Pair> lists = new ArrayList<>();
                ArrayList<Pair> listt = new ArrayList<>();

                int cfreq = 0;
                for (int i = 0; i < s.length; ++i) {
                    cfreq++;
                    if (i == s.length - 1 || s[i + 1] != s[i]) {
                        lists.add(new Pair(s[i], cfreq));
                        cfreq = 0;
                    }
                }

                cfreq = 0;
                for (int i = 0; i < t.length; ++i) {
                    cfreq++;
                    if (i == t.length - 1 || t[i + 1] != t[i]) {
                        listt.add(new Pair(t[i], cfreq));
                        cfreq = 0;
                    }
                }

                if (lists.size() != listt.size()) {
                    out.println("NO");
                    continue;
                }

                for (int i = 0; i < lists.size(); ++i) {
                    if (listt.get(i).a != lists.get(i).a || listt.get(i).freq < lists.get(i).freq) {
                        out.println("NO");
                        continue main;
                    }
                }

                out.println("YES");
            }
        }

        class Pair {
            char a;
            int freq;

            Pair(char b, int c) {
                a = b;
                freq = c;
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