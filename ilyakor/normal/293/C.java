import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
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
    static final long inf = (long)(1E18);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long n = Long.parseLong(in.nextToken());
        if (n % 3L != 0) {
            out.printLine(0);
            return;
        }
        n /= 3L;
        ArrayList<Long> div = new ArrayList<Long>();
        for (long x = 1; x * x <= n; ++x) {
            if (n % x != 0L) continue;
            div.add(x);
            if (n / x != x) div.add(n / x);
        }
        Collections.sort(div);
        //Collections.reverse(div);
        long res = 0;
        for (int ai = 0; ai < div.size(); ++ai) {
            long a = div.get(ai);
            long ra = n / a;
            long a3 = to3(a);
            if (a3 < n) continue;
            int downi = 0, upi = ai;
            while (upi - downi > 1) {
                int t = (upi + downi) / 2;
                long b = div.get(t);
                long c = ra / b;
                long sum = b + c + 1;
                if (sum < a) {
                    downi = t;
                } else {
                    upi = t;
                }
            }
            //upi = 0;

            for (int bi = downi; bi <= ai; ++bi) {
                long b = div.get(bi);
                if (ra % b != 0) continue;
                long c = ra / b;
                if (c > b) continue;
                if (b + c <= a) continue;
                if ((a + b + c) % 2 == 1) continue;
                if (a == b && b == c) ++res;
                else if (a == b || b == c || a == c) res += 3;
                else res += 6;
            }

        }
        out.printLine(res);
    }

    private long to3(long a) {
        long x = a;
        if (inf / a <= x) return inf;
        x *= a;
        if (inf / a <= x) return inf;
        x *= a;
        return x;
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