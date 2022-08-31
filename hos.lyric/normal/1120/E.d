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
  debug {
    enum limA = 20;
    enum limN = 10L^^7;
    
    long calc(long n) {
      long ret;
      for (; n > 0; n /= 10) {
        ret += n % 10;
      }
      return ret;
    }
    /*
    auto anss = new long[limA];
    foreach (a; 1 .. limA) {
      foreach (n; 1 .. limN) {
        if (a * calc(a * n) == calc(n)) {
          anss[a] = n;
          break;
        }
      }
    }
    writeln(anss);
    */
/*
[0, 1, 6, 6669, 75, 0, 0, 14286, 125, 0, 0, 0, 0, 7693077, 0, 0, 0, 5882353, 0, 0]
*/
    /*
    foreach (a; 1 .. limA) {
      writeln("a = ", a);
      foreach (u; 0 .. a) {
        write(u, " ->");
        foreach (x; 0 .. 10) {
          const y = (u * 10 + x) / a;
          const v = (u * 10 + x) % a;
          write(" ", [v, a * x - y]);
        }
        writeln();
      }
    }
    */
  }
  
  try {
    for (; ; ) {
      const A = readInt();
      
      const lim = 2 * A;
      alias Prev = Tuple!(int, "r", int, "s", int, "x");
      auto prev = new Prev[][](A, lim + 1 + lim);
      foreach (r; 0 .. A) foreach (s; -lim .. lim + 1) {
        prev[r][lim + s] = Prev(-1, -1, -1);
      }
      
      auto que = new int[A * (lim + 1 + lim) * 2];
      int qb, qe;
      foreach (x; 1 .. 10) {
        const rr = x % A;
        const ss = A * x - x / A;
        if (-lim <= ss && ss <= lim) {
          if (prev[rr][lim + ss].x == -1) {
            prev[rr][lim + ss] = Prev(-2, -2, x);
            que[qe++] = rr;
            que[qe++] = ss;
          }
        }
      }
      for (; qb != qe; ) {
        const r = que[qb++];
        const s = que[qb++];
        debug {
          // writeln(r, " ", s, " ", prev[r][lim + s]);
        }
        if (r == 0 && s == 0) {
          break;
        }
        foreach (x; 0 .. 10) {
          const rr = (r * 10 + x) % A;
          const y = (r * 10 + x) / A;
          const ss = s + A * x - y;
          if (-lim <= ss && ss <= lim) {
            if (prev[rr][lim + ss].x == -1) {
              prev[rr][lim + ss] = Prev(r, s, x);
              que[qe++] = rr;
              que[qe++] = ss;
            }
          }
        }
      }
      
      if (prev[0][lim + 0].x == -1) {
        writeln(-1);
      } else {
        int[] xs;
        for (int r = 0, s = 0; r != -2; ) {
          const p = prev[r][lim + s];
          xs ~= p.x;
          r = p.r;
          s = p.s;
        }
        xs.reverse;
        int[] ys;
        {
          int r = 0, s = 0;
          foreach (x; xs) {
            const rr = (r * 10 + x) % A;
            const y = (r * 10 + x) / A;
            const ss = s + A * x - y;
            if (!ys.empty || y != 0) {
              ys ~= y;
            }
            r = rr;
            s = ss;
          }
        }
        foreach (y; ys) {
          write(y);
        }
        writeln();
      }
    }
  } catch (EOFException e) {
  }
}