import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    int[][][] d;
    boolean[][][] u;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        boolean[][] a = new boolean[n][2];
        for (int i = 0; i < k; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            a[x][y] = true;
        }
        d = new int[n + 1][4][4];
        u = new boolean[n + 1][4][4];
        int prev = 0;
        int res = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && !a[j][0] && !a[j][1]) ++j;
            int cur = 0;
            if (j < n) {
                if (a[j][0]) cur |= 2;
                if (a[j][1]) cur |= 1;
            }
            int val = go(j - i, prev, cur);
            res ^= val;
            prev = cur;
            i = j + 1;
        }
        out.printLine(res == 0 ? "LOSE" : "WIN");
    }

    private int go(int n, int ml, int mr) {
        if (n <= 0) return 0;
        if (u[n][ml][mr]) return d[n][ml][mr];
        u[n][ml][mr] = true;
        if (ml == 3) {
            // Should be impossible, but anyway.
            int res = go(n - 1, 0, mr);
            d[n][ml][mr] = res;
            return res;
        }
        if (mr == 3) {
            // Should be impossible, but anyway.
            int res = go(n - 1, ml, 0);
            d[n][ml][mr] = res;
            return res;
        }
        int res = 0;
        int[][] a = new int[n][2];
        if (ml % 2 == 1) a[0][0] = 1;
        if ((ml / 2) % 2 == 1) a[0][1] = 1;
        if (mr % 2 == 1) a[n - 1][0] = 1;
        if ((mr / 2) % 2 == 1) a[n - 1][1] = 1;
        HashSet<Integer> hs = new HashSet<Integer>();
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < 2; ++y)
                if (a[x][y] == 0) {
                    int cur = go(x, ml, (1 << (1 - y))) ^ go(n - x - 1, (1 << (1 - y)), mr);
                    hs.add(cur);
                }
        while (hs.contains(res)) ++res;
        d[n][ml][mr] = res;
        return res;
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