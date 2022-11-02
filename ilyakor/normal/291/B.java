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
        Croc13QualB solver = new Croc13QualB();
        solver.solve(1, in, out);
        out.close();
    }
}

class Croc13QualB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.nextLine();
        StringBuilder cur = new StringBuilder();
        boolean inside = false;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '"') {
                if (inside) {
                    inside = false;
                    out.printLine("<" + cur.toString() + ">");
                    cur = new StringBuilder();
                } else {
                    inside = true;
                    String cmd = cur.toString().trim();
                    if (!cmd.isEmpty()) {
                        out.printLine("<" + cmd + ">");
                    }
                    cur = new StringBuilder();
                }
            } else if (c == ' ' && !inside) {
                String cmd = cur.toString().trim();
                if (!cmd.isEmpty()) {
                    out.printLine("<" + cmd + ">");
                }
                cur = new StringBuilder();
            } else {
                cur.append(c);
            }
        }
        String cmd = cur.toString().trim();
        if (!cmd.isEmpty()) {
            out.printLine("<" + cmd + ">");
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

    public String nextLine() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (c != '\n' && c != -1) {
            sb.append((char)c);
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