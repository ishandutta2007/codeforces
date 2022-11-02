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
        int m = in.nextInt();
        int[][] zeros = new int[30][n + 1];
        int[][] ones = new int[30][n + 1];
        int[] L = new int[m];
        int[] R = new int[m];
        int[] Q = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            int q = in.nextInt();
            L[i] = l;
            R[i] = r;
            Q[i] = q;
            for (int j = 0; j < 30; ++j) {
                if ((q >> j) % 2 == 0) {
                    zeros[j][l] += 1;
                    zeros[j][r + 1] -= 1;
                } else {
                    ones[j][l] += 1;
                    ones[j][r + 1] -= 1;
                }
            }
        }
        int[] res = new int[n];
        int[][] d = new int[30][n + 1];
        for (int i = 0; i < 30; ++i) {
            int o = 0, z = 0;
            for (int j = 0; j < n; ++j) {
                o += ones[i][j];
                z += zeros[i][j];
//                if (o > 0 && z > 0) {
//                    out.printLine("NO");
//                    return;
//                }
                if (o > 0) {
                    res[j] |= (1 << i);
                    d[i][j] += 1;
                }
            }
        }
        for (int j = 0; j < 30; ++j) {
            for (int i = 1; i <= n; ++i) {
                d[j][i] += d[j][i - 1];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 30; ++j) {
                if ((Q[i] >> j) % 2 == 0) {
                    int cntOnes = d[j][R[i]] - (L[i] == 0 ? 0 : d[j][L[i] - 1]);
                    if (cntOnes == R[i] - L[i] + 1) {
                        out.printLine("NO");
                        return;
                    }
                }
            }
        }
        out.printLine("YES");
        for (int j = 0; j < n; ++j) {
            out.print(res[j] + " ");
        }
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