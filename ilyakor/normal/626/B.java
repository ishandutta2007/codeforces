import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collections;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    boolean[][][] d;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        char[] s = in.nextToken().toCharArray();
        int[] cnts = new int[3];
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') ++cnts[0];
            if (s[i] == 'G') ++cnts[1];
            if (s[i] == 'R') ++cnts[2];
        }
        int sum = cnts[0] + cnts[1] + cnts[2];
        d = new boolean[sum + 2][sum + 2][sum + 2];
        dfs(cnts[0], cnts[1], cnts[2]);
        ArrayList<Character> res = new ArrayList<>();
        if (d[0][0][1]) res.add('R');
        if (d[0][1][0]) res.add('G');
        if (d[1][0][0]) res.add('B');
        Collections.sort(res);
        for (char c : res)
            out.print(c);
        out.printLine();
    }

    private void dfs(int x, int y, int z) {
        d[x][y][z] = true;
        if (x >= 2 && !d[x - 1][y][z])
            dfs(x - 1, y, z);
        if (y >= 2 && !d[x][y - 1][z])
            dfs(x, y - 1, z);
        if (z >= 2 && !d[x][y][z - 1])
            dfs(x, y, z - 1);
        if (x >= 1 && y >= 1 && !d[x - 1][y - 1][z + 1])
            dfs(x - 1, y - 1, z + 1);
        if (x >= 1 && z >= 1 && !d[x - 1][y + 1][z - 1])
            dfs(x - 1, y + 1, z - 1);
        if (z >= 1 && y >= 1 && !d[x + 1][y - 1][z - 1])
            dfs(x + 1, y - 1, z - 1);
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