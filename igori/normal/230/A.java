import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int s, n;
            s = in.nextInt();
            n = in.nextInt();
        int[] x = new int[10200], y = new int[10200];
        int i = 0;
        while (i < n)
        {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            i++;
        }
        int ans = 1;
        for (int j = 0; j < n; j++)
        {
            int a = 999999999, mm = -1;
            for (int k = 0; k < n; k++)
            {
                if (x[k] < a)
                {
                    a = x[k];
                    mm = k;
                }
            }
            if (s <= a && ans == 1)
            {
                out.println("NO");
                ans = 0;
            }
            s = s + y[mm];
            x[mm] = 999999999;
            y[mm] = 999999999;
        }
        if (ans == 1)
            out.println("YES");
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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