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
 * @author Van Hanh Pham (skyvn97)
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
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.out = out;

            int n = in.nextInt();
            StringTokenizer tokenizer = new StringTokenizer(modify(in.nextString()));
            int maxOut = 0;
            int cntIn = 0;
            while (tokenizer.hasMoreTokens()) {
                String tmp = tokenizer.nextToken();
                if (Character.isUpperCase(tmp.charAt(0))) cntIn++;
                else maxOut = Math.max(maxOut, tmp.length());
            }
            out.printf("%d %d\n", maxOut, cntIn);
        }

        private String modify(String s) {
            char[] arr = new char[s.length()];
            boolean inBracket = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') inBracket = true;
                if (s.charAt(i) == ')') inBracket = false;
                if (!Character.isLetter(s.charAt(i))) arr[i] = ' ';
                else arr[i] = inBracket ? Character.toUpperCase(s.charAt(i)) : Character.toLowerCase(s.charAt(i));
            }
            return new String(arr);
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