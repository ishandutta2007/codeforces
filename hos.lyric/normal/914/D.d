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

// T: monoid
// op: T * T -> T
// query(a, b): returns t_a ... t_{b-1}
class SegmentTree(T, alias op) {
  import std.functional : binaryFun;
  alias opFun = binaryFun!op;
  const(T) idT;

  int n;
  T[] ts;
  this(int n_, const(T) idT) {
    this.idT = idT;
    for (n = 1; n < n_; n <<= 1) {}
    ts = new T[n << 1];
    ts[] = idT;
  }
  this(inout(T)[] ts_, const(T) idT) {
    this.idT = idT;
    const n_ = cast(int)(ts_.length);
    for (n = 1; n < n_; n <<= 1) {}
    ts = new T[n << 1];
    ts[0 .. n] = idT;
    ts[n .. n + n_] = ts_[];
    ts[n + n_ .. n << 1] = idT;
    build();
  }
  ref T at(int a) {
    return ts[n + a];
  }
  void build() {
    foreach_reverse (a; 1 .. n) ts[a] = opFun(ts[a << 1], ts[a << 1 | 1]);
  }
  void set(int a, const(T) val) {
    ts[a += n] = val;
    for (; a >>= 1; ) ts[a] = opFun(ts[a << 1], ts[a << 1 | 1]);
  }
  void mulL(int a, const(T) val) {
    set(a, opFun(val, ts[a + n]));
  }
  void mulR(int a, const(T) val) {
    set(a, opFun(ts[a + n], val));
  }
  T query(int a, int b) const {
    T prodL = idT, prodR = idT;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) prodL = opFun(prodL, ts[a++]);
      if (b & 1) prodR = opFun(ts[--b], prodR);
    }
    return opFun(prodL, prodR);
  }
}



void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto seg = new SegmentTree!(int, gcd)(A, 0);
      bool solve(int l, int r, int x) {
        for (; ; ) {
          debug {
            // writeln(l, " ", r, " ", x);
          }
          if (r - l <= 1) {
            return true;
          }
          const mid = (l + r) / 2;
          debug {
            writefln("l = %s, r = %s, x = %s", l, r, x);
            writeln("seg.query(l, mid) = ", seg.query(l, mid));
            writeln("seg.query(mid, r) = ", seg.query(mid, r));
          }
          if (seg.query(l, mid) % x == 0) {
            l = mid;
          } else if (seg.query(mid, r) % x == 0) {
            r = mid;
          } else {
            return false;
          }
        }
      }
      
      debug {
        auto as = A.dup;
      }
      
      const Q = readInt();
      foreach (q; 0 .. Q) {
        const typ = readInt();
        switch (typ) {
          case 1: {
            const l = readInt() - 1;
            const r = readInt();
            const x = readInt();
            const ans = solve(l, r, x);
            writeln(ans ? "YES" : "NO");
            debug {
              const brt = (as[l .. r].count!(a => (a % x != 0)) <= 1);
              assert(brt == ans, format("%s %s %s %s; brt = %s, ans = %s", as, l, r, x, brt, ans));
            }
          } break;
          case 2: {
            const i = readInt() - 1;
            const y = readInt();
            seg.set(i, y);
            debug {
              as[i] = y;
            }
          } break;
          default: assert(false);
        }
      }
    }
  } catch (EOFException e) {
  }
}