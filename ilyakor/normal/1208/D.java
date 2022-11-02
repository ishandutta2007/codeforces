import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
      long[] s = new long[n];
      for (int i = 0; i < n; ++i) {
        s[i] = in.nextLong();
      }

      long[] a = new long[n + 1];
      TreeSet<Integer> alive = new TreeSet<>();
      for (int i = 1; i <= n; ++i) {
        a[i] = i;
        alive.add(i);
      }
      TaskD.FenwickTree tree = new TaskD.FenwickTree(a);
      int[] res = new int[n];
      for (int i = n - 1; i >= 0; --i) {
        int val = tree.lower_bound(s[i]) + 1;
        val = alive.ceiling(val);
        res[i] = val;
        tree.set(val, 0);
        alive.remove(val);
        a[val] = 0;
      }
      for (int i = 0; i < n; ++i) {
        out.print(res[i] + " ");
      }
    }

    static class FenwickTree {

      long[] t;
      int n;

      public FenwickTree(int n) {
        this.n = n;
        t = new long[n];
      }

      public FenwickTree(long[] a) {
        n = a.length;
        t = new long[n];
        for (int i = 0; i < n; i++) {
          t[i] += a[i];
          int j = i | i + 1;
          if (j < n) {
            t[j] += t[i];
          }
        }
      }

      public void add(int i, long value) {
        for (; i < n; i += (i + 1) & -(i + 1)) {
          t[i] += value;
        }
      }

      public long get(int i) {
        // return sum(i) - sum(i - 1);
        long res = t[i];
        if (i > 0) {
          int lca = i - ((i + 1) & -(i + 1));
          --i;
          while (i != lca) {
            res -= t[i];
            i -= (i + 1) & -(i + 1);
          }
        }
        return res;
      }

      public void set(int i, long value) {
        add(i, -get(i) + value);
      }

      public int lower_bound(long sum) {
        --sum;
        int pos = -1;
        for (int blockSize = Integer.highestOneBit(n); blockSize != 0; blockSize >>= 1) {
          int nextPos = pos + blockSize;
          if (nextPos < n && sum >= t[nextPos]) {
            sum -= t[nextPos];
            pos = nextPos;
          }
        }
        return pos + 1;
      }

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
        res = res * 10L + (long) (c - '0');
        c = read();
      } while (!isSpace(c));
      res *= sgn;
      return res;
    }

  }
}