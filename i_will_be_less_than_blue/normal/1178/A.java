import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            int[] a = in.ia(n);
            List<Pair> input = new ArrayList<>();
            for (int i = 0; i < n; i++) input.add(new Pair(a[i], i + 1));
            int sum = input.stream().mapToInt(e -> e.st).sum();
            int alice = input.get(0).st;
            List<Pair> allHalfList = input.stream().filter(e -> alice >= e.st * 2).collect(Collectors.toList());
            int halfSum = allHalfList.stream().mapToInt(e -> e.st).sum();
            if (2 * (halfSum + alice) > sum) {
                out.println(allHalfList.size() + 1);
                out.print(1 + " ");
                allHalfList.forEach(e -> out.print(e.nd + " "));
            } else {
                out.println(0);
            }
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