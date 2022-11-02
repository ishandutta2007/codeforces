import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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

    static final int mod = 1000 * 1000 * 1000 + 7;
    static final int maxn = 110 * 1000;
    int[] inv;
    ArrayList<Pair<Long, Integer>> ap;
    int[][] coefs;
    long num;
    long den;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      inv = new int[maxn];
      for (int i = 1; i < maxn; ++i) {
        inv[i] = IntegerUtils.pow(i, mod - 2, mod);
      }
      // f = new int[maxn];
      // rf = new int[maxn];
      // f[0] = 1;
      // rf[0]= 1;
      // for (int i = 1; i < maxn; ++i) {
      //     f[i] = (int) ((f[i - 1] * (long) i) % mod);
      //     rf[i] = IntegerUtils.pow(f[i], mod - 2, mod);
      // }

      ap = new ArrayList<>();
      long n = in.nextLong();
      int k = in.nextInt();
      {
        long x = n;
        for (long p = 2; p * p <= x; ++p) {
          if (x % p != 0) {
            continue;
          }
          int pw = 0;
          while (x % p == 0) {
            x /= p;
            ++pw;
          }
          ap.add(new Pair<>(p, pw));
        }
        if (x > 1) {
          ap.add(new Pair<>(x, 1));
        }
      }
      coefs = new int[ap.size()][];
      for (int i = 0; i < ap.size(); ++i) {
        int pw = ap.get(i).second;
        coefs[i] = calc(pw, k);
        // coefs[i] = new int[pw + 1];
        // for (int j = 0; j <= pw; ++j)
        //     coefs[i][j] = C(k + pw - j - 1, k - 1);
      }
      num = 0;
      den = 0;
      for (long t = 1; t * t <= n; ++t) {
        if (n % t != 0) {
          continue;
        }
        process(t);
        if (n / t != t) {
          process(n / t);
        }
      }
      num %= mod;
      den %= mod;
      num *= IntegerUtils.pow(den, mod - 2, mod);
      num %= mod;
      out.printLine(num);
    }

    private int[] calc(int pw, int k) {
      int[][] d = new int[k + 1][pw + 1];
      d[0][pw] = 1;
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= pw; ++j) {
          if (d[i][j] != 0) {
            long den = inv[j + 1];
            for (int t = 0; t <= j; ++t) {
              d[i + 1][t] = (int) ((d[i + 1][t] + d[i][j] * den) % mod);
            }
          }
        }
      }
      return d[k];
    }

    private void process(long x) {
      long ox = x % mod;
      long coef = 1;
      for (int i = 0; i < ap.size(); i++) {
        Pair<Long, Integer> e = ap.get(i);
        long p = e.first;
        int pw = 0;
        while (x % p == 0) {
          x /= p;
          ++pw;
        }
        coef *= coefs[i][pw];
        coef %= mod;
      }
      num += coef * ox;
      num %= mod;
      den += coef;
      den %= mod;
    }

  }

  static class Pair<P, Q> {

    public P first;
    public Q second;

    public Pair() {
    }

    public Pair(P first, Q second) {
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

      Pair pair = (Pair) o;

      if (first != null ? !first.equals(pair.first) : pair.first != null) {
        return false;
      }
      if (second != null ? !second.equals(pair.second) : pair.second != null) {
        return false;
      }

      return true;
    }

    public int hashCode() {
      int result = first != null ? first.hashCode() : 0;
      result = 31 * result + (second != null ? second.hashCode() : 0);
      return result;
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
}