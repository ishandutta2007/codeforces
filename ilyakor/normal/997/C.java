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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    static final int mod = 998244353;
    static final int base = 3;
    static final int maxn = 1010 * 1000;
    static int[] f = new int[maxn];
    static int[] rf = new int[maxn];

    static {
      f[0] = 1;
      rf[0] = 1;
      for (int i = 1; i < maxn; ++i) {
        f[i] = (int) (((long) f[i - 1] * (long) i) % mod);
        rf[i] = IntegerUtils.pow(f[i], mod - 2, mod);
      }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // for (int theta = -18; theta <= 18; ++theta)
      // for (int alpha = -18; alpha <= 18; ++alpha)
      //     for (int beta = -18; beta <= 18; ++beta)
      //         for (int gamma = -18; gamma <= 18; ++gamma)
      //             for (int delta = -18; delta <= 18; ++delta) {
      //                 //if (alpha <= 0) continue;
      //                 int c0 = 3 * theta + alpha * 2 + beta * 1 + gamma * 2 + delta * 0;
      //                 if (c0 != 0) continue;
      //                 int c1 = 81 * theta + alpha * 56 + beta * 49 + gamma * 64 + delta * 36;
      //                 if (c1 != 18) continue;
      //                 int c2 = 19683 * theta + alpha * 16064 + beta * 15625 + gamma * 17576 + delta * 13824;
      //                 if (c2 != 9750) continue;
      //                 System.err.println(theta + " " + alpha + " " + beta + " " + gamma + " " + delta);
      //             }

      // for (int i = 1; i < 5; ++i) {
      //     int val = stupid(i);
      //     int p3 = 1;
      //     for (int j = 0; j < i * i; ++j)
      //         p3 *= base;
      //     System.err.println(val + " " + (p3 - val) + " " + smart(i));
      // }
      // System.err.flush();

      int n = in.nextInt();
      // for (int i = 1; i < 1000; ++i)
      //     System.err.println(i + " " + doSolve(i));
      long res = doSolve(n);
      out.printLine(res);
    }

    public long doSolve(int n) {
      long res = smart(n);
      long p3 = IntegerUtils.pow(3L, (long) n * (long) n, mod);
      res = p3 - res;
      res %= mod;
      res += mod;
      res %= mod;
      return res;
    }

    static long C(int n, int k) {
      if (k < 0 || k > n) {
        return 0;
      }
      long res = f[n] * (long) rf[k];
      res %= mod;
      res *= rf[n - k];
      res %= mod;
      return res;
    }

    long smart(int n) {
      long res = 0;
      long cp = 1;

      for (int k = 0; k <= n; ++k) {
        long cur = C(n, k);
        long cpp = cp - 1;
        if (cpp < 0) {
          cpp += mod;
        }
        cur *= IntegerUtils.pow(cpp, n, mod);
        cur %= mod;
        cp *= base;
        cp %= mod;
        if ((n + k) % 2 == 0) {
          res += cur;
        } else {
          res -= cur;
        }
        res = (res + mod) % mod;
      }
      res %= mod;
      res += mod;
      res %= mod;
      //return res;
      long first = res;
      //res *= 2L;
      // res *= base;
      // res %= mod;
      long zero = IntegerUtils.pow(base, (long) n * (long) n, mod);
      //int zero = IntegerUtils.pow(base, n * n, mod);
      // res += zero;

      long bn = IntegerUtils.pow(base, n, mod);
      bn -= 2;
      bn %= mod;
      bn += mod;
      bn %= mod;
      // long second = IntegerUtils.pow(bn, n, mod);
      //res += 2L * IntegerUtils.pow(bn, n, mod);
      // res += base * IntegerUtils.pow(bn, n, mod);
      // res %= mod;
      // res += mod;
      // res %= mod;

      ++bn;
      bn %= mod;
      bn += mod;
      bn %= mod;
      //res -= 4L * IntegerUtils.pow(bn, n, mod);
      long third = IntegerUtils.pow(bn, n, mod);
      // res -= 2L * base * IntegerUtils.pow(bn, n, mod);
      // res %= mod;
      // res += mod;
      // res %= mod;

      bn -= 2;
      bn %= mod;
      bn += mod;
      bn %= mod;
      long forth = IntegerUtils.pow(bn, n, mod);

      res = zero * 2L + first * 3L - third * 6L + forth * 2L;
      res %= mod;
      res += mod;
      res %= mod;

      return res;
    }

  }

  static class IntegerUtils {

    public static int pow(long x, long y, int mod) {
      x %= mod;
      long res = 1;
      while (y > 0) {
        if (y % 2 == 1) {
          --y;
          res = (res * x) % mod;
        } else {
          y /= 2;
          x = (x * x) % mod;
        }
      }
      return (int) (res % mod);
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