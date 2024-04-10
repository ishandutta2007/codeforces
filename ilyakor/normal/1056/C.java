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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    int n;
    TaskC.Guy[] a;
    InputReader in;
    OutputWriter out;
    int lastMove;
    int alive;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      this.in = in;
      this.out = out;
      n = in.nextInt();
      int m = in.nextInt();
      a = new TaskC.Guy[2 * n];
      for (int i = 0; i < 2 * n; ++i) {
        a[i] = new TaskC.Guy(in.nextInt(), i);
      }
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1, y = in.nextInt() - 1;
        a[x].partner = a[y];
        a[y].partner = a[x];
      }
      lastMove = -1;
      alive = 2 * n;
      int who = in.nextInt();
      if (who == 2) {
        readMove();
      }
      while (alive > 0) {
        if (lastMove != -1 && a[lastMove].partner != null && !a[lastMove].partner.dead) {
          // Forced.
          makeMove(a[lastMove].partner.id);
          continue;
        }
        int best = -1, best2 = -1;
        for (int i = 0; i < 2 * n; ++i) {
          if (a[i].dead) {
            continue;
          }
          if (a[i].partner == null) {
            if (best == -1 || a[best].p < a[i].p) {
              best = i;
            }
          } else {
            if (best2 == -1 || a[best2].p - a[best2].partner.p < a[i].p - a[i].partner.p) {
              best2 = i;
            }
          }
        }
        if (best2 != -1) {
          makeMove(best2);
        } else {
          makeMove(best);
        }
      }
    }

    private void makeMove(int id) {
      --alive;
      a[id].dead = true;
      out.printLine(id + 1);
      out.flush();
      if (alive > 0) {
        readMove();
      }
    }

    private void readMove() {
      lastMove = in.nextInt() - 1;
      a[lastMove].dead = true;
      --alive;
    }

    static class Guy {

      int p;
      TaskC.Guy partner = null;
      boolean dead = false;
      int id;

      public Guy(int p, int id) {
        this.p = p;
        this.id = id;
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

    public void flush() {
      writer.flush();
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