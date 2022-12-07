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
 * @author Sanket Makani
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        public void solve(int testNumber, InputReader sc, PrintWriter w) {

            int n = sc.nextInt();

            int arr[] = new int[n + 2];
            arr[0] = 0;
            arr[n + 1] = 0;

            int start = 0;
            int end = n;

            for (int i = 1; i <= n; i++)
                arr[i] = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                if (arr[i] > arr[i - 1])
                    start = i;
                else
                    break;
            }

            for (int i = n; i > 0; i--) {
                if (arr[i] > arr[i + 1])
                    end = i;
                else
                    break;
            }

            if (start >= end)
                w.println("0");
            else {
                long forward[] = new long[n + 2];
                long prev[] = new long[n + 2];
                long next[] = new long[n + 2];
                long reverse[] = new long[n + 2];

                for (int i = 1; i <= n; i++) {
                    prev[i] = prev[i - 1] + 1;
                    if (prev[i] < arr[i]) {
                        prev[i] = arr[i];
                        forward[i] += forward[i - 1];
                    } else {
                        forward[i] += forward[i - 1] + (prev[i] - arr[i]);
                    }
                }

                for (int i = n; i > 0; i--) {
                    next[i] = next[i + 1] + 1;
                    if (next[i] < arr[i]) {
                        next[i] = arr[i];
                        reverse[i] += reverse[i + 1];
                    } else {
                        reverse[i] += reverse[i + 1] + next[i] - arr[i];
                    }
                }

//            w.println(Arrays.toString(forward));
//            w.println(Arrays.toString(reverse));
//            w.println(Arrays.toString(prev));
//            w.println(Arrays.toString(next));

                long ans = Long.MAX_VALUE;

                for (int i = 1; i <= n; i++) {
                    if (prev[i] != next[i + 1])
                        ans = Math.min(ans, forward[i] + reverse[i + 1]);
                }

                w.println(ans);
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