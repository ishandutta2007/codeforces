import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
import java.util.Collection;
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
    char[][] a;
    int n, m;

    static int[] dx = new int[]{-1, 1, 0, 0};
    static int[] dy = new int[]{0, 0, -1, 1};

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        a = new char[n][];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextToken().toCharArray();
        int res = (int)(1E9);
        int sx = -1, sy = -1, fx = -1, fy = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (a[i][j] == 'E') {
                    fx = i;
                    fy = j;
                }
            }
        /*for (int dir = 0; dir < 4; ++dir)*/ {
//            int x = fx + dx[dir];
//            int y = fy + dy[dir];
            int x = fx;
            int y = fy;
            //if (!good(x, y) || a[x][y] == 'T') continue;
            int[][] d = bfs(x, y);
            int our = d[sx][sy];
            int cur = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (d[i][j] != -1 && d[i][j] <= our && Character.isDigit(a[i][j])) {
                        cur += (int)(a[i][j] - '0');
                    }
            res = Math.min(res, cur);
        }
        out.printLine(res);
    }

    private int[][] bfs(int sx, int sy) {
        int[][] d = new int[n][m];
        for (int i = 0; i < n; ++i)
            Arrays.fill(d[i], -1);
        d[sx][sy] = 0;
        Queue<ii> q = new ArrayDeque<ii>();
        q.add(new ii(sx, sy));
        while (!q.isEmpty()) {
            ii cur = q.poll();
            int x = cur.first;
            int y = cur.second;
            for (int dir = 0; dir < 4; ++dir) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (!good(xx, yy) || a[xx][yy] == 'T') continue;
                if (d[xx][yy] != -1) continue;
                d[xx][yy] = d[x][y] + 1;
                q.add(new ii(xx, yy));
            }
        }
        return d;
    }

    private boolean good(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
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