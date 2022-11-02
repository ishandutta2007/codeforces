import java.io.IOException;
import java.io.OutputStreamWriter;
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
        Croc13QualE solver = new Croc13QualE();
        solver.solve(1, in, out);
        out.close();
    }
}

class Croc13QualE {
    ArrayList<Integer>[] g;
    ArrayList<String>[] gs;
    String pattern;
    int[] p;
    int[][] au;

    long res;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        gs = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<Integer>();
            gs[i] = new ArrayList<String>();
        }
        for (int i = 1; i < n; ++i) {
            int p = in.nextInt() - 1;
            String s = in.nextToken();
            g[p].add(i);
            gs[p].add(s);
        }
        res = 0;
        pattern = in.nextToken() + (char)('z' + 1);
        int N = pattern.length();
        p = KMP.prefixFunction(pattern);
        au = new int[N][27];
        for (int i = 0; i < N; ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (i > 0 && c != pattern.charAt(i))
                    au[i][c - 'a'] = au[p[i - 1]][c - 'a'];
                else
                    au[i][c - 'a'] = i + (c == pattern.charAt(i) ? 1 : 0);
            }
        }
        dfs(0, 0);
        out.printLine(res);
    }

    private void dfs(int x, int k) {
        int _k = k;
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x].get(i);
            String s = gs[x].get(i);
            k = _k;
            for (int j = 0; j < s.length(); ++j) {
                char c = s.charAt(j);
                k = au[k][c - 'a'];
                if (k == pattern.length() - 1)
                    ++res;
            }
            dfs(y, k);
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

class KMP {
    public static int[] prefixFunction(String s) {
        int n = s.length();
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            int k = p[i - 1];
            while (k > 0 && s.charAt(k) != s.charAt(i)) {
                k = p[k - 1];
            }
            p[i] = k + (s.charAt(k) == s.charAt(i) ? 1 : 0);
        }
        return p;
    }

    }