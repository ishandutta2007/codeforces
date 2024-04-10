import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.Vector;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        long[] d = new long[n];
        d[0] = 0;
        Stack<Entry> st1 = new Stack<>();
        Stack<Long> st1m = new Stack<>();
        Stack<Entry> st2 = new Stack<>();
        Stack<Long> st2m = new Stack<>();
        for (int i = 0; i < n; ++i) {
            while (!st1.isEmpty() && a[st1.peek().second] <= a[i]) {
                st1.pop();
                st1m.pop();
            }
            while (!st2.isEmpty() && a[st2.peek().second] >= a[i]) {
                st2.pop();
                st2m.pop();
            }
            long val = 0;
            if (i > 0) val = d[i - 1];

            if (!st1.isEmpty()) {
                val = Math.max(val, st1m.peek() - (long)a[i]);
            }
            if (!st2.isEmpty()) {
                val = Math.max(val, st2m.peek() + (long)a[i]);
            }

            d[i] = val;
            long prevVal = 0;
            if (i > 0) prevVal = d[i - 1];
            Entry cur1 = new Entry(prevVal + (long) a[i], i);
            long val1 = cur1.first;
            if (!st1m.isEmpty()) {
                val1 = Math.max(val1, st1m.peek());
            }
            st1.add(cur1);
            st1m.add(val1);

            Entry cur2 = new Entry(prevVal - (long) a[i], i);
            long val2 = cur2.first;
            if (!st2m.isEmpty()) {
                val2 = Math.max(val2, st2m.peek());
            }
            st2.add(cur2);
            st2m.add(val2);
        }
        out.printLine(d[n - 1]);
    }

    static class Entry extends ComparablePair<Long, Integer> {
        Entry(Long first, Integer second) {
            super(first, second);
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

class ComparablePair<P extends Comparable, Q extends Comparable>
        extends Pair<P, Q> implements Comparable<Pair<P, Q>> {

    public ComparablePair() {
    }

    public ComparablePair(P first, Q second) {
        super(first, second);
    }


    public int compareTo(Pair<P, Q> other) {
        int valP = first.compareTo(other.first);
        if (valP != 0) return valP;
        return second.compareTo(other.second);
    }
}

class Pair<P, Q> {
    public P first;
    public Q second;

    public Pair() {
    }

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