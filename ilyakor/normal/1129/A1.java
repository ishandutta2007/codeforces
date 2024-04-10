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
import java.util.ArrayList;
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
    TaskA1 solver = new TaskA1();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA1 {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      ArrayList<Integer>[] A = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        A[i] = new ArrayList<>();
      }
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        A[x].add(y);
      }
      int[] al = new int[n];
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        al[i] = A[i].size();
        a[i] = n;
        for (int y : A[i]) {
          int val = y - i;
          if (val < 0) {
            val += n;
          }
          a[i] = Math.min(a[i], val);
        }
      }
      for (int start = 0; start < n; ++start) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
          if (al[i] == 0) {
            continue;
          }
          int inc = (al[i] - 1) * n;
          if (i >= start) {
            inc += i - start;
          } else {
            inc += i - start + n;
          }
          if (inc + n <= cur) {
            continue;
          }
          int best = a[i];
          if (inc + best > cur) {
            cur = inc + best;
          }
        }
        out.print(cur + " ");
      }
      out.printLine();
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