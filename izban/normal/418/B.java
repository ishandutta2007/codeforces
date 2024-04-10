import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
        int M = in.nextInt();
        int b = in.nextInt();

        final int x[] = new int[n], k[] = new int[n], m[] = new int[n], msk[] = new int[n];
        Integer p[] = new Integer[n], o[] = new Integer[n];
        int a[][] = new int[n][];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            k[i] = in.nextInt();
            m[i] = in.nextInt();
            p[i] = i;
            a[i] = new int[m[i]];
            for (int j = 0; j < m[i]; j++) {
                a[i][j] = in.nextInt() - 1;
                msk[i] |= 1 << a[i][j];
            }
        }

        Arrays.sort(p, new Comparator<Integer>() {
            @Override
            public int compare(Integer i, Integer j) {
                return Integer.compare(k[i], k[j]);
            }
        });
        for (int i = 0; i < n; i++) o[p[i]] = i;

        long dp[] = new long[1 << M];
        for (int i = 0; i < 1 << M; i++) dp[i] = Long.MAX_VALUE;
        dp[0] = 0;

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            i = p[i];
            for (int mask = 0; mask < 1 << M; mask++) {
                if (dp[mask] == Long.MAX_VALUE) continue;
                dp[mask | msk[i]] = Math.min(dp[mask | msk[i]], dp[mask] + x[i]);
            }
            if (dp[(1 << M) - 1] != Long.MAX_VALUE) {
                ans = Math.min(ans, dp[(1 << M) - 1] + 1L * b * k[i]);
            }
            i = o[i];
        }
        if (ans == Long.MAX_VALUE) ans = -1;
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