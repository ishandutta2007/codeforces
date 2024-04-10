import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        private static final String ORDER = "fedabc";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String input = in.nextString();
            long row = Long.parseLong(input.substring(0, input.length() - 1)) - 1;
            int col = findOrder(input.charAt(input.length() - 1));
            long numTurn = 2 * (row / 4);
            if (row % 2 != 0) numTurn++;
            long res = 6 * numTurn + col + 1;
            if (row % 4 >= 2) res += row - 2;
            else res += row;
            out.println(res);
        }

        private static int findOrder(char c) {
            for (int i = 0; i < 6; i++)
                if (ORDER.charAt(i) == c) return i;
            throw new RuntimeException();
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

    }
}