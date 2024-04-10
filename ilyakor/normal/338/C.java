import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
    int n;
    long[] a;
    int[] count;
    int[] next;
    int cur;
    int cntRoots;
    int opt;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        a = new long[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextLong();
        Arrays.sort(a);
        count = new int[n];
        for (int i = 0; i < n; ++i) {
            long x = a[i];
            for (long y = 2; y * y <= x; ++y) {
                while (x % y == 0) {
                    x /= y;
                    ++count[i];
                }
            }
            if (x > 1) ++count[i];
        }
        next = new int[n];
        cur = 0;
        opt = 1000 * 1000 * 1000;
        cntRoots = 0;
        dfs(0);
        out.printLine(opt + n);
    }

    private void dfs(int ind) {
        if (ind >= n) {
            int val = cur;
            if (cntRoots > 1) ++val;
            if (val < opt) opt = val;
            return;
        }
        int w = count[ind];
        long y = a[ind];
        for (int i = 0; i < ind; ++i)
            if (next[i] == ind) {
                if (y % a[i] != 0) return;
                y /= a[i];
                w -= count[i];
            }
        if (count[ind] == 1) w = 0; // prime
        cur += w;
        for (int i = ind; i < n; ++i) {
            next[ind] = i;
            if (i == ind) ++cntRoots;
            dfs(ind + 1);
            if (i == ind) --cntRoots;
        }
        cur -= w;
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

    public long nextLong() {
        long sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10L + (long)(c - '0');
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