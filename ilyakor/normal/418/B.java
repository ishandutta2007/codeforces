import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
    static final long inf = (long)(2E18);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long b = in.nextLong();
        long[] d = new long[1 << m];
        Arrays.fill(d, inf);
        d[0] = 0;
        ArrayList<Entry> entries = new ArrayList<Entry>();
        for (int i = 0; i < n; ++i) {
            long cost = in.nextLong();
            long cnt = in.nextLong();
            int mc = in.nextInt();
            int mask = 0;
            for (int j = 0; j < mc; ++j)
                mask |= (1 << (in.nextInt() - 1));
            entries.add(new Entry(cost, cnt, mask));
        }
        Collections.sort(entries, new Comparator<Entry>() {
            @Override
            public int compare(Entry entry1, Entry entry2) {
                return Long.valueOf(entry1.cnt).compareTo(entry2.cnt);
            }
        });
        long res = inf;
        for (int i = 0; i < n; ++i) {
            int mask = entries.get(i).mask;
            long cost = entries.get(i).money;
            for (int j = 0; j < d.length; ++j) {
                long val = d[j] + cost;
                if (d[j | mask] > val) d[j | mask] = val;
            }
            long cur = b * entries.get(i).cnt + d[(1 << m) - 1];
            if (cur < res) res = cur;
        }
        if (res >= inf) res = -1;
        out.printLine(res);
    }

    static class Entry {
        long money, cnt;
        int mask;

        Entry(long money, long cnt, int mask) {
            this.money = money;
            this.cnt = cnt;
            this.mask = mask;
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