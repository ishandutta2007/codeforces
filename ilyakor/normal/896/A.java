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
    TaskA solver = new TaskA();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class TaskA {

    static final long inf = (long) (2E18);
    static final String MSG = "What are you doing at the end of the world? Are you busy? Will you save us?";
    static final String PART1 = "What are you doing while sending \"";
    static final String PART2 = "\"? Are you busy? Will you send \"";
    static final String PART3 = "\"?";

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      long k = in.nextLong();
      --k;

      long[] d = new long[n + 1];
      d[0] = MSG.length();
      for (int i = 1; i <= n; ++i) {
        d[i] = d[i - 1] * 2L + PART1.length() + PART2.length() + PART3.length();
        if (d[i] > inf) {
          d[i] = inf;
        }
      }
      for (int i = n; i > 0; --i) {
        if (k >= d[i]) {
          out.print('.');
          return;
        }
        if (k < PART1.length()) {
          out.print(PART1.charAt((int) k));
          return;
        }
        k -= PART1.length();
        if (k < d[i - 1]) {
          continue;
        }
        k -= d[i - 1];
        if (k < PART2.length()) {
          out.print(PART2.charAt((int) k));
          return;
        }
        k -= PART2.length();
        if (k < d[i - 1]) {
          continue;
        }
        k -= d[i - 1];
        Assert.assertTrue(k < PART3.length());
        out.print(PART3.charAt((int) k));
        return;
      }
      if (k >= d[0]) {
        out.print('.');
        return;
      }
      out.print(MSG.charAt((int) k));
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

    public void close() {
      writer.close();
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
}