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
        CDrazilLikesHeap solver = new CDrazilLikesHeap();
        solver.solve(1, in, out);
        out.close();
    }

    static class CDrazilLikesHeap {
        int g;
        int h;
        long sum = 0;
        ArrayList<Integer> ans;
        int[] a;

        boolean check(int i, int level) {
            if (a[i] == 0)
                return false;

            if (level == h) {
                return true;
            }

            if (a[2 * i + 1] == 0 && a[2 * i + 2] == 0) {
                if (level > g)
                    return true;
                return false;
            }

            if (a[2 * i + 1] > a[2 * i + 2]) {
                return check(2 * i + 1, level + 1);
            } else
                return check(2 * i + 2, level + 1);
        }

        void doing(int i, int level) {
            if (level == h) {
                a[i] = 0;
                return;
            }

            if (a[2 * i + 1] == 0 && a[2 * i + 2] == 0) {
                a[i] = 0;
                return;
            }

            if (a[2 * i + 1] > a[2 * i + 2]) {
                a[i] = a[2 * i + 1];
                doing(2 * i + 1, level + 1);
            } else {
                a[i] = a[2 * i + 2];
                doing(2 * i + 2, level + 1);
            }
        }

        void dfs(int i, int level) {
            while (check(i, level)) {
//            System.out.println(i + " " + level);
//            for(int j = 0; j < ((1 << h) - 1); ++j)
//                System.out.print(a[j] + " ");
//            System.out.println();

                ans.add(i + 1);
                sum -= a[i];
                doing(i, level);
//            cnt++;
//            if(cnt > 5)
//                return;
            }

            if (level < h) {
                dfs(2 * i + 1, level + 1);
                dfs(2 * i + 2, level + 1);
            }
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int t = sc.nextInt();

            for (int x = 0; x < t; ++x) {
                h = sc.nextInt();
                g = sc.nextInt();

                int n = (1 << h) - 1;
                int removed = (1 << h) - (1 << g);
                a = new int[n];
                for (int i = 0; i < n; ++i)
                    a[i] = sc.nextInt();

                sum = 0;
                for (int i = 0; i < n; ++i)
                    sum += a[i];

                ans = new ArrayList<>();
                dfs(0, 1);

                out.println(sum);
                for (int i : ans)
                    out.print(i + " ");
                out.println();
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