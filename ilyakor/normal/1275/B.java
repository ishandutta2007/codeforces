import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {

    public static final int inf = 1000 * 1000 * 1000;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int n0 = n / 2;
      int n1 = n - n0;
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
        if (a[i] == 0) {
          a[i] = -1;
        } else {
          a[i] = a[i] % 2;
        }
      }
      int[][][] d = new int[2][n0 + 1][n1 + 1];
      int[][][] nd = new int[2][n0 + 1][n1 + 1];
      for (int i = 0; i < d.length; ++i) {
        for (int j = 0; j < d[i].length; ++j) {
          Arrays.fill(d[i][j], inf);
        }
      }
      d[0][n0][n1] = 0;
      d[1][n0][n1] = 0;
      for (int it = 0; it < n; ++it) {
        for (int i = 0; i < nd.length; ++i) {
          for (int j = 0; j < nd[i].length; ++j) {
            Arrays.fill(nd[i][j], inf);
          }
        }
        int x = a[it];
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < d[i].length; ++j) {
            for (int k = 0; k < d[i][j].length; ++k) {
              if (d[i][j][k] == inf) {
                continue;
              }
              for (int c = 0; c < 2; ++c) {
                if (x != -1 && x != c) {
                  continue;
                }
                int val = d[i][j][k];
                if (c != i) {
                  ++val;
                }
                int nj = j, nk = k;
                if (c == 0) {
                  --nj;
                } else {
                  --nk;
                }
                if (nj < 0 || nk < 0) {
                  continue;
                }
                if (nd[c][nj][nk] > val) {
                  nd[c][nj][nk] = val;
                }
              }
            }
          }
        }
        int[][][] tmp = d;
        d = nd;
        nd = tmp;
      }
      int res = Math.min(d[0][0][0], d[1][0][0]);
      out.printLine(res);
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