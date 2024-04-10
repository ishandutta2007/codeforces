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

    static final int N = 3;
    static final int[] mods = new int[]{1000 * 1000 * 1000 + 7, 999999893, 500 * 1000 * 1000 + 9};
    static final int[] xs = new int[]{57, 43, 2184057};
    char[] s;
    char[] t;
    int[][] ph;
    int[][] h;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      s = in.nextToken().toCharArray();
      t = in.nextToken().toCharArray();
      if (s[0] == '1') {
        for (int i = 0; i < s.length; ++i) {
          s[i] = (s[i] == '0' ? '1' : '0');
        }
      }
      int c0 = 0, c1 = 0;
      for (int i = 0; i < s.length; ++i) {
        if (s[i] == '0') {
          ++c0;
        } else {
          ++c1;
        }
      }

      h = new int[N][t.length + 1];
      ph = new int[N][t.length + 1];
      for (int i = 0; i < N; ++i) {
        ph[i][0] = 1;
        for (int j = 1; j < ph[i].length; ++j) {
          ph[i][j] = (int) ((ph[i][j - 1] * (long) xs[i]) % mods[i]);
        }
        h[i][0] = 0;
        for (int j = 1; j < h[i].length; ++j) {
          h[i][j] = (int) ((h[i][j - 1] * (long) xs[i] + t[j - 1]) % mods[i]);
        }
      }

      int res = 0;
      for (int l1 = 0; l1 <= t.length; ++l1) {
        if (c1 == 0 && l1 != 0) {
          continue;
        }
        if (c1 != 0 && l1 == 0) {
          continue;
        }
        int rem = t.length - l1 * c1;
        if (rem < 0) {
          break;
        }
        if (rem % c0 != 0) {
          continue;
        }
        int l0 = rem / c0;
        if (l0 == 0) {
          continue;
        }
        if (check(l0, l1)) {
          ++res;
        }
      }
      out.printLine(res);
    }

    private boolean check(int l0, int l1) {
      int[] val0 = calc(0, l0);
      int[] val1 = null;
      for (int i = 0; i < s.length; ++i) {
        if (s[i] == '1') {
          val1 = calc(l0 * i, l0 * i + l1);
          break;
        }
      }
      if (val1 != null) {
        boolean eq = true;
        for (int i = 0; i < N; ++i) {
          if (val0[i] != val1[i]) {
            eq = false;
          }
        }
        if (eq) {
          return false;
        }
      }
      int pos = 0;
      for (int i = 0; i < s.length; ++i) {
        char c = s[i];
        int nx = pos + (c == '0' ? l0 : l1);
        if (!cmp(c == '0' ? val0 : val1, pos, nx)) {
          return false;
        }
        pos = nx;
      }
      return true;
    }

    private boolean cmp(int[] need, int l, int r) {
      for (int i = 0; i < N; ++i) {
        int val = (int) ((h[i][r] - h[i][l] * (long) ph[i][r - l]) % mods[i]);
        val += mods[i];
        val %= mods[i];
        if (val != need[i]) {
          return false;
        }
      }
      return true;
    }

    private int[] calc(int l, int r) {
      int[] res = new int[N];
      for (int i = 0; i < N; ++i) {
        res[i] = (int) ((h[i][r] - h[i][l] * (long) ph[i][r - l]) % mods[i]);
        res[i] += mods[i];
        res[i] %= mods[i];
      }
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

    public String nextToken() {
      int c = readSkipSpace();
      StringBuilder sb = new StringBuilder();
      while (!isSpace(c)) {
        sb.append((char) c);
        c = read();
      }
      return sb.toString();
    }

  }
}