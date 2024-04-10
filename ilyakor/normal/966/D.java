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
import java.util.HashSet;
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

    ArrayList<Integer>[] g;
    HashSet<ii> edges;
    int[] path;
    int ps;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      //Random random = new Random(0xdead);
      int n = in.nextInt();
      int m = in.nextInt();
      // int n = 300 * 1000;
      // int m = 300 * 1000;
      g = new ArrayList[n];
      edges = new HashSet<>();
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }

      // ArrayList<ii> inp = new ArrayList<>();
      // HashSet<Integer> was = new HashSet<>();
      // was.add(0);
      // was.add(n - 1);
      // int K = 100 * 1000;
      // ArrayList<Integer> nei = new ArrayList<>();
      // for (int i = 0; i < K; ++i) {
      //     int x;
      //     do {
      //         x = random.nextInt(n);
      //     } while (was.contains(x));
      //     inp.add(new ii(0, x));
      //     nei.add(x);
      // }
      // HashSet<ii> wasP = new HashSet<>();
      // for (int i = 0; i < m - K; ++i) {
      //     ii cur;
      //     do {
      //         cur = new ii(nei.get(random.nextInt(nei.size())), nei.get(random.nextInt(nei.size())));
      //     } while (cur.first == cur.second || wasP.contains(cur));
      //     wasP.add(cur);
      //     wasP.add(new ii(cur.second, cur.first));
      //     inp.add(cur);
      // }

      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        // int x = inp.get(i).first;
        // int y = inp.get(i).second;
        g[x].add(y);
        g[y].add(x);
        edges.add(new ii(x, y));
        edges.add(new ii(y, x));
      }
      // if (edges.contains(new ii(0, n - 1))) {
      //     out.printLine(1);
      //     out.printLine(1 + " " + n);
      //     return;
      // }
      int[] q = new int[2 * n];
      int ql = 0, qr = 0;
      q[qr++] = 0;
      int[] d = new int[n];
      int[] from = new int[n];
      Arrays.fill(d, -1);
      Arrays.fill(from, -1);
      d[0] = 0;
      while (qr > ql) {
        int x = q[ql++];
        for (int y : g[x]) {
          if (d[y] == -1) {
            d[y] = d[x] + 1;
            from[y] = x;
            q[qr++] = y;
          }
        }
      }
      if (d[n - 1] != -1 && d[n - 1] <= 4) {
        out.printLine(d[n - 1]);
        ArrayList<Integer> res = new ArrayList<>();
        int cur = n - 1;
        while (cur != -1) {
          res.add(cur);
          cur = from[cur];
        }
        Collections.reverse(res);
        for (int x : res) {
          out.print((x + 1) + " ");
        }
        out.printLine();
        return;
      }
      for (int x : g[0]) {
        for (int y : g[x]) {
          if (y != 0) {
            if (edges.contains(new ii(0, y))) {
              continue;
            }
            out.printLine(4);
            out.printLine(1 + " " + (x + 1) + " " + (y + 1) + " " + 1 + " " + n);
            return;
          }
        }
      }
      DisjointSets dsu = new DisjointSets(n);
      int[] sz = new int[n];
      //Arrays.fill(sz, 1);
      for (int x : g[0]) {
        for (int y : g[x]) {
          if (y != 0) {
            int rx = dsu.root(x), ry = dsu.root(y);
            if (rx != ry) {
              dsu.unite(rx, ry);
              //int r = dsu.root(rx);
              //sz[r] = sz[rx] + sz[ry];
            }
          }
        }
      }
      ArrayList<Integer>[] comps = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        comps[i] = new ArrayList<>();
      }
      boolean[] u = new boolean[n];
      for (int x : g[0]) {
        int r = dsu.root(x);
        for (int y : comps[r]) {
          if (!edges.contains(new ii(x, y))) {
            out.printLine(5);
            // int z = -1;
            // while (true) {
            //     u[y] = true;
            //     int smth = -1;
            //     for (int t : g[y]) if (t != 0) {
            //         if (edges.contains(new ii(t, x))) {
            //             z = t;
            //             break;
            //         }
            //         if (!u[t]) smth = t;
            //     }
            //     if (z != -1) break;
            //     Assert.assertTrue(smth != -1);
            //     y = smth;
            // }
            HashSet<Integer> zs = new HashSet<>(g[x]);
            path = new int[n + 2];
            ps = 0;
            dfs(y, x, u);
            int z = -1;
            for (int Y : path) {
              y = Y;
              for (int t : g[y]) {
                if (t != 0) {
                  if (zs.contains(t)) {
                    z = t;
                    break;
                  }
                }
              }
              if (z != -1) {
                break;
              }
            }
            Assert.assertTrue(z != -1);
            out.printLine(
                1 + " " + (x + 1) + " " + (z + 1) + " " + (y + 1) + " " + (x + 1) + " " + n);
            return;
          }
        }
        comps[r].add(x);
      }
      out.printLine(-1);
    }

    private boolean dfs(int from, int to, boolean[] u) {
      if (from == to) {
        return true;
      }
      u[from] = true;
      path[ps++] = from;
      for (int x : g[from]) {
        if (x != 0) {
          if (u[x]) {
            continue;
          }
          if (dfs(x, to, u)) {
            return true;
          }
        }
      }
      --ps;
      return false;
    }

  }

  static class Assert {

    public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
      if (!flag) {
        throw new AssertionError();
      }
    }

  }

  static class DisjointSets {

    int[] p;
    int[] rank;

    public DisjointSets(int size) {
      p = new int[size];
      for (int i = 0; i < size; i++) {
        p[i] = i;
      }
      rank = new int[size];
    }

    public DisjointSets(int[] p, int[] rank) {
      this.p = p;
      this.rank = rank;
    }

    public int root(int x) {
      while (x != p[x]) {
        x = p[x];
      }
      return x;
    }

    public void unite(int a, int b) {
      a = root(a);
      b = root(b);
      if (a == b) {
        return;
      }
      if (rank[a] < rank[b]) {
        p[a] = b;
      } else {
        p[b] = a;
        if (rank[a] == rank[b]) {
          ++rank[a];
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