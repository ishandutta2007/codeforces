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


struct Dancer {
  int g, p, t;
  int id;
  int diff;
}

struct Pt {
  int x, y;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const W = readInt();
      const H = readInt();
      auto D = new Dancer[N];
      foreach (i; 0 .. N) {
        D[i].g = readInt();
        D[i].p = readInt();
        D[i].t = readInt();
        D[i].id = i;
      }
      
      foreach (i; 0 .. N) {
        D[i].diff = D[i].t - D[i].p;
      }
      D.sort!((a, b) =>
          (a.diff != b.diff) ? (a.diff < b.diff)
                             : (a.g != b.g) ? (a.g > b.g)
                                            : (a.g == 2) ? (a.p > b.p) : (a.p < b.p));
      
      auto ans = new Pt[N];
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && D[i].diff == D[j].diff; ++j) {}
        debug {
          writeln("D[i .. j] = ", D[i .. j]);
        }
        Pt[] ps;
        foreach (k; i .. j) {
          ps ~= (D[k].g == 1) ? Pt(D[k].p, H) : Pt(W, D[k].p);
        }
        ps.sort!((p, q) => (p.x != q.x) ? (p.x < q.x) : (p.y > q.y));
        debug {
          writeln("ps = ", ps);
        }
        foreach (k; i .. j) {
          ans[D[k].id] = ps[k - i];
        }
      }
      
      foreach (i; 0 .. N) {
        writeln(ans[i].x, " ", ans[i].y);
      }
    }
  } catch (EOFException e) {
  }
}