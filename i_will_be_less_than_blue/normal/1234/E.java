import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ESpecialPermutations solver = new ESpecialPermutations();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESpecialPermutations {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int m = in.i();
            int[] a = in.ia(m);
            MiscUtils.decreaseByOne(a);
            // numberOfInterval[i] contains total segment where i is present inside the endpoints of the segment
            int[] numberOfInterval = new int[n + 1];
            Graph g = new Graph(n);
            long f1p = 0;
            for (int i = 0; i < m - 1; i++) {
                int l = a[i];
                int r = a[i + 1];
                f1p += Math.abs(l - r);
                if (l != r) {
                    g.addEdgeUndirected(l, r);
                }
                if (l > r) {
                    int tem = l;
                    l = r;
                    r = tem;
                }
                if (r - l < 2) continue; // there are no elements inside (l, r) so we ignore this case.
                numberOfInterval[l + 1]++;
                numberOfInterval[r]--;
            }
            for (int i = 1; i <= n; i++) {
                numberOfInterval[i] += numberOfInterval[i - 1];
            }

            long[] ans = new long[n];
            ans[0] = f1p;
            for (int i = 1; i < n; i++) {
                long res = f1p - numberOfInterval[i];
                for (int j : g.graph.get(i)) {
                    res -= Math.abs(j - i); // remove the segment (i, j) and add j to the answer since i will converted to 1
                    res += j;
                    if (j < i)
                        ++res; // if j is less than i than answer will increase by 1, since i will be 1 and j will increase by 1 and so their difference will increase by one
                }
                ans[i] = res;
            }
            out.printLine(ans);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(long[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class Graph {
        public List<List<Integer>> graph;
        public final int size;

        public Graph(int size) {
            this.size = size;
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }

        public void addEdgeUndirected(int from, int to) {
            this.graph.get(from).add(to);
            this.graph.get(to).add(from);
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
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