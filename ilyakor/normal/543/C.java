import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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

    public static final int inf = 1000 * 1000 * 500;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] s = new char[n][];
        for (int i = 0; i < n; ++i) {
            s[i] = in.nextToken().toCharArray();
            Assert.assertTrue(s[i].length == m);
        }
        int[][] w = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                w[i][j] = in.nextInt();
        ArrayList<ii> a = new ArrayList<>();
        int smask = 0;
        for (int i = 0; i < m; ++i) {
            int[] masks = new int[26];
            int[] costs = new int[26];
            int[] maxs = new int[26];
            for (int j = 0; j < n; ++j) {
                int c = s[j][i] - 'a';
                masks[c] |= (1 << j);
                costs[c] += w[j][i];
                maxs[c] = Math.max(maxs[c], w[j][i]);
            }
            for (int j = 0; j < 26; ++j)
                if (masks[j] > 0) {
                    if (costs[j] - maxs[j] == 0)
                        smask |= masks[j];
                    else
                        a.add(new ii(masks[j], costs[j] - maxs[j]));
                }
        }
        for (int i = 0; i < n; ++i) {
            int cost = inf;
            for (int j = 0; j < m; ++j)
                cost = Math.min(cost, w[i][j]);
            a.add(new ii((1 << i), cost));
        }

        int[] d = new int[1 << n];
        Arrays.fill(d, inf);
        d[smask] = 0;
        d[0] = 0;
        for (int i = smask; i < d.length; ++i) {
            if (d[i] >= inf) continue;
            for (int i1 = 0; i1 < a.size(); ++i1) {
                ii entry = a.get(i1);
                if (i != (i | entry.first)) {
                    int val = d[i] + entry.second;
                    if (d[i | entry.first] > val)
                        d[i | entry.first] = val;
                }
            }
        }
        Assert.assertTrue(d[(1 << n) - 1] < inf);
        out.printLine(d[(1 << n) - 1]);
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

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
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