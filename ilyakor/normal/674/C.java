import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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

    public static final double inf = 1E100;

    int[] a;
    double[] invSum;
    double[] pairSum;
    double[] sum;
    int n, k;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        k = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

invSum = new double[n + 1];
        pairSum = new double[n + 1];
        sum = new double[n + 1];
        for (int i = 0; i < n; ++i) {
            invSum[i + 1] = invSum[i] + 1.0 / a[i];
            sum[i + 1] = sum[i] + a[i];
            pairSum[i + 1] = pairSum[i] + sum[i + 1] / a[i];
        }
        double[][] d = new double[k + 1][n + 1];
        int[][] opt = new int[k + 1][n + 1];
        for (int i = 0; i <= k; ++i)
            Arrays.fill(d[i], inf);
        for (int i = 0; i <= k; ++i)
            d[0][0] = 0.0;

double[] sx = new double[n + 10];
        double[] sy = new double[n + 10];
        int ss, ptr;
        for (int i = 1; i <= k; ++i) {
            ss = 0;
            ptr = 0;
            for (int j = 1; j <= n; ++j) {
                double val = Math.min(d[i - 1][j] - pairSum[j], calc(0, j - 1) - pairSum[j]);
                if (j > 1) {
                    while (ptr + 1 < ss && sx[ptr] + sy[ptr] * invSum[j] >= sx[ptr + 1] + sy[ptr + 1] * invSum[j])
                        ++ptr;
                    double cur = sx[ptr] + sy[ptr] * invSum[j];
                    val = Math.min(val, cur);
}
                d[i][j] = val + pairSum[j];

                double c = d[i - 1][j] - pairSum[j] + invSum[j] * sum[j];
                double alpha = -sum[j];
                while (ss >= 2 && check(sx[ss - 2], sy[ss - 2], sx[ss - 1], sy[ss - 1], c, alpha))
                    --ss;
                sx[ss] = c;
                sy[ss] = alpha;
                ++ss;
            }
        }

out.printLine(String.format("%.10f", d[k][n]));
    }

    private boolean check(double x1, double y1, double x2, double y2, double x3, double y3) {
        return (x2 - x1) * (y2 - y3) >= (x3 - x2) * (y1 - y2);
    }


    private double calc(int l, int r) {
        if (l > r) return 0.0;
        return pairSum[r + 1] - pairSum[l] - (invSum[r + 1] - invSum[l]) * sum[l];
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