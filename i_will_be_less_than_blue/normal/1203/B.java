import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.io.InputStream;
import java.util.ArrayList;

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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            int[] size = in.ia(4 * n);
            int[] freq = new int[10004];
            for (int i = 0; i < 4 * n; i++) {
                freq[size[i]]++;
            }
            for (int i = 0; i < 10004; i++) {
                if (freq[i] % 2 != 0) {
                    out.println("NO");
                    return;
                }
            }
            List<Integer> makeList = makeListWithFrequency(freq);
            if (makeList.size() % 2 == 1) {
                out.println("NO");
                return;
            }
            makeList.sort(Comparator.naturalOrder());
            int area = makeList.get(0) * makeList.get(makeList.size() - 1);
            for (int i = 1, j = makeList.size() - 2; i <= j; i++, j--) {
                int first = makeList.get(i);
                int second = makeList.get(j);
                if (first * second != area) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
        }

        private List<Integer> makeListWithFrequency(int[] freq) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < freq.length; i++) {
                if (freq[i] != 0) {
                    while (freq[i] >= 2) {
                        list.add(i);
                        freq[i] -= 2;
                    }
                }
            }
            return list;
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

        public int[] ia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i();
            return a;
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