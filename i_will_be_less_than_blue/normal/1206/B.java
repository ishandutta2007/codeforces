import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.stream.Stream;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(in.i());
            }
            list.sort(Comparator.naturalOrder());
            int numberOfNegative = (int) list.stream().filter(e -> e < 0).count();
            long ans = 0;
            if (numberOfNegative % 2 != 0) {
                numberOfNegative--;
            }
            for (int i = 0; i < numberOfNegative; i++) {
                ans += Math.abs(list.get(i) + 1);
            }
            for (int i = numberOfNegative; i < n; ) {
                if (list.get(i) < 0) {
                    if (i + 1 < n) {
                        long first = (long) Math.abs(list.get(i) + 1) + (long) Math.abs(list.get(i + 1) + 1);
                        long secon = (long) Math.abs(list.get(i) - 1) + (long) Math.abs(list.get(i + 1) - 1);
                        ans += Math.min(first, secon);
                        i += 2;
                    } else {
                        ans += Math.abs(list.get(i) - 1);
                        i++;
                    }
                } else {
                    ans += Math.abs(list.get(i) - 1);
                    i++;
                }

            }
            out.println(ans);
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