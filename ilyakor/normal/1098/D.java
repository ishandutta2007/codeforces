import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {

    ArrayList<ii> coords;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // Random random = new Random(0xdead);
      // for (int it = 0; it < 10000; ++it) {
      //     int n = random.nextInt(8);
      //     int[] a = new int[n];
      //     for (int i = 0; i < n; ++i)
      //         a[i] = random.nextInt(50);
      //     int greedy = greedy(a);
      //     int stupid = stupidGreedy(a);
      //     if(greedy != stupid) {
      //         throw new RuntimeException();
      //     }
      // }

      int q = in.nextInt();
      ii[] queries = new ii[q];
      coords = new ArrayList<>();
      for (int i = 0; i < q; ++i) {
        char c = in.nextToken().toCharArray()[0];
        int x = in.nextInt();
        queries[i] = new ii(c == '+' ? 1 : -1, x);
        if (c == '+') {
          coords.add(new ii(x, i));
        }
      }
      Collections.shuffle(coords);
      Collections.sort(coords);
      int[] ind = new int[q];
      for (int i = 0; i < coords.size(); ++i) {
        ind[coords.get(i).second] = i;
      }
      SegmentTreeFastIntervalAddMax tree = new SegmentTreeFastIntervalAddMax(coords.size() + 10);
      long minusInf = (long) (-1e18);
      tree.modifyAdd(1, coords.size(), minusInf);
      HashMap<Integer, ArrayList<Integer>> state = new HashMap<>();
      int cnt = 0;
      for (int it = 0; it < q; ++it) {
        int op = queries[it].first;
        int x = queries[it].second;
        if (op == 1) {
          int pos = ind[it];
          tree.modifyAdd(pos + 1, pos + 1, (x + 1) / 2 - minusInf);
          tree.modifyAdd(pos + 2, coords.size(), -x);
          if (!state.containsKey(x)) {
            state.put(x, new ArrayList<>());
          }
          state.get(x).add(pos);
          ++cnt;
        } else {
          ArrayList<Integer> a = state.get(x);
          int pos = a.get(a.size() - 1);
          a.remove(a.size() - 1);
          tree.modifyAdd(pos + 1, pos + 1, minusInf - (x + 1) / 2);
          tree.modifyAdd(pos + 2, coords.size(), x);
          --cnt;
        }

        int res = cnt;
        res -= dfs(tree, 1, coords.size());
        out.printLine(res);
      }
    }

    private int dfs(SegmentTreeFastIntervalAddMax tree, int l, int r) {
      if (l > r) {
        return 0;
      }
      long val = tree.queryMax(l, r);
      if (val <= 0) {
        return 0;
      }
      int pos = tree.queryMaxPos(l, r);
      return 1 + dfs(tree, l, pos - 1) + dfs(tree, pos + 1, r);
    }

  }

  static class ii implements Comparable<ii> {

    public int first;
    public int second;

    public ii() {
    }

    public ii(int first, int second) {
      this.first = first;
      this.second = second;
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      ii ii = (ii) o;

      if (first != ii.first) {
        return false;
      }
      if (second != ii.second) {
        return false;
      }

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

    public String toString() {
      return "{" +
          "first=" + first +
          ", second=" + second +
          '}';
    }

  }

  static class OutputWriter {

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

  static class SegmentTreeFastIntervalAddMax {

    final int n;
    final long[] t;
    final long[] m;
    final boolean[] h;
    final long[] q;
    final int[] maxPos;

    public SegmentTreeFastIntervalAddMax(int n) {
      this.n = n;
      t = new long[2 * n];
      m = new long[2 * n];
      h = new boolean[2 * n];
      q = new long[2 * n];
      maxPos = new int[2 * n];
      for (int i = n; i < 2 * n; ++i) {
        maxPos[i] = i - n;
      }
      for (int i = n - 1; i > 0; --i) {
        maxPos[i] = Math.min(maxPos[2 * i], maxPos[2 * i + 1]);
      }
      for (int i = n; i < 2 * n; i++) {
        q[i] = 1;
      }
      for (int i = 2 * n - 1; i > 1; i -= 2) {
        q[i >> 1] = q[i] + q[i ^ 1];
      }
    }

    void modifierHelper(int i, long p) {
      t[i] += p;
      m[i] += p;
      h[i] = true;
    }

    void pop(int i) {
      if (t[i] > t[i ^ 1] || (t[i] == t[i ^ 1] && maxPos[i] < maxPos[i ^ 1])) {
        t[i >> 1] = t[i];
        maxPos[i >> 1] = maxPos[i];
      } else {
        t[i >> 1] = t[i ^ 1];
        maxPos[i >> 1] = maxPos[i ^ 1];
      }
      if (h[i >> 1]) {
        t[i >> 1] += m[i >> 1];
      }
    }

    void popUp(int i) {
      for (; i > 1; i >>= 1) {
        pop(i);
      }
    }

    void push(int i) {
      if (h[i >> 1]) {
        modifierHelper(i, m[i >> 1]);
        modifierHelper(i ^ 1, m[i >> 1]);
        h[i >> 1] = false;
        m[i >> 1] = 0;
      }
    }

    void pushDown(int i) {
      int k;
      for (k = 0; (i >> k) > 0; k++) {
        ;
      }
      for (k -= 2; k >= 0; k--) {
        push(i >> k);
      }
    }

    public void modifyAdd(int a, int b, long v) {
      a += n;
      b += n;
      pushDown(a);
      pushDown(b);
      int ta = a;
      int tb = b;

      for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
        if ((a & 1) != 0) {
          modifierHelper(a, v);
        }
        if ((b & 1) == 0) {
          modifierHelper(b, v);
        }
      }

      popUp(ta);
      popUp(tb);
    }

    public long queryMax(int a, int b) {
      a += n;
      b += n;
      pushDown(a);
      pushDown(b);

      long res = Long.MIN_VALUE;
      for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
        if ((a & 1) != 0) {
          res = Math.max(res, t[a]);
        }
        if ((b & 1) == 0) {
          res = Math.max(res, t[b]);
        }
      }
      return res;
    }

    public int queryMaxPos(int a, int b) {
      a += n;
      b += n;
      pushDown(a);
      pushDown(b);

      long res = -1;
      int resPos = -1;
      for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
        if ((a & 1) != 0) {
          if (t[a] > res || (t[a] == res && maxPos[a] < resPos)) {
            res = t[a];
            resPos = maxPos[a];
          }
        }
        if ((b & 1) == 0) {
          if (t[b] > res || (t[b] == res && maxPos[b] < resPos)) {
            res = t[b];
            resPos = maxPos[b];
          }
        }
      }
      return resPos;
    }

  }

  static class InputReader {

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
          if (count <= 0) {
            return -1;
          }
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
}