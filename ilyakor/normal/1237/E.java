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

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // int[] d = new int[100];
      // d[0] = 0;
      // d[1] = 0;
      // for (int n = 2; n < d.length; ++n) {
      //     d[n] = Integer.MAX_VALUE;
      //     for (int k = 0; k <= n - 1; ++k) {
      //         int val = d[k] + d[n - k - 1] + n - 1;
      //         d[n] = Math.min(d[n], val);
      //     }
      //     System.err.print(n + " " + d[n] + " " + f(n) + "-" + (n - f(n) - 1) + ": ");
      //     for (int k = 0; k <= n - 1; ++k) {
      //         int val = d[k] + d[n - k - 1] + n - 1;
      //         if (val == d[n])
      //             System.err.print(k + " ");
      //     }
      //     System.err.println();
      // }

      // int n = in.nextInt();
      // int[][] d = new int[2][n + 1];
      // d[0][0] = 1;
      // d[1][0] = 1;
      // d[1][1] = 1;
      // for (int i = 2; i <= n; ++i) {
      //     int l = f(i);
      //     int r = i - l - 1;
      //     for (int root = l + 1; root <= r + 1; ++root) {
      //         long cur = 1;
      //         if (root > 0)
      //             cur *= d[(root + 1) % 2][root - 1];
      //         if (root < i)
      //             cur *= d[0][i - root];
      //         d[root % 2][i] = (int) ((d[root % 2][i] + cur) % mod);
      //     }
      //     System.err.println(i + " " + (d[0][i] + d[1][i]));
      // }
      // long res = d[0][n] + d[1][n];
      // res %= mod;
      // out.printLine(res);

      int n = in.nextInt();
      int[] a = new int[25];
      a[0] = 0;
      for (int i = 1; i < a.length; ++i) {
        if (i % 2 == 0) {
          a[i] = 2 * a[i - 1];
        } else {
          a[i] = 2 * a[i - 1] + 1;
        }
      }

      for (int i = 1; i < a.length; ++i) {
        int val = 2 * a[i] - i % 2;
        if (val == n || val + 1 == n) {
          out.printLine(1);
          return;
        }
      }
      out.printLine(0);
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