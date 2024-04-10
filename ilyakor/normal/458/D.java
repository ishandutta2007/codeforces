import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.math.MathContext;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {

    double[] logf;
    double[][] C;

    public void solve(int testNumber, InputReader in, OutputWriter out) {

        logf = new double[218 * 1000];
        logf[0] = 0.0;
        logf[1] = 0.0;
        for (int i = 2; i < logf.length; ++i) {
            logf[i] = logf[i - 1] + Math.log((double) i);
        }

        C = new double[400][400];
        C[0][0] = 1;
        for (int i = 1; i < C.length; ++i) {
            C[i][0] = 1;
            for (int j = 1; j < C[i].length; ++j)
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        solveCase(out, n, m, k);

//        for (int k = 0; k < 10000; ++k) {
//            long start = System.nanoTime();
//            solveCase(out, 300, 100000, k);
//            long end = System.nanoTime();
//            Assert.assertTrue(end - start < 1E8);
//        }
    }

    private void solveCase(OutputWriter out, int n, int m, int k) {
        double res = 0;
        double log2 = Math.log(2.0);
        double upper = 1E99;

        double[] probs = new double[k + 1];
        probs[0] = 1.0;
        double cur = 1.0;
        for (int i = 1; i <= k; ++i) {
            cur *= (k - i + 1.0);
            cur /= (m - i + 1.0);
            probs[i] = cur;
        }

        double[][] d = new double[n + 1][n + 1];
        for (int x = n; x >= 0; --x)
            for (int y = n; y >= 0; --y) {
                int l = n * (x + y) - x * y;
                if (l > m || l > k) continue;
                double logP = 0;
                double p = probs[l];

//                for (int i = x; i <= n; ++i)
//                    for (int j = y; j <= n; ++j) {
//                        if (i == x && j == y) continue;
//                        if (d[i][j] <= 0.0) continue;
//                        p -= C[n - x][i - x] * C[n - y][j - y] * d[i][j];
////                        double cp = Math.log(d[i][j]);
////                        cp += logf[n - x] - logf[i - x] - logf[n - i];
////                        cp += logf[n - y] - logf[j - y] - logf[n - j];
////                        p -= Math.exp(cp);
//                    }
//                d[x][y] = p;

                if (p <= 0) continue;
                logP = Math.log(p);

                logP += (logf[n] - logf[x] - logf[n - x]) + (logf[n] - logf[y] - logf[n - y]);
//                logP += log2 * (x + y);
                if (logP > Math.log(upper)) {
                    out.printLine("1e99");
                    return;
                }
                res += Math.exp(logP);
                if (res > upper) {
                    out.printLine("1e99");
                    return;
                }
            }
        out.printLine(String.format("%.1000f", res));
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