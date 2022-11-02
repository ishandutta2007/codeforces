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
    public static final int inf = 1000 * 1000 * 1000;
    int[] type;
    int[] r, b;
    int[][] d;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        type = new int[n];
        r = new int[n];
        b = new int[n];
        int sumR = 0, sumB = 0;
        for (int i = 0; i < n; ++i) {
            String s = in.nextToken();
            type[i] = s.equals("R") ? 0 : 1;
            r[i] = in.nextInt();
            b[i] = in.nextInt();
            sumR += r[i];
            sumB += b[i];
        }
        d = new int[1 << n][n * (n - 1) / 2 + 1];
        for (int i = 0; i < d.length; ++i)
            Arrays.fill(d[i], -inf);
        d[0][0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cr = 0, cb = 0;
            for (int i = 0; i < n; ++i)
                if ((mask >> i) % 2 == 1) {
                    if (type[i] == 0) ++cr;
                    else ++cb;
                }
            for (int i = 0; i < n; ++i) if ((mask >> i) % 2 == 0) {
                int nm = mask ^ (1 << i);
                int addR = Math.min(cr, r[i]);
                int addB = Math.min(cb, b[i]);
                for (int rDisc = 0; rDisc < d[mask].length; ++rDisc) {
                    if (d[mask][rDisc] < 0) continue;
                    int val = d[mask][rDisc] + addB;
                    if (d[nm][rDisc + addR] < val)
                        d[nm][rDisc + addR] = val;
                }
            }
        }
        int m = (1 << n) - 1;
        int res = inf;
        for (int i = 0; i < d[m].length; ++i) {
            if (d[m][i] == -inf) continue;
            res = Math.min(res, Math.max(sumR - i, sumB - d[m][i]));
        }
        out.printLine(res + n);
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