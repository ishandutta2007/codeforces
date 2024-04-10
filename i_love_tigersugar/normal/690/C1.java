import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author @VanHanhPham_skyvn97
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC1 {
        private static final String yes = "yes";
        private static final String no = "no";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.println(result(in) ? yes : no);
        }

        private boolean result(InputReader in) {
            int n = in.nextInt();
            int m = in.nextInt();
            if (m != n - 1) return false;
            DisjointSet dsu = new DisjointSet(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                if (!dsu.join(a, b)) return false;
            }
            return true;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextString() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }

    static class DisjointSet {
        private int[] label;

        public DisjointSet(int n) {
            label = new int[n + 1];
            Arrays.fill(label, -1);
        }

        public int getRoot(int x) {
            if (label[x] < 0) return x;
            label[x] = getRoot(label[x]);
            return label[x];
        }

        public boolean join(int a, int b) {
            int x = getRoot(a);
            int y = getRoot(b);
            if (x == y) return false;
            if (label[x] > label[y]) {
                int t = x;
                x = y;
                y = t;
            }
            label[x] += label[y];
            label[y] = x;
            return true;
        }

    }
}