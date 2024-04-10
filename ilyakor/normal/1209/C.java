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
    TaskC solver = new TaskC();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class TaskC {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      char[] a = in.nextToken().toCharArray();
      int[] col = new int[n];
      for (int dig = 0; dig <= 9; ++dig) {
        boolean ok = true;
        Arrays.fill(col, 0);
        int prev = -1;
        for (int i = 0; i < n; ++i) {
          int c = a[i] - '0';
          if (c < dig) {
            if (prev == -1 || a[i] >= a[prev]) {
              col[i] = -1;
              prev = i;
            } else {
              ok = false;
              break;
            }
          }
        }
        if (!ok) {
          continue;
        }
        for (int i = prev + 1; i < n; ++i) {
          if (a[i] - '0' == dig) {
            col[i] = -1;
          }
        }
        prev = n;
        for (int i = n - 1; i >= 0; --i) {
          int c = a[i] - '0';
          if (c > dig) {
            if (prev == n || a[i] <= a[prev]) {
              col[i] = 1;
              prev = i;
            } else {
              ok = false;
              break;
            }
          }
        }
        if (!ok) {
          continue;
        }
        for (int i = prev - 1; i >= 0; --i) {
          if (a[i] - '0' == dig && col[i] == 0) {
            col[i] = 1;
          }
        }
        for (int i = 0; i < n; ++i) {
          if (col[i] == 0) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          continue;
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; ++i) {
          res.append(col[i] == -1 ? '1' : '2');
        }
        out.printLine(res.toString());
        return;
      }
      out.printLine("-");
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