import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author izban
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        int ans = Integer.MIN_VALUE;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int b[] = new int[r - l + 1];
                int c[] = new int[n - r + l - 1];
                int o = 0;
                for (int i = 0; i < l; i++) c[o++] = a[i];
                for (int i = r + 1; i < n; i++) c[o++] = a[i];
                for (int i = l; i <= r; i++) b[i - l] = a[i];
                Arrays.sort(b);
                Arrays.sort(c);
                int i = 0, j = o - 1;
                while (i < b.length && j >= 0 && i < k) {
                    if (b[i] < c[j]) {
                        b[i] = c[j];
                        i++;
                        j--;
                    } else {
                        break;
                    }
                }
                int res = 0;
                for (i = 0; i < b.length; i++) res += b[i];
                ans = Math.max(ans, res);
            }
        }
        out.println(ans);
    }
}

class Scanner {
    BufferedReader in;
    StringTokenizer tok;

    public Scanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}