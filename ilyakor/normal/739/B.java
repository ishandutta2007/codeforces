import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
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

    ArrayList<ii>[] g;
    int[] a;
    int[] d;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
//        int n = 200 * 1000;
//        g = new ArrayList[n];
//        for (int i = 0; i < n; ++i) {
//            g[i] = new ArrayList<>();
//        }
//        a = new int[n];
//        for (int i = 0; i < n; ++i) {
//            a[i] = 1000 * 1000 * 1000;
//        }
//
//        for (int i = 1; i < n; ++i) {
//            int p = i - 1;
//            int w = 1000 * 1000 * 1000;
//            g[p].add(new ii(w, i));
//        }
//        d = new int[n];

      int n = in.nextInt();
      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
      }
      for (int i = 1; i < n; ++i) {
        int p = in.nextInt() - 1;
        int w = in.nextInt();
        g[p].add(new ii(w, i));
      }
      d = new int[n];
      Arrays.fill(d, -1);
      dfs(0);
      for (int x : d) {
        out.print(x + " ");
      }
      out.printLine();
    }

    private TaskB.Set dfs(int x) {
      TaskB.Set[] sets = new TaskB.Set[g[x].size()];
      int ind = -1, val = -1;
      for (int i = 0; i < g[x].size(); ++i) {
        sets[i] = dfs(g[x].get(i).second);
        sets[i].delta -= g[x].get(i).first;
        sets[i].clean();
        if (sets[i].s.isEmpty()) {
          continue;
        }
        if (sets[i].s.size() > val) {
          val = sets[i].s.size();
          ind = i;
        }
      }
      TaskB.Set s;
      if (ind == -1) {
        s = new TaskB.Set();
      } else {
        s = sets[ind];
      }
      for (int i = 0; i < sets.length; ++i) {
        if (i != ind) {
          s.merge(sets[i]);
        }
      }
      s.clean();
      d[x] = s.s.size();
      s.s.add(new TaskB.Entry(a[x] - s.delta, x));
      return s;
    }

    static class Entry implements Comparable<TaskB.Entry> {

      long first;
      int second;

      public Entry(long x, int y) {
        this.first = x;
        this.second = y;
      }


      public boolean equals(Object o) {
        if (this == o) {
          return true;
        }
        if (o == null || getClass() != o.getClass()) {
          return false;
        }

        TaskB.Entry entry = (TaskB.Entry) o;

        if (first != entry.first) {
          return false;
        }
        return second == entry.second;

      }


      public int hashCode() {
        int result = (int) (first ^ (first >>> 32));
        result = 31 * result + second;
        return result;
      }


      public int compareTo(TaskB.Entry o) {
        int res = Long.compare(first, o.first);
        if (res != 0) {
          return res;
        }
        return Long.compare(second, o.second);
      }

    }

    static class Set {

      TreeSet<TaskB.Entry> s;
      long delta;

      public Set() {
        s = new TreeSet<>();
        delta = 0;
      }

      void merge(TaskB.Set other) {
        if (s.size() < other.s.size()) {
          other.merge(this);
          s = other.s;
          delta = other.delta;
          return;
        }
        for (TaskB.Entry x : other.s) {
          x.first += other.delta - delta;
          s.add(x);
        }
      }

      void clean() {
        while (!s.isEmpty() && s.first().first + delta < 0) {
          s.remove(s.first());
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