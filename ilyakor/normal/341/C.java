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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static final long mod = 1000000007L;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a = 0, b = 0;
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
            if (p[i] != -1) p[i]--;
        }
        boolean[] u = new boolean[n];
        for (int i = 0; i < n; ++i) if (!u[i] && p[i] != -1) {
            int cur = i;
            while (cur != -1 && !u[cur]) {
                u[cur] = true;
                cur = p[cur];
            }
            if (cur == -1) ++a;
        }
        for (int i = 0; i < n; ++i) if (!u[i]) ++b;

        long[][] C = new long[a + b + 5][a + b + 5];
        C[0][0] = 1;
        for (int i = 1; i <= a + b; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                C[i][j] %= mod;
            }
        }

        long[][] d = new long[a + b + 1][a + b + 1];
        d[0][0] = 1;
        for (int i = 1; i <= a + b; ++i)
            for (int j = 0; j <= i; ++j) {
                long cur = 0;
                if (j > 0) cur += d[i - 1][j - 1];
                if (j <= i - 1) cur += d[i - 1][j] * (long)(i - 1 - j);
                if (j + 1 <= i - 1) cur += d[i - 1][j + 1] * (long)(j + 1);
                cur %= mod;
                d[i][j] = cur;
            }
        long res = 0;
        for (int i = 0; i <= a; ++i) {
            res += d[a + b - i][0] * C[a][i];
            res %= mod;
        }
        out.printLine(res);
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