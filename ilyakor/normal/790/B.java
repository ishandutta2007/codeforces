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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    int n, k;
    ArrayList<Integer>[] g;
    long res;
    int[][] cnts;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        k = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        res = 0;
        cnts = new int[n][k + 1];
        dfs(0, -1);
        Assert.assertTrue(res % 2L == 0);
        res /= 2L;
        out.printLine(res);
    }

    private void dfs(int x, int p) {
        cnts[x][0] = 1;
        for (int y : g[x]) {
            if (y == p) continue;
            dfs(y, x);
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j <= k; ++j) {
                    long coeff = (i + j + 1) / k;
                    if ((i + j + 1) % k != 0) ++coeff;
                    res += 2L * coeff * cnts[y][i] * (long) cnts[x][j];
                }
            }
            for (int i = 0; i < k; ++i) {
                cnts[x][i + 1] += cnts[y][i];
            }
        }
        int sum = 0;
        for (int t : cnts[x]) sum += t;
        res += 2L * (long) cnts[x][k] * (long) (n - sum);
        cnts[x][0] += cnts[x][k];
        cnts[x][k] = 0;
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

class Assert {

    public static void assertTrue(boolean flag) {
if (!flag)
            throw new AssertionError();
    }

}