import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        if (n - k < k) {
            k = n - k;
        }
        FenwickTree tree = new FenwickTree(n + 10);
        long cur = 1;
        int x = 0;
        for (int i = 0; i < n; ++i) {
            int y = (x + k) % n;
            int cnt = 0;
            if (y > x) {
                if (x + 1 <= y - 1) {
                    cnt += tree.sum(x + 2, y);
                }
            } else {
                if (x + 1 < n) {
                    cnt += tree.sum(x + 2, n);
                }
                if (y > 0) {
                    cnt += tree.sum(1, y);
                }
            }
            cur += 1 + cnt;
            out.print(cur + " ");
            tree.add(x + 1, 1);
            tree.add(y + 1, 1);
            x = y;
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

class FenwickTree {
	int[] t;
	int n;

	public FenwickTree(int n) {
		this.n = n;
		t = new int[n];
	}

    public void add(int i, int value) {
		for (; i < n; i += (i + 1) & -(i + 1))
			t[i] += value;
	}

	public int sum(int i) {
		int res = 0;
		for (; i >= 0; i -= (i + 1) & -(i + 1))
			res += t[i];
		return res;
	}

	public int sum(int a, int b) {
		return sum(b) - sum(a - 1);
	}

}