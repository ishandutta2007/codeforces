import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
      long[] a = new long[n];
      ArrayList<TaskD.Event> events = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextLong();
      }
      Arrays.sort(a);
      for (int i = 1; i < n; ++i) {
        events.add(new TaskD.Event(a[i] - a[i - 1], -1));
      }
      int q = in.nextInt();
      long[] res = new long[q];
      Arrays.fill(res, -1);
      for (int i = 0; i < q; ++i) {
        long l = in.nextLong(), r = in.nextLong();
        events.add(new TaskD.Event(r - l + 1, i));
      }
      Collections.shuffle(events);
      Collections.sort(events);
      long total = 0;
      long prev = 0;
      long active = n;
      for (TaskD.Event e : events) {
        total += (e.t - prev) * active;
        prev = e.t;
        if (e.q == -1) {
          --active;
          if (active < 0) {
            throw new RuntimeException();
          }
        } else {
          res[e.q] = total;
        }
      }
      for (long x : res) {
        out.print(x + " ");
      }
      out.printLine();
    }

    static class Event implements Comparable<TaskD.Event> {

      long t;
      int q;

      public Event(long t, int q) {
        this.t = t;
        this.q = q;
      }

      public int compareTo(TaskD.Event o) {
        return Long.compare(t, o.t);
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