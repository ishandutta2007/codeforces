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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    int n, m;
    int a[];

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();

        long sumR[] = new long[n];
        int cntR[] = new int[n];
        for (int i = n - 1; i >= 0; i -= m) {
            for (int j = 0; j < m; j++) {
                if (i - j < 0) break;
                sumR[i - j] = a[i];
                cntR[i - j] = 1;
                if (i != n - 1) {
                    sumR[i - j] += sumR[i - j + m];
                    cntR[i - j] += cntR[i - j + m];
                }
            }
        }

        long sumL[] = new long[n];
        int cntL[] = new int[n];
        for (int i = 0; i < n; i += m) {
            for (int j = 0; j < m; j++) {
                if (i + j == n) break;
                sumL[i + j] = a[i];
                cntL[i + j] = 1;
                if (i >= m) {
                    sumL[i + j] += sumL[i + j - m];
                    cntL[i + j] += cntL[i + j - m];
                }
            }
        }

        long ans = Long.MAX_VALUE;
        for (int l = 0; l < n; l++) {
            int r = l;
            while (r + 1 < n && a[r + 1] == a[l]) r++;

            long res = 0;
            if (r + 1 < n) {
                res += sumR[r + 1] - 1L * a[l] * cntR[r + 1];
            }
            if (l - 1 >= 0) {
                res += 1L * a[l] * cntL[l - 1] - sumL[l - 1];
            }
            ans = Math.min(ans, res);
            l = r;
        }
        out.print(2 * ans);
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