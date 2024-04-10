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
 * Built using CHelper plug-in
 * Actual solution is at the top
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

    static final int mod = 1000 * 1000 * 1000 + 7;
    static final int maxn = 1000 * 1000;
    public static final int LEN = 6;
    static int[] p2;
    static int[] p10;

    static {
      p2 = new int[maxn + 10];
      p2[0] = 1;
      for (int i = 1; i < p2.length; ++i) {
        p2[i] = (p2[i - 1] * 2) % mod;
      }

      p10 = new int[LEN];
      p10[0] = 1;
      for (int i = 1; i < LEN; ++i) {
        p10[i] = p10[i - 1] * 10;
      }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int[] a0 = new int[maxn];
      int[] a1 = new int[maxn];
      int[] a2 = new int[maxn];
      for (int i = 0; i < n; ++i) {
        int x = in.nextInt();
        a0[x] = (a0[x] + 1) % mod;
        a1[x] = (a1[x] + x) % mod;
        a2[x] = (int) ((a2[x] + (long) x * (long) x) % mod);
      }
      a0 = fourier(a0);
      a1 = fourier(a1);
      a2 = fourier(a2);
      int[] d = new int[maxn];
      for (int i = 0; i < maxn; ++i) {
        d[i] = calc(a0[i], a1[i], a2[i]);
      }
      d = inverseFourier(d);
      long res = 0;
      for (int i = 1; i < maxn; ++i) {
        long cur = d[i];
        if (cur > 0) {
          cur = (cur * (long) i);
          res ^= cur;
        }
      }
      out.printLine(res);
    }

    private int calc(int x0, int x1, int x2) {
      if (x0 == 0) {
        return 0;
      }
      if (x0 == 1) {
        return x2;
      }
      long res = (long) x1 * (long) x1;
      res += x2;
      res %= mod;
      res *= p2[x0 - 2];
      res %= mod;
      return (int) res;
    }

    private int[] fourier(int[] a) {
      for (int dig = 0; dig < LEN; ++dig) {
        for (int i = maxn - 1; i >= 0; --i) {
          int t = (i / p10[dig]) % 10;
          if (t < 9) {
            a[i] += a[i + p10[dig]];
            a[i] %= mod;
          }
        }
      }
      return a;
    }

    private int[] inverseFourier(int[] a) {
      for (int dig = LEN - 1; dig >= 0; --dig) {
        for (int i = 0; i < maxn; ++i) {
          int t = (i / p10[dig]) % 10;
          if (t < 9) {
            a[i] -= a[i + p10[dig]];
            a[i] %= mod;
            if (a[i] < 0) {
              a[i] += mod;
            }
          }
        }
      }
      return a;
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