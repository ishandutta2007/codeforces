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

    InputReader in;
    OutputWriter out;
    int[] a;
    int[] prev;
    int[] next;
    int c;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      this.in = in;
      this.out = out;

      int n = in.nextInt();
      int m = in.nextInt();
      c = in.nextInt();
      doSolve(n, m);

      // Random random = new Random(0xdead);
      // for (int it = 0; it < 1000000; ++it) {
      //     int n = 4;
      //     c = 4;
      //     int m = n * ((c + 1) / 2);
      //     Q = new int[m];
      //     qc = 0;
      //     for (int i = 0; i < m; ++i)
      //         Q[i] = random.nextInt(c) + 1;
      //     doSolve(n, m);
      // }
    }

    public void doSolve(int n, int m) {
      a = new int[n];
      prev = new int[n];
      next = new int[n];
      Arrays.fill(a, -1);
      int cnt = 0;
      while (true) {
        int x = get();
        int pos = getMove(x);
        a[pos] = x;
        ++cnt;
        send(pos);
        if (done()) {
          break;
        }
      }
      Assert.assertTrue(cnt <= m);
    }

    private int getMove(int x) {
      prev[0] = a[0];
      for (int i = 1; i < a.length; ++i) {
        prev[i] = prev[i - 1];
        if (a[i] != -1) {
          prev[i] = a[i];
        }
      }
      next[a.length - 1] = a[a.length - 1];
      if (next[a.length - 1] == -1) {
        next[a.length - 1] = 1000 * 1000;
      }
      for (int i = a.length - 2; i >= 0; --i) {
        next[i] = next[i + 1];
        if (a[i] != -1) {
          next[i] = a[i];
        }
      }
      for (int i = 0; i < a.length; ++i) {
        int j = i;
        if (x > c / 2) {
          j = a.length - i - 1;
        }
        if (a[j] != -1) {
          continue;
        }
        if (prev[j] <= x && x <= next[j]) {
          return j;
        }
      }
      for (int i = 0; i < a.length; ++i) {
        int j = i;
        if (x > c / 2) {
          j = a.length - i - 1;
        }
        if (a[j] == -1) {
          continue;
        }
        if (x > c / 2 && a[j] >= x) {
          continue;
        }
        if (x <= c / 2 && a[j] <= x) {
          continue;
        }
        int p = -1;
        if (j > 0) {
          p = prev[j - 1];
        }
        int n = 1000000;
        if (j < a.length - 1) {
          n = next[j + 1];
        }
        if (p <= x && x <= n) {
          return j;
        }
      }
      throw new RuntimeException();
    }

    private boolean done() {
      for (int x : a) {
        if (x == -1) {
          return false;
        }
      }
      for (int i = 1; i < a.length; ++i) {
        if (a[i] < a[i - 1]) {
          return false;
        }
      }
      return true;
    }

    int get() {
      //return Q[qc++];
      return in.nextInt();
    }

    void send(int pos) {
      out.printLine(pos + 1);
      out.flush();
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

  static class Assert {

    public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
      if (!flag) {
        throw new AssertionError();
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

  }
}