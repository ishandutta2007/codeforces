import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      String[] a1 = new String[n];
      String[] a2 = new String[n];
      HashMap<String, Integer> cnt = new HashMap<>();
      for (int i = 0; i < n; ++i) {
        String s1 = in.nextToken();
        String s2 = in.nextToken();
        a1[i] = s1.substring(0, 3);
        a2[i] = s1.substring(0, 2) + s2.substring(0, 1);
        if (cnt.containsKey(a1[i])) {
          cnt.put(a1[i], cnt.get(a1[i]) + 1);
        } else {
          cnt.put(a1[i], 1);
        }
      }
      String[] d = new String[n];
      Arrays.fill(d, null);
      HashSet<String> forbidden = new HashSet<>();
      HashSet<String> forbidden1 = new HashSet<>();
      for (int i = 0; i < n; ++i) {
        if (cnt.get(a1[i]) > 1) {
          forbidden1.add(a1[i]);
        }
      }
      while (true) {
        boolean ch = false;
        for (int i = 0; i < n; ++i) {
          if (d[i] != null) {
            continue;
          }
          boolean f1 = forbidden.contains(a1[i]) || forbidden1.contains(a1[i]);
          boolean f2 = forbidden.contains(a2[i]);
          if (f1 && f2) {
            out.printLine("NO");
            return;
          }
          if (f1) {
            d[i] = a2[i];
            forbidden.add(a2[i]);
            ch = true;
          } else if (f2) {
            d[i] = a1[i];
            forbidden.add(a1[i]);
            ch = true;
          }
        }
        if (!ch) {
          break;
        }
      }
      for (int i = 0; i < n; ++i) {
        if (d[i] == null) {
          d[i] = a1[i];
        }
      }
      out.printLine("YES");
      for (int i = 0; i < n; ++i) {
        out.printLine(d[i]);
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

    public String nextToken() {
      int c = readSkipSpace();
      StringBuilder sb = new StringBuilder();
      while (!isSpace(c)) {
        sb.append((char) c);
        c = read();
      }
      return sb.toString();
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