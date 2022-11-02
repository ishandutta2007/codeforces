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
    TaskF solver = new TaskF();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskF {

    static final int mod = 1000 * 1000 * 1000 + 7;
    int[] L;
    int[] R;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = -in.nextInt();
      }
      L = new int[n];
      R = new int[n];
      RMQSparseTable rmq = new RMQSparseTable(a);
      int res = 0;
      for (int m = 0; m < k - 1; ++m) {
        int[] b = new int[(n - m - 1) / (k - 1)];
        for (int j = 0; j < b.length; ++j) {
          int l = m + (k - 1) * j;
          int r = m + (k - 1) * (j + 1);
          Assert.assertTrue(r < n);
          int pos = rmq.minPos(l, r);
          b[j] = -a[pos];
        }
        res += calc(b);
        res %= mod;
      }
      out.printLine(res);
    }

    private int calc(int[] a) {
      for (int i = 0; i < a.length; ++i) {
        int x = i - 1;
        while (x >= 0 && a[x] < a[i]) {
          x = L[x];
        }
        L[i] = x;
      }
      int res = 0;
      for (int i = a.length - 1; i >= 0; --i) {
        int x = i + 1;
        while (x < a.length && a[x] <= a[i]) {
          x = R[x];
        }
        R[i] = x;
        long cur = a[i];
        cur *= (R[i] - i);
        cur %= mod;
        cur *= (i - L[i]);
        cur %= mod;
        res += (int) cur;
        res %= mod;
      }
      return res;
    }

  }

  static class RMQSparseTable {

    int[] logTable;
    int[][] rmq;
    int[] a;

    public RMQSparseTable(int[] a) {
      this.a = a;
      int n = a.length;

      logTable = new int[n + 1];
      for (int i = 2; i <= n; i++) {
        logTable[i] = logTable[i >> 1] + 1;
      }

      rmq = new int[logTable[n] + 1][n];

      for (int i = 0; i < n; ++i) {
        rmq[0][i] = i;
      }

      for (int k = 1; (1 << k) < n; ++k) {
        for (int i = 0; i + (1 << k) <= n; i++) {
          int x = rmq[k - 1][i];
          int y = rmq[k - 1][i + (1 << k - 1)];
          rmq[k][i] = a[x] <= a[y] ? x : y;
        }
      }
    }

    public int minPos(int i, int j) {
      int k = logTable[j - i];
      int x = rmq[k][i];
      int y = rmq[k][j - (1 << k) + 1];
      return a[x] <= a[y] ? x : y;
    }

  }

  static class Assert {

    public static void assertTrue(boolean flag) {
      // if (!flag)
      // while (true);
      if (!flag) {
        throw new AssertionError();
      }
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
}