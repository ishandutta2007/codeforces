import java.io.OutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.nextToken();
        String t = in.nextToken();
        int[] a1 = calc(s, t);
        int[] a2 = calc(new StringBuilder(s).reverse().toString(), new StringBuilder(t).reverse().toString());
        for (int i = 0; i < a2.length / 2; ++i) {
            int x = a2[i];
            a2[i] = a2[a2.length - i - 1];
            a2[a2.length - i - 1] = x;
        }
        boolean res = true;
        for (int i = 0; i < s.length(); ++i) {
            int l = a1[i], r = a2[i];
            if (l + r <= t.length()) {
                res = false;
                break;
            }
        }
        out.printLine(res ? "Yes" : "No");
    }

    int[] calc(String s, String t) {
        int[] res = new int[s.length()];
        int[] opt = new int[300];
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (j < t.length() && s.charAt(i) == t.charAt(j)){
                ++j;
                opt[s.charAt(i)] = j;
            }
            res[i] = opt[s.charAt(i)];
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
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