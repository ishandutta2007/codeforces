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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s1 = in.nextToken();
        String s2 = in.nextToken();
        int[] a = new int[218 * 1000];
        for (int i = 0; i < s1.length(); ++i) {
            if (s1.charAt(i) == '0') continue;
            a[s1.length() - i + 10] += 1;
        }
        for (int i = 0; i < s2.length(); ++i) {
            if (s2.charAt(i) == '0') continue;
            a[s2.length() - i + 10] -= 1;
        }
        for (int i = a.length - 1; i >= 0; --i) {
            if (a[i] == 0) continue;
            while (a[i] > 0) {
                if (i == 0 || a[i - 1] >= 0) {
                    out.printLine(">");
                    return;
                } else {
                    a[i] -= 1;
                    a[i - 1] += 1;
                    if (i >= 2) a[i - 2] += 1;
                }
            }
            while (a[i] < 0) {
                if (i == 0 || a[i - 1] <= 0) {
                    out.printLine("<");
                    return;
                } else {
                    a[i] += 1;
                    a[i - 1] -= 1;
                    if (i >= 2) a[i - 2] -= 1;
                }
            }
        }
        out.printLine("=");
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