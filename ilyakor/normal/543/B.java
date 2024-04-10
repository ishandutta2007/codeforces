import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
import java.util.Collection;
import java.io.InputStream;

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
    public static final int inf = 100 * 1000 * 1000;
    ArrayList<Integer>[] g;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<>();

        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }

        int[][] d = new int[n][n];


        int s1 = in.nextInt() - 1;
        int t1 = in.nextInt() - 1;
        int l1 = in.nextInt();
        int s2 = in.nextInt() - 1;
        int t2 = in.nextInt() - 1;
        int l2 = in.nextInt();

        for (int i = 0; i < n; ++i) {
            bfs(i, d[i]);
        }

        int res = inf;
        if (d[s1][t1] <= l1 && d[s2][t2] <= l2)
            res = d[s1][t1] + d[s2][t2];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2) {
                    res = Math.min(res, d[s1][i] + d[i][j] + d[j][t1] + d[s2][i] + d[j][t2]);
                }
                if (d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[t2][i] + d[i][j] + d[j][s2] <= l2) {
                    res = Math.min(res, d[s1][i] + d[i][j] + d[j][t1] + d[t2][i] + d[j][s2]);
                }
            }
        if (res >= inf) res = -1;
        else res = m - res;
        out.printLine(res);
    }

    private void bfs(int x, int[] d) {
        Arrays.fill(d, inf);
        d[x] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(x);
        while (!q.isEmpty()) {
            int y = q.poll();
            for (int z : g[y])
                if (d[z] == inf) {
                    d[z] = d[y] + 1;
                    q.add(z);
                }
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

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
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