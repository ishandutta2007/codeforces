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
    char[][] a;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        a = new char[n][];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextToken().toCharArray();
        int res = 1000 * 1000 * 1000;
        for (int it = 0; it < 2; ++it) {
            {
                char[][] _a = new char[m][n];
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        _a[j][i] = a[i][j];
                a = _a;
                {
                    int t = n;
                    n = m;
                    m = t;
                }
            }


            int[][] right = new int[n][m + 1];
            for (int i = 0; i < n; ++i) {
                right[i][m] = 0;
                for (int j = m - 1; j >= 0; --j) {
                    if (a[i][j] == 'X')
                        right[i][j] = right[i][j + 1] + 1;
                    else
                        right[i][j] = 0;
                }
            }

            int sx = -1, sy = -1;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != 'X') continue;
                    if (sx == -1) {
                        sx = i;
                        sy = j;
                    }
                }
            if (sx == -1) continue;
            int Y = right[sx][sy];
            int X = 1;
            for (int i = sx; i < n; ++i)
                if (right[i][sy] > Y) {
                    X = 0;
                    while (i + X < n && a[i + X][sy] == 'X')
                        ++X;
                    break;
                }
            int val = X * Y;
            if (val > res) continue;

            int[][] down = new int[n + 1][m];
            for (int i = n; i >= 0; --i)
                for (int j = 0; j < m; ++j) {
                    if (i == n) down[i][j] = 0;
                    else {
                        if (right[i][j] >= Y)
                            down[i][j] = down[i + 1][j] + 1;
                        else
                            down[i][j] = 0;
                    }
                }

            boolean[][] brush = new boolean[n][m];
            int cntBrush = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (down[i][j] >= X) {
                        cntBrush++;
                        brush[i][j] = true;
                    }
                }
            if (!brush[sx][sy]) continue;
            boolean[][] marked = new boolean[n][m];
            for (int i = 0; i < X; ++i)
                for (int j = 0; j < Y; ++j)
                    marked[sx + i][sy + j] = true;
            --cntBrush;
            while (true) {
                if (sx + 1 < n && brush[sx + 1][sy]) {
                    --cntBrush;
                    ++sx;
                    for (int j = 0; j < Y; ++j)
                        marked[sx + X - 1][sy + j] = true;
                } else if (sy + 1 < m && brush[sx][sy + 1]) {
                    --cntBrush;
                    ++sy;
                    for (int i = 0; i < X; ++i)
                        marked[sx + i][sy + Y - 1] = true;
                } else {
                    break;
                }
            }
            if (cntBrush > 0) continue;

            boolean ok = true;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (marked[i][j] && a[i][j] != 'X')  // should not happen
                        ok = false;
                    if (!marked[i][j] && a[i][j] == 'X')
                        ok = false;
                }

            if (ok) {
                res = val;
            }
        }
        if (res == 1000 * 1000 * 1000)
            res = -1;
        out.printLine(res);
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