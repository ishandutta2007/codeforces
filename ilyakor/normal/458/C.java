import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long seed = 0xdead;

        int n = in.nextInt();  seed = seed * 57L + n;
        int c0 = 0;
        ArrayList<Integer>[] adds = new ArrayList[n + 1];
        for (int i = 0; i < adds.length; ++i)
            adds[i] = new ArrayList<>();
        int[] who = new int[n];
        int[] costs = new int[n];
        ArrayList<ii>[] members = new ArrayList[218 * 1000];
        for (int i = 0; i < members.length; ++i)
            members[i] = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            who[i] = in.nextInt();   seed = seed * 57L + who[i];
            costs[i] = in.nextInt();   seed = seed * 57L + costs[i];
            if (who[i] == 0) ++c0;
            else {
                members[who[i]].add(new ii(costs[i], i));
            }
        }
        Random random = new Random(seed);
        for (int i = 0; i < members.length; ++i) {
            if (members[i].isEmpty())
                continue;
            adds[members[i].size()].add(i);
            Collections.shuffle(members[i], random);
            Collections.sort(members[i]);
            Collections.reverse(members[i]);
        }

        int h = 2;
        while (h <= 57000) h *= 2;
        SegmentTreeAddSum sums = new SegmentTreeAddSum(h);
        SegmentTreeAddSum counts = new SegmentTreeAddSum(h);
        for (int i = 0; i < n; ++i) {
            if (who[i] != 0) {
                sums.add(costs[i] + 1, costs[i]);
                counts.add(costs[i] + 1, 1);
            }
        }
        counts.add(49000, 10000000);

        long res = (long) 1E18;
        long cost = 0;
        int excess = c0;
        ArrayList<Integer> front = new ArrayList<>();
        for (int i = n; i > 0; --i) {
            for (int x : adds[i])
                front.add(x);
            for (int x : front) {
                int el = members[x].get(i - 1).second;
                cost += costs[el];
                ++excess;
                sums.add(costs[el] + 1, -costs[el]);
                counts.add(costs[el] + 1, -1);
            }
            long cur = cost;
            int need = i - excess;
            if (need > 0) {
                int ind = counts.lower_bound(1, 50000, need);
                // Should fit in int.
                int sum = ind <= 1 ? 0 : sums.sum(1, ind - 1);
                int cnt = ind <= 1 ? 0 : counts.sum(1, ind - 1);
                cur += sum;
                cur += (long) (need - cnt) * (long) (ind - 1);
            }
            if (cur < res)
                res = cur;
        }
        out.printLine(res);
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

class SegmentTreeAddSum {
    final int[] s;
    final int n;

    public SegmentTreeAddSum(int n) {
        this.n = n;
        s = new int[4 * n];
        buildTree(1, 0, n - 1);
    }

    void buildTree(int node, int left, int right) {
        if (left != right) {
            int mid = (left + right) >> 1;
            buildTree(node * 2, left, mid);
            buildTree(node * 2 + 1, mid + 1, right);
            s[node] = s[node * 2] + s[node * 2 + 1];
        }
    }

    public void add(int i, int value) {
        add(i, value, 1, 0, n - 1);
    }

    void add(int i, int value, int node, int left, int right) {
        if (left == right) {
            s[node] += value;
            return;
        }
        int mid = (left + right) >> 1;
        if (i <= mid)
            add(i, value, node * 2, left, mid);
        else
            add(i, value, node * 2 + 1, mid + 1, right);
        s[node] = s[node * 2] + s[node * 2 + 1];
    }

    public int sum(int a, int b) {
        return sum(a, b, 1, 0, n - 1);
    }

    int sum(int a, int b, int node, int left, int right) {
        if (left >= a && right <= b)
            return s[node];
        int mid = (left + right) >> 1;
        int res = 0;
        if (a <= mid)
            res += sum(a, b, node * 2, left, mid);
        if (b > mid)
            res += sum(a, b, node * 2 + 1, mid + 1, right);
        return res;
    }

    // Returns min(p | p<=b && sum[a,p]>=sum)
    public int lower_bound(int a, int b, int sum) {
        return lower_bound(a, b, sum, 1, 0, n - 1);
    }

    int lower_bound(int a, int b, int sum, int node, int left, int right) {
        if (left > b || right < a)
            return ~0;
        if (left >= a && right <= b && s[node] < sum)
            return ~s[node];
        if (left == right)
            return left;
        int mid = (left + right) >> 1;
        int res1 = lower_bound(a, b, sum, node * 2, left, mid);
        if (res1 >= 0)
            return res1;
        res1 = ~res1;
        int res2 = lower_bound(a, b, sum - res1, node * 2 + 1, mid + 1, right);
        if (res2 >= 0)
            return res2;
        res2 = ~res2;
        return ~(res1 + res2);
    }

}