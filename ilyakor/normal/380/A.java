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
    static final int BUBEN = 110 * 1000;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int m = in.nextInt();
        int[] a = new int[BUBEN];
        long[] cnt = new long[m + 1];
        int[] len = new int[m + 1];
        int[] what = new int[m + 1];
        Arrays.fill(len, -1);
        int ac = 0;
        cnt[0] = 0;
        len[0] = -1;
        for (int i = 0; i < m; ++i) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt();
                if (ac < BUBEN) {
                    a[ac++] = x;
                }
                cnt[i + 1] = cnt[i] + 1;
                len[i + 1] = -1;
                what[i + 1] = x;
            } else {
                int l = in.nextInt();
                int c = in.nextInt();
                for (int j = 0; j < (long) l * (long) c && ac < BUBEN; ++j) {
                    a[ac++] = a[j % l];
                }
                cnt[i + 1] = cnt[i] + (long) l * (long) c;
                len[i + 1] = l;
            }
        }
        int n = in.nextInt();
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            long cur = in.nextLong() - 1;
            while (cur >= cnt[pos]) ++pos;
            if (len[pos] == -1) {
                out.print(what[pos] + " ");
            } else {
                out.print(a[(int)((cur - cnt[pos - 1]) % len[pos])] + " ");
            }
        }
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

    public void close() {
        writer.close();
    }

    }