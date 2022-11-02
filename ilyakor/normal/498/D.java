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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        SegmentTreeCustom tree = new SegmentTreeCustom(1 << 17);
        for (int i = 0; i < n; ++i)
            tree.set(i + 1, in.nextInt());
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            String c = in.nextToken();
            int x = in.nextInt();
            int y = in.nextInt();
            if (c.equals("A")) {
                out.printLine(tree.get(x, y - 1)[0]);
            } else {
                tree.set(x, y);
            }
        }
    }

    public class SegmentTreeCustom {
        final int[][] a;
        int n;

        public SegmentTreeCustom(int n) {
            this.n = n;
            a = new int[2 * n + 1][60];
        }

        public void set(int pos, int period) {
            pos += n - 1;
            Arrays.fill(a[pos], 1);
            for (int i = 0; i < a[pos].length; i += period)
                a[pos][i] = 2;
            pos /= 2;
            while (pos > 0) {
                combine(a[pos * 2], a[pos * 2 + 1], a[pos]);
                pos /= 2;
            }
        }

        public int[] get(int l, int r) {
            l += n - 1;
            r += n - 1;
            if (l > r) return new int[60];
            if (l == r) return a[l];
            int[] res1 = a[l];
            int[] res2 = a[r];
            while (l < r - 1) {
                if (l % 2 == 0) {
                    int[] tmp = new int[60];
                    combine(res1, a[l + 1], tmp);
                    res1 = tmp;
                }
                if (r % 2 == 1) {
                    int[] tmp = new int[60];
                    combine(a[r - 1], res2, tmp);
                    res2 = tmp;
                }
                l /= 2;
                r /= 2;
            }
            int[] res = new int[60];
            combine(res1, res2, res);
            return res;
        }

        private void combine(int[] a, int[] b, int[] out) {
            for (int i = 0; i < 60; ++i)
                out[i] = a[i] + b[(i + a[i]) % 60];
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