import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
import java.util.Collection;
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
    public static final int inf = 100000000;
    int[] a;
    ArrayList<Integer>[] g;

    int get(int x) {
        if (a[x] == x) return x;
        return a[x] = get(a[x]);
    }

    void uni(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) a[x] = y;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int[] d = new int[n + m];
        for (int i = 0; i < d.length; ++i)
            d[i] = inf;
        Queue<Integer> q = new ArrayDeque<Integer>();
        for (int i = 0; i < k; ++i) {
            int x = in.nextInt();
            --x;
            d[x] = 0;
            q.add(x);
        }
        a = new int[n + m];
        g = new ArrayList[n + m];
        for (int i = 0; i < a.length; ++i) {
            a[i] = i;
            g[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            --x;
            --y;
            g[x].add(n + i); g[n + i].add(y);
            g[y].add(n + i); g[n + i].add(x);
        }
        int s = in.nextInt();
        int t = in.nextInt();
        --s;
        --t;
        d[t] = 0;
        q.add(t);
        int res = 1;
        while (!q.isEmpty() && get(s) != get(t)) {
            int x = q.poll();
            res = d[x] + 1;
            for (int y : g[x]) {
                uni(x, y);
                if (d[y] == inf) {
                    d[y] = d[x] + 1;
                    q.add(y);
                }
            }
        }
        if (get(s) != get(t)) res = -1;
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