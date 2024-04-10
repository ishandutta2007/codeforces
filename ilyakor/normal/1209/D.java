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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      boolean[] u = new boolean[n];
      DisjointSets dsu = new DisjointSets(n);
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        u[x] = true;
        u[y] = true;
        if (dsu.root(x) != dsu.root(y)) {
          dsu.unite(x, y);
        }
      }
      int res = m;
      for (int i = 0; i < n; ++i) {
        if (u[i]) {
          --res;
          if (dsu.root(i) == i) {
            ++res;
          }
        }
      }
      out.printLine(res);
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

  static class DisjointSets {

    int[] p;
    int[] rank;

    public DisjointSets(int size) {
      p = new int[size];
      for (int i = 0; i < size; i++) {
        p[i] = i;
      }
      rank = new int[size];
    }

    public DisjointSets(int[] p, int[] rank) {
      this.p = p;
      this.rank = rank;
    }

    public int root(int x) {
      while (x != p[x]) {
        x = p[x];
      }
      return x;
    }

    public void unite(int a, int b) {
      a = root(a);
      b = root(b);
      if (a == b) {
        return;
      }
      if (rank[a] < rank[b]) {
        p[a] = b;
      } else {
        p[b] = a;
        if (rank[a] == rank[b]) {
          ++rank[a];
        }
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
}