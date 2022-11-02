import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
    static final int mod = 1000 * 1000 * 1000 + 7;
    static int maxn = 1100 * 1000;
    static int[] f, rf;

    static {
        f = new int[maxn];
        f[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            f[i] = (int)((f[i - 1] * (long) i) % mod);
        }
        rf = new int[maxn];
        rf[0] = 1;
        rf[1] = 1;
        for (int i = 2; i < maxn; ++i) {
            rf[i] = (int) ((mod - (mod / i) * (long) rf[mod % i] % mod) % mod);
        }
        for (int i = 2; i < maxn; ++i) {
            rf[i] = (int)((rf[i] * (long) rf[i - 1]) % mod);
            }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        ++k;
        int[] F = new int[n + 1];
        int[] D = new int[n + 1];
        F[0] = 1;
        D[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (i < k) {
                D[i] = 0;
            } else {
                long cur = F[i - k] * C(i - 1, k - 1);
                cur %= mod;
                cur *= f[k - 1];
                cur %= mod;
                D[i] = (int) cur;
            }
            {
                long cur = F[i - 1] * (long) i;
                cur -= D[i];
                cur %= mod; cur += mod; cur %= mod;
                F[i] = (int) cur;
            }
        }

        long res = 0;
        for (int m = k; m < n; ++m) {
            long cur = D[m];
            cur *= C(n - 1, m);
            cur %= mod;
            cur *= f[n - m];
            cur %= mod;
            res += cur;
            res %= mod;
        }
        out.printLine(res);
    }

    private long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        long res = f[n];
        res *= rf[k];
        res %= mod;
        res *= rf[n - k];
        res %= mod;
        return res;
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