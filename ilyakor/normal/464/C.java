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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static final long mod = 1000000007;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long[] vals = new long[10];
        long[] shifts = new long[10];
        for (int i = 0; i < 10; ++i) {
            vals[i] = i;
            shifts[i] = 10;
        }
        String s = in.nextToken();
        int m = in.nextInt();
        int[] left = new int[m];
        String[] right = new String[m];
        for (int i = 0; i < m; ++i) {
            String cur = in.nextToken();
            left[i] = cur.charAt(0) - '0';
            right[i] = cur.substring(3);
        }
        for (int i = m - 1; i >= 0; --i) {
            long newVal = 0;
            long newShift = 1;
            for (int j = 0; j < right[i].length(); ++j) {
                int c = right[i].charAt(j) - '0';
                newVal = (newVal * shifts[c] + vals[c]) % mod;
                newShift = (newShift * shifts[c]) % mod;
            }
            vals[left[i]] = newVal;
            shifts[left[i]] = newShift;
        }
        long val = 0;
        for (int j = 0; j < s.length(); ++j) {
            int c = s.charAt(j) - '0';
            val = (val * shifts[c] + vals[c]) % mod;
        }
        out.printLine(val);
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