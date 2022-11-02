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

    static final int M = 21;
    int[] u;
    int[] d;
    int[] q;
    int gen;
    int ql;
    int qr;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      u = new int[1 << M];
      d = new int[1 << M];
      q = new int[(1 << M) + 10];
      gen = 1;
      int n = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
      }
      int res = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (i <= n - 3) {
          int cur = calc(a[i]);
          if (cur > res) {
            res = cur;
          }
        }
        add(a[i]);
      }
      out.printLine(res);
    }

    private int calc(int x) {
      int mask = 0;
      for (int i = M - 1; i >= 0; --i) {
        if ((x >> i) % 2 == 1) {
          continue;
        }
        int nm = mask ^ (1 << i);
        if (d[nm] >= 2) {
          mask = nm;
        }
      }
      return x | mask;
    }

    private void add(int x) {
      if (d[x] >= 2) {
        return;
      }
      ++gen;
      ql = 0;
      qr = 0;
      q[ql++] = x;
      u[x] = gen;
      ++d[x];
      while (ql > qr) {
        int y = q[qr++];
        for (int i = 0; i < M; ++i) {
          if ((y >> i) % 2 == 1) {
            int z = y ^ (1 << i);
            if (u[z] == gen) {
              continue;
            }
            if (d[z] >= 2) {
              continue;
            }
            d[z]++;
            u[z] = gen;
            q[ql++] = z;
          }
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