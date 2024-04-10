import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
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

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int[] a = new int[n];
      ArrayList<ii> order = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
        order.add(new ii(a[i], i));
      }
      Collections.sort(order);
      int r = 0;
      SegmentTreeSetMax tree = new SegmentTreeSetMax(n + 10);
      int[] d = new int[n];
      for (int i = 0; i < n; ++i) {
        int cur = order.get(i).first;
        while (r < order.size() && order.get(r).first <= 2 * cur) {
          int ind = order.get(r).second;
          int val = tree.get(tree.maxPos(ind + 1, n + 2));
          if (val == Integer.MIN_VALUE) {
            val = tree.get(tree.maxPos(1, ind + 1));
          }
          if (val == Integer.MIN_VALUE) {
            val = -1;
          } else {
            val = n + 10 - val;
          }
          d[ind] = val;
          ++r;
        }
        tree.set(order.get(i).second + 1, n + 10 - order.get(i).second);
      }

      SegmentTreeSetMax tree2 = new SegmentTreeSetMax(n + 10);
      for (int i = 0; i < n + 10; ++i) {
        tree2.set(i, -1000000);
      }
      Collections.reverse(order);
      for (ii entry : order) {
        int ind = entry.second;
        int t = d[ind];
        if (t == -1) {
          t = ind;
        }
        int val = t;
        if (val <= ind) {
          val += n;
        }
        if (t == ind) {
          val += n;
        }
        if (t > ind) {
          val = Math.min(val, -tree2.get(tree2.maxPos(ind + 1, t + 1)));
        } else {
          val = Math.min(val, -tree2.get(tree2.maxPos(ind + 1, n + 1)));
          val = Math.min(val, n - tree2.get(tree2.maxPos(0, t + 1)));
        }
        d[ind] = val - ind;
        tree2.set(ind + 1, -val);
      }
      for (int i = 0; i < n; ++i) {
        out.print(d[i] >= 2 * n ? -1 : d[i]);
        out.print(" ");
      }
      out.printLine();
    }

  }

  static class SegmentTreeSetMax {

    final int[] v;
    final int[] vv;
    final int[] maxPos;
    final int n;

    public SegmentTreeSetMax(int n) {
      int h = 1;
      while (h <= n) {
        h *= 2;
      }
      n = h;
      this.n = n;
      v = new int[n * 4];
      vv = new int[n];
      Arrays.fill(v, Integer.MIN_VALUE);
      maxPos = new int[n * 4];
      buildTree(1, 0, n - 1);
    }

    void buildTree(int node, int left, int right) {
      if (left == right) {
        maxPos[node] = left;
      } else {
        int mid = (left + right) >> 1;
        buildTree(node * 2, left, mid);
        buildTree(node * 2 + 1, mid + 1, right);
        maxPos[node] = v[maxPos[node * 2]] >= v[maxPos[node * 2 + 1]] ? maxPos[node * 2]
            : maxPos[node * 2 + 1];
      }
    }

    public int maxPos(int a, int b) {
      return maxPos(a, b, 1, 0, n - 1);
    }

    int maxPos(int a, int b, int node, int left, int right) {
      if (left >= a && right <= b) {
        return maxPos[node];
      }
      int mid = (left + right) >> 1;
      int p1 = a <= mid ? maxPos(a, b, node * 2, left, mid) : -1;
      int p2 = b > mid ? maxPos(a, b, node * 2 + 1, mid + 1, right) : -1;
      if (p1 == -1) {
        return p2;
      }
      if (p2 == -1) {
        return p1;
      }
      return vv[p1] >= vv[p2] ? p1 : p2;
    }

    public void set(int i, int value) {
      vv[i] = value;
      set(i, value, 1, 0, n - 1);
    }

    void set(int i, int value, int node, int left, int right) {
      if (left == right) {
        v[left] = value;
        return;
      }
      int mid = (left + right) >> 1;
      if (i <= mid) {
        set(i, value, node * 2, left, mid);
      } else {
        set(i, value, node * 2 + 1, mid + 1, right);
      }
      maxPos[node] =
          v[maxPos[node * 2]] >= v[maxPos[node * 2 + 1]] ? maxPos[node * 2] : maxPos[node * 2 + 1];
    }

    public int get(int i) {
      return v[i];
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