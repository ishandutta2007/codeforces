import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    ArrayList<Integer>[] g;

    int[] mark;
    int T;

    boolean[] u;
    int[] res;
    int[] dir;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }

        u = new boolean[n];
        res = new int[n];
        dir = new int[n];

        T = 1;
        mark = new int[n];
        boolean[] init = new boolean[n];
        init[0] = true;
        markComp(g[0]);
        mark[0] = T;
        for (int x : g[0]) {
            init[x] = true;
        }
        int num0 = 1;
        u[0] = true;
        res[0] = 0;
        for (int x : g[0])
            if (deg(x) == g[0].size() && g[x].size() == g[0].size()) {
                ++num0;
                u[x] = true;
                res[x] = 0;
            }


        Queue<ArrayList<Integer>> layers = new ArrayDeque<>();

        int rem = g[0].size() + 1 - num0;
        for (int it = 0; it < 2; ++it) {
            int s = -1;
            for (int x : g[0])
                if (!u[x]) s = x;
            int num1 = 0;
            if (s != -1) {
                ArrayList<Integer> comp = new ArrayList<>();
                comp.add(s);
                for (int x : g[s]) {
                    if (init[x] && !u[x])
                        comp.add(x);
                }
                markComp(comp);
                num1 = comp.size();
                for (int x : comp) {
                    if (deg(x) != comp.size() - 1) {
                        out.printLine("NO");
                        return;
                    }
                    u[x] = true;
                    dir[x] = it == 0 ? 1 : -1;
                    res[x] = dir[x];
                }
                layers.add(comp);
            }
            rem -= num1;
        }
        if (rem != 0) {
            out.printLine("NO");
            return;
        }
        while (!layers.isEmpty()) {
            ArrayList<Integer> comp = layers.poll();
            ArrayList<Integer> ncomp = new ArrayList<>();
            ++T;
            int pdir = dir[comp.get(0)];
            int pres = res[comp.get(0)];
            for (int x : comp) {
                for (int y : g[x]) {
                    if (u[y]) {
                        if (Math.abs(res[x] - res[y]) > 1) {
                            out.printLine("NO");
                            return;
                        }
                        continue;
                    }
                    if (mark[y] != T) {
                        ncomp.add(y);
                        mark[y] = T;
                    }
                }
            }
            if (ncomp.isEmpty()) continue;
            for (int x : ncomp) {
                if (deg(x) != ncomp.size() - 1) {
                    out.printLine("NO");
                    return;
                }
                u[x] = true;
                res[x] = pres + pdir;
                dir[x] = pdir;
            }
            layers.add(ncomp);
        }
        out.printLine("YES");
        int mv = 0;
        for (int x : res) {
            if (x < mv) mv = x;
        }
        for (int x : res)
            out.print((x - mv + 1) + " ");
        out.printLine();
    }

    private void markComp(ArrayList<Integer> comp) {
        ++T;
        for (int x : comp)
            mark[x] = T;
    }

    private int deg(int x) {
        int res = 0;
        for (int y : g[x])
            if (mark[y] == T)
                ++res;
        return res;
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