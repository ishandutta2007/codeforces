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
 * @author Van Hanh Pham <skyvn97> <vanhanh.pham@gmail.com>
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] value = IOUtils.readIntArray(in, n, 1);

            if (k == 1) {
                out.println(0);
                return;
            }

            int[] countSum = new int[2 * k + 1];
            int[] countMax = new int[2 * k + 1];
            int[] countMin = new int[2 * k + 1];

            Arrays.fill(countSum, 0);
            Arrays.fill(countMax, 0);
            Arrays.fill(countMin, 0);

            for (int i = 1; i <= n / 2; i++) {
                int x = value[i], y = value[n - i + 1];
                countSum[x + y]++;
                countMax[Math.max(x, y)]++;
                countMin[Math.min(x, y)]++;
            }

            for (int i = 1; i <= 2 * k; i++) countMax[i] += countMax[i - 1];
            for (int i = 2 * k; i >= 1; i--) countMin[i - 1] += countMin[i];

            int res = Others.INT_INFINITY;
            for (int x = 2; x <= 2 * k; x++) {
                int price = n / 2 - countSum[x];
                price += countMax[Math.max(1, x - k) - 1];
                price += countMin[Math.min(k, x - 1) + 1];
                res = Math.min(res, price);
            }
            out.println(res);
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

        public String next() {
            return nextString();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size, int start) {
            int[] res = new int[start + size];
            for (int i = start; i < start + size; i++)
                res[i] = in.nextInt();
            return res;
        }

    }

    static class Others {
        public static final int INT_INFINITY = (int) 1e9 + 7;

    }
}