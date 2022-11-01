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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] input = in.next().toCharArray();
            int n = input.length;
            long[][] distance = new long[10][10];
            for (int x = 0; x < 10; x++)
                for (int y = 0; y < 10; y++) {
                    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) distance[i][j] = Cons.INF;
                    for (int i = 0; i < 10; i++) {
                        distance[i][(i + x) % 10] = distance[i][(i + y) % 10] = 1;
                    }
                    for (int k = 0; k < 10; k++) {
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                            }
                        }
                    }
                    long ans = 0;
                    boolean notGood = false;
                    for (int i = 0; i < n - 1; i++) {
                        int f = input[i] - '0';
                        int t = input[i + 1] - '0';
                        if (distance[f][t] == Cons.INF) {
                            out.print(-1 + " ");
                            notGood = true;
                            break;
                        } else {
                            ans += distance[f][t] - 1;
                        }
                    }
                    if (!notGood) out.print(ans + " ");
                    if (y == 9) out.println();
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

    }

    static class Cons {
        public static long INF = (long) 1e18 + 100;

    }
}