import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.AbstractCollection;
import java.util.Collections;
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
    public static final int inf = (int) (1E9);

    ArrayList<ii> bugs;
    ArrayList<Stud> studs;
    int[] which;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long s = in.nextLong();
        bugs = new ArrayList<>();
        which = new int[m];
        long seed = 0xdead;
        studs = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            bugs.add(new ii(in.nextInt(), i));
            seed = seed * 57L + bugs.get(i).hashCode();
        }
        for (int i = 0; i < n; ++i) {
            studs.add(new Stud(in.nextInt(), 0));
        }
        for (int i = 0; i < n; ++i) {
            studs.get(i).second = in.nextInt();
            studs.get(i).index = i;
            seed = seed * 57L + studs.get(i).hashCode();
        }
        Random random = new Random(seed);
        Collections.shuffle(studs, random);
        Collections.sort(studs);
        Collections.shuffle(bugs);
        Collections.sort(bugs);

        int down = 0;
        int up = inf;
        while (up - down > 1) {
            int t = (up + down) / 2;
            if (calc(t) <= s)
                up = t;
            else
                down = t;
        }
        if (up >= inf / 2) {
            out.printLine("NO");
            return;
        }
        calc(up);
        out.printLine("YES");
        for (int i = 0; i < m; ++i)
            out.print((which[i] + 1) + " ");
        out.printLine();
    }

    private long calc(int days) {
        PriorityQueue<ii> q = new PriorityQueue<>();
        int cur = studs.size() - 1;
        int stack = days;
        int studIndex = -1;
        long res = 0;
        for (int i = bugs.size() - 1; i >= 0; --i) {
            while (cur >= 0 && studs.get(cur).first >= bugs.get(i).first) {
                q.add(new ii(studs.get(cur).second, studs.get(cur).index));
                --cur;
            }
            if (stack >= days) {
                if (q.isEmpty()) {
                    return (long)(1E17);
                }
                ii st = q.poll();
                res += st.first;
                stack = 1;
                studIndex = st.second;
            } else {
                ++stack;
            }
            which[bugs.get(i).second] = studIndex;
        }
        return res;
    }

    class Stud extends ii {
        int index;

        Stud() {
        }

        Stud(int first, int second) {
            super(first, second);
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            if (!super.equals(o)) return false;

            Stud stud = (Stud) o;

            if (index != stud.index) return false;

            return true;
        }

        public int hashCode() {
            int result = super.hashCode();
            result = 31 * result + index;
            return result;
        }
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

    public long nextLong() {
        long sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10L + (long)(c - '0');
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