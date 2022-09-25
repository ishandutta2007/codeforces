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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int[] get(int n) {
        int res[] = new int[n];
        if (n == 1) {
            res[0] = 1;
            return res;
        }
        if (n == 2) {
            res[0] = 3;
            res[1] = 4;
            return res;
        }
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                res[i] = 1;
            }
            res[n - 1] = (n - 1) / 2;
        } else {
            for (int i = 0; i < n - 2; i++) {
                res[i] = 1;
            }
            res[n - 2] = 2;
            res[n - 1] = (n + 1) / 2;
        }
        return res;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int a[] = get(n);
        int b[] = get(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(a[i] * b[j] + " ");
            }
            out.println();
        }
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