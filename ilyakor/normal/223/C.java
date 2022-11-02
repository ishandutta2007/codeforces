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
    static final long mod = 1000 * 1000 * 1000 + 7;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long k = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextLong();
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                out.print(a[i] + " ");
            }
            out.printLine();
            return;
        }
        --k;
        long[] coef = new long[n + 1];
        long num = 1;
        long den = 1;
        for (int i = 0; i <= n; ++i) {
            coef[i] = num * IntegerUtlis.pow(den, mod - 2, (int) mod);
            coef[i] %= mod;
            num *= k + i + 1;
            num %= mod;
            den *= (long)(i + 1);
            den %= mod;
        }
        for (int i = 0; i < n; ++i) {
            long cur = 0;
            for (int j = 0; j <= i; ++j) {
                cur += coef[j] * a[i - j];
                cur %= mod;
            }
            out.print(cur + " ");
        }
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

class IntegerUtlis {

    public static int pow(long x, long y, int mod) {
        x %= mod;
        long res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                --y;
                res = (res * x) % mod;
            } else {
                y /= 2;
                x = (x * x) % mod;
            }
        }
        return (int)(res % mod);
    }

    }