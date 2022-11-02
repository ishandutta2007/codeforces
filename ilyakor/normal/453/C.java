import java.io.IOException;
import java.io.OutputStreamWriter;
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
    ArrayList<Integer>[] g;
    int[] marked;
    boolean[] u;
    ArrayList<Integer> res;

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
        marked = new int[n];
        int cntM = 0;
        for (int i = 0; i < n; ++i) {
            marked[i] = in.nextInt();
            cntM += marked[i];
        }
        u = new boolean[n];
        res = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            int cur = dfs(i);
            if (cur == 0) continue;
            if (cur != cntM) {
                out.printLine(-1);
                return;
            }
            u = new boolean[n];
            int root = genAns(i);
            if (root == 0) {
                res.remove(res.size() - 1);
            }
            break;
        }
        out.printLine(res.size());
//        HashMap<Integer, Integer> D = new HashMap<>();
        for (int x : res) {
            out.print((x + 1) + " ");
//            if (D.containsKey(x))
//                D.put(x, D.get(x) + 1);
//            else
//                D.put(x, 1);
        }
//        for (int i = 0; i < n; ++i) {
//            int val = 0;
//            if (D.containsKey(i))
//                val = D.get(i) % 2;
//            if (val != marked[i])
//                throw new RuntimeException();
//        }
        out.printLine();
    }

    private int genAns(int x) {
        u[x] = true;
        res.add(x);
        int rc = marked[x];
        for (int y : g[x]) {
            if (u[y]) continue;
            int cur = genAns(y);
            res.add(x);
            if (cur == 0) {
                res.add(y);
                res.add(x);
            } else {
                rc = (rc + 1) % 2;
            }
        }
        return rc;
    }

    private int dfs(int x) {
        u[x] = true;
        int res = marked[x];
        for (int y : g[x]) {
            if (u[y]) continue;
            res += dfs(y);
        }
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