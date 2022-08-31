import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const Q = readInt();
      auto X = new int[N];
      auto Y = new int[N];
      foreach (i; 0 .. N) {
        X[i] = readInt();
        Y[i] = readInt();
      }
      auto F = new int[Q];
      foreach (q; 0 .. Q) {
        F[q] = readInt();
      }
      
      Y[] -= Y.minElement;
      const maxY = Y.maxElement;
      
      auto xss = new real[][maxY + 1];
      foreach (i; 0 .. N) {
        int x0 = X[i], y0 = Y[i];
        int x1 = X[(i + 1) % N], y1 = Y[(i + 1) % N];
        if (y0 > y1) {
          swap(x0, x1);
          swap(y0, y1);
        }
        foreach (y; y0 .. y1 + 1) {
          // x0 + ((y - y0) / (y1 - y0)) (x1 - x0)
          xss[y] ~= x0 + 1.0L * (y - y0) / (y1 - y0) * (x1 - x0);
        }
      }
      foreach (y; 0 .. maxY + 1) {
        xss[y] = xss[y].sort.uniq.array;
        debug {
          writefln("xss[%s] = %s", y, xss[y]);
        }
        assert(xss[y].length == ((y == 0 || y == maxY) ? 1 : 2));
      }
      
      auto xs = new real[3 * (maxY + 1)];
      foreach (y; 0 .. maxY + 1) {
        if (y == 0 || y == maxY) {
          xss[y] ~= xss[y][0];
        }
        xss[y] = [xss[y][0], (xss[y][0] + xss[y][1]) / 2.0L, xss[y][1]];
        foreach (j; 0 .. 3) {
          xs[y * 3 + j] = xss[y][j];
        }
      }
      xs = xs.sort.uniq.array;
      const xsLen = cast(int)(xs.length) - 1;
      debug {
        writeln("xs = ", xs);
      }
      
      real total = 0.0L;
      auto fs = new real[xsLen + 1];
      auto gs = new real[xsLen + 1];
      fs[] = 0.0L;
      gs[] = 0.0L;
      foreach (y; 0 .. maxY) {
        total += ((xss[y][2] - xss[y][0]) + (xss[y + 1][2] - xss[y + 1][0])) / 2.0L;
        foreach (j; 0 .. 3) {
          real x0 = xss[y][j];
          real x1 = xss[y + 1][j];
          if (x0 > x1) {
            swap(x0, x1);
          }
          const coef = [-1.0L, +2.0L, -1.0L][j];
          if (x0 == x1) {
            fs[xs.lowerBound(x0)] += coef;
          } else {
            gs[xs.lowerBound(x0)] += coef / (x1 - x0);
            gs[xs.lowerBound(x1)] -= coef / (x1 - x0);
          }
        }
      }
      debug {
        writeln("fs = ", fs);
        writeln("gs = ", gs);
      }
      
      auto ans = new real[Q];
      auto qss = new int[][xsLen];
      foreach (q; 0 .. Q) {
        qss[xs.upperBound(F[q]) - 1] ~= q;
      }
      real now0 = total, now1 = 0.0L, now2 = 0.0L;
      foreach (e; 0 .. xsLen) {
        now1 += fs[e];
        now2 += gs[e];
        foreach (q; qss[e]) {
          const dx = F[q] - xs[e];
          ans[q] = now0 + (now1 + now2 * dx / 2.0L) * dx;
        }
        {
          const dx = xs[e + 1] - xs[e];
          now0 += (now1 + now2 * dx / 2.0L) * dx;
          now1 += now2 * dx;
        }
      }
      
      foreach (q; 0 .. Q) {
        writefln("%.12f", ans[q]);
      }
    }
  } catch (EOFException e) {
  }
}