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

    static final int mod = 998244353;
    static final int maxn = 3650;
    int[][] C;
    int[] f;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      C = new int[maxn][maxn];
      C[0][0] = 1;
      for (int i = 1; i < maxn; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < maxn; ++j) {
          C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
      }

      f = new int[maxn];
      f[0] = 1;
      for (int i = 1; i < maxn; ++i) {
        f[i] = (int) (((long) f[i - 1] * (long) i) % mod);
      }

      int n = in.nextInt();
      int m = in.nextInt();
      boolean[] u1 = new boolean[n];
      boolean[] u2 = new boolean[m];
      int cntK = in.nextInt();
      for (int i = 0; i < cntK; ++i) {
        int x1 = in.nextInt() - 1;
        int y1 = in.nextInt() - 1;
        int x2 = in.nextInt() - 1;
        int y2 = in.nextInt() - 1;
        u1[x1] = true;
        u1[x2] = true;
        u2[y1] = true;
        u2[y2] = true;
      }
      int[] outt = new int[1];
      int[] d1 = calc(u1, outt);
      int cnt1 = outt[0];
      int[] d2 = calc(u2, outt);
      int cnt2 = outt[0];
      long res = 0;
      for (int i = 0; i < d1.length; ++i) {
        if (d1[i] != 0) {
          for (int j = 0; j < d2.length; ++j) {
            if (d2[j] != 0) {
              if (i * 2 + j > cnt1) {
                continue;
              }
              if (i + j * 2 > cnt2) {
                continue;
              }
              long cur = d1[i] * (long) d2[j];
              cur %= mod;
              cur *= C[cnt1 - i * 2][j];
              cur %= mod;
              cur *= C[cnt2 - j * 2][i];
              cur %= mod;
              cur *= f[j];
              cur %= mod;
              cur *= f[i];
              cur %= mod;
              res += cur;
              res %= mod;
            }
          }
        }
      }
      out.printLine(res);
    }

    private int[] calc(boolean[] u, int[] out) {
      int n = u.length;
      int[] d = new int[n / 2 + 1];
      d[0] = 1;
      int cur = 0;
      int total = 0;
      for (int i = 0; i < u.length; ++i) {
        if (u[i]) {
          if (cur > 1) {
            add(d, cur);
          }
          cur = 0;
        } else {
          ++cur;
          ++total;
        }
      }
      if (cur > 1) {
        add(d, cur);
      }
      out[0] = total;
      return d;
    }

    private void add(int[] d, int cnt) {
      for (int i = d.length - 1; i >= 0; --i) {
        int val = d[i];
        if (val == 0) {
          continue;
        }
        for (int j = 1; j <= cnt / 2; ++j) {
          long cur = C[cnt - j][j];
          cur *= val;
          d[i + j] = (int) ((d[i + j] + cur) % mod);
        }
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