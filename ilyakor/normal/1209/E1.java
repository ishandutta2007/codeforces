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
    TaskE1 solver = new TaskE1();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class TaskE1 {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[][] d = new int[2][1 << n];
      int[] buf = new int[1 << n];
      int[][] a = new int[m][n];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          a[j][i] = in.nextInt();
        }
      }
      for (int i = 0; i < m; ++i) {
        int[] prev = d[i % 2], nx = d[(i + 1) % 2];
        for (int shift = 0; shift < n; ++shift) {
          int[] b = new int[n];
          for (int j = 0; j < n; ++j) {
            b[j] = a[i][(j + shift) % n];
          }
          System.arraycopy(prev, 0, buf, 0, prev.length);
          for (int mask = 0; mask < (1 << n); ++mask) {
            int val0 = buf[mask];
            for (int j = 0; j < n; ++j) {
              if ((mask >> j) % 2 == 0) {
                int val = val0 + b[j];
                int nm = mask ^ (1 << j);
                if (val > buf[nm]) {
                  buf[nm] = val;
                }
              }
            }
          }
          for (int mask = 0; mask < (1 << n); ++mask) {
            if (nx[mask] < buf[mask]) {
              nx[mask] = buf[mask];
            }
          }
        }
      }
      out.printLine(d[m % 2][(1 << n) - 1]);
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

    public String next() {
      return nextToken();
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