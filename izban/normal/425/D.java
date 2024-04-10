import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.util.Collections;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    final int mx = 100100;
    final long ml = 1000000;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int x[] = new int[n], y[] = new int[n];
        HashSet<Long> st = new HashSet<Long>();
        ArrayList<Integer> vx[] = new ArrayList[mx];
        ArrayList<Integer> vy[] = new ArrayList[mx];
        for (int i = 0; i < mx; i++) {
            vx[i] = new ArrayList<Integer>();
            vy[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            st.add(x[i] * ml + y[i]);
            vx[x[i]].add(y[i]);
            vy[y[i]].add(x[i]);
        }
        for (int i = 0; i < mx; i++) {
            Collections.sort(vx[i]);
            Collections.sort(vy[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x0 = x[i], y0 = y[i];
            if (vx[x[i]].size() <= vy[y[i]].size()) {
                for (int j = 0; j < vx[x[i]].size(); j++) {
                    if (vx[x[i]].get(j) <= y[i]) continue;
                    int d = vx[x[i]].get(j) - y[i];
                    if (st.contains((x[i] + d) * ml + y[i]) && st.contains((x[i] + d) * ml + (y[i] + d))) {
                        ans++;
                    }
                }
            } else {
                for (int j = 0; j < vy[y[i]].size(); j++) {
                    if (vy[y[i]].get(j) <= x[i]) continue;
                    int d = vy[y[i]].get(j) - x[i];
                    if (st.contains(x[i] * ml + (y[i] + d)) && st.contains((x[i] + d) * ml + (y[i] + d))) {
                        ans++;
                    }
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