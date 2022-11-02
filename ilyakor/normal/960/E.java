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
import java.util.ArrayList;
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

    static final int mod = 1000 * 1000 * 1000 + 7;
    ArrayList<Integer>[] g;
    int[] down0;
    int[] down1;
    int[] up0;
    int[] up1;
    int[] par;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int[] V = new int[n];
      for (int i = 0; i < n; ++i) {
        V[i] = in.nextInt();
        V[i] = (V[i] % mod + mod) % mod;
      }

      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      for (int i = 0; i < n - 1; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        g[x].add(y);
        g[y].add(x);
      }

      down0 = new int[n];
      down1 = new int[n];
      dfs1(0, -1);

      up0 = new int[n];
      up1 = new int[n];
      par = new int[n];
      dfs2(0, -1);

      long res = 0;
      for (int i = 0; i < n; ++i) {
        long cur0 = (long) up0[i] * (long) up0[i];
        long cur1 = (long) up1[i] * (long) up1[i];
        for (int x : g[i]) {
          long c0, c1;
          if (x == par[i]) {
            c0 = up1[x] - down0[i];
            c1 = up0[x] - down1[i];
          } else {
            c0 = down1[x];
            c1 = down0[x];
          }
          cur0 -= c0 * c0;
          cur1 -= c1 * c1;
        }
        Assert.assertTrue(cur0 >= 0);
        Assert.assertTrue(cur1 >= 0);
        Assert.assertTrue(cur0 % 2L == 1);
        Assert.assertTrue(cur1 % 2L == 0);
        // cur0 /= 2;
        // cur1 /= 2;
        // ++cur0;
        long cur = cur0 - cur1;
        cur = (cur % mod + mod) % mod;
        cur *= V[i];
        cur = (cur % mod + mod) % mod;
        res = (res + cur) % mod;
      }
      out.printLine(res);
    }

    private void dfs2(int x, int p) {
      par[x] = p;
      if (p == -1) {
        up0[x] = 0;
        up1[x] = 0;
      } else {
        up0[x] = up1[p];
        up1[x] = up0[p];
      }
      up0[x] += down0[x];
      up1[x] += down1[x];
      for (int y : g[x]) {
        if (y != p) {
          up0[x] -= down1[y];
          up1[x] -= down0[y];
          dfs2(y, x);
          up0[x] += down1[y];
          up1[x] += down0[y];
        }
      }
    }

    private void dfs1(int x, int p) {
      down0[x] = 1;
      down1[x] = 0;
      for (int y : g[x]) {
        if (y != p) {
          dfs1(y, x);
          down0[x] += down1[y];
          down1[x] += down0[y];
        }
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
}