import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    int k;
    ArrayList<ii>[] g;
    int[] q;
    int[] deg;
    boolean[] alive;
    int T;
    int cur;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      Random random = new Random(0xdead);

      int n = in.nextInt();
      int m = in.nextInt();
      k = in.nextInt();
      // int n = 1000, m = 10000;
      // k = 10;

      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      ArrayList<ii> edges = new ArrayList<>();
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        // int x = random.nextInt(n);
        // int y;
        // do {
        //     y = random.nextInt(n);
        // } while (y == x);
        g[x].add(new ii(y, i));
        g[y].add(new ii(x, i));
        edges.add(new ii(x, y));
      }
      deg = new int[n];
      for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
      }
      T = m - 1;
      cur = n;
      alive = new boolean[n];
      q = new int[2 * n + 10];
      Arrays.fill(alive, true);
      for (int i = 0; i < n; ++i) {
        update(i);
      }
      int[] res = new int[m];
      for (int i = m - 1; i >= 0; --i) {
        res[i] = cur;
        int x = edges.get(i).first, y = edges.get(i).second;
        --T;
        if (alive[x]) {
          --deg[y];
        }
        if (alive[y]) {
          --deg[x];
        }
        update(x);
        update(y);
      }
      for (int i = 0; i < m; ++i) {
        out.printLine(res[i]);
      }
    }

    private void update(int x) {
      if (!alive[x]) {
        return;
      }
      int ql = 0, qr = 0;
      q[ql++] = x;
      while (ql > qr) {
        x = q[qr++];
        if (!alive[x]) {
          continue;
        }
        Assert.assertTrue(g[x].size() >= deg[x]);
        if (deg[x] >= k) {
          while (g[x].get(g[x].size() - 1).second > T) {
            g[x].remove(g[x].size() - 1);
          }
        } else {
          for (ii e : g[x]) {
            int y = e.first;
            if (alive[y] && deg[y] >= k && e.second <= T) {
              --deg[y];
              if (deg[y] < k) {
                q[ql++] = y;
              }
            }
          }
          g[x].clear();
          deg[x] = 0;
          alive[x] = false;
          --cur;
        }
      }
    }

  }

  static class Assert {

    public static void assertTrue(boolean flag) {
      // if (!flag)
      // while (true);
      if (!flag) {
        throw new AssertionError();
      }
    }

  }

  static class ii implements Comparable<ii> {

    public int first;
    public int second;

    public ii() {
    }

    public ii(int first, int second) {
      this.first = first;
      this.second = second;
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      ii ii = (ii) o;

      if (first != ii.first) {
        return false;
      }
      if (second != ii.second) {
        return false;
      }

      return true;
    }

    public int hashCode() {
      int result = first;
      result = 31 * result + second;
      return result;
    }

    public int compareTo(ii o) {
      if (first != o.first) {
        return first < o.first ? -1 : 1;
      }
      if (second != o.second) {
        return second < o.second ? -1 : 1;
      }
      return 0;
    }


    public String toString() {
      return "{" +
          "first=" + first +
          ", second=" + second +
          '}';
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
}