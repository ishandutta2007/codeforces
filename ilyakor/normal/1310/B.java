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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    static final int inf = 1000 * 1000 * 1000;
    int[] A;
    int[][] d;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      A = new int[(1 << (n + 1))];
      for (int i = 0; i < k; ++i) {
        A[(1 << n) + in.nextInt() - 1] = 1;
      }
      if (k == 0) {
        out.printLine(0);
        return;
      }
      for (int i = A.length - 1; i > 0; --i) {
        A[i / 2] += A[i];
      }
      d = new int[4][A.length];
      for (int i = 0; i < d.length; ++i) {
        Arrays.fill(d[i], -inf - 1);
      }
      int res = Math.max(calc(1, 1), Math.max(calc(1, 2), calc(1, 3)));
      if (res < 0) {
        res = 0;
      }
      ++res;
      out.printLine(res);
    }

    int calc(int v, int s) {
      if (s == 0) {
        return 0;
      }
      if (A[v] == 0) {
        return -inf;
      }
      if (s == 3 && A[v] < 2) {
        return -inf;
      }
      if (v * 4 >= A.length) {
        return 1;
      }
      if (d[s][v] != -inf - 1) {
        return d[s][v];
      }
      int res = -inf;
      for (int s1 = 0; s1 <= 3; ++s1) {
        for (int s2 = 0; s2 <= 3; ++s2) {
          int val1 = calc(v * 2, s1);
          int val2 = calc(v * 2 + 1, s2);
          for (int mask = 0; mask < 8; ++mask) {
            int cur = val1 + val2;
            int w1 = mask % 2 == 0 ? s1 % 2 : s2 % 2;
            int l1 = mask % 2 == 0 ? s2 % 2 : s1 % 2;
            if (w1 + l1 > 0) {
              ++cur;
            }

            int w2 = (mask >> 1) % 2 == 0 ? (s1 >> 1) % 2 : (s2 >> 1) % 2;
            int l2 = (mask >> 1) % 2 == 0 ? (s2 >> 1) % 2 : (s1 >> 1) % 2;
            if (w2 + l2 > 0) {
              ++cur;
            }

            int w3 = (mask >> 2) % 2 == 0 ? l1 : w2;
            if (l1 + w2 > 0) {
              ++cur;
            }
            if (w3 * 2 + w1 != s) {
              continue;
            }
            if (cur > res) {
              res = cur;
            }
          }
        }
      }
      //System.err.println(s + " " + v + ": " + res);
      d[s][v] = res;
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