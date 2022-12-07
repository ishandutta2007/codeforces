import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        E1DaleksInvasionEasy solver = new E1DaleksInvasionEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1DaleksInvasionEasy {
        int[] par;
        Edge[] e;

        boolean union(int i, int j) {
            i = findSet(i);
            j = findSet(j);

            if (i == j)
                return false;

            par[j] = i;
            return true;
        }

        int findSet(int i) {
            if (par[i] == i)
                return i;
            par[i] = findSet(par[i]);
            return par[i];
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            e = new Edge[m];
            for (int i = 0; i < m; ++i) {
                e[i] = new Edge(i, sc.nextInt() - 1, sc.nextInt() - 1, sc.nextLong());
            }

            par = new int[n];
            long start = 0, end = (long) 1e9, ans = 0;
            while (start <= end) {
                long mid = (start + end) >> 1;

                for (int i = 0; i < m; ++i) {
                    if (e[i].ind == 0)
                        e[i].weight = mid;
                }

                Arrays.sort(e, new Comparator<Edge>() {

                    public int compare(Edge o1, Edge o2) {
                        if (o1.weight < o2.weight)
                            return -1;
                        if (o1.weight > o2.weight)
                            return 1;

                        if (o1.ind < o2.ind)
                            return -1;
                        if (o1.ind > o2.ind)
                            return 1;
                        return 0;
                    }
                });

                for (int i = 0; i < n; ++i)
                    par[i] = i;

                int flag = 0;
                for (int i = 0; i < m; ++i) {
                    if (union(e[i].u, e[i].v)) {
                        if (e[i].ind == 0)
                            flag = 1;
                    }
                }

                if (flag == 1) {
                    ans = mid;
                    start = mid + 1;
                } else
                    end = mid - 1;
            }

            out.print(ans);
        }

        class Edge {
            int u;
            int v;
            int ind;
            long weight;

            Edge(int a, int b, int c, long d) {
                ind = a;
                u = b;
                v = c;
                weight = d;
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