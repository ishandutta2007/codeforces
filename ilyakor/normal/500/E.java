import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Collections;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Random random = new Random(0xdead);
        //int n = 2 * 100 * 1000;
        int n = in.nextInt();
        ArrayList<Domino> a = new ArrayList<>();
        TreeSet<Integer> oxs = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            int p = in.nextInt();
            int l = in.nextInt();
//            int p = random.nextInt(1000 * 1000 * 1000) + 1;
//            int l = random.nextInt(1000 * 1000 * 1000) + 1;
            a.add(new Domino(p, l));
            oxs.add(p);
            //oxs.add(p + 1);
            //oxs.add(p - 1);
            oxs.add(p + l);
            //oxs.add(p + l + 1);
            //oxs.add(p + l - 1);
        }
        oxs.add(2 * 1000 * 1000 * 1000 + 10);
        oxs.add(-1);
        ArrayList<Integer> ox = new ArrayList<>(oxs);

        int q = in.nextInt();
        //int q = 2 * 100 * 1000;
        for (int i = 0; i < q; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            //int x = random.nextInt(n);
            //int y = random.nextInt(n);
            a.get(x).queries.add(new ii(a.get(y).p, i));
        }

        Collections.sort(a);

        //System.err.println("Phase 1");

        int h = 1;
        while (h < ox.size() + 10) h *= 2;
        SegmentTreeFastIntervalSetSum tree = new SegmentTreeFastIntervalSetSum(h);
        for (int i = 1; i < ox.size(); ++i) {
            int len = ox.get(i) - ox.get(i - 1);
            tree.set(i, len);
        }
        HashMap<Integer, Integer> coordMapping = new HashMap<>();
        for (int i = 1; i < ox.size(); ++i) {
            coordMapping.put(ox.get(i - 1), i);
        }

//        System.err.println("Phase 2");

        int[] res = new int[q];
        Arrays.fill(res, -1);
        for (Domino domino : a) {
            tree.modifySet(coordMapping.get(domino.p), coordMapping.get(domino.p + domino.l) - 1, 0);
            for (ii query : domino.queries) {
                res[query.second] = tree.querySum(coordMapping.get(domino.p), coordMapping.get(query.first));
            }
        }

        for (int i = 0 ; i < q; ++i)
            out.printLine(res[i]);
    }

    static class Domino implements Comparable<Domino> {
        int p;
        int l;
        ArrayList<ii> queries;

        Domino(int p, int l) {
            this.p = p;
            this.l = l;
            this.queries = new ArrayList<>();
        }


        public int compareTo(Domino o) {
            return -Integer.compare(p, o.p);
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

class ii implements Comparable<ii> {
    public int first;
    public int second;

    public ii() {
    }

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

}

class SegmentTreeFastIntervalSetSum {
	final int n;
	final int[] t;
	final int[] m;
	final boolean[] h;
	final int[] q;

	public SegmentTreeFastIntervalSetSum(int n) {
		this.n = n;
		t = new int[2 * n];
		m = new int[2 * n];
		h = new boolean[2 * n];
		q = new int[2 * n];
		for (int i = n; i < 2 * n; i++)
			q[i] = 1;
		for (int i = 2 * n - 1; i > 1; i -= 2)
			q[i >> 1] = q[i] + q[i ^ 1];
	}

	void modifierHelper(int i, int p) {
		t[i] = p * q[i];
		m[i] = p;
		h[i] = true;
	}

	void pop(int i) {
		if (h[i >> 1]) {
			t[i >> 1] = m[i >> 1] * q[i >> 1];
		} else {
			t[i >> 1] = t[i] + t[i ^ 1];
		}
	}

	void popUp(int i) {
		for (; i > 1; i >>= 1)
			pop(i);
	}

	void push(int i) {
		if (h[i >> 1]) {
			modifierHelper(i, m[i >> 1]);
			modifierHelper(i ^ 1, m[i >> 1]);
			h[i >> 1] = false;
		}
	}

	void pushDown(int i) {
		int k;
		for (k = 0; (i >> k) > 0; k++)
			;
		for (k -= 2; k >= 0; k--)
			push(i >> k);
	}

	public void modifySet(int a, int b, int v) {
		a += n;
		b += n;
		pushDown(a);
		pushDown(b);
		int ta = a;
		int tb = b;

		for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
			if ((a & 1) != 0)
				modifierHelper(a, v);
			if ((b & 1) == 0)
				modifierHelper(b, v);
		}

		popUp(ta);
		popUp(tb);
	}

	public int querySum(int a, int b) {
		a += n;
		b += n;
		pushDown(a);
		pushDown(b);

		int res = 0;
		for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
			if ((a & 1) != 0)
				res += t[a];
			if ((b & 1) == 0)
				res += t[b];
		}
		return res;
	}

    public void set(int i, int v) {
		modifySet(i, i, v);
	}

}