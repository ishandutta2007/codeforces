import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        C2BalancedRemovalsHarder solver = new C2BalancedRemovalsHarder();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2BalancedRemovalsHarder {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            Pair p[] = new Pair[n];
            for (int i = 0; i < n; ++i) {
                p[i] = new Pair(sc.nextInt(), sc.nextInt(), sc.nextInt(), i + 1);
            }
            Arrays.sort(p, new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    if (o1.x < o2.x)
                        return -1;
                    if (o1.x > o2.x)
                        return 1;
                    if (o1.y < o2.y)
                        return -1;
                    if (o1.y > o2.y)
                        return 1;
                    if (o1.z < o2.z)
                        return -1;
                    if (o1.z > o2.z)
                        return 1;
                    return 0;
                }
            });

            ArrayList<Integer> list = new ArrayList<>();
            Pair lastP = null;
            int sel[] = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                if (lastP == null)
                    lastP = p[i];
                else {
                    if (lastP.x == p[i].x && lastP.y == p[i].y) {
                        list.add(lastP.ind);
                        list.add(p[i].ind);

                        sel[lastP.ind] = 1;
                        sel[p[i].ind] = 1;

                        lastP = null;
                    } else
                        lastP = p[i];
                }
            }

            lastP = null;
            for (int i = 0; i < n; ++i) {
                if (sel[p[i].ind] == 0) {
                    if (lastP == null)
                        lastP = p[i];
                    else {
                        if (lastP.x == p[i].x) {
                            list.add(lastP.ind);
                            list.add(p[i].ind);

                            sel[lastP.ind] = 1;
                            sel[p[i].ind] = 1;

                            lastP = null;
                        } else
                            lastP = p[i];
                    }
                }
            }

            lastP = null;
            for (int i = 0; i < n; ++i) {
                if (sel[p[i].ind] == 0) {
                    if (lastP == null)
                        lastP = p[i];
                    else {
                        list.add(lastP.ind);
                        list.add(p[i].ind);

                        sel[lastP.ind] = 1;
                        sel[p[i].ind] = 1;

                        lastP = null;
                    }
                }
            }

            for (int i = 0; i < n; i += 2)
                out.println(list.get(i) + " " + list.get(i + 1));
        }

        class Pair {
            int x;
            int y;
            int z;
            int ind;

            Pair(int a, int b, int c, int d) {
                x = a;
                y = b;
                z = c;
                ind = d;
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