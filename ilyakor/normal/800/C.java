import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    int m;
    int pm;
    int[] G;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      m = in.nextInt();
      pm = phi(m);
      HashSet<Integer>[] a = new HashSet[m + 1];
      for (int i = 0; i < a.length; ++i) {
        a[i] = new HashSet<>();
      }
      G = new int[m + 1];
      G[m] = m;
      for (int i = 0; i < m; ++i) {
        G[i] = IntegerUtils.gcd(i, m);
        a[G[i]].add(i);
      }
      for (int i = 0; i < n; ++i) {
        int x = in.nextInt();
        a[G[x]].remove(x);
      }
      int[] d = new int[m + 1];
      int[] from = new int[m + 1];
      ArrayList<Integer> divs = new ArrayList<>();
      for (int i = 1; i <= m; ++i) {
        if (m % i != 0) {
          continue;
        }
        divs.add(i);
      }
      for (int i : divs) {
        d[i] = a[i].size();
        from[i] = -1;
        for (int j : divs) {
          if (j >= i) {
            break;
          }
          if (i % j == 0) {
            int val = d[j] + a[i].size();
            if (val > d[i]) {
              d[i] = val;
              from[i] = j;
            }
          }
        }
      }
      ArrayList<Integer> prods = new ArrayList<>();
      int t = m;
      while (t != -1) {
        prods.addAll(a[t]);
        t = from[t];
      }
      Assert.assertTrue(prods.size() == d[m]);
      Collections.reverse(prods);
      out.printLine(prods.size());
      int prev = 1;
      for (int i = 0; i < prods.size(); ++i) {
        out.print(divide(prev, prods.get(i)) + " ");
        prev = prods.get(i);
      }
    }

    private int divide(int x, int y) {
      int x0 = x / G[x], y0 = y / G[y];
      int rx0 = IntegerUtils.pow(x0, pm - 1, m);
      int res = (int) (((long) y0 * (long) (rx0)) % m);
      if (G[y] % G[x] != 0) {
        throw new RuntimeException();
      }
      res *= G[y] / G[x];
      res %= m;
      //Assert.assertTrue(((long) x * (long) res) % m == y);
      return res;
    }

    static int phi(int n) {
      int result = n;
      for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
          while (n % i == 0) {
            n /= i;
          }
          result -= result / i;
        }
      }
      if (n > 1) {
        result -= result / n;
      }
      return result;
    }

  }

  static class Assert {

    public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
      if (!flag) {
        throw new AssertionError();
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

    public void printLine(Object... objects) {
      print(objects);
      writer.println();
    }

    public void close() {
      writer.close();
    }

  }

  static class IntegerUtils {

    public static int gcd(int x, int y) {
      if (y == 0) {
        return x;
      }
      return gcd(y, x % y);
    }

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