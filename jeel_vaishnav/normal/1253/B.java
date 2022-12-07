import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        BSillyMistake solver = new BSillyMistake();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSillyMistake {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextInt();

            ArrayList<Integer> ans = new ArrayList<>();
            HashSet<Integer> set = new HashSet<>();
            HashSet<Integer> remSet = new HashSet<>();
            int comp = 0;
            for (int i = 0; i < n; ++i) {
                if (set.size() == 0) {
                    if (a[i] < 0) {
                        out.print("-1");
                        return;
                    }
                    set.add(a[i]);
                } else {
                    if (a[i] > 0) {
                        if (set.contains(a[i])) {
                            out.print("-1");
                            return;
                        }
                        set.add(a[i]);
                    } else {
                        a[i] = -a[i];
                        if (!set.contains(a[i]) || remSet.contains(a[i])) {
                            out.print("-1");
                            return;
                        }
                        remSet.add(a[i]);
                        comp++;
                        if (comp == set.size()) {
                            ans.add(2 * comp);
                            set.clear();
                            remSet.clear();
                            comp = 0;
                        }
                    }
                }
            }
            if (set.size() == 0) {
                out.println(ans.size());
                for (int i : ans)
                    out.print(i + " ");
            } else
                out.print("-1");
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