import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.Random;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    static final Random random = new Random(0xdead);

    boolean[][] a;
    int[] goals;
    int[] cnts;
    boolean[] u;
    int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        a = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            char[] s = in.nextToken().toCharArray();
            for (int j = 0; j < n; ++j)
                a[i][j] = s[j] == '1';
        }

        goals = new int[n];
        for (int i = 0; i < n; ++i)
            goals[i] = in.nextInt();


        cnts = new int[n];
        u = new boolean[n];
        boolean solved = false;
        for (int it = 0; it < 100000; ++it) {
            boolean done = true;
            boolean bad = false;
            for (int i = 0; i < n; ++i)
                if (cnts[i] == goals[i]) {
                    done = false;
                    if (!fix(i)) {
                        bad = true;
                        break;
                    }
                }
            if (bad) break;
            if (done) {
                solved = true;
                break;
            }
        }
        if (!solved) {
            out.printLine(-1);
        } else {
            int res = 0;
            for (int i = 0; i < n; ++i)
                if (u[i])
                    ++res;
            out.printLine(res);
            for (int i = 0; i < n; ++i)
                if (u[i]) out.print((i + 1) + " ");
            out.printLine();
        }
    }

    private boolean fix(int x) {
        if (cnts[x] > 0 && (random.nextInt(1 << 20) >> 10) % 2 == 0) {
            ArrayList<Integer> l = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                if (a[i][x] && u[i])
                    l.add(i);
            if (l.size() == 0)
                return false;
            int ind = random.nextInt(l.size());
            int y = l.get(ind);
            for (int i = 0; i < n; ++i)
                if (a[y][i])
                    --cnts[i];
            u[y] = false;
        } else {
            ArrayList<Integer> l = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                if (a[i][x] && !u[i])
                    l.add(i);
            if (l.size() == 0)
                return false;
            int ind = random.nextInt(l.size());
            int y = l.get(ind);
            for (int i = 0; i < n; ++i)
                if (a[y][i])
                    ++cnts[i];
            u[y] = true;
        }
        return true;
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