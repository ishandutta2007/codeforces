import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    ArrayList<Integer>[] g_;
    ArrayList<Integer>[] gr_;
    int[] deg;
    int[][] g;
    int[] depth;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        g_ = new ArrayList[n];
        gr_ = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g_[i] = new ArrayList<>();
            gr_[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            gr_[x].add(g_[y].size());
            gr_[y].add(g_[x].size());
            g_[x].add(y);
            g_[y].add(x);
        }
        if (n == 2) {
            out.printLine(1);
            return;
        }
        deg = new int[n];
        g = new int[n][];
        for (int i = 0; i < n; ++i) {
            deg[i] = g_[i].size();
            g[i] = new int[deg[i]];
            for (int j = 0; j < deg[i]; ++j)
                g[i][j] = g_[i].get(j);
        }
        depth = new int[n];
        Arrays.fill(depth, -1);
        int[][] dc = new int[n][2];
        for (int i = 0; i < n; ++i)
            Arrays.fill(dc[i], -1);

        int[] q = new int[n + 10];
        int ql = 0, qr = 0;

        for (int i = 0; i < n; ++i) {
            if (deg[i] > 1) continue;
            depth[i] = 0;
            q[ql++] = i;
        }
        while (ql > qr) {
            int x = q[qr++];
            if (dc[x][0] != -1 && dc[x][1] != -1) {
                depth[x] = -1;
                continue;
            }
            int p = -1, pi = 0;
            for (int i = 0; i < g[x].length; ++i) {
                int y = g[x][i];
                if (y != -1) {
                    p = y;
                    pi = gr_[x].get(i);
                    g[x][i] = -1;
                    break;
                }
            }
            if (p == -1) continue;
            if (dc[p][0] != -1 && dc[p][0] != depth[x] + 1 &&
                    dc[p][1] != -1 && dc[p][1] != depth[x] + 1) continue;
            if (dc[p][0] == -1 || dc[p][0] == depth[x] + 1)
                dc[p][0] = depth[x] + 1;
            else
                dc[p][1] = depth[x] + 1;
            depth[x] = -2;
            g[p][pi] = -1;
            --deg[p];
            if (deg[p] == 1 && dc[p][1] == -1) {
                depth[p] = dc[p][0];
                q[ql++] = p;
            }
        }
        int num = 0, sum = 0, num1 = 0, sum1 = 0, o = -1;
        for (int i = 0; i < n; ++i)
            if (depth[i] != -2) {
                if (depth[i] == -1) {
                    ++num1;
                    o = i;
                    if (dc[i][0] != -1)
                        sum1 += dc[i][0];
                    if (dc[i][1] != -1)
                        sum1 += dc[i][1];
                } else {
                    ++num;
                    sum += depth[i];
                }
            }
        if (num1 > 1) {
            out.printLine(-1);
            return;
        }
        if (num1 == 1) {
            if (num == 1) {
                if (sum  + 1 == dc[o][0] || sum + 1 == dc[o][1])
                    num = 0;
            }
            if (num > 0) {
                out.printLine(-1);
                return;
            }
            Assert.assertTrue(dc[o][0] != -1);
            Assert.assertTrue(dc[o][1] != -1);
            while (sum1 % 2 == 0) sum1 /= 2;
            out.printLine(sum1);
            return;
        }
        if (num > 2) {
            out.printLine(-1);
            return;
        }
        if (num == 2) {
            ++sum;
            if (sum % 2 == 0) sum /= 2;
        }
        while (sum % 2 == 0) sum /= 2;
        out.printLine(sum);
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

class Assert {

    public static void assertTrue(boolean flag) {
if (!flag)
            throw new AssertionError();
    }

}