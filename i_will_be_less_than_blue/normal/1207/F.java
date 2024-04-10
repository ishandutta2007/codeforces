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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        private static final int MAX = 500001;
        private static final int SQRT = (int) Math.sqrt(MAX) + 1;
        private int[][] storedSolution;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCase = in.i();
            int[] a = new int[MAX];
            storedSolution = new int[SQRT + 1][SQRT + 1];
            for (int i = 0; i < testCase; i++) {
                int t = in.i();
                int x = in.i();
                int y = in.i();
                if (t == 1) {
                    a[x] += y;
                    buildSqrtSolution(a, x, y);
                } else {
                    if (x < SQRT) {
                        out.println(storedSolution[x][y]);
                    } else {
                        long sum = 0;
                        for (int j = y; j < MAX; j += x) {
                            sum += a[j];
                        }
                        out.println(sum);
                    }
                }
            }
        }

        private void buildSqrtSolution(int[] a, int x, int y) {
            for (int i = 1; i < SQRT; i++) {
                storedSolution[i][x % i] += y;
            }
        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int i() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}