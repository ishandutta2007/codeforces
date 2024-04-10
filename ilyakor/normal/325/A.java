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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        ArrayList<Integer> ax = new ArrayList<Integer>();
        ArrayList<Integer> ay = new ArrayList<Integer>();
        int n = in.nextInt();
        int[][] a = new int[n][4];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j) {
                a[i][j] = in.nextInt();
                ax.add(a[i][0]);
                ay.add(a[i][1]);
                ax.add(a[i][2]);
                ay.add(a[i][3]);
            }
        for (int x1 : ax)
            for (int x2 : ax) if (x1 < x2)
                for (int y1 : ay)
                    for (int y2 : ay) if (y1 < y2 && x2 - x1 == y2 - y1) {
                        int s = 0;
                        boolean ok = true;
                        for (int i = 0; i < n; ++i) {
                            s += (a[i][2] - a[i][0]) * (a[i][3] - a[i][1]);
                            if (a[i][0] < x1 || a[i][2] > x2 || a[i][1] < y1 || a[i][3] > y2)
                                ok = false;
                        }
                        if (ok && s == (x2 - x1) * (y2 - y1)) {
                            out.printLine("YES");
                            return;
                        }
                    }
        out.printLine("NO");
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