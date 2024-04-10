import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt() - 1;
        }
        boolean[] u = new boolean[n];
        ArrayList<Integer> lens = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            int x = i, l = 0;
            while (!u[x]) {
                ++l;
                u[x] = true;
                x = p[x];
            }
            lens.add(l);
        }
        int[] a = new int[lens.size()];
        for (int i = 0; i < lens.size(); ++i)
            a[i] = lens.get(i);

        int M = 0, km = k;
        for (int i = 0; i < a.length; ++i) {
            if (a[i] % 2 == 1) continue;
            int t = a[i] / 2;
            if (t > km) t = km;
            M += t * 2;
            km -= t;
        }
        for (int i = 0; i < a.length; ++i) {
            if (a[i] % 2 == 0) continue;
            int t = a[i] / 2;
            if (t > km) t = km;
            M += t * 2;
            km -= t;
        }
        for (int i = 0; i < a.length; ++i) {
            if (a[i] % 2 == 0) continue;
            if (km > 0) {
                --km;
                ++M;
            }
        }

        int m = 0;
        int[] cnts = new int[n + 1];
        for (int x : a) ++cnts[x];
        for (int i = 1; i <= n; ++i) {
            while (cnts[i] > 2) {
                int p2 = 1;
                while (p2 * 2 - 1 <= cnts[i]) p2 *= 2;

                for (int t = 1; t < p2; t *= 2) {
                    ++cnts[t * i];
                }
                cnts[i] -= (p2 - 1);
            }
        }
        BigInteger can = BigInteger.ONE;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < cnts[i]; ++j)
                can = can.or(can.shiftLeft(i));
        }
        m = k;
        if (!can.testBit(k))
            ++m;

        out.printLine(m + " " + M);
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