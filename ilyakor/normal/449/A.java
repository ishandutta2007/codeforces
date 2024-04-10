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
        long n = in.nextLong();
        long m = in.nextLong();
        long k = in.nextLong();
        if (n + m - 2 < k) {
            out.printLine(-1);
            return;
        }
        if (n > m) {
            long t = n;
            n = m;
            m = t;
        }
        long l = k - m + 1, r = n - 1;
        if (l < 0) l = 0;
        if (r > k) r = k;
//        while (l < r - 10) {
//            long t1 = (2L * l + r) / 3L;
//            long t2 = (l + 2L * r) / 3L;
//            long val1 = n / (t1 + 1L) * m / (k - t1 + 1);
//            long val2 = n / (t2 + 1L) * m / (k - t2 + 1);
//            if (val1 < val2)
//                l = val1;
//            else r = val2;
//        }
//        while (l < r - 1) {
//            long val = (l + r) / 2;
//            long v1 = n / (val + 1L);
//            long v2 = m / (k - val + 1L);
//            if (v1 < v2)
//                r = val;
//            else
//                l = val;
//        }
        long res = (long) -1E18;
        long[] candidates = new long[]{l, r};
        for (long val : candidates)
            if (val >= l && val <= r)
                res = Math.max(res, (n / (val + 1L)) * (m / (k - val + 1)));
//        for (long val = l; val <= r; ++val) {
//            if (n / (val + 1L) * m / (k - val + 1) > res) {
//                System.err.println("AAA " + n + " " + m + " " + k + " " + val);
//                throw new RuntimeException();
//            }
//        }
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