import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.nextToken();
        int[] a = new int[n];
        int[] allow = new int[n];
        for (int i = 0; i < n; ++i) {
            boolean[] avail = new boolean[k];
            Arrays.fill(avail, true);
            for (int j = 1; j <= 2 && i - j >= 0; ++j) {
                avail[s.charAt(i - j) - 'a'] = false;
            }
            int cur = s.charAt(i) - 'a';
            int cnt = 0;
            for (int j = 0; j < cur; ++j)
                if (avail[j])
                    ++cnt;
            a[i] = cnt;

            cnt = 0;
            for (int j = 0; j < k; ++j)
                if (avail[j])
                    ++cnt;
            allow[i] = cnt;
        }
        int pos = n - 1;
        while (pos >= 0 && a[pos] + 1 >= allow[pos]) {
            a[pos] = 0;
            --pos;
        }
        if (pos < 0) {
            out.printLine("NO");
            return;
        }
        ++a[pos];
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            boolean[] avail = new boolean[k];
            Arrays.fill(avail, true);
            for (int j = 1; j <= 2 && i - j >= 0; ++j) {
                avail[res.charAt(i - j) - 'a'] = false;
            }
            int cur = 0;
            int cnt = 0;
            while (cnt <= a[i]) {
                if (avail[cur])
                    ++cnt;
                if (cnt > a[i]) break;
               ++cur;
            }
            res.append((char)(cur + 'a'));
        }
        out.printLine(res.toString());
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