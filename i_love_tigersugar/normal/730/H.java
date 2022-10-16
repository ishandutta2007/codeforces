import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.StringTokenizer;
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
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            String[] str = IOUtils.readStringArray(in, n, 1);
            boolean[] willDel = new boolean[n + 1];
            ArrayList<String> toDel = new ArrayList<String>();
            for (int i = 0; i < m; i++) {
                int tmp = in.nextInt();
                willDel[tmp] = true;
                toDel.add(str[tmp]);
            }

            String res = getPattern(toDel);
            if (res == null) {
                out.println(NO);
                return;
            }
            for (int i = 1; i <= n; i++)
                if (isMatch(res, str[i]) != willDel[i]) {
                    out.println(NO);
                    return;
                }
            out.printf("%s\n%s\n", YES, res);
        }

        private static String getPattern(ArrayList<String> strings) {
            int len = strings.get(0).length();
            for (String str : strings) if (str.length() != len) return null;

            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < len; i++) {
                TreeSet<Character> haveChar = new TreeSet<Character>();
                for (String str : strings) haveChar.add(str.charAt(i));
                builder.append(haveChar.size() > 1 ? '?' : haveChar.first());
            }

            return builder.toString();
        }

        private static boolean isMatch(String patern, String str) {
            if (patern.length() != str.length()) return false;
            for (int i = 0; i < str.length(); i++) {
                if (patern.charAt(i) == '?') continue;
                if (patern.charAt(i) != str.charAt(i)) return false;
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

    static class IOUtils {
        public static String[] readStringArray(InputReader in, int size, int start) {
            String[] res = new String[start + size];
            for (int i = start; i < start + size; i++)
                res[i] = in.nextString();
            return res;
        }

    }
}