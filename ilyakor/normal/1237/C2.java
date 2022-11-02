import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
    TaskC1 solver = new TaskC1();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC1 {

    OutputWriter out;
    HashSet<TaskC1.Point> alive;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      this.out = out;

      alive = new HashSet<>();
      int n = in.nextInt();
      ArrayList<TaskC1.Point> a = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        TaskC1.Point p = new TaskC1.Point(in.nextInt(), in.nextInt(), in.nextInt(), i + 1);
        a.add(p);
        // alive.add(p);
      }
      solveX(a);
    }

    void print(TaskC1.Point p1, TaskC1.Point p2) {
      out.printLine(p1.id + " " + p2.id);
      // alive.remove(p1);
      // alive.remove(p2);
      // for (Point p : alive) {
      //     if (bad(p.x, p1.x, p2.x) && bad(p.y, p1.y, p2.y) && bad(p.z, p1.z, p2.z))
      //         throw new RuntimeException();
      // }
    }

    void solveX(ArrayList<TaskC1.Point> a) {
      Collections.sort(a, new Comparator<TaskC1.Point>() {

        public int compare(TaskC1.Point p1, TaskC1.Point p2) {
          if (p1.x != p2.x) {
            return Integer.compare(p1.x, p2.x);
          }
          if (p1.y != p2.y) {
            return Integer.compare(p1.y, p2.y);
          }
          if (p1.z != p2.z) {
            return Integer.compare(p1.z, p2.z);
          }
          return 0;
        }
      });
      ArrayList<TaskC1.Point> remaining = new ArrayList<>();
      ArrayList<TaskC1.Point> cur = new ArrayList<>();
      cur.add(a.get(0));
      for (int i = 1; i < a.size(); ++i) {
        if (cur.get(0).x != a.get(i).x) {
          cur = solveY(cur);
          remaining.addAll(cur);
          cur.clear();
          cur.add(a.get(i));
        } else {
          cur.add(a.get(i));
        }
      }
      cur = solveY(cur);
      remaining.addAll(cur);
      if (remaining.size() % 2 != 0) {
        throw new RuntimeException();
      }
      for (int i = 0; i < remaining.size(); i += 2) {
        print(remaining.get(i), remaining.get(i + 1));
      }
    }

    ArrayList<TaskC1.Point> solveY(ArrayList<TaskC1.Point> a) {
      Collections.sort(a, new Comparator<TaskC1.Point>() {

        public int compare(TaskC1.Point p1, TaskC1.Point p2) {
          if (p1.y != p2.y) {
            return Integer.compare(p1.y, p2.y);
          }
          if (p1.z != p2.z) {
            return Integer.compare(p1.z, p2.z);
          }
          if (p1.x != p2.x) {
            return Integer.compare(p1.x, p2.x);
          }
          return 0;
        }
      });
      ArrayList<TaskC1.Point> remaining = new ArrayList<>();
      ArrayList<TaskC1.Point> cur = new ArrayList<>();
      cur.add(a.get(0));
      for (int i = 1; i < a.size(); ++i) {
        if (cur.get(0).y != a.get(i).y) {
          cur = solveZ(cur);
          remaining.addAll(cur);
          cur.clear();
          cur.add(a.get(i));
        } else {
          cur.add(a.get(i));
        }
      }
      cur = solveZ(cur);
      remaining.addAll(cur);
      for (int i = 0; i + 1 < remaining.size(); i += 2) {
        print(remaining.get(i), remaining.get(i + 1));
      }
      ArrayList<TaskC1.Point> res = new ArrayList<>();
      if (remaining.size() % 2 == 1) {
        res.add(remaining.get(remaining.size() - 1));
      }
      return res;
    }

    ArrayList<TaskC1.Point> solveZ(ArrayList<TaskC1.Point> a) {
      Collections.sort(a, new Comparator<TaskC1.Point>() {

        public int compare(TaskC1.Point p1, TaskC1.Point p2) {
          if (p1.z != p2.z) {
            return Integer.compare(p1.z, p2.z);
          }
          if (p1.x != p2.x) {
            return Integer.compare(p1.x, p2.x);
          }
          if (p1.y != p2.y) {
            return Integer.compare(p1.y, p2.y);
          }
          return 0;
        }
      });
      for (int i = 0; i + 1 < a.size(); i += 2) {
        print(a.get(i), a.get(i + 1));
      }
      ArrayList<TaskC1.Point> res = new ArrayList<>();
      if (a.size() % 2 == 1) {
        res.add(a.get(a.size() - 1));
      }
      return res;
    }

    static class Point {

      int x;
      int y;
      int z;
      int id;

      public Point(int x, int y, int z, int id) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.id = id;
      }

      public boolean equals(Object o) {
        if (this == o) {
          return true;
        }
        if (!(o instanceof TaskC1.Point)) {
          return false;
        }
        TaskC1.Point point = (TaskC1.Point) o;
        return x == point.x &&
            y == point.y &&
            z == point.z &&
            id == point.id;
      }

      public int hashCode() {
        return Objects.hash(x, y, z, id);
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