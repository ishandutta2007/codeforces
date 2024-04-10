import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    ArrayList<Integer>[] g;
    int[] col;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        col = new int[n];
        Arrays.fill(col, -1);
        dfs(0);
        for (int i = 0; i < n; ++i)
            out.print((char)((int)'A' + col[i]) + " ");
        out.printLine();
    }

    private int dfs(int x) {
        col[x] = -2;
        int dep = 0;
        int[] cnt = new int[26];
        int mp2 = -1;
        for (int y : g[x]) if (col[y] == -1) {
            int val = dfs(y);
            dep = Math.max(dep, val);
            int p2 = 0;
            while (val > 1) {
                ++p2;
                val /= 2;
            }
            ++cnt[p2];
            if (mp2 < p2) mp2 = p2;
        }
        if (mp2 >= 0) --cnt[mp2];
        while (mp2 >= 0 && cnt[mp2] == 0) --mp2;
        dep = roundUp(dep, mp2);
        int t = dep;
        col[x] = 25;
        while (t % 2 == 0) {
            t /= 2;
            --col[x];
        }
        Assert.assertTrue(col[x] >= 0);
        return dep;
    }

    private int roundUp(int dep, int p) {
        ++dep;
        if (p >= 0 && (dep & ((1 << (p + 1)) - 1)) != 0)
            dep = (dep & (~((1 << (p + 1)) - 1))) + (1 << (p + 1));
        return dep;
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

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
    }

    }