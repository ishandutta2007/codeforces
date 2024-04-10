import java.io.IOException;
import java.io.OutputStreamWriter;
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
    static boolean[] a;
    static int[] was;
    static int C;
    static int[] cur;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        a = new boolean[10];
        for (int i = 0; i < n; ++i) {
            a[in.nextInt()] = true;
        }
        ArrayList<Integer> _good = new ArrayList<Integer>() ;
        for (int i = 0; i < 256; ++i) {
            boolean bad = false;
            int x = i;
            while (x > 0) {
                if (!a[x % 10]) bad = true;
                x /= 10;
            }
            if (!bad)
                _good.add(i);
        }
        int[] good = new int[_good.size()];
        for (int i =0 ; i < good.length; ++i)
            good[i] = _good.get(i);
        ArrayList<String> res = new ArrayList<String>();
        for (int len = 4; len <= 12; ++len) {
            cur = new int[100];
            was = new int[100];
            C = 0;
            for (int x : good) {
                int plx = cur[0];
                if (append(len, x) && cur[0] + 3 <= len && cur[0] + 9 >= len && C + 9 >= n) {
                    for (int y : good) {
                        int ply = cur[0];
                        if (append(len, y) && cur[0] + 2 <= len && cur[0] + 6 >= len && C + 6 >= n) {
                            for (int z : good) {
                                int plz = cur[0];
                                if (append(len, z)&& cur[0] + 1 <= len && cur[0] + 3 >= len && C + 3 >= n) {
                                    for (int t : good) {
                                        int plt = cur[0];
                                        int _l = 1;
                                        if (t >= 10) ++_l;
                                        if (t >= 100) ++_l;
                                        if (cur[0] + _l != len) continue;
                                        if (append(len, t) && cur[0] == len && C == n) {
                                            StringBuilder sb = new StringBuilder();
                                            sb.append(x).append(".").append(y).append(".").append(z).append(".").append(t);
                                            res.add(sb.toString());
                                        }
                                        while (cur[0] > plt) {
                                            --was[cur[cur[0]]];
                                            if (was[cur[cur[0]]] == 0)
                                                --C;
                                            --cur[0];
                                        }
                                    }
                                }
                                while (cur[0] > plz) {
                                    --was[cur[cur[0]]];
                                    if (was[cur[cur[0]]] == 0)
                                        --C;
                                    --cur[0];
                                }
                            }
                        }
                        while (cur[0] > ply) {
                            --was[cur[cur[0]]];
                            if (was[cur[cur[0]]] == 0)
                                --C;
                            --cur[0];
                        }
                    }
                }
                while (cur[0] > plx) {
                    --was[cur[cur[0]]];
                    if (was[cur[cur[0]]] == 0)
                        --C;
                    --cur[0];
                }
            }
        }
        out.printLine(res.size());
        for (String s : res)
            out.printLine(s);
    }

    private boolean append(int len, int x) {
        boolean ok = false;
        if (x >= 100) {
            ok = true;
            int y = x / 100;
            x %= 100;
            if (!a[y]) return false;
            cur[++cur[0]] = y;
            ++was[y];
            if (was[y] == 1) ++C;
            int ind = len - cur[0] + 1;
            if (ind >= 0 && ind <= cur[0] && cur[ind] != y) return false;
        }
        if (x >= 10 || ok) {
            int y = x / 10;
            x %= 10;
            if (!a[y]) return false;
            cur[++cur[0]] = y;
            ++was[y];
            if (was[y] == 1) ++C;
            int ind = len - cur[0] + 1;
            if (ind >= 0 && ind <= cur[0] && cur[ind] != y) return false;
        }
        {
            int y = x;
            if (!a[y]) return false;
            cur[++cur[0]] = y;
            ++was[y];
            if (was[y] == 1) ++C;
            int ind = len - cur[0] + 1;
            if (ind >= 0 && ind <= cur[0] && cur[ind] != y) return false;
        }
        return true;

//        if (x == 0) {
//            if (!a[0]) return false;
//            cur[++cur[0]] = x;
//            ++was[x];
//            if (was[x] == 1) ++C;
//            int ind = len - cur[0] + 1;
//            if (ind >= 0 && ind <= cur[0] && cur[ind] != x) return false;
//            return true;
//        }
//        int xc = 0;
//        while (x > 0) {
//            X[xc++] = x % 10;
//            x /= 10;
//        }
//        while (xc > 0) {
//            --xc;
//            int y = X[xc];
//            if (!a[y]) return false;
//            x /= 10;
//            cur[++cur[0]] = y;
//            ++was[y];
//            if (was[y] == 1) ++C;
//            int ind = len - cur[0] + 1;
//            if (ind >= 0 && ind <= cur[0] && cur[ind] != y) return false;
//        }
//        return true;
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