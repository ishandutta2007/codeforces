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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      // for (int it = 0; it < 1000; ++it) {
      //     long[] a = gen(10000);
      //     long[] val = solve(Arrays.copyOf(a, a.length));
      //     if (val == null) {
      //         solve(a);
      //     }
      //     Assert.assertTrue(val != null);
      // }
      // for (int i = 1; i < 6; ++i)
      //     System.err.println(Integer.toString((i + 1) ^ i, 2));
      int n = in.nextInt();
      long[] b = new long[n];
      for (int i = 0; i < n; ++i) {
        b[i] = in.nextLong();
      }
      long[] res = solve(b);
      if (res == null) {
        out.printLine("No");
        return;
      }
      out.printLine("Yes");
      for (long x : res) {
        out.print(x + " ");
      }
      out.printLine();
    }

    long[] solve(long[] a) {
      int n = a.length;

      long[][] res = new long[2][n];
      int sz = 0;
      for (int i = 60; i >= 0; --i) {
        long[] prev = res[(i + 1) % 2];
        long[] cur = res[i % 2];
        boolean done = false;
        int nsz = 0;
        int pnt = 0;
        int parity = 0;
        for (int j = 0; j < n; ++j) {
          if (a[j] == -1) {
            continue;
          }
          if ((a[j] >> (long) i) % 2L != 1L) {
            continue;
          }
          if (done) {
            return null;
          }
          cur[nsz++] = a[j];
          a[j] = -1;
          parity = 1 - parity;
          if (pnt >= sz) {
            done = true;
          }
          while (pnt < sz) {
            cur[nsz++] = prev[pnt];
            ++pnt;
            if (((prev[pnt - 1] >> (long) i) % 2L) == 1L) {
              parity = 1 - parity;
            }
            if (parity == 0) {
              break;
            }
            if (pnt == sz) {
              done = true;
            }
          }
        }
        while (pnt < sz) {
          cur[nsz++] = prev[pnt++];
        }
        sz = nsz;
      }
      long[] tmp = Arrays.copyOf(res[0], res[0].length);
      for (int i = 1; i < n; ++i) {
        tmp[i] ^= tmp[i - 1];
        Assert.assertTrue(tmp[i] > tmp[i - 1]);
      }
      return res[0];

      // long cur = 0;
      // for (long x : a) cur ^= x;
      //
      // // ArrayList<Long>[] alive = new ArrayList[65];
      // // for (int i = 0; i < alive.length; ++i)
      // //     alive[i] = new ArrayList<>();
      // // for (int i = 0; i < n; ++i)
      // //     alive[Long.numberOfTrailingZeros(Long.highestOneBit(a[i]))].add(a[i]);
      //
      // // int[][] next = new int[n * 62][2];
      // // int[] cnt = new int[next.length];
      // // int sz = 1;
      // // next[0][0] = -1;
      // // next[0][1] = -1;
      // // for (int i = 0; i < n; ++i) {
      // //     long x = a[i];
      // //     int r = 0;
      // //     ++cnt[r];
      // //     for (int j = 60; j >= 0; --j) {
      // //         int bit = (int) ((x >> (long) j) % 2L);
      // //         if (next[r][bit] == -1) {
      // //             next[r][bit] = sz;
      // //             next[sz][0] = -1;
      // //             next[sz][1] = -1;
      // //             ++sz;
      // //         }
      // //         r = next[r][bit];
      // //         ++cnt[r];
      // //     }
      // // }
      // //
      // for (int i = 0; i < n; ++i) {
      //     res[i] = cur;
      //     // long nx = Long.MAX_VALUE;
      // //     for (int j = 0; j < 61; ++j) {
      // //         if ((cur >> (long) j) % 2L == 1L) {
      // //             int r = 0;
      // //             for (int t = 0; t < 60 - j; ++t) {
      // //                 r = next[r][0];
      // //                 if (r == -1) break;
      // //             }
      // //             if (r == -1) continue;
      // //             r = next[r][1];
      // //             if (r == -1) continue;
      // //             if (cnt[r] == 0) continue;
      // //             nx = 1L << (long) j;
      // //             for (int t = j - 1; t >= 0; --t) {
      // //                 int bit = (int) ((cur >> (long) t) % 2L);
      // //                 if (next[r][bit] == -1 || cnt[next[r][bit]] == 0)
      // //                     bit = bit ^ 1;
      // //                 nx |= ((long) bit) << (long) t;
      // //                 r = next[r][bit];
      // //             }
      // //             nx = cur ^ nx;
      // //             if (nx < cur) break;
      // //         }
      // //     }
      // //     if (nx >= cur)
      // //         return null;
      // //     {
      // //         int r = 0;
      // //         --cnt[r];
      // //         for (int j = 60; j >= 0; --j) {
      // //             int bit = (int) ((nx >> (long) j) % 2L);
      // //             if (next[r][bit] == -1) {
      // //                 next[r][bit] = sz;
      // //                 next[sz][0] = -1;
      // //                 next[sz][1] = -1;
      // //                 ++sz;
      // //             }
      // //             r = next[r][bit];
      // //             --cnt[r];
      // //         }
      // //     }
      // //     cur = nx;
      //     long nx = Long.MAX_VALUE;
      //     int ni = -1;
      //     for (int j = 0; j < n; ++j) {
      //         if (a[j] == -1) continue;
      //         long t = cur ^ a[j];
      //         if (t < nx) {
      //             nx = t;
      //             ni = j;
      //         }
      //     }
      //     if (ni == -1) return null;
      //     if (nx >= cur) return null;
      //     cur ^= a[ni];
      //     a[ni] = -1;
      // }
      // for (int i = 0; i < n - 1; ++i)
      //     res[i] ^= res[i + 1];
      // return res;
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

    public long nextLong() {
      long sgn = 1;
      int c = readSkipSpace();
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res = res * 10L + (long) (c - '0');
        c = read();
      } while (!isSpace(c));
      res *= sgn;
      return res;
    }

  }
}