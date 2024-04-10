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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    ArrayList<Integer>[] g;
    int[] need;
    int n;
    boolean[] alive;
    int[] res;
    int pos;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      need = new int[n];
      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      int r = -1;
      for (int i = 0; i < n; ++i) {
        int p = in.nextInt() - 1;
        int x = in.nextInt();
        if (p != -1) {
          g[p].add(i);
        } else {
          r = i;
        }
        need[i] = x;
      }
      alive = new boolean[n];
      Arrays.fill(alive, true);
      res = new int[n];
      pos = 0;
      if (!dfs(r)) {
        out.printLine("NO");
        return;
      }
      out.printLine("YES");
      for (int i = 0; i < n; ++i) {
        out.print((res[i] + 1) + " ");
      }
      out.printLine();
    }

    private boolean dfs(int x) {
      int k = need[x] + 1;
      int t = pos;
      while (t < n && k > 0) {
        if (alive[t]) {
          --k;
        }
        if (k == 0) {
          break;
        }
        ++t;
      }
      if (k > 0 || t >= n) {
        return false;
      }
      alive[t] = false;
      res[x] = t;
      for (int y : g[x]) {
        if (!dfs(y)) {
          return false;
        }
      }
      while (pos < n && !alive[pos]) {
        ++pos;
      }
      if (pos < t) {
        return false;
      }
      return true;
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