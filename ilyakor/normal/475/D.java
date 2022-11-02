import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.OutputStream;
import java.math.MathContext;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        int q = in.nextInt();
        int[] queries = new int[q];
        HashMap<Integer, Long> ans = new HashMap<>();
        for (int i = 0; i < q; ++i) {
            int val = in.nextInt();
            queries[i] = val;
            ans.put(val, 0L);
        }
        int[] stack = new int[218 * 1000]; // it is logarithmic in fact.
        int[] sind = new int[stack.length];
        int ssize = 0;
        for (int i = 0; i < a.length; ++i) {
            int cur = a[i];
            int newSize = 0;
            stack[ssize] = cur;
            sind[ssize] = i;
            ++ssize;
            for (int j = 0; j < ssize; ++j) {
                stack[j] = IntegerUtlis.gcd(stack[j], cur);
                if (j > 0 && stack[j] == stack[j - 1]) {
                    // do nothing
                } else {
                    stack[newSize] = stack[j];
                    sind[newSize] = sind[j];
                    ++newSize;
                }
            }
            ssize = newSize;
            for (int j = 0; j < ssize; ++j) {
                if (ans.containsKey(stack[j])) {
                    int val = j == ssize - 1 ? (i + 1) : sind[j + 1];
                    val -= sind[j];
                    ans.put(stack[j], ans.get(stack[j]) + val);
                }
            }
        }

        for (int i = 0; i < q; ++i) {
            out.printLine(ans.get(queries[i]));
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

class IntegerUtlis {
    public static int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

}