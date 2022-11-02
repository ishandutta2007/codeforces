import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Random;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    static final int BUBEN = 2;
    Random random;
    int[] mods;
    int[][] d;
    int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      Random rnd = new Random(0xdead);
      long seed = 57;
      n = in.nextInt();
      int q = in.nextInt();
      // n = 10000;
      // int q = 10000;
      seed = seed * 43 + n;
      seed = seed * 43 + q;
      ArrayList<Integer>[] ops = new ArrayList[n + 1];
      for (int i = 0; i < ops.length; ++i) {
        ops[i] = new ArrayList<>();
      }
      for (int i = 0; i < q; ++i) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        int x = in.nextInt();
        // int l = rnd.nextInt(n);
        // int r = rnd.nextInt(n);
        // if (l > r) { int tmp = l; l = r; r = tmp; }
        // int x = rnd.nextInt(n) + 1;
        ops[l].add(x);
        ops[r + 1].add(-x);
      }
      random = new Random(seed);
      mods = new int[BUBEN];
      d = new int[BUBEN][n + 1];
      for (int i = 0; i < BUBEN; ++i) {
        mods[i] = random.nextInt(900 * 1000 * 1000) + 100 * 1000 * 1000;
        d[i][0] = 1;
      }
      boolean[] can = new boolean[n + 1];
      for (int i = 0; i < n; ++i) {
        for (int x : ops[i]) {
          apply(x);
        }
        for (int j = 0; j <= n; ++j) {
          if (!can[j]) {
            boolean ok = false;
            for (int t = 0; t < BUBEN; ++t) {
              if (d[t][j] != 0) {
                ok = true;
                break;
              }
            }
            if (ok) {
              can[j] = true;
            }
          }
        }
      }
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (can[i]) {
          ++cnt;
        }
      }
      out.printLine(cnt);
      for (int i = 1; i <= n; ++i) {
        if (can[i]) {
          out.print(i + " ");
        }
      }
      out.printLine();
    }

    private void apply(int x) {
      if (x > 0) {
        for (int t = 0; t < BUBEN; ++t) {
          int m = mods[t];
          int[] line = d[t];
          for (int i = n; i >= x; --i) {
            line[i] += line[i - x];
            if (line[i] >= m) {
              line[i] -= m;
            }
          }
        }
      } else {
        for (int t = 0; t < BUBEN; ++t) {
          int m = mods[t];
          int[] line = d[t];
          for (int i = 0; i <= n + x; ++i) {
            line[i - x] -= line[i];
            if (line[i - x] < 0) {
              line[i - x] += m;
            }
          }
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