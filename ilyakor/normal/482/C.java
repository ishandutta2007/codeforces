import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.PrintStream;
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
    static final int[] POPCOUNT16 = new int[1 << 16];
    static {
        for (int i = 0; i < (1 << 16); ++i) {
            int x = i, cnt = 0;
            while (x > 0) {
                cnt += x % 2;
                x /= 2;
            }
            POPCOUNT16[i] = cnt;
        }
    }

    int popcount(long x) {
        int mask = (1 << 16) - 1;
        return POPCOUNT16[((int) (x & mask))] + POPCOUNT16[((int) ((x >> 16) & mask))] + POPCOUNT16[((int) ((x >> 32) & mask))] + POPCOUNT16[((int) ((x >> 48) & mask))];
    }

    long[][] A;
    long[][] curMasks;
    double[] d;
    int k, n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextToken();
        k = a[0].length();
        A = new long[k][n];
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < n; ++j)
                for (int t = 0; t < n; ++t)
                    if (a[j].charAt(i) == a[t].charAt(i))
                        A[i][j] |= ((long) 1L << (long) t);
        curMasks = new long[k + 1][n];
        Arrays.fill(curMasks[0], ((long) 1L << (long) n) - 1L);
        d = new double[1 << k];
        Arrays.fill(d, -1.0);
        System.err.println("Start");
        double res = calc(0, 0, ((long) 1L << (long) n) - 1L);
        res /= n;
        out.printLine(String.format("%.20f", res));
    }

    private double calc(int mask, int depth, long alive) {
        if (d[mask] > -0.5) return d[mask];
        for (int i = 0; i < n; ++i) {
            if ((alive >> i) % 2 == 0) continue;
            int val = popcount(curMasks[depth][i]);
            if (val <= 1) alive ^= (1L << (long) i);
        }
        if (alive == 0L) return 0.0;
        double weight = popcount(alive);
        double num = 0.0, den = 0.0;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) % 2 == 1) continue;
            if (d[mask ^ (1 << i)] < -0.5) {
                for (int j = 0; j < n; ++j) {
                    curMasks[depth + 1][j] = (curMasks[depth][j] & A[i][j]);
                }
            }
            den += 1.0;
            num += weight + calc(mask ^ (1 << i), depth + 1, alive);
        }
        d[mask] = num / den;
        return d[mask];
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
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