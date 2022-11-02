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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.nextToken();
        String p = in.nextToken();
        int n = s.length();
        int m = p.length();
        int[] forward = new int[n];
        for (int i = 0; i < n; ++i) {
            int val = i, pos = 0;
            while (val < n && pos < m) {
                if (s.charAt(val) == p.charAt(pos)) {
                    ++val;
                    ++pos;
                } else {
                    ++val;
                }
            }
            if (pos == m) {
                forward[i] = val;
            } else {
                forward[i] = -1;
            }
        }
        int[][] d = new int[n + 1][n + 1];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j) {
                // Don't skip.
                if (d[i + 1][j] < d[i][j])
                    d[i + 1][j] = d[i][j];
                // Skip.
                if (d[i + 1][j + 1] < d[i][j])
                    d[i + 1][j + 1] = d[i][j];
                // Try to match p.
                if (forward[i] != -1) {
                    int len = forward[i] - i;
                    int skipped = len - m;
                    if (d[forward[i]][j + skipped] < d[i][j] + 1)
                        d[forward[i]][j + skipped] = d[i][j] + 1;
                }
            }
        for (int i = 0; i <= n; ++i)
            out.print(d[n][i] + " ");
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