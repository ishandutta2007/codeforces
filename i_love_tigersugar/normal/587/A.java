import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        private static final int MAX = 3000300;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] cnt = new int[MAX];
            for (int i = 0, n = in.nextInt(); i < n; i = i + 1) cnt[in.nextInt()]++;
            for (int i = 0; i < MAX; i = i + 1)
                if (cnt[i] > 0) {
                    int tmp = cnt[i];
                    cnt[i] = 0;
                    for (int j = 0; j < 30; j = j + 1) cnt[i + j] += BitsUtil.BIT(tmp, j);
                }
            int res = 0;
            for (int i = 0; i < MAX; i = i + 1) res += cnt[i];
            out.println(res);
        }

    }

    static class BitsUtil {
        public static int BIT(long x, int i) {
            long res = (x >> i) & 1;
            return ((int) res);
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

    }
}