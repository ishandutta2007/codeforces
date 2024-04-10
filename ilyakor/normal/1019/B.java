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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      int base = calc(in, out, 0);
      if (base == 0) {
        out.printLine("! 1");
        out.flush();
        return;
      }
      if (Math.abs(base) % 2 != 0) {
        out.printLine("! -1");
        out.flush();
        return;
      }
      int down = 0, up = n / 2;
      int sdown = base < 0 ? -1 : 1;
      int sup = up < 0 ? -1 : 1;
      while (up - down > 1) {
        int t = (up + down) / 2;
        int cur = calc(in, out, t);
        if (cur == 0) {
          out.printLine("! " + (t + 1));
          out.flush();
          return;
        }
        int scur = cur < 0 ? -1 : 1;
        if (scur == sdown) {
          down = t;
        } else {
          up = t;
        }
      }
      throw new RuntimeException();
    }

    private int calc(InputReader in, OutputWriter out, int val) {
      out.printLine("? " + (val + 1));
      out.flush();
      int res1 = in.nextInt();
      out.printLine("? " + ((val + n / 2) % n + 1));
      out.flush();
      int res2 = in.nextInt();
      return res1 - res2;
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

    public void flush() {
      writer.flush();
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