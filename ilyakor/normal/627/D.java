import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] gr;
    int[] a;

    int[][] d;
    int[][] st;
    int[] stSum;
    int[] initialized;
    int[] sum;
    int[] residual1, residual2;
    int[] uninit;

    int T;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        g = new ArrayList[n];
        gr = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
            gr[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            gr[x].add(g[y].size());
            gr[y].add(g[x].size());
            g[x].add(y);
            g[y].add(x);
        }

        int down = 0, up = 1100 * 1000;
        while (up - down > 1) {
            T = (up + down) / 2;

            d = new int[n][];
            st = new int[n][];
            for (int i = 0; i < n; ++i) {
                d[i] = new int[g[i].size() + 1];
                st[i] = new int[g[i].size() + 1];
                Arrays.fill(d[i], -1);
                Arrays.fill(st[i], -1);
            }
            initialized = new int[n];
            sum = new int[n];
            stSum = new int[n];
            uninit = new int[n];
            residual1 = new int[n];
            residual2 = new int[n];

            boolean ok = false;
            for (int i = 0; i < n; ++i) {
                if (dfs(i, g[i].size()) >= k) {
                    ok = true;
                    break;
                }
            }
            if (ok)
                down = T;
            else
                up = T;
        }
        out.printLine(down);
    }

    private int dfs(int x, int p) {
        if (d[x][p] != -1)
            return d[x][p];
        if (a[x] < T)
            return 0;
        if (initialized[x] == 0) {
            initialized[x] = 1;
            uninit[x] = p;
            st[x][p] = 1;
            sum[x] = 0;
            if (a[x] >= T) ++sum[x];
            for (int i = 0; i < g[x].size(); ++i) {
                if (i == p) continue;
                int y = g[x].get(i);
                int cur = dfs(y, gr[x].get(i));
                if (cur == st[y][gr[x].get(i)]) {
                    sum[x] += cur;
                } else {
                    updateResidual(x, cur);
                }
                st[x][p] += st[y][gr[x].get(i)];
            }
            stSum[x] = st[x][p];
            d[x][p] = sum[x] + residual1[x];
            return d[x][p];
        }

        if (initialized[x] == 1) {
            if (uninit[x] < g[x].size()) {
                int y = g[x].get(uninit[x]);
                int cur = dfs(y, gr[x].get(uninit[x]));
                if (cur == st[y][gr[x].get(uninit[x])]) {
                    sum[x] += cur;
                } else {
                    updateResidual(x, cur);
                }
                stSum[x] += st[y][gr[x].get(uninit[x])];
            }
            initialized[x] = 2;
        }

        if (p == g[x].size()) {
            d[x][p] = sum[x] + residual1[x];
            st[x][p] = stSum[x];
            return d[x][p];
        }
        int baddie = dfs(g[x].get(p), gr[x].get(p));
        st[x][p] = stSum[x] - st[g[x].get(p)][gr[x].get(p)];
        if (baddie == st[g[x].get(p)][gr[x].get(p)]) {
            d[x][p] = sum[x] - baddie + residual1[x];
        } else {
            d[x][p] = sum[x];
            if (baddie == residual1[x])
                d[x][p] += residual2[x];
            else
                d[x][p] += residual1[x];
        }
        return d[x][p];
    }

    private void updateResidual(int x, int val) {
        if (val > residual1[x]) {
            residual2[x] = residual1[x];
            residual1[x] = val;
        } else if (val > residual2[x]) {
            residual2[x] = val;
        }
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}