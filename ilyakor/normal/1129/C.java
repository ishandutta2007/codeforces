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
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    static final int mod = 1000 * 1000 * 1000 + 7;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      // int n = 1000;
      char[] s = new char[n];
      for (int i = 0; i < n; ++i) {
        s[i] = (char) ('0' + in.nextInt());
        // s[i] = '1';
      }
      int[][] pr = new int[n][];
      for (int i = 0; i < n; ++i) {
        pr[i] = prefixFunction(s, i);
      }
      int res = 0;
      int[] d = new int[n + 2];
      for (int i = 0; i < n; ++i) {
        int skip = 0;
        for (int j = 0; j < i; ++j) {
          skip = Math.max(skip, pr[j][i - j]);
        }
        Arrays.fill(d, 0);
        d[i + 1] = 1;
        for (int j = i + 1; j >= 0; --j) {
          if (j - 1 >= 0) {
            d[j - 1] = (d[j - 1] + d[j]) % mod;
          }
          if (j - 2 >= 0) {
            d[j - 2] = (d[j - 2] + d[j]) % mod;
          }
          if (j - 3 >= 0) {
            d[j - 3] = (d[j - 3] + d[j]) % mod;
          }
          if (j - 4 >= 0 && ok(s[j - 4], s[j - 3], s[j - 2], s[j - 1])) {
            d[j - 4] = (d[j - 4] + d[j]) % mod;
          }
          if (i - j >= skip) {
            res = (res + d[j]) % mod;
          }
        }
        out.printLine(res);
      }
    }

    private boolean ok(char c1, char c2, char c3, char c4) {
      if (c1 == '0' && c2 == '0' && c3 == '1' && c4 == '1') {
        return false;
      }
      if (c1 == '0' && c2 == '1' && c3 == '0' && c4 == '1') {
        return false;
      }
      if (c1 == '1' && c2 == '1' && c3 == '1' && c4 == '0') {
        return false;
      }
      if (c1 == '1' && c2 == '1' && c3 == '1' && c4 == '1') {
        return false;
      }
      return true;
    }

    static int[] prefixFunction(char[] s, int from) {
      int n = s.length - from;
      int[] p = new int[n];
      for (int i = 1; i < n; i++) {
        int k = p[i - 1];
        while (k > 0 && s[from + k] != s[from + i]) {
          k = p[k - 1];
        }
        p[i] = k + (s[from + k] == s[from + i] ? 1 : 0);
      }
      return p;
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