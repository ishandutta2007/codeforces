import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
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
        int n = in.nextInt();
        n *= 2;
        String s1 = in.nextToken();
        String s2 = in.nextToken();
        final int[] a1 = new int[n];
        final int[] a2 = new int[n];
        ArrayList<Integer> ind1 = new ArrayList<Integer>();
        ArrayList<Integer> ind2 = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            int c1 = s1.charAt(i) - '0';
            int c2 = s2.charAt(i) - '0';
            a1[i] = c1;
            a2[i] = c2;
            ind1.add(i);
            ind2.add(i);
        }
        Collections.sort(ind1, new Comparator<Integer>() {
            @Override
            public int compare(Integer x, Integer y) {
                if (a1[x] != a1[y])
                    return a1[x] == 1 ? -1 : 1;
                if (a2[x] != a2[y])
                    return a2[x] == 1 ? -1 : 1;
                return 0;
            }
        });
        Collections.sort(ind2, new Comparator<Integer>() {
            @Override
            public int compare(Integer x, Integer y) {
                if (a2[x] != a2[y])
                    return a2[x] == 1 ? -1 : 1;
                if (a1[x] != a1[y])
                    return a1[x] == 1 ? -1 : 1;
                return 0;
            }
        });
        int[] r = new int[]{0, 0};
        boolean[] u = new boolean[n];
        int[] sum = new int[2];
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                while (u[ind1.get(r[0])]) ++r[0];
                u[ind1.get(r[0])] = true;
                sum[0] += a1[ind1.get(r[0])];
            } else {
                while (u[ind2.get(r[1])]) ++r[1];
                u[ind2.get(r[1])] = true;
                sum[1] += a2[ind2.get(r[1])];
            }
        }
        if (sum[0] > sum[1])
            out.printLine("First");
        else if (sum[0] == sum[1])
            out.printLine("Draw");
        else
            out.printLine("Second");
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