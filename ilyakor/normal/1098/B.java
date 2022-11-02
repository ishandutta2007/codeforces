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
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {

    int n;
    int m;
    char[][] a;
    char[][] b;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      m = in.nextInt();
      a = new char[n][];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextToken().toCharArray();
      }
      b = new char[n][m];
      int best = n * m + 1;
      char ra00 = 0, ra01 = 0, ra10 = 0, ra11 = 0;
      int rd = -1;
      char[] alphabet = "AGCT".toCharArray();
      for (char a00 : alphabet) {
        for (char a01 : alphabet) {
          if (a00 != a01) {
            for (char a10 : alphabet) {
              if (a00 != a10 && a01 != a10) {
                for (char a11 : alphabet) {
                  if (a00 != a11 && a01 != a11 && a10 != a11) {
                    {
                      b[0][0] = a00;
                      b[0][1] = a01;
                      b[1][0] = a10;
                      b[1][1] = a11;
                      genHor();
                      int cur = diff();
                      if (cur < best) {
                        best = cur;
                        ra00 = a00;
                        ra01 = a01;
                        ra10 = a10;
                        ra11 = a11;
                        rd = 0;
                      }
                    }
                    {
                      b[0][0] = a00;
                      b[0][1] = a01;
                      b[1][0] = a10;
                      b[1][1] = a11;
                      genVert();
                      int cur = diff();
                      if (cur < best) {
                        best = cur;
                        ra00 = a00;
                        ra01 = a01;
                        ra10 = a10;
                        ra11 = a11;
                        rd = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      b[0][0] = ra00;
      b[0][1] = ra01;
      b[1][0] = ra10;
      b[1][1] = ra11;
      if (rd == 0) {
        genHor();
      } else {
        genVert();
      }
      for (int i = 0; i < n; ++i) {
        out.printLine(new String(b[i]));
      }
    }

    private void genHor() {
      for (int i = 2; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
          b[i][j] = b[i % 2][j];
        }
      }
      for (int j = 2; j < m; ++j) {
        int cost01 = 0, cost10 = 0;
        for (int i = 0; i < n; ++i) {
          if (a[i][j] != b[i % 2][j % 2]) {
            ++cost01;
          }
          if (a[i][j] != b[(i + 1) % 2][j % 2]) {
            ++cost10;
          }
        }
        int inc = cost01 <= cost10 ? 0 : 1;
        for (int i = 0; i < n; ++i) {
          b[i][j] = b[(i + inc) % 2][j % 2];
        }
      }
    }

    private void genVert() {
      for (int j = 2; j < m; ++j) {
        for (int i = 0; i < 2; ++i) {
          b[i][j] = b[i][j % 2];
        }
      }
      for (int i = 2; i < n; ++i) {
        int cost01 = 0, cost10 = 0;
        for (int j = 0; j < m; ++j) {
          if (a[i][j] != b[i % 2][j % 2]) {
            ++cost01;
          }
          if (a[i][j] != b[i % 2][(j + 1) % 2]) {
            ++cost10;
          }
        }
        int inc = cost01 <= cost10 ? 0 : 1;
        for (int j = 0; j < m; ++j) {
          b[i][j] = b[i % 2][(j + inc) % 2];
        }
      }
    }

    private int diff() {
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (a[i][j] != b[i][j]) {
            ++res;
          }
        }
      }
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