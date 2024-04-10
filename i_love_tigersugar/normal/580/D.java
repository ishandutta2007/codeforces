import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.io.InputStreamReader;
import java.io.IOException;

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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int q = in.nextInt();
            long[] val = new long[n];
            long[][] cst = new long[n][n];
            for (long[] y : cst) Arrays.fill(y, 0);
            for (int i = 0; i < n; i = i + 1) val[i] = in.nextLong();
            for (int i = 0; i < q; i = i + 1) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                cst[x][y] += in.nextLong();
            }
            long[][] f = new long[n][MASK(n)];
            for (long[] y : f) Arrays.fill(y, -1);
            for (int i = 0; i < n; i = i + 1) f[i][MASK(i)] = val[i];
            for (int i = 1; i < MASK(n); i = i + 1)
                for (int j = 0; j < n; j = j + 1)
                    if (BIT(i, j) == 1)
                        for (int k = 0; k < n; k = k + 1)
                            if (BIT(i, k) == 0)
                                f[k][i | MASK(k)] = Math.max(f[k][i | MASK(k)], f[j][i] + val[k] + cst[j][k]);
            long res = 0;
            for (int i = 1; i < MASK(n); i = i + 1)
                if (bitCount(i) == m)
                    for (int j = 0; j < n; j = j + 1) res = Math.max(res, f[j][i]);
            out.println(res);
        }

        private int MASK(int n) {
            return (1 << n);
        }

        private int BIT(int x, int i) {
            return ((x >> i) & 1);
        }

        private int bitCount(int x) {
            int res = 0;
            for (int i = 0; i < 30; i = i + 1) if (BIT(x, i) == 1) res++;
            return (res);
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
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
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}