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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      PointDouble[] a = new PointDouble[n];
      for (int i = 0; i < n; ++i) {
        a[i] = new PointDouble(in.nextDouble(), in.nextDouble());
      }
      double res = 1E100;
      for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        res = Math.min(res, calc(a[i], a[j], a[k]));
      }
      out.printLine(String.format("%.20f", res));
    }

    private double calc(PointDouble p1, PointDouble p2, PointDouble p3) {
      double s = Math.abs(p1.subtract(p2).cross(p3.subtract(p2)));
      double h = s / p1.subtract(p3).len();
      return h * 0.5;
    }

  }

  static class PointDouble {

    public double x;
    public double y;

    public PointDouble(double x, double y) {
      this.x = x;
      this.y = y;
    }

    public PointDouble() {
      x = 0;
      y = 0;
    }

    public double cross(PointDouble p) {
      return x * p.y - y * p.x;
    }

    public PointDouble subtract(PointDouble p) {
      return new PointDouble(x - p.x, y - p.y);
    }

    public double len() {
      return Math.sqrt(x * x + y * y);
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

    public double nextDouble() {
      double sgn = 1;
      int c = readSkipSpace();
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      double res = 0;
      while (!isSpace(c) && c != '.') {
        if (c == 'e' || c == 'E') {
          return res * Math.pow(10, nextInt());
        } else if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res = res * 10 + c - '0';
        c = read();
      }
      if (c == '.') {
        c = read();
        double m = 1;
        while (!isSpace(c)) {
          if (c == 'e' || c == 'E') {
            return res * Math.pow(10, nextInt());
          } else if (c < '0' || c > '9') {
            throw new InputMismatchException();
          }
          m /= 10;
          res += (c - '0') * m;
          c = read();
        }
      }
      res *= sgn;
      return res;
    }

  }
}