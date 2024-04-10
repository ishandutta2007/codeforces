import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    ArrayList<Integer>[] g;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();

        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }

        boolean[] u = new boolean[n];
        int cnt = 0;
        int[] d = new int[4];
        for (int i = 0; i < n; ++i) {
            int deg = g[i].size();
            if (deg >= 3) deg = 3;
            ++d[deg];
            if (!u[i]) {
                ++cnt;
                dfs(i, u);
            }
        }
        if (cnt != 1) {
            out.printLine("unknown topology");
            return;
        }
        if (d[2] == n) {
            out.printLine("ring topology");
            return;
        }
        if (d[1] == n - 1) {
            out.printLine("star topology");
            return;
        }
        if (d[1] == 2 && d[2] == n - 2) {
            out.printLine("bus topology");
            return;
        }
        out.printLine("unknown topology");
    }

    private void dfs(int x, boolean[] u) {
        u[x] = true;
        for (int y : g[x])
            if (!u[y]) dfs(y, u);
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