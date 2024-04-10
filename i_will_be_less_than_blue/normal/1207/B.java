import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            int m = in.i();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = in.i();
                }
            }
            List<Pair> pair = new ArrayList<>();
            int[][] b = new int[n][m];
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    if (check(a, i, j)) {
                        b[i][j] = 1;
                        b[i + 1][j] = 1;
                        b[i][j + 1] = 1;
                        b[i + 1][j + 1] = 1;
                        pair.add(new Pair(i + 1, j + 1));
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!(a[i][j] == b[i][j])) {
                        out.println(-1);
                        return;
                    }
                }
            }
            out.println(pair.size());
            pair.forEach(e -> out.println(e.st + " " + e.nd));
        }

        private boolean check(int[][] a, int i, int j) {
            return a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1;
        }

    }

    static class Pair {
        public int st;
        public int nd;

        public Pair(int st, int nd) {
            this.st = st;
            this.nd = nd;
        }

        public String toString() {
            return "Pair{" +
                "st=" + st +
                ", nd=" + nd +
                '}';
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