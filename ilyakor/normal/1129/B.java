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

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // Random random = new Random(0xdead);
      // for (int t = 1000 * 1000 * 1000 - 100000; t < 1000 * 1000 * 1000; ++t)
      //     // doSolve(random.nextInt(1000 * 1000 * 1000) + 1);
      //     doSolve(t);
      int k = in.nextInt();
      TaskB.Res res = doSolve(k);
      out.printLine(res.len + 4);
      for (int i = 0; i < res.len - 2; ++i) {
        out.print("0 ");
      }
      out.print("-1 ");
      out.print(res.x + " ");
      out.print("-1000000 ");
      out.print("-1000000 ");
      out.print("-1000000 ");
      out.printLine(res.y);
    }

    TaskB.Res doSolve(int delta) {
      for (int len = 2; len <= 2000; ++len) {
        if ((delta + len) / (len + 1) >= 1000 * 1000 - 10) {
          continue;
        }
        for (int y = 0; y < 1000; ++y) {
          int val = delta + len + y;
          if (val % (len - 1) != 0) {
            continue;
          }
          val /= len - 1;
          if (val > 1000 * 1000) {
            continue;
          }
          if (val + y > 1000 * 1000) {
            continue;
          }
          return new TaskB.Res(len, val, val + y);
        }
      }
      throw new RuntimeException();
    }

    static class Res {

      int len;
      int x;
      int y;

      public Res(int len, int x, int y) {
        this.len = len;
        this.x = x;
        this.y = y;
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