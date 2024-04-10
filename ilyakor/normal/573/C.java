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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    ArrayList<Integer>[] g;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }

        if (n == 1) {
            out.printLine("Yes");
            return;
        }

        boolean[] chained = new boolean[n];
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                chained[i] = true;
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int x = q.poll();
            int y = -1;
            for (int z : g[x])
                if (!chained[z])
                    y = z;
            if (y == -1) continue;
            if (g[y].size() > 2) continue;
            chained[y] = true;
            q.add(y);
        }

        boolean[] chainRoot = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (chained[i]) continue;
            if (g[i].size() > 3) continue;
            int cntChains = 0;
            for (int x : g[i])
                if (chained[x]) ++cntChains;
            if (cntChains != 2) continue;
            chainRoot[i] = true;
        }

        for (int i = 0; i < n; ++i) {
            if (chained[i] || chainRoot[i]) continue;
            int deg = 0;
            for (int x : g[i])
                if (!chained[x] && !chainRoot[x])
                    ++deg;
            if (deg > 2)  {
                out.printLine("No");
                return;
            }
        }

        out.printLine("Yes");
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