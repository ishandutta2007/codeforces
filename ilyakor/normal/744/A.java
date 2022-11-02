import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int[] r = new int[k];
        for (int i = 0; i < k; ++i) {
            r[i] = in.nextInt() - 1;
        }
        DisjointSets dsu = new DisjointSets(n);

        ArrayList<ii> edges = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (dsu.root(x) != dsu.root(y)) {
                dsu.unite(x, y);
            }
            edges.add(new ii(x, y));
        }
        int[] cnts = new int[n];
        boolean[] marked = new boolean[n];
        for (int x : r) {
            marked[dsu.root(x)] = true;
        }
        for (int i = 0; i < n; ++i) {
            ++cnts[dsu.root(i)];
        }
        int M = 0, S = 0;
        for (int i = 0; i < n; ++i) {
            if (marked[i]) M = Math.max(M, cnts[i]);
            else S += cnts[i];
        }
        long res = 0;
        while (S > 0) {
            res += M;
            ++M;
            --S;
        }
        for (int i = 0; i < n; ++i) {
            if (marked[i])
                res += (cnts[i] * (cnts[i] - 1)) / 2;
        }
        res -= m;
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

class DisjointSets {
	int[] p;
	int[] rank;

	public DisjointSets(int size) {
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = i;
		}
		rank = new int[size];
	}

    public int root(int x) {
		while (x != p[x])
			x = p[x];
		return x;
	}

	public void unite(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b)
			return;
		if (rank[a] < rank[b]) {
			p[a] = b;
		} else {
			p[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}

}

class ii implements Comparable<ii> {
    public int first;
    public int second;

    public ii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        ii ii = (ii) o;

        if (first != ii.first) return false;
        if (second != ii.second) return false;

        return true;
    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(ii o) {
        if (first != o.first) {
            return first < o.first ? -1 : 1;
        }
        if (second != o.second) {
            return second < o.second ? -1 : 1;
        }
        return 0;
    }

    public String toString() {
        return "{" +
                "first=" + first +
                ", second=" + second +
                '}';
    }
}