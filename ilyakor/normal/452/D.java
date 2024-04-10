import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int k = in.nextInt();
        int[] n = new int[3];
        int[] t = new int[3];
        for (int i = 0; i < 3; ++i)
            n[i] = in.nextInt();
        for (int i = 0; i < 3; ++i)
            t[i] = in.nextInt();
        PriorityQueue<Integer>[] q = new PriorityQueue[3];
        for (int i = 0; i < 3; ++i) {
            q[i] = new PriorityQueue<>();
            for (int j = 0; j < n[i]; ++j)
                q[i].add(0);
        }
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int[] times = new int[3];
            int M = 0, dec = 0;
            for (int j = 0; j < 3; ++j) {
                times[j] = q[j].poll() - dec;
                M = Math.max(M, times[j]);
                dec += t[j];
            }
            for (int j = 0; j < 3; ++j) {
                M += t[j];
                q[j].add(M);
            }
            res = Math.max(res, M);
        }
        out.printLine(res);
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