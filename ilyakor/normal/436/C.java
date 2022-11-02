import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int w = in.nextInt();
        int[][] d = new int[k][k];
        char[][][] a = new char[k][n][];
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j)
                a[i][j] = in.nextToken().toCharArray();
        }
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j) {
                int t = calc(a[i], a[j]);
                d[i][j] = Math.min(w * t, n * m);
            }
        int res = n * m;
        boolean[] u = new boolean[k];
        int[] D = new int[k];
        int[] F = new int[k];
        Arrays.fill(F, -1);
        Arrays.fill(D, 1000 * 1000 * 1000);
        D[0] = 0;
        ArrayList<ii> rl = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            int ind = -1, l = 1000 * 1000 * 1000;
            for (int j = 0; j < k; ++j)
                if (!u[j] && D[j] < l) {
                    ind = j;
                    l = D[j];
                }
            u[ind] = true;
            res += D[ind];
            rl.add(new ii(ind, F[ind]));
            for (int j = 0; j < k; ++j) {
                if (!u[j] && D[j] > d[ind][j]) {
                    D[j] = d[ind][j];
                    F[j] = ind;
                }
            }
        }
        out.printLine(res);
        for (ii entry : rl) {
            int x = entry.first;
            int y = entry.second;
            if (y == -1) {
                out.printLine((x + 1) + " " + 0);
                continue;
            }
            int t = calc(a[y], a[x]);
            if (n * m > w * t) {
                out.printLine((x + 1) + " " + (y + 1));
            } else {
                out.printLine((x + 1) + " " + 0);
            }
        }
    }

    private int calc(char[][] a, char[][] b) {
        int res = 0;
        for (int i = 0; i < a.length; ++i)
            for (int j = 0; j < a[i].length; ++j)
                if (a[i][j] != b[i][j]) ++res;
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

class ii implements Comparable<ii> {
    public int first;
    public int second;

    public ii() {
    }

    public ii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        ii ii = (ii) o;

        if (first != ii.first) return false;
        if (second != ii.second) return false;

        return true;
    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(ii o) {
        if (first != o.first) {
            return first < o.first ? -1 : 1;
        }
        if (second != o.second) {
            return second < o.second ? -1 : 1;
        }
        return 0;
    }

}