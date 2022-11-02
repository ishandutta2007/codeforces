import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
    static final long minf = Long.MIN_VALUE;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long[] a = new long[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            a[i] = in.nextInt();
        }
        long[][] d = new long[n][2];
        d[0][0] = 0;
        d[0][1] = 0;
        long res = 0;
        long sum = 0;
        for (int i = 1; i < n; ++i) {
            long cur = a[i - 1];
            long odd = cur;
            if (odd % 2L == 0) --odd;
            long even = cur;
            if (even % 2L == 1) --even;
            if (even != 0)
                sum += even;
            else
                sum = 0;

            d[i][0] = sum;
            d[i][1] = sum;
            if (even > 0 && d[i - 1][0] + even > d[i][0])
                d[i][0] = d[i - 1][0] + even;
            if (even > 0 && d[i - 1][1] + even > d[i][0])
                d[i][0] = d[i - 1][1] + even;
            if (d[i - 1][1] + odd > d[i][1])
                d[i][1] = d[i - 1][1] + odd;

            if (res < d[i][0]) res = d[i][0];
            if (res < d[i][1]) res = d[i][1];
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
    }

    public String next() {
        return nextToken();
    }

    public String nextLine() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (c != '\n' && c != -1) {
            sb.append(c);
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

    public double nextDouble() {
        double sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpace(c) && c != '.') {
            if (c == 'e' || c == 'E') {
                return res * Math.pow(10, nextInt());
            } else if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpace(c)) {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                } else if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
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