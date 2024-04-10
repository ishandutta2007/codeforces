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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    static final int mod = 1000 * 1000 * 1000 + 7;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();

Arrays.sort(a);
        long[][] d = new long[n + 1][k + 1];
        d[0][0] = 1;
        d[1][0] = 1;
        for (int i = 0; i + 1 < n; ++i) {
            long[][] nd = new long[n + 1][k + 1];
            for (int open = 0; open <= i + 1; ++open) {
                for (int delta = -1; delta <= 1; ++delta) {
                    if (open == 0 && delta == -1) continue;
                    int nopen = open + delta;
                    int costInc = open * (a[i + 1] - a[i]);
                    for (int cost = 0; cost + costInc <= k; ++cost) {
                        long inc = d[open][cost];
                        if (delta == -1)
                            inc *= open;
                        else if (delta == 0)
                            inc *= open + 1;
                        nd[nopen][cost + costInc] = (nd[nopen][cost + costInc] + inc) % mod;
                    }
                }
            }
            d = nd;
        }
        long res = 0;
        for (int i = 0; i <= k; ++i)
            res = (res + d[0][i]) % mod;
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