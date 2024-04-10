import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {

    public static final int inf = 100000000;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long g = in.nextLong();
        long r = in.nextLong();
        long[] l = new long[n + 1];
        long[] ls = new long[n + 2];
        ArrayList<lili> all = new ArrayList<lili>();
        long cur = 0;
        for (int i = 0; i < n + 1; ++i) {
            l[i] = in.nextLong();
            ls[i + 1] = ls[i] + l[i];
            cur = (cur + l[i]) % (r + g);
            all.add(new lili(cur, i + 1));
        }
        Collections.sort(all);
        int[] wh = new int[n + 2];
        for (int i = 0; i < all.size(); ++i)
            wh[(int) all.get(i).second] = i;
        SegmentTreeSimpleSetMin tree = new SegmentTreeSimpleSetMin(all.size() + 10);
        for (int i = 0; i < all.size(); ++i)
            tree.put(i + 1, inf);
        long[] d = new long[n + 2];
        d[n + 1] = 0;
        tree.put(wh[n + 1] + 1, (n + 1));
        for (int i = n; i >= 0; --i) {
            long L = (g + ls[i]) % (r + g);
            long R = ls[i] % (r + g);
            int val;
            if (L < R) {
                val = calc(all, tree, L, R);
            } else {
                val = Math.min(calc(all, tree, L, r + g), calc(all, tree, 0, R));
            }
            if (val == inf) val = n + 1;
            long t1 = ls[val] - ls[i];
            long t2 = t1 % (r + g);
            if (t2 < g) t2 = 0;
            else t2 = r + g - t2;
            if (val == n + 1) t2 = 0;
            d[i] = d[val] + t1 + t2;
            if (i > 0)
                tree.put(wh[i] + 1, i);
        }
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            int t = in.nextInt();
            long L = (g - t) % (r + g);
            long R = (-t) % (r + g);
            L = (L + r + g) % (r + g);
            R = (R + r + g) % (r + g);
            int val;
            if (L < R) {
                val = calc(all, tree, L, R);
            } else {
                val = Math.min(calc(all, tree, L, r + g), calc(all, tree, 0, R));
            }
            if (val == inf) val = n + 1;
            long t1 = ls[val] + t;
            long t2 = t1 % (r + g);
            if (t2 < g) t2 = 0;
            else t2 = r + g - t2;
            if (val == n + 1) t2 = 0;
            long res = t1 + t2 + d[val];
            out.printLine(res);
        }
    }

    private int calc(ArrayList<lili> all, SegmentTreeSimpleSetMin tree, long l, long r) {
        int indL = Collections.binarySearch(all, new lili(l, -1));
        indL = -indL - 1;
        int indR = Collections.binarySearch(all, new lili(r, -1));
        indR = -indR - 1;
        if (indL >= indR) return inf;
        return tree.get(indL + 1, indR);
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
    }

    public String next() {
        return nextToken();
    }

    public String nextLine() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (c != '\n' && c != -1) {
            sb.append(c);
            c = read();
        }
        return sb.toString();
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

    public double nextDouble() {
        double sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpace(c) && c != '.') {
            if (c == 'e' || c == 'E') {
                return res * Math.pow(10, nextInt());
            } else if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpace(c)) {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                } else if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
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

class lili implements Comparable<lili> {
    public long first;
    public long second;

    public lili() {
    }

    public lili(long first, long second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        lili lili = (lili) o;

        if (first != lili.first) return false;
        if (second != lili.second) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = (int) (first ^ (first >>> 32));
        result = 31 * result + (int) (second ^ (second >>> 32));
        return result;
    }

    public lili add(lili o) {
        return new lili(first + o.first, second + o.second);
    }

    public lili subtract(lili o) {
        return new lili(first - o.first, second - o.second);
    }

    public lili negate() {
        return new lili(-first, -second);
    }

    public int compareTo(lili o) {
        if (first != o.first) {
            return first < o.first ? -1 : 1;
        }
        if (second != o.second) {
            return second < o.second ? -1 : 1;
        }
        return 0;
    }
}

class SegmentTreeSimpleSetMin {
    int[] a;
    int h;

    public SegmentTreeSimpleSetMin(int n) {
        h = 1;
        while (h <= n) h *= 2;
        a = new int[2 * h + 1];
    }

    public void put(int index, int val) {
        index += h;
        a[index] = val;
        index /= 2;
        while (index > 0) {
            a[index] = Math.min(a[2 * index], a[2 * index + 1]);
            index /= 2;
        }
    }

    public int get(int l, int r) {
        if (l > r) return Integer.MIN_VALUE;
        l += h;
        r += h;
        int al = a[l];
        int ar = a[r];
        while (l < r - 1) {
            if (l % 2 == 0) al = Math.min(al, a[l + 1]);
            if (r % 2 == 1) ar = Math.min(ar, a[r - 1]);
            l /= 2;
            r /= 2;
        }
        return Math.min(al, ar);
    }
}