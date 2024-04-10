import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
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
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] value = IOUtils.readIntArray(in, n, 1);
            Pair<Integer, Long>[][] dp = new Pair[n + 1][2];
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < 2; j++) dp[i][j] = new Pair<Integer, Long>(-1, -Others.longINF);

            for (int i = 1; i <= n; i++) {
                dp[i][sign(value[i])].first = 1;
                dp[i][sign(value[i])].second = (long) value[i];
            }

            for (int i = 1; i < n; i++)
                for (int j = 0; j < 2; j++)
                    if (dp[i][j].first > 0) {
                        update(dp[i + 1][j], dp[i][j].first, dp[i][j].second);
                        if (sign(value[i + 1]) != j)
                            update(dp[i + 1][1 - j], dp[i][j].first + 1, dp[i][j].second + value[i + 1]);
                    }

            int maxLength = Math.max(dp[n][0].first, dp[n][1].first);
            long result = -Others.longINF;
            for (int j = 0; j < 2; j++) if (dp[n][j].first == maxLength) result = Math.max(result, dp[n][j].second);
            out.println(result);
        }

        private void update(Pair<Integer, Long> cur, int length, long sum) {
            if (cur.first < length) {
                cur.first = length;
                cur.second = sum;
            } else if (cur.first == length) cur.second = Math.max(cur.second, sum);
        }

        private int sign(int x) {
            return x > 0 ? 1 : 0;
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

    static class Pair<First, Second> {
        public First first;
        public Second second;

        public Pair() {
        }

        public Pair(First first, Second second) {
            this.first = first;
            this.second = second;
        }

        public Pair(Map.Entry<First, Second> entry) {
            first = entry.getKey();
            second = entry.getValue();
        }

        public String toString() {
            return "{ " + first.toString() + " " + second.toString() + " }";
        }

    }

    static class Others {
        public static final long longINF = (long) 1e18 + 7;

    }
}