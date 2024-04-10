import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Collection;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static final int inf = 1000 * 1000 * 1000;

    int n;
    ArrayList<Edge>[] g;
    int[] u;
    ArrayList<Integer> L, R;
    ArrayList<Integer> restore;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Edge>[] g1 = new ArrayList[n];
        ArrayList<Edge>[] g2 = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g1[i] = new ArrayList<>();
            g2[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int z = in.nextToken().equals("R") ? 0 : 1;
            g1[x].add(new Edge(y, z));
            g1[y].add(new Edge(x, z));
            g2[x].add(new Edge(y, 1 - z));
            g2[y].add(new Edge(x, 1 - z));
        }
        int r1 = calc(g1);
        ArrayList<Integer> rest1 = restore;
        int r2 = calc(g2);
        ArrayList<Integer> rest2 = restore;

        int res;
        if (r1 <= r2) {
            res = r1;
            restore = rest1;
        } else {
            res = r2;
            restore = rest2;
        }
        if (res == inf)
            out.printLine(-1);
        else {
            out.printLine(res);
            for (int x : restore)
                out.print((x + 1) + " ");
            out.printLine();
        }
    }

    private int calc(ArrayList<Edge>[] g_) {
        g = g_;
        u = new int[n];
        restore = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (u[i] != 0) continue;
            L = new ArrayList<>();
            R = new ArrayList<>();
            if (!dfs(i, +1))
                return inf;
            if (L.size() <= R.size())
                restore.addAll(L);
            else
                restore.addAll(R);
        }
        return restore.size();
    }

    private boolean dfs(int x, int val) {
        u[x] = val;
        if (val > 0)
            L.add(x);
        else
            R.add(x);
        for (Edge e : g[x]) {
            int y = e.to;
            int nv = val;
            if (e.color == 1)
                nv = -nv;
            if (u[y] == 0) {
                if (!dfs(y, nv))
                    return false;
            } else {
                if (u[y] != nv)
                    return false;
            }
        }
        return true;
    }

    static class Edge {
        int to;
        int color;

        public Edge(int to, int color) {
            this.to = to;
            this.color = color;
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