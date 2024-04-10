import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    int[][] a;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        a = new int[8][3];
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][j] = in.nextInt();
            }
            Arrays.sort(a[i]);
        }
        for (int e1 = 1; e1 < 8; ++e1)
            for (int e2 = e1 + 1; e2 < 8; ++e2)
                for (int e3 = e2 + 1; e3 < 8; ++e3) {
                    Arrays.sort(a[e1]);
                    do {
                        Arrays.sort(a[e2]);
                        do {
                            Arrays.sort(a[e3]);
                            do {
                                if (!good(a[0], a[e1], a[e2])) continue;
                                if (!good(a[0], a[e1], a[e3])) continue;
                                if (!good(a[0], a[e3], a[e2])) continue;
                                int[][] b = new int[8][3];
                                for (int i = 0; i < 8; ++i) {
                                    b[i][0] = a[0][0];
                                    b[i][1] = a[0][1];
                                    b[i][2] = a[0][2];
                                    int[] jc = new int[]{e1, e2, e3};
                                    for (int j = 0; j < 3; ++j) {
                                        if ((i >> j) % 2 == 1) {
                                            b[i][0] += a[jc[j]][0] - a[0][0];
                                            b[i][1] += a[jc[j]][1] - a[0][1];
                                            b[i][2] += a[jc[j]][2] - a[0][2];
                                        }
                                    }
                                }
                                boolean[][] matches = new boolean[8][8];
                                for (int i = 0; i < 8; ++i) {
                                    int[] c1 = Arrays.copyOf(b[i], b[i].length);
                                    Arrays.sort(c1);
                                    for (int j = 0; j < 8; ++j) {
                                        int[] c2 = Arrays.copyOf(a[j], a[j].length);
                                        Arrays.sort(c2);
                                        matches[i][j] = Arrays.equals(c1, c2);
                                    }
                                }
                                int[] matching = new int[8];
                                int matchingSize = MaxMatching.maxMatching(matches, matching);
                                if (matchingSize != 8) continue;
                                out.printLine("YES");
                                for (int i = 0; i < 8; ++i) {
                                    for (int j = 0; j < 3; ++j)
                                        out.print(b[matching[i]][j] + " ");
                                    out.printLine();
                                }
                                return;
                            } while (Permutations.nextPermutation(a[e3]));
                        } while (Permutations.nextPermutation(a[e2]));
                    } while (Permutations.nextPermutation(a[e1]));
                }
        out.printLine("NO");
    }

    boolean good(int[] o, int[] e1, int[] e2) {
        long x11 = e1[0] - o[0];
        long x12 = e1[1] - o[1];
        long x13 = e1[2] - o[2];
        long x21 = e2[0] - o[0];
        long x22 = e2[1] - o[1];
        long x23 = e2[2] - o[2];
        return x11 * x21 + x12 * x22 + x13 * x23 == 0 && x11 * x11 + x12 * x12 + x13 * x13 == x21 * x21 + x22 * x22 + x23 * x23 && x11 * x11 + x12 * x12 + x13 * x13 > 0;
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

class MaxMatching {

    static boolean findPath(int u1, boolean[][] d, int[] matching, boolean[] vis) {
        vis[u1] = true;
        for (int v = 0; v < matching.length; ++v) {
            int u2 = matching[v];
            if (d[u1][v] && (u2 == -1 || !vis[u2] && findPath(u2, d, matching, vis))) {
                matching[v] = u1;
                return true;
            }
        }
        return false;
    }

    public static int maxMatching(boolean[][] d, /* out */ int[] matching) {
        int n1 = d.length;
        int n2 = n1 == 0 ? 0 : d[0].length;
        Arrays.fill(matching, -1);
        int matches = 0;
        for (int u = 0; u < n1; u++)
            if (findPath(u, d, matching, new boolean[n1]))
                ++matches;
        return matches;
    }

}

class Permutations {

    public static boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

}