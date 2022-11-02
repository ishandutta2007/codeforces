import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Integer> att = new ArrayList<Integer>();
        ArrayList<Integer> def = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            String s = in.nextToken();
            int st = in.nextInt();
            if (s.equals("ATK"))
                att.add(st);
            else
                def.add(st);
        }
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < m; ++i)
            a.add(in.nextInt());
        Collections.sort(att);
        Collections.sort(def);
        Collections.sort(a);
        int res = 0;
        {
            // Not all
            for (int i = 0; i < att.size(); ++i) {
                boolean ok = true;
                int cur = 0;
                for (int j = 0; j <= i; ++j) {
                    int x = att.get(i - j);
                    if (a.size() - 1 - j < 0) {
                        ok = false;
                        break;
                    }
                    int y = a.get(a.size() - 1 - j);
                    if (y < x) {
                        ok = false;
                        break;
                    }
                    cur += y - x;
                }
                if (ok)
                    res = Math.max(res, cur);
            }
        }
        {
            // All
            boolean ok = true;
            int cur = 0;
            for (int x : def) {
                ArrayList<Integer> tmp = new ArrayList<Integer>();
                if (spilt(a, x + 1, tmp) == -1) {
                    ok = false;
                    break;
                }
                a = tmp;
            }
            for (int x : att) {
                ArrayList<Integer> tmp = new ArrayList<Integer>();
                int val = spilt(a, x, tmp);
                if (val < x) {
                    ok = false;
                    break;
                }
                cur += val - x;
                a = tmp;
            }
            for (int x : a)
                cur += x;
            if (ok)
                res = Math.max(res, cur);
        }
        out.printLine(res);
    }

    private int spilt(ArrayList<Integer> a, int x, ArrayList<Integer> tmp) {
        tmp.clear();
        int res = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a.get(i) >= x && res == -1) {
                res = a.get(i);
            } else {
                tmp.add(a.get(i));
            }
        }
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