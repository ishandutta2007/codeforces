import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.math.MathContext;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
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
    static long inf = (long)(1E15);

    int[] a;
    long[] d, dd;
    ArrayList<Integer>[] g;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        a = new int[n];
        d = new long[n];
        dd = new long[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            sum += a[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        long res = dfs(0, -1);
        out.printLine(sum - res);
    }

    private long dfs(int x, int p) {
        long R = inf;
        long t = 1;
        long cnt = 0;
        for (int y : g[x]) if (y != p) {
            ++cnt;
            dfs(y, x);
        }
        for (int y : g[x]) if (y != p) {
            if (dd[y] >= inf || t >= inf) {
                R = 0;
                t = inf;
            } else {
                long tmp = IntegerUtlis.gcd(t, dd[y]);
                t /= tmp;
                if (inf / dd[y] + 2 < t) t = inf;
                else t *= dd[y];
            }
            if (t > inf) t = inf;
        }
        for (int y : g[x]) if (y != p) {
            R = Math.min(R, d[y] / t);
        }
        if (cnt == 0) {
            d[x] = a[x];
            dd[x] = 1;
        } else {
            d[x] = R == 0 ? 0 : (R * cnt * t);
            dd[x] = (inf / t + 2 < cnt ? inf : (t * cnt));
            if (dd[x] > inf) dd[x] = inf;
        }
        return d[x];
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

class IntegerUtlis {

    public static long gcd(long x, long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    }