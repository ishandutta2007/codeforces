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
    int[][] next;
    int cnt;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        cnt = 1;
        next = new int[600 * 1000][26];

        int n = in.nextInt();
        int k = in.nextInt();
        for (int i = 0; i < n; ++i) {
            String s = in.nextToken();
            int cur = 0;
            for (int j = 0; j < s.length(); ++j) {
                int c = s.charAt(j) - 'a';
                if (next[cur][c] <= 0) {
                    next[cur][c] = cnt;
                    ++cnt;
                }
                cur = next[cur][c];
            }
        }
        int g1 = calc1(0);
        int g2 = calc2(0);
        if (k % 2 == 1) {
            out.printLine(g1 == 1 ? "First" : "Second");
        } else {
            out.printLine((g1 == 1 && g2 == 1) ? "First" : "Second");
        }
    }

    int calc1(int x) {
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (next[x][i] <= 0) continue;
            if (calc1(next[x][i]) == 0) res = 1;
        }
        return res;
    }

    int calc2(int x) {
        int res = 0;
        int cntC = 0;
        for (int i = 0; i < 26; ++i) {
            if (next[x][i] <= 0) continue;
            ++cntC;
            if (calc2(next[x][i]) == 0) res = 1;
        }
        if (cntC == 0) res = 1;
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