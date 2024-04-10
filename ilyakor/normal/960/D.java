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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {

    static final int BUBEN = 70;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int q = in.nextInt();
      long[] d = new long[BUBEN];
      long[] sz = new long[BUBEN];
      sz[0] = 1;
      for (int i = 1; i < BUBEN; ++i) {
        sz[i] = sz[i - 1] * 2L;
      }
      for (int it = 0; it < q; ++it) {
        int t = in.nextInt();
        long x = in.nextLong();
        if (t == 1 || t == 2) {
          long k = in.nextLong();
          int l = 0;
          while (x > 1) {
            x /= 2L;
            ++l;
          }
          if (t == 1) {
            d[l] = ((d[l] + k) % sz[l] + sz[l]) % sz[l];
          } else {
            for (int i = l; i < BUBEN; ++i) {
              if (sz[i] == 0) {
                break;
              }
              d[i] = ((d[i] + k) % sz[i] + sz[i]) % sz[i];
              k *= 2L;
            }
          }
        } else {
          int l = 0;
          long X = x;
          while (X > 1) {
            X /= 2L;
            ++l;
          }
          x = sz[l] + ((x + d[l]) % sz[l] + sz[l]) % sz[l];
          while (x > 0) {
            out.print(sz[l] + ((x - sz[l] - d[l]) % sz[l] + sz[l]) % sz[l]);
            out.print(" ");
            x /= 2;
            --l;
          }
          out.printLine();
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