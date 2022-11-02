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
    TaskA solver = new TaskA();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class TaskA {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int a = in.nextInt();
      int b = in.nextInt();
      long d = IntegerUtils.gcd(a, b);
      long xPrime = a / d;
      long yPrime = b / d;
      long xyOverG2 = xPrime * yPrime;
      if (xyOverG2 > a || xyOverG2 > b) {
        out.printLine("No");
        return;
      }
      long aOverG3 = xyOverG2 * xPrime;
      if (a % aOverG3 != 0) {
        out.printLine("No");
        return;
      }
      long g3 = a / aOverG3;
      long l = 0, r = (long) (1.1E6);
      while (r - l > 1) {
        long t = (l + r) / 2;
        if (t * t * t <= g3) {
          l = t;
        } else {
          r = t;
        }
      }
      if (l * l * l != g3) {
        out.printLine("No");
        return;
      }
      long g = l;
      long x = xPrime * g, y = yPrime * g;
      if (x > a || x > b || y > a || y > b) {
        out.printLine("No");
        return;
      }
      long xy = x * y;
      if (xy > a || xy > b) {
        out.printLine("No");
        return;
      }
      long x2y = xy * x, xy2 = xy * y;
      if (x2y != a || xy2 != b) {
        out.printLine("No");
        return;
      }
      out.printLine("Yes");
    }

  }

  static class IntegerUtils {

    public static int gcd(int x, int y) {
      if (y == 0) {
        return x;
      }
      return gcd(y, x % y);
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