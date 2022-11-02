import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.math.MathContext;

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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        long res = getRes(n, a);
        out.printLine(res);

    }

    public long getRes(int n, int[] a) {
        ArrayList<Integer>[] ss = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            ss[i] = new ArrayList<>();
        }
        for (int s = 1; s < n; ++s)
            ss[IntegerUtils.gcd(s, n)].add(s);

        int[] groups = new int[n + 10];
        int gcnt;
        long res = 0;
        for (int d = 1; d < n; ++d) {
            if (n % d != 0) continue;
            int[] mx = new int[d];
            for (int i = 0; i < n; ++i) {
                if (mx[i % d] < a[i])
                    mx[i % d] = a[i];
            }
            gcnt = 0;
            int cur = 0;
            long sum = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == mx[i % d])
                    ++cur;
                else {
                    groups[gcnt++] = cur;
                    sum += cur;
                    cur = 0;
                }
            }

            if (cur == n) {
                res += (long) ss[d].size() * (long) n;
                continue;
            }

            if (cur > 0) {
                if (a[0] == mx[0] && cur < n) {
                    groups[0] += cur;
                } else {
                    groups[gcnt++] = cur;
                }
                sum += cur;
            }

            Arrays.sort(groups, 0, gcnt);
            int pos = 0;
            int prev = 1;
            for (int x : ss[d]) {
                while (pos < gcnt && groups[pos] < x) {
                    sum -= groups[pos] - prev + 1;
                    ++pos;
                }
                sum -= (long) (x - prev) * (long) (gcnt - pos);
                res += sum;
                prev = x;
            }
        }

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

class IntegerUtils {
    public static int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

}