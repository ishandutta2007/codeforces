import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    static Random random = new Random(0xdead);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; ++i) {
            x[i] = in.nextInt() - 1;
            y[i] = in.nextInt() - 1;
        }
        a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = i;
        ArrayList<Integer> l1 = new ArrayList<Integer>();
        for (int i = 0; i < m; ++i) {
            if (get(x[i]) != get(y[i])) {
                l1.add(i);
                unite(x[i], y[i]);
            }
        }
        for (int i = 0; i < n; ++i)
            a[i] = i;
        ArrayList<Integer> l2 = new ArrayList<Integer>();
        for (int i = m - 1; i >= 0; --i) {
            if (get(x[i]) != get(y[i])) {
                l2.add(i);
                unite(x[i], y[i]);
            }
        }

        int q = in.nextInt();
        for (int it = 0; it < q; ++it) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            for (int i = 0; i < n; ++i)
                a[i] = i;
            int res = n;
            for (int i = 0; i < l1.size() && l1.get(i) < l; ++i) {
                int j = l1.get(i);
                if (get(x[j]) != get(y[j])) {
                    --res;
                    unite(x[j], y[j]);
                }
            }
            for (int i = 0; i < l2.size() && l2.get(i) > r; ++i) {
                int j = l2.get(i);
                if (get(x[j]) != get(y[j])) {
                    --res;
                    unite(x[j], y[j]);
                }
            }
            out.printLine(res);
        }
    }

    int[] a;

    int get(int x) {
        if (a[x] == x) return x;
        return a[x] = get(a[x]);
    }

    int unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return x;
        if (random.nextBoolean())
            a[x] = y;
        else
            a[y] = x;
        return a[x];
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