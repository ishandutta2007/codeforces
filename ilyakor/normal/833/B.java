import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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

    int n;
    int k;
    int[] a;
    int[][] d;
    int[] next;
    PersistentTree.Node[] treeR;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
//        n = 35000;
//        k = 50;
//        Random random = new Random(0xdead);
      n = in.nextInt();
      k = in.nextInt();
      a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
//            a[i] = random.nextInt(10) + 1;
      }

      next = new int[n + 1];
      int[] nv = new int[n + 1];
      Arrays.fill(nv, n);
      for (int i = n - 1; i >= 0; --i) {
        next[i] = nv[a[i]];
        nv[a[i]] = i;
      }

      treeR = new PersistentTree.Node[n + 1];
      treeR[0] = PersistentTree.build(0, n + 1);
      int[] prev = new int[n + 1];
      Arrays.fill(prev, -1);
      for (int i = 0; i < n; ++i) {
        int x = a[i];
        PersistentTree.Node n1 = PersistentTree.set(i, 1, treeR[i], 0, n);
        PersistentTree.Node n2;
        if (prev[x] == -1) {
          n2 = n1;
        } else {
          n2 = PersistentTree.set(prev[x], 0, n1, 0, n);
        }
        prev[x] = i;
        treeR[i + 1] = n2;
      }

      d = new int[k + 1][n + 1];
      for (int i = 1; i <= k; ++i) {
        compute(i, 0, n, 0, n + 1);
      }

//        int[][] D = new int[k + 1][n + 1];
//        for (int i = 1; i <= k; ++i)
//            for (int j = 0; j <= n; ++j)
//                for (int t = 0; t < j; ++t)
//                    D[i][j] = Math.max(D[i][j], D[i - 1][t] + cost(t, j));
//        Assert.assertTrue(D[k][n] == d[k][n]);

      out.printLine(d[k][n]);
    }

    private void compute(int ind, int l, int r, int optL, int optR) {
      if (l > r) {
        return;
      }
      int m = (l + r) / 2;
      int opt = optL;
//        optL = 0;
//        optR = n;
      int curCost = cost(optL, m);
      for (int i = optL; i <= optR && i <= m; ++i) {
        int val = d[ind - 1][i] + curCost;
        if (d[ind][m] <= val) {
          d[ind][m] = val;
          opt = i;
        }
        if (next[i] >= m) {
          --curCost;
        }
      }
      compute(ind, l, m - 1, optL, opt);
      compute(ind, m + 1, r, opt, optR);
    }

    int cost(int l, int r) {
      if (l >= r) {
        return 0;
      }
      int res = PersistentTree.sum(l, r - 1, treeR[r], 0, n);
//        HashSet<Integer> vals = new HashSet<>();
//        for (int i = l; i < r; ++i)
//            vals.add(a[i]);
//        Assert.assertTrue(vals.size() == res);
      return res;
    }

  }

  static class PersistentTree {

    public static PersistentTree.Node build(int left, int right) {
      if (left == right) {
        return new PersistentTree.Node(0);
      }
      int mid = (left + right) >> 1;
      return new PersistentTree.Node(build(left, mid), build(mid + 1, right));
    }

    public static int sum(int a, int b, PersistentTree.Node root, int left, int right) {
      if (a == left && b == right) {
        return root.sum;
      }
      int mid = (left + right) >> 1;
      if (a <= mid && b > mid) {
        return sum(a, Math.min(b, mid), root.left, left, mid) + sum(Math.max(a, mid + 1), b,
            root.right, mid + 1, right);
      } else if (a <= mid) {
        return sum(a, Math.min(b, mid), root.left, left, mid);
      } else if (b > mid) {
        return sum(Math.max(a, mid + 1), b, root.right, mid + 1, right);
      } else {
        throw new RuntimeException();
      }
    }

    public static PersistentTree.Node set(int pos, int value, PersistentTree.Node root, int left,
        int right) {
      if (left == right) {
        return new PersistentTree.Node(value);
      }
      int mid = (left + right) >> 1;
      if (pos <= mid) {
        return new PersistentTree.Node(set(pos, value, root.left, left, mid), root.right);
      } else {
        return new PersistentTree.Node(root.left, set(pos, value, root.right, mid + 1, right));
      }
    }

    public static class Node {

      PersistentTree.Node left;
      PersistentTree.Node right;
      int sum;

      Node(int value) {
        this.sum = value;
      }

      Node(PersistentTree.Node left, PersistentTree.Node right) {
        this.left = left;
        this.right = right;
        if (left != null) {
          sum += left.sum;
        }
        if (right != null) {
          sum += right.sum;
        }
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
}