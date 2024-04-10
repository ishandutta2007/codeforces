import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    public static final int inf = 1000 * 1000 * 100;
    public static final int BUBEN = 52;
    int[][] d;
    int[][] from;
    int[][] next;
    int[][] prev;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
//        if (true) {
//            Random random = new Random(0xdead);
//            StringBuilder sb = new StringBuilder();
//            for (int i = 0; i < 50; ++i)
//                sb.append((char)('a' + random.nextInt(26)));
//            out.print(sb);
//            out.print('a');
//            out.print(sb.reverse());
//            return;
//        }
        String s = in.nextToken();
        int n = s.length();
        d = new int[BUBEN + 1][n + 1];
        from = new int[BUBEN + 1][n + 1];
        for (int i = 0; i < d.length; ++i)
            for (int j = 0; j < d[i].length; ++j)
                d[i][j] = -inf;
        next = new int[n + 1][26];
        prev = new int[n + 1][26];

        Arrays.fill(next[n], inf);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                next[i][j] = next[i + 1][j];
            }
            next[i][s.charAt(i) - 'a'] = i;
        }

        Arrays.fill(prev[0], -inf);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                prev[i + 1][j] = prev[i][j];
            }
            prev[i + 1][s.charAt(i) - 'a'] = i;
        }

        Arrays.fill(d[0], n);
        int best = -1, bi = -1, bj = -1;
        for (int i = 0; i <= BUBEN; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (d[i][j] < j - 1) continue;
                int current = 2 * i;
                if (d[i][j] == j - 1) --current;
                if (current > best && current <= 100) {
                    best = current;
                    bi = i;
                    bj = j;
                }
                if (i == BUBEN) continue;
                for (int c = 0; c < 26; ++c) {
                    int jj = next[j][c];
                    if (jj == inf) continue;
                    int val = prev[d[i][j]][c];
                    if (val == -inf) continue;
                    if (d[i + 1][jj + 1] < val) {
                        d[i + 1][jj + 1] = val;
                        from[i + 1][jj + 1] = j;
                    }
                }
            }
        }
        boolean odd = (best % 2 == 1);
        StringBuilder half = new StringBuilder();
        while (bi > 0) {
            int nj = from[bi][bj];
            half.append(s.charAt(bj - 1));
            bj = nj;
            --bi;
        }
        for (int i = half.length() - 1; i >= 0; --i)
            out.print(half.charAt(i));
        for (int i = (odd ? 1 : 0); i < half.length(); ++i)
            out.print(half.charAt(i));
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