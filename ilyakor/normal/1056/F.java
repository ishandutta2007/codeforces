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
    TaskF solver = new TaskF();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class TaskF {

    static final double inf = 1E100;
    static double[][] d = new double[101][1001];

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // Random random = new Random(0xdead);
      // for (int it = 0; it < 10000; ++it) {
      //     int n = random.nextInt(5) + 1;
      //     double C = random.nextDouble() * 10.0;
      //     if (C < 0.001) C = 0.001;
      //     double T = random.nextDouble() * 200000.0;
      //     Entry[] a = new Entry[n];
      //     for (int i = 0; i < n; ++i) {
      //         a[i] = new Entry(random.nextInt(10 * 1000) + 1, random.nextInt(10) + 1);
      //     }
      //     doSolve(n, C, T, a);
      // }

      int n = in.nextInt();
      double C = in.nextDouble();
      double T = in.nextDouble();
      TaskF.Entry[] a = new TaskF.Entry[n];
      for (int i = 0; i < n; ++i) {
        a[i] = new TaskF.Entry(in.nextInt(), in.nextInt());
      }

      int res = doSolve(n, C, T, a);
      out.printLine(res);
    }

    public int doSolve(int n, double C, double T, TaskF.Entry[] a) {
      Arrays.sort(a);
      double[] p09 = new double[n + 1];
      p09[0] = 1.0;
      for (int i = 1; i < p09.length; ++i) {
        p09[i] = p09[i - 1] * 0.9;
      }

      doFill(d, n + 1, n * 10 + 1, inf);
      d[0][0] = 0.0;
      for (int i = 0; i < n; ++i) {
        for (int k = i; k >= 0; --k) {
          for (int cost = 0; cost <= 10 * k; ++cost) {
            double cur = d[k][cost];
            if (cur > inf * 0.5) {
              continue;
            }
            int ncost = cost + a[i].p;
            double val = cur + a[i].a / p09[k + 1];
            if (d[k + 1][ncost] > val) {
              d[k + 1][ncost] = val;
            }
          }
        }
      }
      int res = 0;
      for (int k = 0; k <= n; ++k) {
        for (int cost = res + 1; cost <= k * 10; ++cost) {
          double beta = d[k][cost];

          //double obeta = stupid(k, cost, a);
          //Assert.assertTrue(Math.abs(beta - obeta) / (beta + obeta) < 1E-6);

          if (beta > inf * 0.5) {
            continue;
          }
          double alpha = k * 10.0;
          double D = Math.sqrt(beta * C);
          boolean ok = false;
          {
            double t = (-1.0 + D) / C;
            //double v0 = beta / (1.0 + C * t) + t;
            if (t < 0) {
              t = 0.0;
            } /*else {
                        double v = beta / (1.0 + C * (t - 0.01)) + (t - 0.01);
                        Assert.assertTrue(v >= v0);
                    }*/
            // {
            //     double v = beta / (1.0 + C * (t + 0.01)) + (t + 0.01);
            //     Assert.assertTrue(v >= v0);
            // }
            // {
            //     double v = beta;
            //     Assert.assertTrue(v >= v0);
            // }
            double total = alpha + beta / (1.0 + C * t) + t;
            if (total <= T) {
              ok = true;
            }
          }
          if (ok) {
            res = cost;
          }
        }
      }
      return res;
    }

    private void doFill(double[][] d, int s1, int s2, double val) {
      for (int i = 0; i < s1; ++i) {
        for (int j = 0; j < s2; ++j) {
          d[i][j] = val;
        }
      }
    }

    static class Entry implements Comparable<TaskF.Entry> {

      int a;
      int p;

      public Entry(int a, int p) {
        this.a = a;
        this.p = p;
      }

      public int compareTo(TaskF.Entry o) {
        return -Integer.compare(a, o.a);
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

    public String next() {
      return nextToken();
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

    public double nextDouble() {
      double sgn = 1;
      int c = readSkipSpace();
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      double res = 0;
      while (!isSpace(c) && c != '.') {
        if (c == 'e' || c == 'E') {
          return res * Math.pow(10, nextInt());
        } else if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res = res * 10 + c - '0';
        c = read();
      }
      if (c == '.') {
        c = read();
        double m = 1;
        while (!isSpace(c)) {
          if (c == 'e' || c == 'E') {
            return res * Math.pow(10, nextInt());
          } else if (c < '0' || c > '9') {
            throw new InputMismatchException();
          }
          m /= 10;
          res += (c - '0') * m;
          c = read();
        }
      }
      res *= sgn;
      return res;
    }

  }
}