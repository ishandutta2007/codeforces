import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        // n * (n - 1) / 2 + (2 ^ k - 1) * n == m
        // n ^ 2 + n (2 * C - 1) - 2 * m = 0
        // D = (2 * C - 1) ^ 2 + 8 * m
        // n = (-(2 * C - 1) + sqrt(D)) / 2
        long m = in.nextLong();
        boolean was = false;
        for (long k = 1; k - 1 <= m; k *= 2L) {
            BigInteger b = BigInteger.valueOf(2L * (k - 1L) - 1L);
            BigInteger d = b.multiply(b).add(BigInteger.valueOf(8L).multiply(BigInteger.valueOf(m)));
            BigInteger s = root(d);
            if (s == null) continue;
            BigInteger val = s.subtract(b);
            if (val.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) != 0) continue;
            BigInteger t = val.divide(BigInteger.valueOf(2));
            if (t.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) continue;
            out.printLine(t.multiply(BigInteger.valueOf(k)));
            was = true;
        }
        if (!was) out.printLine(-1);
    }

    private BigInteger root(BigInteger d) {
        BigInteger down = BigInteger.ZERO;
        BigInteger up = BigInteger.valueOf(2).pow(300);
        while (up.subtract(down).compareTo(BigInteger.ONE) > 0) {
            BigInteger t = up.add(down).divide(BigInteger.valueOf(2));
            if (t.multiply(t).compareTo(d) > 0) {
                up = t;
            } else {
                down = t;
            }
        }
        if (down.multiply(down).compareTo(d) == 0)
            return down;
        return null;
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