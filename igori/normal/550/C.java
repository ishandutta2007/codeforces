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
            String ss = in.next();
            int n = ss.length();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = ss.charAt(i) - '0';
                if (arr[i] % 8 == 0)
                {
                    out.println("YES");
                    out.print(arr[i]);
                    return;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((arr[i] * 10 + arr[j]) % 8 == 0)
                    {
                        out.println("YES");
                        out.print(arr[i]);
                        out.print(arr[j]);
                        return;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if ((arr[i] * 100 + arr[j] * 10 + arr[k]) % 8 == 0)
                        {
                            out.println("YES");
                            out.print(arr[i]);
                            out.print(arr[j]);
                            out.print(arr[k]);
                            return;
                        }
                    }
                }
            }
            out.print("NO");
            return;
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