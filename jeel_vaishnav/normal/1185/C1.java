import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        C2ExamInBerSUHardVersion solver = new C2ExamInBerSUHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2ExamInBerSUHardVersion {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            long m = sc.nextLong();

            long a[] = new long[n];
            PriorityQueue<Long> queueRetained = new PriorityQueue<>(new Comparator<Long>() {

                public int compare(Long o1, Long o2) {
                    if (o1 > o2)
                        return -1;
                    if (o1 < o2)
                        return 1;
                    return 0;
                }
            });

            PriorityQueue<Long> queueRemoved = new PriorityQueue<>();

            for (int i = 0; i < n; ++i)
                a[i] = sc.nextLong();

            long sumRetained = 0, sumRemoved = 0;

            for (int i = 0; i < n; ++i) {
                while (queueRemoved.size() > 0 && queueRetained.size() > 0 && queueRemoved.peek() < queueRetained.peek()) {
                    long val1 = queueRemoved.poll();
                    long val2 = queueRetained.poll();

                    sumRetained -= val2;
                    sumRetained += val1;

                    queueRemoved.add(val2);
                    queueRetained.add(val1);
                }

                while (sumRetained + a[i] > m) {
                    sumRetained -= queueRetained.peek();
                    queueRemoved.add(queueRetained.poll());
                }
                while (queueRemoved.size() > 0 && sumRetained + a[i] + queueRemoved.peek() <= m) {
                    long val = queueRemoved.poll();
                    queueRetained.add(val);
                    sumRetained += val;
                }

                out.print(queueRemoved.size() + " ");
                queueRetained.add(a[i]);
                sumRetained += a[i];
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