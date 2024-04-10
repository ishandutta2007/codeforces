import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static final int inf = 2 * 1000 * 1000 * 1000;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        for (int i = 0; i < n; ++i)
            b[i] = in.nextInt();
        ii[] st = new ii[n + 1];
        int ss = 0;
        long[] d = new long[n];
        d[0] = 0;
        st[ss++] = new ii(0, 0);
        for (int i = 1; i < n; ++i) {

            int ind;
            {
                int down = 0, up = ss;
                while (up - down > 1) {
                    int t = (up + down) / 2;
                    if (st[t].first <= a[i])
                        down = t;
                    else
                        up = t;
                }
                ind = down;
            }

            int prev = st[ind].second;
            d[i] = d[prev] + (long) a[i] * (long) b[prev];

            while (ss > 0) {
                int j = st[ss - 1].second;
                long t = st[ss - 1].first;
                if (d[j] + (long) b[j] * t >= d[i] + (long) b[i] * t) {
                    --ss;
                    continue;
                }
                break;
            }

            {
                int j = st[ss - 1].second;
                long num = d[i] - d[j];
                long den = b[j] - b[i];
                long lim = num / den;
                if (num % den != 0) ++lim;
                int ilim;
                if (lim < inf)
                    ilim = (int) lim;
                else
                    ilim = inf;
                st[ss++] = new ii(ilim, i);
            }
        }
        out.printLine(d[n - 1]);
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