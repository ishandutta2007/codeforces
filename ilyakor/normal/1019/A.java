import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      ArrayList<Integer>[] a = new ArrayList[m];
      for (int i = 0; i < m; ++i) {
        a[i] = new ArrayList<>();
      }
      for (int i = 0; i < n; ++i) {
        int who = in.nextInt() - 1;
        int price = in.nextInt();
        a[who].add(price);
      }
      for (int i = 0; i < m; ++i) {
        Collections.sort(a[i]);
      }
      long res = Long.MAX_VALUE;
      for (int cnt = 1; cnt <= n; ++cnt) {
        int us = a[0].size();
        long cur = 0;
        for (int i = 1; i < m; ++i) {
          for (int j = 0; j <= a[i].size() - cnt; ++j) {
            ++us;
            cur += a[i].get(j);
          }
        }
        if (cur >= res) {
          continue;
        }
        if (us < cnt) {
          ArrayList<Integer> alive = new ArrayList<>();
          for (int i = 1; i < m; ++i) {
            for (int j = Math.max(a[i].size() - cnt + 1, 0); j < a[i].size(); ++j) {
              alive.add(a[i].get(j));
            }
          }
          Collections.sort(alive);
          for (int x : alive) {
            if (us >= cnt) {
              break;
            }
            if (cur >= res) {
              break;
            }
            ++us;
            cur += x;
          }
        }
        if (cur >= res) {
          continue;
        }
        Assert.assertTrue(us >= cnt);
        if (us >= cnt && cur < res) {
          res = cur;
        }
      }
      out.printLine(res);
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
      // if (!flag)
      // while (true);
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