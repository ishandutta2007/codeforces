import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    final int maxn = 100100;
    final int maxk = 310;

    int lowerBound(ArrayList<Integer> a, int x) {
        if (a.isEmpty()) return -1;
        int l = 0, r = a.size() - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a.get(m) < x) {
                l = m;
            } else {
                r = m;
            }
        }
        if (a.get(l) >= x) return a.get(l);
        if (a.get(r) >= x) return a.get(r);
        return -1;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        int e = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[m];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        ArrayList<Integer> pos[] = new ArrayList[maxn];
        for (int i = 0; i < maxn; i++) pos[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
            pos[b[i]].add(i);
        }

        int dp[] = new int[maxk];
        for (int i = 0; i < maxk; i++) dp[i] = Integer.MAX_VALUE;
        dp[0] = 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = maxk - 2; j >= 0; j--) if (dp[j] != Integer.MAX_VALUE) {
                int k = lowerBound(pos[a[i]], dp[j]);
                if (k == -1) continue;
                dp[j + 1] = Math.min(dp[j + 1], k + 1);
                if ((j + 1) * e + (i + 1) + (k + 1) <= s) {
                    ans = Math.max(ans, j + 1);
                }
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