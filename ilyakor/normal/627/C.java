import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Collections;
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
    static final long inf = (long)(1E18);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long len = in.nextLong();
        long cap = in.nextLong();
        int N = in.nextInt();

        ArrayList<ComparablePair<Long, Long>> points = new ArrayList<>();
        points.add(new ComparablePair<Long, Long>(0L, 0L));
        points.add(new ComparablePair<Long, Long>(cap, inf));
        points.add(new ComparablePair<Long, Long>(len, 0L));
        for (int i = 0; i < N; ++i) {
            long pos = in.nextLong();
            long cost = in.nextLong();
            points.add(new ComparablePair<Long, Long>(pos, cost));
            if (pos + cap < len)
                points.add(new ComparablePair<Long, Long>(pos + cap, inf));
        }
        Collections.shuffle(points);
        Collections.sort(points);

        long[] a = new long[points.size()];
        long[] p = new long[points.size()];
        for (int i = 0; i < points.size(); ++i) {
            a[i] = points.get(i).first;
            p[i] = points.get(i).second;
        }

        long[] d = new long[a.length];
        Arrays.fill(d, inf);
        d[0] = 0;
        int l = 0;

        int h = 1;
        while (h < d.length + 20) h *= 2;
        SegmentTreeFastAddMax tree = new SegmentTreeFastAddMax(h);
        for (int i = 0; i < a.length; ++i)
            tree.set(i + 1, -p[i]);

        for (int i = 1; i < d.length; ++i) {
            while (l < i && a[i] - a[l] > cap) ++l;
            if (l == i) {
                out.printLine(-1);
                return;
            }
            long M = -tree.max(l + 1, i);
            if (M >= inf) {
                out.printLine(-1);
                return;
            }
            d[i] = d[i - 1] + ((long) (a[i] - a[i - 1])) * M;

        }
        out.printLine(d[d.length - 1]);
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

    public long nextLong() {
        long sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10L + (long)(c - '0');
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

class ComparablePair<P extends Comparable, Q extends Comparable>
        extends Pair<P, Q> implements Comparable<Pair<P, Q>> {

    public ComparablePair(P first, Q second) {
        super(first, second);
    }


    public int compareTo(Pair<P, Q> other) {
        int valP = first.compareTo(other.first);
        if (valP != 0) return valP;
        return second.compareTo(other.second);
    }
}

class SegmentTreeFastAddMax {
	final int n;
	final long[] t;

	public SegmentTreeFastAddMax(int n) {
        int h = 1;
        while (h <= n) h *= 2;
        n = h;
		this.n = n;
		t = new long[n + n];
	}

    public void set(int i, long value) {
		add(i, value - t[i + n]);
	}

	public void add(int i, long value) {
		i += n;
		t[i] += value;
		for (; i > 1; i >>= 1)
			t[i >> 1] = Math.max(t[i], t[i ^ 1]);
	}

	public long max(int a, int b) {
		long res = Long.MIN_VALUE;
		for (a += n, b += n; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
			res = Math.max(res, t[a]);
			res = Math.max(res, t[b]);
		}
		return res;
	}

}

class Pair<P, Q> {
    public P first;
    public Q second;

    public Pair(P first, Q second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
        if (second != null ? !second.equals(pair.second) : pair.second != null) return false;

        return true;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
}