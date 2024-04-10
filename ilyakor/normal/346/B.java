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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s1 = in.nextToken();
        String s2 = in.nextToken();
        String bad = in.nextToken();
        int[][] next = new int[bad.length()][26];
        for (int i = 0; i < bad.length(); ++i) {
            for (int c = 0; c < 26; ++c) {
                for (int len = i + 1; len >= 0; --len) {
                    boolean ok = true;
                    for (int j = 0; j < len; ++j) {
                        char c1 = bad.charAt(j);
                        char c2 = j == len - 1 ? (char)('A' + c) : bad.charAt(i - len + 1 + j);
                        if (c1 != c2) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        next[i][c] = len;
                        break;
                    }
                }
            }
        }

        int[][][] d = new int[s1.length() + 1][s2.length() + 1][bad.length() + 1];
        int[][][] from = new int[s1.length() + 1][s2.length() + 1][bad.length() + 1];
        d[0][0][0] = 1;
        int res = 0;
        int oi = 0, oj = 0, ok = 0;
        for (int i = 0; i <= s1.length(); ++i)
            for (int j = 0; j <= s2.length(); ++j)
                for (int k = 0; k < bad.length(); ++k) {
                    if (d[i][j][k] == 0) continue;
                    if (d[i][j][k] - 1 > res) {
                        res = d[i][j][k] - 1;
                        oi = i;
                        oj = j;
                        ok = k;
                    }
                    if (i == s1.length() || j == s2.length()) continue;
                    if (d[i + 1][j][k] < d[i][j][k]) {
                        d[i + 1][j][k] = d[i][j][k];
                        from[i + 1][j][k] = (i * 200 + j) * 200 + k;
                    }
                    if (d[i][j + 1][k] < d[i][j][k]) {
                        d[i][j + 1][k] = d[i][j][k];
                        from[i][j + 1][k] = (i * 200 + j) * 200 + k;
                    }
                    if (s1.charAt(i) == s2.charAt(j) && d[i + 1][j + 1][next[k][s1.charAt(i) - 'A']] < d[i][j][k] + 1) {
                        d[i + 1][j + 1][next[k][s1.charAt(i) - 'A']] = d[i][j][k] + 1;
                        from[i + 1][j + 1][next[k][s1.charAt(i) - 'A']] = (i * 200 + j) * 200 + k;
                    }
                }
        if (res == 0) {
            out.printLine(0);
            return;
        }
        StringBuilder sb = new StringBuilder();
        while (oi > 0 && oj > 0) {
            int f = from[oi][oj][ok];
            int nk = f % 200; f /= 200;
            int nj = f % 200; f /= 200;
            int ni = f % 200; f /= 200;
            if (ni == oi - 1 && nj == oj - 1) {
                sb.append(s1.charAt(ni));
            }
            oi = ni;
            oj = nj;
            ok = nk;
        }
        out.printLine(sb.reverse().toString());
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