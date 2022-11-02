import java.io.OutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextToken();
        }
        int[] next = new int[n];
        int right = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            while (s <= c && right < n) {
                if (s > 0) ++s;
                s += a[right].length();
                ++right;
            }
            if (s <= c)
                next[i] = n;
            else
                next[i] = right - 1;
            s -= a[i].length();
            if (s > 0) --s;
        }
        int[] perm = new int[n];
        for (int i = 0; i < n; ++i)
            perm[i] = i;
        int P = r;
        while (P > 0) {
            if (P % 2 == 1) {
                perm = mult(perm, next);
                --P;
            } else {
                next = mult(next, next);
                P /= 2;
            }
        }

        int opt = -1;
        int ol = 0, or = 0;
        for (int i = 0; i < n; ++i)
            if (perm[i] - i > opt) {
                opt = perm[i] - i;
                ol = i;
                or = perm[i];
            }
        int sum = 0;
        for (int i = ol; i < or; ++i) {
            int nsum = sum;
            if (sum > 0) ++nsum;
            nsum += a[i].length();
            if (nsum > c) {
                out.printLine();
                sum = 0;
            }
            if (sum != 0) {
                out.print(" ");
                ++sum;
            }
            sum += a[i].length();
            out.print(a[i]);
        }
    }

    private int[] mult(int[] a, int[] b) {
        int[] c = new int[a.length];
        for (int i = 0; i < a.length; ++i) {
            int val = a[i];
            if (val < a.length)
                val = b[val];
            c[i] = val;
        }
        return c;
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