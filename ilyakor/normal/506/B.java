import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    ArrayList<Integer>[] g1, g2;
    boolean[] u;
    int[] ind;
    int[] pos;
    ArrayList<Integer> inds;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g1 = new ArrayList[n];
        g2 = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g1[i] = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            g2[i] = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g1[x].add(y);
            g1[y].add(x);
            g2[x].add(y);
        }
        u = new boolean[n];
        ind = new int[n];
        pos = new int[n];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            inds = new ArrayList<>();
            dfs(i);
            if (inds.size() <= 1) continue;
            ArrayList<Integer>[] subG = new ArrayList[inds.size()];
            for (int j = 0; j < subG.length; ++j) {
                subG[j] = new ArrayList<>();
                for (int x : g2[inds.get(j)])
                    subG[j].add(ind[x]);
            }

            List<Integer> order = TopologicalSort.topologicalSort(subG);
            boolean ok = true;
            for (int j = 0; j < order.size(); ++j)
                pos[order.get(j)] = j;
            for (int j = 0; j < subG.length; ++j)
                for (int x : subG[j]) {
                    if (pos[x] < pos[j])
                        ok = false;
                }
            if (ok) res += inds.size() - 1;
            else res += inds.size();
        }
        out.printLine(res);
    }

    private void dfs(int x) {
        u[x] = true;
        ind[x] = inds.size();
        inds.add(x);
        for (int y : g1[x])
            if (!u[y])
                dfs(y);
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

class TopologicalSort {

    static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
        used[u] = true;
        for (int v : graph[u])
            if (!used[v])
                dfs(graph, used, res, v);
        res.add(u);
    }

    public static List<Integer> topologicalSort(List<Integer>[] graph) {
        int n = graph.length;
        boolean[] used = new boolean[n];
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs(graph, used, res, i);
        Collections.reverse(res);
        return res;
    }

}