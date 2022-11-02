import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = 1 << n;
        double[][] a = new double[m][m];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = in.nextInt() * 0.01;
        double[][] p = new double[m][n];
        for (int i = 0; i < m; ++i)
            p[i][0] = a[i][i ^ 1];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                double base = p[j][i - 1];
                int bucket = j & (~((1 << i) - 1));
                int obucket = bucket ^ (1 << i);
                for (int k = 0; k < (1 << i); ++k)
                    p[j][i] += base * p[obucket + k][i - 1] * a[j][obucket + k];
            }

        double[][] d = new double[m][n];
        for (int i = 0; i < m; ++i)
            d[i][0] = p[i][0];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                double base = d[j][i - 1];
                base += p[j][i] * (1 << i);
                int bucket = j & (~((1 << i) - 1));
                int obucket = bucket ^ (1 << i);
                double inc = 0.0;
                for (int k = 0; k < (1 << i); ++k)
                    inc = Math.max(inc, d[obucket + k][i - 1]);
                d[j][i] = base + inc;
            }
        double res = 0;
        for (int i = 0; i < m; ++i)
            res = Math.max(res, d[i][n - 1]);
        out.printLine(String.format("%.20f", res));
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