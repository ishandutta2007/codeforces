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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int q = in.nextInt();
        int h = 1;
        while (h < n + 20)
            h *= 2;
        SegmentTreeAddSum treeA = new SegmentTreeAddSum(h);
        SegmentTreeAddSum treeB = new SegmentTreeAddSum(h);
        for (int it = 0; it < q; ++it) {
            int t = in.nextInt();
            if (t == 1) {
                int di = in.nextInt();
                int ai = in.nextInt();
                treeA.set(di, Math.min(a, treeA.get(di) + ai));
                treeB.set(di, Math.min(b, treeB.get(di) + ai));
            } else {
                int p = in.nextInt();
                int res = p == 1 ? 0 : treeB.sum(1, p - 1);
                res += treeA.sum(p + k, n + 10);
                out.printLine(res);
            }
        }
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

class SegmentTreeAddSum {
	final int[] s;
	final int n;

	public SegmentTreeAddSum(int n) {
		this.n = n;
		s = new int[4 * n];
		buildTree(1, 0, n - 1);
	}

	void buildTree(int node, int left, int right) {
		if (left != right) {
			int mid = (left + right) >> 1;
			buildTree(node * 2, left, mid);
			buildTree(node * 2 + 1, mid + 1, right);
			s[node] = s[node * 2] + s[node * 2 + 1];
		}
	}

	public void add(int i, int value) {
		add(i, value, 1, 0, n - 1);
	}

	void add(int i, int value, int node, int left, int right) {
		if (left == right) {
			s[node] += value;
			return;
		}
		int mid = (left + right) >> 1;
		if (i <= mid)
			add(i, value, node * 2, left, mid);
		else
			add(i, value, node * 2 + 1, mid + 1, right);
		s[node] = s[node * 2] + s[node * 2 + 1];
	}

	public int sum(int a, int b) {
		return sum(a, b, 1, 0, n - 1);
	}

	int sum(int a, int b, int node, int left, int right) {
		if (left >= a && right <= b)
			return s[node];
		int mid = (left + right) >> 1;
		int res = 0;
		if (a <= mid)
			res += sum(a, b, node * 2, left, mid);
		if (b > mid)
			res += sum(a, b, node * 2 + 1, mid + 1, right);
		return res;
	}

	public int get(int i) {
		return sum(i, i);
	}

	public void set(int i, int value) {
		add(i, -get(i) + value);
	}

}