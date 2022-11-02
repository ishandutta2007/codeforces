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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    ArrayList<Integer>[] g;
    boolean[] u;
    ArrayList<Integer> path;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      int m = in.nextInt();
      int k = in.nextInt();
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        g[x].add(y);
        g[y].add(x);
      }
      u = new boolean[n];
      path = new ArrayList<>();
      dfs(0);
      Assert.assertTrue(path.size() <= 2 * n);
      int lim = (2 * n / k) + (2 * n % k == 0 ? 0 : 1);
      int[] cur = new int[lim];
      int s = 0, cnt = 0;
      for (int x : path) {
        cur[s++] = x;
        if (s >= lim) {
          out.print(s);
          for (int i = 0; i < s; ++i) {
            out.print(" " + (cur[i] + 1));
          }
          out.printLine();
          s = 0;
          ++cnt;
        }
      }
      if (s > 0) {
        out.print(s);
        for (int i = 0; i < s; ++i) {
          out.print(" " + (cur[i] + 1));
        }
        out.printLine();
        s = 0;
        ++cnt;
      }
      while (cnt < k) {
        out.printLine("1 1");
        ++cnt;
      }
      Assert.assertTrue(cnt == k);
    }

    void dfs(int x) {
      u[x] = true;
      path.add(x);
      for (int y : g[x]) {
        if (u[y]) {
          continue;
        }
        dfs(y);
        path.add(x);
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