import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.HashMap;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public static final int inf = (int) (1E8);
    int n;
    char[] s;
    static ArrayList<Integer>[] pos;
    HashMap<Pos, Integer> d;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        s = in.nextToken().toCharArray();
        Assert.assertTrue(n == s.length);
        pos = new ArrayList[3];
        for (int i = 0; i < 3; ++i)
            pos[i] = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'V') pos[0].add(i);
            else if (s[i] == 'K') pos[1].add(i);
            else pos[2].add(i);
        }
        d = new HashMap<>();
        int res = go(new Pos(pos[0].size(), pos[1].size(), pos[2].size(), 3));
out.printLine(res);
    }

    private int go(Pos pos) {
        if (pos.p1 + pos.p2 + pos.p3 == 0) return 0;
        if (d.containsKey(pos)) return d.get(pos);
        int res = inf;
        if (pos.p1 > 0 && pos.c != 1)
            res = Math.min(res, pos.cost0() + go(pos.n1()));
        if (pos.p2 > 0)
            res = Math.min(res, pos.cost1() + go(pos.n2()));
        if (pos.p3 > 0)
            res = Math.min(res, pos.cost2() + go(pos.n3()));
        d.put(pos, res);
        return res;
    }

    static class Pos {
        int p1, p2, p3, c;

        public Pos(int p1, int p2, int p3, int c) {
            this.p1 = p1;
            this.p2 = p2;
            this.p3 = p3;
            this.c = c;
        }


        int cost0() {
            int ind = p1 + p2 + p3 - 1;
            int res = Math.abs(ind - getPos(pos[0].get(p1 - 1)));

            return res;
        }

        int cost1() {
            int ind = p1 + p2 + p3 - 1;
            int res = Math.abs(ind - getPos(pos[1].get(p2 - 1)));
return res;
        }

        int cost2() {
            int ind = p1 + p2 + p3 - 1;

int res = Math.abs(ind - getPos(pos[2].get(p3 - 1)));
            return res;
        }

        private int getPos(int x) {
            int[] lims = new int[]{p1, p2, p3};
            int res = 0;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < lims[i]; ++j)
                    if (pos[i].get(j) < x) ++res;
            return res;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pos pos = (Pos) o;

            if (p1 != pos.p1) return false;
            if (p2 != pos.p2) return false;
            if (p3 != pos.p3) return false;
            return c == pos.c;

        }

        public int hashCode() {
            int result = p1;
            result = 31 * result + p2;
            result = 31 * result + p3;
            result = 31 * result + c;
            return result;
        }

        public Pos n1() {
            return new Pos(p1 - 1, p2, p3, 0);
        }

        public Pos n2() {
            return new Pos(p1, p2 - 1, p3, 1);
        }

        public Pos n3() {
            return new Pos(p1, p2, p3 - 1, 2);
        }

        public String toString() {
            return "Pos{" +
                    "p1=" + p1 +
                    ", p2=" + p2 +
                    ", p3=" + p3 +
                    ", c=" + c +
                    '}';
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