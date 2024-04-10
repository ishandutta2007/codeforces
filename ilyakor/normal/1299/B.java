import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
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
    TaskBReal solver = new TaskBReal();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskBReal {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int[] X = new int[n];
      int[] Y = new int[n];
      long sx = 0, sy = 0;
      HashSet<ComparablePair<Long, Long>> S = new HashSet<>();
      for (int i = 0; i < n; ++i) {
        X[i] = in.nextInt();
        Y[i] = in.nextInt();
        S.add(new ComparablePair<Long, Long>((long) X[i], (long) Y[i]));
        sx += X[i];
        sy += Y[i];
      }
      if (n % 2 != 0) {
        out.printLine("NO");
        return;
      }
      sx *= 2L;
      sy *= 2L;
      if (sx % n != 0 || sy % n != 0) {
        out.printLine("NO");
        return;
      }
      sx /= n;
      sy /= n;
      for (int i = 0; i < n; ++i) {
        long x = sx - X[i], y = sy - Y[i];
        if (!S.contains(new ComparablePair<>(x, y))) {
          out.printLine("NO");
          return;
        }
      }
      // long l2 = len2(X[0], Y[0], X[1], Y[1]);
      // for (int i = 0; i < n; ++i) {
      //     int j = (i + 1) % n;
      //     long cl2 = len2(X[i], Y[i], X[j], Y[j]);
      //     if (l2 != cl2) {
      //         out.printLine("NO");
      //         return;
      //     }
      // }
      // long ang = crossProd(X[0], Y[0], X[1], Y[1], X[2], Y[2]);
      // for (int i = 0; i < n; ++i) {
      //     int j = (i + 1) % n;
      //     int k = (i + 2) % n;
      //     long cang = crossProd(X[i], Y[i], X[j], Y[j], X[k], Y[k]);
      //     if (ang != cang) {
      //         out.printLine("NO");
      //         return;
      //     }
      // }
      out.printLine("YES");
    }

  }

  static class Pair<P, Q> {

    public P first;
    public Q second;

    public Pair() {
    }

    public Pair(P first, Q second) {
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

      Pair pair = (Pair) o;

      if (first != null ? !first.equals(pair.first) : pair.first != null) {
        return false;
      }
      if (second != null ? !second.equals(pair.second) : pair.second != null) {
        return false;
      }

      return true;
    }

    public int hashCode() {
      int result = first != null ? first.hashCode() : 0;
      result = 31 * result + (second != null ? second.hashCode() : 0);
      return result;
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

  static class ComparablePair<P extends Comparable, Q extends Comparable> extends
      Pair<P, Q> implements Comparable<Pair<P, Q>> {

    public ComparablePair() {
    }

    public ComparablePair(P first, Q second) {
      super(first, second);
    }

    public int compareTo(Pair<P, Q> other) {
      int valP = first.compareTo(other.first);
      if (valP != 0) {
        return valP;
      }
      return second.compareTo(other.second);
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