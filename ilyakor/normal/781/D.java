import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.BitSet;
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

    static final int maxh = 61;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
//        int n = 500;
//        int m = 500 * 500;
      BitSet[][][] next = new BitSet[2][maxh][n];
      for (int c = 0; c < 2; ++c) {
        for (int h = 0; h < maxh; ++h) {
          for (int i = 0; i < n; ++i) {
            next[c][h][i] = new BitSet(n);
          }
        }
      }
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        int c = in.nextInt();
//            int c = i % 2;
//            int x = i / n;
//            int y = i % n;
        next[c][0][x].set(y);
      }
      for (int h = 1; h < maxh; ++h) {
        for (int c = 0; c < 2; ++c) {
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
              if (!next[c][h - 1][i].get(j)) {
                continue;
              }
              next[c][h][i].or(next[1 - c][h - 1][j]);
            }
          }
        }
      }

      long[][][] d = new long[2][maxh][n];
      long res = 0;

      for (int h = 0; h < maxh; ++h) {
        long inc = (1L << (long) h);
        for (int c = 0; c < 2; ++c) {
          for (int i = 0; i < n; ++i) {
            if (h > 0) {
              d[c][h][i] = d[c][h - 1][i];
            }
            for (int j = 0; j < n; ++j) {
              if (next[c][h][i].get(j)) {
                long val = 0;
                if (h > 0) {
                  val += d[1 - c][h - 1][j];
                }
                val += inc;
                if (val > d[c][h][i]) {
                  d[c][h][i] = val;
                }
              }
            }
            if (c == 0 && d[c][h][i] > res) {
              res = d[c][h][i];
            }
          }
        }
      }

      if (res > BigInteger.valueOf(10).pow(18).longValue()) {
        res = -1;
      }
      out.printLine(res);
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