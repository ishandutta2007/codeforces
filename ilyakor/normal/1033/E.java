import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Random;
import java.util.List;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.OutputStream;
import java.util.Collections;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Interactor interactor = new IOInteractor(in, out);
        doSolve(interactor);
}

    ArrayList<Integer>[] g;
    int[] col;
    Interactor interactor;
    int n;
    boolean[] u;

    void doSolve(Interactor interactor) {
        this.interactor = interactor;
        n = interactor.getN();
        g = new ArrayList[n];
        col = new int[n];
        u = new boolean[n];
        Arrays.fill(col, -1);
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<>();
        dfs(0, 0);
        ArrayList<Integer> h1 = new ArrayList<>(), h2 = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            Assert.assertTrue(col[i] != -1);
            if (col[i] == 0)
                h1.add(i);
            else
                h2.add(i);
        }
        int ch1 = interactor.query(toInt(h1));
        int ch2 = interactor.query(toInt(h2));
        if (ch1 == 0 && ch2 == 0) {
            interactor.yes(col);
            return;
        }
        List<Integer> bad = ch1 > 0 ? h1 : h2;
        while (bad.size() > 2) {
            Collections.shuffle(bad);
            List<Integer> half = bad.subList(0, (bad.size() + 1) / 2);
            int cnt = interactor.query(toInt(half));
            if (cnt > 0)
                bad = half;
        }
        Assert.assertTrue(bad.size() == 2);
        int x = bad.get(0), y = bad.get(1);
        ArrayList<Integer> order = new ArrayList<>();
        path(y, x, order);
        Collections.reverse(order);
        interactor.no(toInt(order));
    }

    private boolean path(int from, int to, ArrayList<Integer> out) {
        u[from] = true;
        if (from == to) {
            out.add(from);
            return true;
        }
        for (int x : g[from]) {
            if (u[x]) continue;
            if (path(x, to, out)) {
                out.add(from);
                return true;
            }
        }
        return false;
    }

    private void dfs(int x, int c) {
        col[x] = c;
        while (true) {
            int y = sample(x);
            if (y == -1) break;
            g[x].add(y);
            g[y].add(x);
            dfs(y, 1 - c);
        }
    }

    private int sample(int x) {
        List<Integer> alive = new ArrayList<>();
        for (int i = 0; i < n; ++i) if (col[i] == -1)
            alive.add(i);
        if (!hasEdges(x, alive))
            return -1;
        while (alive.size() > 1) {
            int s = alive.size() / 2;
            List<Integer> half = alive.subList(0, s);
            if (hasEdges(x, half))
                alive = half;
            else {
                alive = alive.subList(s, alive.size());
                }
        }
        int y = alive.get(0);
        return y;
    }

    private boolean hasEdges(int x, List<Integer> a) {
        int[] r1 = new int[a.size() + 1];
        for (int i = 0; i < a.size(); ++i)
            r1[i + 1] = a.get(i);
        r1[0] = x;
        int s = interactor.query(r1);
        if (s == 0)
            return false;
        int ss = interactor.query(toInt(a));
        return s > ss;
    }

    private int[] toInt(List<Integer> a) {
        int[] res = new int[a.size()];
        for (int i = 0; i < res.length; ++i)
            res[i] = a.get(i);
        return res;
    }

    interface Interactor {
        int getN();
        int query(int[] nodes);
        void yes(int[] cert);
        void no(int[] path);
    }

    static class IOInteractor implements Interactor {
        InputReader in;
        OutputWriter out;

        public IOInteractor(InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
        }

        public int getN() {
            return in.nextInt();
        }

        public int query(int[] nodes) {
            if (nodes.length <= 1)
                return 0;
            out.printLine("? " + nodes.length);
            for (int x : nodes)
                out.print((x + 1) + " ");
            out.printLine();
            out.flush();
            return in.nextInt();
        }

        public void yes(int[] cert) {
            int n = 0;
            for (int i = 0; i < cert.length; ++i)
                if (cert[i] == 0) ++n;
            out.printLine("Y " + n);
            for (int i = 0; i < cert.length; ++i)
                if (cert[i] == 0)
                    out.print((i + 1) + " ");
            out.printLine();
            out.flush();
        }

        public void no(int[] path) {
            out.printLine("N " + path.length);
            for (int x : path)
                out.print((x + 1) + " ");
            out.printLine();
            out.flush();
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

    public void flush() {
        writer.flush();
    }
}

class Assert {

    public static void assertTrue(boolean flag) {
if (!flag)
            throw new AssertionError();
    }

}