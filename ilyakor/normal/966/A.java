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

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int numL = in.nextInt();
      int numE = in.nextInt();
      int v = in.nextInt();
      int[] l = new int[numL];
      for (int i = 0; i < numL; ++i) {
        l[i] = in.nextInt();
      }
      int[] e = new int[numE];
      for (int i = 0; i < numE; ++i) {
        e[i] = in.nextInt();
      }
      int q = in.nextInt();
      for (int it = 0; it < q; ++it) {
        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        if (x1 == x2) {
          out.printLine(Math.abs(y1 - y2));
          continue;
        }
        int res = 1000 * 1000 * 1000;
        {
          int ind = Arrays.binarySearch(l, y1);
          if (ind < 0) {
            ind = -ind - 1;
          }
          for (int i = ind - 1; i <= ind + 1; ++i) {
            if (i < 0 || i >= l.length) {
              continue;
            }
            int cur = Math.abs(y1 - l[i]) + Math.abs(y2 - l[i]);
            cur += Math.abs(x1 - x2);
            res = Math.min(res, cur);
          }
        }
        {
          int ind = Arrays.binarySearch(e, y2);
          if (ind < 0) {
            ind = -ind - 1;
          }
          for (int i = ind - 1; i <= ind + 1; ++i) {
            if (i < 0 || i >= e.length) {
              continue;
            }
            int cur = Math.abs(y1 - e[i]) + Math.abs(y2 - e[i]);
            cur += (Math.abs(x1 - x2) + v - 1) / v;
            res = Math.min(res, cur);
          }
        }
        out.printLine(res);
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