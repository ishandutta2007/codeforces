import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Arrays;
import java.util.PriorityQueue;
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
        D2TooManySegmentsHardVersion solver = new D2TooManySegmentsHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class D2TooManySegmentsHardVersion {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int cnt[] = new int[(int) 2e5 + 1];

            Segment s[] = new Segment[n];
            for (int i = 0; i < n; ++i)
                s[i] = new Segment(i, sc.nextInt() - 1, sc.nextInt() - 1);
            Arrays.sort(s, new Comparator<Segment>() {

                public int compare(Segment o1, Segment o2) {
                    if (o1.l < o2.l)
                        return -1;
                    if (o1.l > o2.l)
                        return 1;
                    return 0;
                }
            });
            PriorityQueue<Segment> queue = new PriorityQueue<>(new Comparator<Segment>() {

                public int compare(Segment o1, Segment o2) {
                    if (o1.r > o2.r)
                        return -1;
                    if (o1.r < o2.r)
                        return 1;
                    return 0;
                }
            });
            int ptr = 0;
            int add = 0;
            HashSet<Integer> indices = new HashSet<>();
            for (int i = 0; i < (int) 2e5; ++i) {
                while (ptr < n && s[ptr].l <= i) {
                    queue.add(s[ptr]);
                    cnt[s[ptr].r + 1]--;
                    ptr++;
                    add++;
                }
                add += cnt[i];
                while (add > k) {
                    Segment curS = queue.poll();
                    indices.add(curS.ind);
                    add--;
                    cnt[curS.r + 1]++;
                }
            }

            out.println(indices.size());
            for (int i : indices)
                out.print((i + 1) + " ");
        }

        class Segment {
            int ind;
            int l;
            int r;

            Segment(int a, int b, int c) {
                ind = a;
                l = b;
                r = c;
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