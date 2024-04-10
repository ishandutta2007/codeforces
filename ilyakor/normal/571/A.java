import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int[] a = new int[3];
        for (int i = 0; i < 3; ++i)
            a[i] = in.nextInt();
        int l = in.nextInt();
        long res = 0;
        for (int i = 0; i < 3; ++i) {
            for (int ai = 0; ai <= l; ++ai) {
                int rem = l - ai;
                int cur = a[i] + ai;
                int[] up = new int[2];
                int us = 0;
                int down = cur;
                for (int j = 0; j < 3; ++j) {
                    if (i == j) continue;
                    int lim = cur;
                    if (j < i) --lim;
                    lim -= a[j];
                    up[us++] = lim;
                    down -= a[j];
                }
                if (up[0] < 0 || up[1] < 0) continue;
                if (rem < down) continue;
                long cnt = (long) (up[0] + 1) * (long) (up[1] + 1);
                cnt -= calc(down, up[0], up[1]);
                cnt -= calc(up[0] + up[1] - rem - 1, up[0], up[1]);
                if (cnt > 0)
                    res += cnt;
            }
        }
        out.printLine(res);
    }

    private long calc(long d, long x, long y) {
        if (d < 0) return 0;
        if (d >= x + y) return (x + 1L) * (y + 1L);
        if (x > y) {
            long t = x;
            x = y;
            y = t;
        }
        if (d <= x) {
            return (d + 1L) * (d + 2L) / 2L;
        }
        if (d >= y) {
            return (x + 1L) * (y + 1L) - calc(x + y - d - 1, x, y);
        }
        long base = (x + 1L) * (x + 2L) / 2L;
        long inc = d - x;
        return base + inc * (x + 1L);
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