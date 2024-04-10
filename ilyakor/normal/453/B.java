import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    static final int maxn = 59;
    public static final int inf = 1000 * 1000 * 1000;
    public static final int[] P = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        int[][] d = new int[n + 1][1 << P.length];
        int[][] from = new int[n + 1][1 << P.length];
        int[][] fc = new int[n + 1][1 << P.length];
        for (int i = 0; i < d.length; ++i) {
            Arrays.fill(d[i], inf);
            Arrays.fill(from[i], -1);
        }
        int[] ma = new int[maxn];
        for (int i = 0; i < maxn; ++i) {
            int mask = 0;
            for (int t = 0; t < P.length; ++t) {
                if (i % P[t] == 0) {
                    mask |= (1 << t);
                }
            }
            ma[i] = mask;
        }
        d[0][0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < (1 << P.length); ++j) {
                if (d[i][j] >= inf) continue;
                for (int k = 1; k < maxn; ++k) {
                    if ((j & ma[k]) != 0) continue;
                    int nm = j | ma[k];
                    if (d[i + 1][nm] > d[i][j] + Math.abs(a[i] - k)) {
                        d[i + 1][nm] = d[i][j] + Math.abs(a[i] - k);
                        from[i + 1][nm] = j;
                        fc[i + 1][nm] = k;
                    }
                }
            }
        ArrayList<Integer> res = new ArrayList<>();
        int cur = 0;
        for (int i = 1; i < (1 << P.length); ++i)
            if (d[n][i] < d[n][cur])
                cur = i;
        //System.err.println(d[n][cur]);
        for (int i = n; i > 0; --i) {
            res.add(fc[i][cur]);
            cur = from[i][cur];
        }
        Collections.reverse(res);
        for (int x : res)
            out.print(x + " ");
        out.printLine();
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