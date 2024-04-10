import java.io.OutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
    static final long mod = 1000000007;
    int[][][] can;
    int[] cnt;
    int[][] a;
    int n, m, k;
    int oq;

    long res = 0;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        if (k < n + m - 1) {
            out.printLine(0);
            return;
        }
        a = new int[n][m];
        cnt = new int[k];
        can = new int[n][m][k];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                a[i][j] = in.nextInt();
                if (a[i][j] != 0) {
                    if (can[i][j][a[i][j] - 1] > 0) {
                        out.printLine(0);
                        return;
                    }
                    ++cnt[a[i][j] - 1];
                    for (int p = 0; p <= i; ++p)
                        for (int q = 0; q <= j; ++q)
                            can[p][q][a[i][j] - 1]++;
                    for (int p = i; p < n; ++p)
                        for (int q = j; q < m; ++q)
                            can[p][q][a[i][j] - 1]++;
                }
            }
        oq = 0;
        for (int i = 0; i < k; ++i)
            if (cnt[i] != 0) ++oq;
        dfs(0, 0);
        res %= mod;
//        for (int i = 1; i <= k; ++i)
//            res = (res * (long) i) % mod;
        out.printLine(res);
    }

    void dfs(int x, int y) {
        if (x >= n) {
            long cur = 1;
            int cntt = 0;
            for (int i = 0; i < k; ++i) if (cnt[i] != 0) {
                ++cntt;
            }
            cntt -= oq;
            for (int i = 0; i < cntt; ++i)
                cur = (cur * (long)(k - oq - i)) % mod;
            res = (res + cur) % mod;
            return;
        }
        int xx = x, yy = y + 1;
        if (yy == m) {
            xx = x + 1;
            yy = 0;
        }
        if (a[x][y] != 0) {
            dfs(xx, yy);
            return;
        }
        boolean was0 = false;
        for (int c = 0; c < k; ++c) if (can[x][y][c] == 0) {
            if (cnt[c] == 0) {
                if (was0) continue;
                was0 = true;
            }
            ++cnt[c];
            for (int i = x; i < n; ++i)
                for (int j = y; j < m; ++j)
                    ++can[i][j][c];
            dfs(xx, yy);
            for (int i = x; i < n; ++i)
                for (int j = y; j < m; ++j)
                    --can[i][j][c];
            --cnt[c];
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