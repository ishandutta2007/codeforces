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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    int w;
    int n;
    int[] a;
    RMQSparseTable rmq;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // Random random = new Random(0xdead);
      // int N = 1000 * 1000 / 10;
      // w = 1000 * 1000;
      //
      int N = in.nextInt();
      w = in.nextInt();
      long[] d = new long[w + 1];
      for (int it = 0; it < N; ++it) {
        n = in.nextInt();
        // n = random.nextInt(10) + 1;
        a = new int[n];
        for (int i = 0; i < n; ++i) {
          a[i] = -in.nextInt();
        }
        // a[i] = random.nextInt(2 * 1000 * 1000 * 1000) - 1000 * 1000 * 1000;
        rmq = new RMQSparseTable(a);
        if (n * 2 < w) {
          for (int i = 0; i < n; ++i) {
            int val = calc(i);
            d[i] += val;
            d[i + 1] -= val;
          }
          for (int i = w - n; i < w; ++i) {
            int val = calc(i);
            d[i] += val;
            d[i + 1] -= val;
          }
          int L = n, R = w - n - 1;
          if (L <= R) {
            int val = -a[rmq.minPos(0, n - 1)];
            if (val < 0) {
              val = 0;
            }
            // for (int i = L; i <= R; ++i) {
            //     int oval = calc(i);
            //     if (val != oval) {
            //         throw new RuntimeException();
            //     }
            // }
            d[L] += val;
            d[R + 1] -= val;
          }
        } else {
          for (int i = 0; i < w; ++i) {
            int val = calc(i);
            d[i] += val;
            d[i + 1] -= val;
          }
        }
      }
      long cur = 0;
      for (int i = 0; i < w; ++i) {
        cur += d[i];
        out.print(cur + " ");
      }
      out.printLine();
    }

    public int calc(int i) {
      int l = i + n - w, r = i;
      if (l < 0) {
        l = 0;
      }
      if (r >= n) {
        r = n - 1;
      }
      int val = -a[rmq.minPos(l, r)];
      if (val < 0) {
        if (i + n < w || i - n >= 0) {
          val = 0;
        }
      }
      return val;
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