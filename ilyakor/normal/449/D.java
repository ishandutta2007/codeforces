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
    static final int maxn = 1 << 18;
    static final int mod = 1000 * 1000 * 1000 + 7;

    static int[] bcnt = new int[maxn];

    int[] p2;

    static {
        bcnt[0] = 0;
        for (int i = 1; i < maxn; ++i) {
            bcnt[i] = (i % 2) + bcnt[i / 2];
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        p2 = new int[maxn * 4];
        p2[0] = 1;
        for (int i = 1; i < p2.length; ++i)
            p2[i] = (p2[i - 1] * 2) % mod;

        int n = in.nextInt();
//        int n = 1000 * 1000;
        int[][] d = new int[5][maxn];
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
//            int x = i;
            d[x % 4][x / 4] += 1;
            if (x % 4 == 1 || x % 4 == 0)
                d[4][x / 4] += 1;
        }
        int[] D = new int[maxn];
        long res = 0;
        for (int i = 0; i < maxn; ++i) {
            if (d[3][i] == 0) continue;
            addNum(D, i, d[3][i]);
        }
        res = calc(D);
        int[] D_save = Arrays.copyOf(D, maxn);
        for (int i = 0; i < maxn; ++i) {
            if (d[2][i] == 0) continue;
            addNum(D, i, d[2][i]);
        }
        res = (res - calc(D)) % mod;
        res = (res + mod) % mod;
        for (int i = 0; i < maxn; ++i) {
            if (d[4][i] == 0) continue;
            addNum(D, i, d[4][i]);
        }
//        for (int i = 0; i < maxn; ++i) {
//            if (d[1][i] == 0) continue;
//            addNum(D, i, d[1][i]);
//        }
//        for (int i = 0; i < maxn; ++i) {
//            if (d[0][i] == 0) continue;
//            addNum(D, i, d[0][i]);
//        }
        res = (res + calc(D)) % mod;

        D = D_save;
        for (int i = 0; i < maxn; ++i) {
            if (d[1][i] == 0) continue;
            addNum(D, i, d[1][i]);
        }
        res = (res - calc(D)) % mod;
        res = (res + mod) % mod;
//
//        for (int i = 0; i < maxn; ++i) {
//            for (int j = i; ; j = (j - 1) & i) {
//                D[j] += d[i];
//                if (j == 0) break;
//            }
//        }
//        for (int i = 0; i < maxn; ++i) {
//            int x = i;
//            long s = 1;
//            while (x > 0) {
//                if (x % 2 == 1) s = -s;
//                x /= 2;
//            }
//            res = (res + s * (long) p2[D[i]]) % mod;
//        }
        out.printLine(res);
    }

    private long calc(int[] d) {
        long res = 0;
        for (int i = 0; i < maxn; ++i) {
            if (bcnt[i] % 2 == 0) {
                res += p2[d[i]];
                res %= mod;
            } else {
                res -= p2[d[i]];
                res %= mod;
                res += mod;
                res %= mod;
            }
        }
        return res;
    }

    static void addNum(int[] D, int x, int cnt) {
        for (int j = x; ; j = (j - 1) & x) {
            D[j] += cnt;
            if (j == 0) break;
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