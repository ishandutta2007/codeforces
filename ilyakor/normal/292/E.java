import java.io.OutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        for (int i = 0; i < n; ++i)
            b[i] = in.nextInt();

        int h = 1;
        while (h <= n + 4) h *= 2;

        SegmentTreeIntervalFillSum type = new SegmentTreeIntervalFillSum(h);
        SegmentTreeIntervalFillSum val = new SegmentTreeIntervalFillSum(h);
        for (int i = 0; i < n; ++i)
            type.set(i + 1, 1);
        for (int i = 0; i < m; ++i) {
            int ti = in.nextInt();
            if (ti == 1) {
                int xi = in.nextInt();
                int yi = in.nextInt();
                int qi = in.nextInt();
                type.fill(yi, yi + qi - 1, xi + 2);
                val.fill(yi, yi + qi - 1, yi + 2);
            } else {
                int x = in.nextInt();
                int tmp = type.get(x) - 2;
                if (tmp == -1) {
                    out.printLine(b[x - 1]);
                } else {
                    int xi = tmp;
                    int yi = val.get(x) - 2;
                    out.printLine(a[xi + x - yi - 1]);
                }
            }
        }
    }

    public class SegmentTreeIntervalFillSum {

        int n;
        int[] tfill;
        int[] tsum;

        public SegmentTreeIntervalFillSum(int n) {
            this.n = n;
            tfill = new int[4 * n];
            Arrays.fill(tfill, -1);
            tsum = new int[4 * n];
        }

        void push(int node, int left, int right) {
            if (tfill[node] == -1)
                return;
            tsum[node] = tfill[node] * (right - left + 1);
            if (left < right) {
                tfill[node * 2] = tfill[node];
                tfill[node * 2 + 1] = tfill[node];
            }
            tfill[node] = -1;
        }

        void pop(int node, int left, int right) {
            int mid = (left + right) >> 1;
            tsum[node] = (tfill[node * 2] != -1) ? tfill[node * 2] * (mid - left + 1) : tsum[node * 2];
            tsum[node] += (tfill[node * 2 + 1] != -1) ? tfill[node * 2 + 1] * (right - mid) : tsum[node * 2 + 1];
        }

        public void add(int i, int value) {
            add(i, value, 1, 0, n - 1);
        }

        void add(int i, int value, int node, int left, int right) {
            push(node, left, right);
            if (left == right) {
                tsum[node] += value;
                return;
            }
            int mid = (left + right) >> 1;
            if (i <= mid)
                add(i, value, node * 2, left, mid);
            else
                add(i, value, node * 2 + 1, mid + 1, right);
            pop(node, left, right);
        }

        int sum(int a, int b) {
            return sum(a, b, 1, 0, n - 1);
        }

        int sum(int a, int b, int node, int left, int right) {
            push(node, left, right);
            if (left >= a && right <= b)
                return tsum[node];
            int mid = (left + right) >> 1;
            int res = 0;
            if (a <= mid)
                res += sum(a, b, node * 2, left, mid);
            if (b > mid)
                res += sum(a, b, node * 2 + 1, mid + 1, right);
            pop(node, left, right);
            return res;
        }

        int get(int i) {
            return sum(i, i);
        }

        void set(int i, int value) {
            add(i, -get(i) + value);
        }

        void fill(int a, int b, int value) {
            fill(a, b, value, 1, 0, n - 1);
        }

        void fill(int a, int b, int value, int node, int left, int right) {
            push(node, left, right);
            if (left >= a && right <= b) {
                tfill[node] = value;
                return;
            }
            int mid = (left + right) >> 1;
            if (a <= mid)
                fill(a, b, value, node * 2, left, mid);
            if (b > mid)
                fill(a, b, value, node * 2 + 1, mid + 1, right);
            pop(node, left, right);
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