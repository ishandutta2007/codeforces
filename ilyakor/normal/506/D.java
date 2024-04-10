import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
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
    int gen = 1;
    int[] genMark;
    int[] parent;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<ii>[] edges = new ArrayList[m];
        for (int i = 0; i < m; ++i)
            edges[i] = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            edges[c].add(new ii(x, y));
        }

        HashSet<Integer>[] marks = new HashSet[n];
        for (int i = 0; i < n; ++i)
            marks[i] = new HashSet<>();
        gen = 1;
        genMark = new int[n];
        parent = new int[n];
        int currentMark = 1;
        for (int i = 0; i < m; ++i) {
            ++gen;
            HashSet<Integer> touched = new HashSet<>();
            for (ii edge : edges[i]) {
                int x = edge.first;
                int y = edge.second;
                touched.add(x);
                touched.add(y);
                uni(x, y);
            }

            HashMap<Integer, Integer> markIndex = new HashMap<>();
            for (int x : touched) {
                int comp = get(x);
                if (!markIndex.containsKey(comp)) {
                    markIndex.put(comp, currentMark);
                    currentMark++;
                }
                marks[x].add(markIndex.get(comp));
            }
        }

        HashMap<ii, Integer> queryCache = new HashMap<>();
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if ((marks[x].size() > marks[y].size()) || (marks[x].size() == marks[y].size() && x > y)) {
                int t = x;
                x = y;
                y = t;
            }
            ii key = new ii(x, y);
            if (queryCache.containsKey(key)) {
                out.printLine(queryCache.get(key));
                continue;
            }

            int res = calc(marks[x], marks[y]);
            queryCache.put(key, res);
            out.printLine(res);
        }
    }

    private int calc(HashSet<Integer> a, HashSet<Integer> b) {
        int res = 0;
        for (int x : a)
            if (b.contains(x))
                ++res;
        return res;
    }

    void uni(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return;
        if ((((x * 43) ^ (y + 21)) >> 3) % 2 == 0) {
            parent[x] = y;
        } else {
            parent[y] = x;
        }
    }

    int get(int x) {
        if (genMark[x] != gen) {
            genMark[x] = gen;
            parent[x] = x;
        }
        if (parent[x] == x)
            return x;
        parent[x] = get(parent[x]);
        return parent[x];
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