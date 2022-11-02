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
    int n, m, k, p;
    int[] h;
    int[] a;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        p = in.nextInt();
        h = new int[n];
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            h[i] = in.nextInt();
            a[i] = in.nextInt();
        }
        long down = 0, up = (long)(1E18);
        while (up - down > 1) {
            long t = (up + down) / 2L;
            if (check(t))
                up = t;
            else
                down = t;
        }
        long res = check(down) ? down : up;
        out.printLine(res);
    }

    private boolean check(long maxH) {
        ArrayList<Integer> touched = new ArrayList<>();
        long minHits = 0;
        for (int i = 0; i < n; ++i) {
            if (maxH < a[i]) return false;
            long finalH = (long) h[i] + (long) a[i] * (long) m;
            if (finalH <= maxH) continue;
            touched.add(i);
            long hits = finalH - maxH;
            hits = hits / p + (hits % p > 0 ? 1 : 0);
            minHits += hits;
        }
        if (minHits > k * m) return false;

        // Now it is theoretically possible to achieve maxH, if zeroes don't stop us.
        int[] events = new int[m + 1];
        for (int i : touched) {
            long inc = 0;
            for (int j = m - 1; j >= 0; ) {
                for (int step = (1 << 12); step >= 1; step /= 2) {
                    if (j - step < -1) continue;
                    if (inc + (long) a[i] * (long) step > maxH) continue;
                    inc += (long) a[i] * (long) step;
                    j -= step;
                }
                long next = a[i];
                if (j == -1) next = h[i];
                while (inc + next > maxH) {
                    events[j + 1] += 1;
                    inc -= p;
                }
            }
        }

        int active = 0;
        for (int i = 0; i < m; ++i) {
            active += events[i];
            active -= k;
            if (active < 0) active = 0;
        }
        if (active > 0) return false;

        return true;
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