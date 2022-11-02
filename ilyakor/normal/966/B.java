import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int x1 = in.nextInt();
      int x2 = in.nextInt();
      ii[] a = new ii[n];
      for (int i = 0; i < n; ++i) {
        a[i] = new ii(-in.nextInt(), i);
      }
      Arrays.sort(a);
      for (int i = 0; i < n; ++i) {
        a[i].first = -a[i].first;
      }
      int[] d1 = new int[n + 1];
      int[] d2 = new int[n + 1];
      int l = 0;
      for (int k = 0; k <= n; ++k) {
        while (l < n && a[l].first * (long) k >= x1) {
          ++l;
        }
        d1[k] = l;
      }
      l = 0;
      for (int k = 0; k <= n; ++k) {
        while (l < n && a[l].first * (long) k >= x2) {
          ++l;
        }
        d2[k] = l;
      }

      int mk1 = n + 1, mk2 = n + 1;
      for (int k = 1; k < n; ++k) {
        if (d1[k] >= k) {
          mk1 = Math.min(mk1, k);
        }
        if (d2[k] >= k) {
          mk2 = Math.min(mk2, k);
        }
      }
      if (mk1 > n || mk2 > n) {
        out.printLine("No");
        return;
      }

      for (int k1 = 1; k1 < n; ++k1) {
        if (d1[k1] < k1) {
          continue;
        }
        if (mk2 > d1[k1] - k1) {
          continue;
        }
        out.printLine("Yes");
        out.printLine(k1 + " " + mk2);
        for (int i = mk2; i < mk2 + k1; ++i) {
          out.print((a[i].second + 1) + " ");
        }
        out.printLine();
        for (int i = 0; i < mk2; ++i) {
          out.print((a[i].second + 1) + " ");
        }
        out.printLine();
        return;
      }
      for (int k2 = 1; k2 < n; ++k2) {
        if (d2[k2] < k2) {
          continue;
        }
        if (mk1 > d2[k2] - k2) {
          continue;
        }
        out.printLine("Yes");
        out.printLine(mk1 + " " + k2);
        for (int i = 0; i < mk1; ++i) {
          out.print((a[i].second + 1) + " ");
        }
        out.printLine();
        for (int i = mk1; i < mk1 + k2; ++i) {
          out.print((a[i].second + 1) + " ");
        }
        out.printLine();
        return;
      }

      out.printLine("No");
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
}