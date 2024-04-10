import java.util.Arrays;
import java.util.TreeSet;
import java.util.HashSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int a = in.nextInt() - 1;
        int b = in.nextInt() - 1;
        int c = in.nextInt() - 1;
        int d = in.nextInt() - 1;
        if (k < n + 1 || n <= 4) {
            out.printLine(-1);
            return;
        }
        int[] mapping = new int[n];
        Arrays.fill(mapping, -1);
        mapping[0] = a;
        mapping[1] = b;
        mapping[2] = c;
        mapping[4] = d;
        TreeSet<Integer> free = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            free.add(i);
        }
        free.remove(a);free.remove(b);free.remove(c);free.remove(d);
        for (int i = 0; i < n; ++i) {
            if (mapping[i] == -1) {
                mapping[i] = free.first();
                free.remove(mapping[i]);
            }
        }
        HashSet<ii> roads = new HashSet<>();
        int prev = -1;
        for (int i = 0; ; i = (i + n - 1) % n) {
            if (prev != -1) roads.add(new ii(Math.min(prev, mapping[i]), Math.max(prev, mapping[i])));
            prev = mapping[i];

            out.print((mapping[i] + 1) + " ");
            if (i == 1) break;
        }
        out.printLine();
        prev = -1;
        ArrayList<Integer> inds = new ArrayList<>();
        inds.add(c);
        inds.add(b);
        inds.add(mapping[3]);
        for (int i = 0; ; i = (i + n - 1) % n) {
            inds.add(mapping[i]);
            if (i == 4) break;
        }
        for (int x : inds) {
            if (prev != -1) roads.add(new ii(Math.min(prev, x), Math.max(prev, x)));
            prev = x;

            out.print((x + 1) + " ");
        }

        out.printLine();
        Assert.assertTrue(roads.size() <= n + 1);
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

class Assert {

    public static void assertTrue(boolean flag) {
if (!flag)
            throw new AssertionError();
    }

}