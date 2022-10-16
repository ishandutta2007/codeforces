import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Van Hanh Pham (skyvn97)
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
        private static final String yes = "YES";
        private static final String no = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int start = in.nextInt();
            int goal = in.nextInt();

            ArrayList<Integer> moves = new ArrayList<Integer>();
            moves.add(goal);
            while (goal > start) {
                if (goal % 2 == 0) goal /= 2;
                else {
                    goal--;
                    if (goal % 10 != 0) {
                        out.println(no);
                        return;
                    }
                    goal /= 10;
                }
                moves.add(goal);
            }

            if (!moves.contains(start)) out.println(no);
            else {
                Collections.reverse(moves);
                out.println(yes);
                out.println(moves.size());
                for (int x : moves) out.printf("%d ", x);
                out.println();
            }
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
}