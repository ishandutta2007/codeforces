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
        
    public static int _abs(int a)
    {
        if (a >= 0)
            return a;
        return -a;
    }
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = in.nextInt();
            }
            int ans = 999999999;
            for (int i = 1; i + 1 < n; i++)
            {
                int q = 0;
                for (int j = 0; j + 1 < n; j++)
                {
                    if (j + 1 == i)
                    {
                        if (_abs(a[j] - a[j + 2]) > q)
                            q = _abs(a[j] - a[j + 2]);
                        j++;
                    }
                    if (_abs(a[j] - a[j + 1]) > q)
                        q = _abs(a[j] - a[j + 1]);
                }
                if (q < ans)
                    ans = q;
            }
            out.println(ans);
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