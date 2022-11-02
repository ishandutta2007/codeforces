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
    TaskC1 solver = new TaskC1();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC1 {

    InputReader in;
    OutputWriter out;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // Random random = new Random(0xdead);
      // for (int it = 0; it < 10000; ++it) {
      //     int n = 8;
      //     StringBuilder sb = new StringBuilder();
      //     for (int i = 0; i < n; ++i)
      //         sb.append((char)('a' + random.nextInt(26)));
      //     S = sb.toString();
      //     sum = 0;
      //     String res = new String(doSolve(S.length()));
      //     if (sum > (n + 1) * (n + 1))
      //         throw new RuntimeException();
      //     if (!res.equals(S))
      //         throw new RuntimeException();
      // }

      this.in = in;
      this.out = out;

      int n = in.nextInt();
      if (n == 1) {
        char c1 = doQuery(1, 1).get(0)[0];
        out.printLine("! " + c1);
        out.flush();
        return;
      }
      if (n == 2) {
        char c1 = doQuery(1, 1).get(0)[0];
        out.printLine("? 2 2");
        out.flush();
        char c2 = in.nextToken().toCharArray()[0];
        out.printLine("! " + c1 + "" + c2);
        out.flush();
        return;
      }
      if (n == 3) {
        char c1 = doQuery(1, 1).get(0)[0];
        out.printLine("? 2 2");
        out.flush();
        char c2 = in.nextToken().toCharArray()[0];
        out.printLine("? 3 3");
        out.flush();
        char c3 = in.nextToken().toCharArray()[0];
        out.printLine("! " + c1 + "" + c2 + "" + c3);
        out.flush();
        return;
      }
      char[] res = doSolve(n);
      out.printLine("! " + new String(res));
      out.flush();
    }

    public char[] doSolve(int n) {
      char c1 = doQuery(1, 1).get(0)[0];
      char[][] qn = query(1, n);
      int m = 1;
      // int m = n / 2 - 1;
      // if ((n - m) % 2 == 1) ++m;
      char[][] qm = query(m + 1, n);
      char[] res = new char[n];
      char c = c1;
      int pos = 0;
      for (int it = 0; it < n; ++it) {
        res[pos] = c;
        if (it == n - 1) {
          break;
        }
        if (res[n - 1 - pos] == 0) {
          c = other(qn[Math.min(pos, n - 1 - pos)], c);
          pos = n - 1 - pos;
        } else {
          if (res[m + n - 1 - pos] != 0) {
            throw new RuntimeException();
          }
          c = other(qm[Math.min(pos, m + n - 1 - pos) - m], c);
          pos = m + n - 1 - pos;
        }
      }
      return res;
    }

    private char other(char[] a, char c) {
      if (a[0] != c) {
        return a[0];
      }
      return a[1];
    }

    private char[][] query(int l, int r) {
      int n = r - l + 1;
      ArrayList<char[]> output = doQuery(l, r);
      ArrayList<char[]>[] ans = new ArrayList[n + 1];
      for (int i = 0; i < ans.length; ++i) {
        ans[i] = new ArrayList<>();
      }
      for (char[] s : output) {
        Arrays.sort(s);
        ans[s.length].add(s);
      }
      char[][] res = new char[(n + 1) / 2][2];
      int[] cnts = new int[26];
      char[] st = new char[20];
      int ss = 0;
      for (char[] s : ans[n - 1]) {
        char[] os = ans[n].get(0);
        Arrays.fill(cnts, 0);
        for (char c : os) {
          ++cnts[c - 'a'];
        }
        for (char c : s) {
          --cnts[c - 'a'];
        }
        for (int i = 0; i < cnts.length; ++i) {
          if (cnts[i] > 0) {
            st[ss++] = (char) ('a' + i);
          }
        }
      }
      if (ss != 2) {
        throw new RuntimeException();
      }
      res[0][0] = st[0];
      res[0][1] = st[1];
      for (int i = 1; i < res.length; ++i) {
        int len = n - i - 1;
        Arrays.fill(cnts, 0);
        for (char[] s : ans[len]) {
          for (char c : s) {
            ++cnts[c - 'a'];
          }
        }
        for (int j = 0; j < i; ++j) {
          for (char c : res[j]) {
            cnts[c - 'a'] -= j + 1;
          }
        }
        ss = 0;
        for (int j = 0; j < cnts.length; ++j) {
          if (cnts[j] % (i + 2) != 0) {
            st[ss++] = (char) ('a' + j);
          }
        }
        if (ss != 1 && ss != 2) {
          throw new RuntimeException();
        }
        if (ss == 1) {
          st[1] = st[0];
        }
        res[i][0] = st[0];
        res[i][1] = st[1];
      }
      return res;
    }

    ArrayList<char[]> doQuery(int l, int r) {
      // ArrayList<char[]> res = new ArrayList<>();
      // for (int i = l - 1; i <= r - 1; ++i)
      //     for (int j = i; j <= r - 1; ++j)
      //         res.add(S.substring(i, j + 1).toCharArray());
      // sum += res.size();
      // return res;
      out.printLine("? " + l + " " + r);
      out.flush();
      int n = r - l + 1;
      ArrayList<char[]> res = new ArrayList<>();
      for (int i = 0; i < (n * (n + 1)) / 2; ++i) {
        res.add(in.nextToken().toCharArray());
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