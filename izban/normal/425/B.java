import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int a[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }

        if (n > m) {
            int b[][] = new int[m][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[j][i] = a[i][j];
                }
            }
            a = b;
            int o = n;
            n = m;
            m = o;
        }

        int ans = Integer.MAX_VALUE;
        if (m > k) {
            for (int cur = 0; cur < m; cur++) {
                int res = 0;
                for (int j = 0; j < m; j++) {
                    int diff = 0;
                    for (int i = 0; i < n; i++) {
                        if (a[i][j] != a[i][cur]) {
                            diff++;
                        }
                    }
                    res += Math.min(diff, n - diff);
                }
                ans = Math.min(ans, res);
            }
        } else {
            for (int mask = 0; mask < 1 << n; mask++) {
                int b[] = new int[n];
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        b[i] = 1;
                    } else {
                        b[i] = 0;
                    }
                }
                int res = 0;
                for (int j = 0; j < m; j++) {
                    int diff = 0;
                    for (int i = 0; i < n; i++) {
                        if (a[i][j] != b[i]) {
                            diff++;
                        }
                    }
                    res += Math.min(diff, n - diff);
                }
                ans = Math.min(ans, res);
            }
        }
        if (ans > k) ans = -1;
        out.print(ans);
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