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

// t -> max{t + a, b}
struct T {
  int a, b;
  T opBinary(string op)(const(T) t) const {
    return T(a + t.a, max(b + t.a, t.b));
  }
}
enum INF = 10^^9;
enum ID_T = T(0, -INF);


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt();
      }
      auto Q = new int[N];
      foreach (j; 0 .. N) {
        Q[j] = readInt() - 1;
      }
      
      auto poss = new int[N + 1];
      foreach (i; 0 .. N) {
        poss[P[i]] = i;
      }
      
      auto ans = new int[N];
      auto seg = new SegmentTree!(T, "a * b")(2 * N, ID_T);
      {
        int x = N + 1;
        foreach (j; 0 .. N) {
          for (; max(0 + seg.ts[1].a, seg.ts[1].b) <= 0; ) {
            // add large
            --x;
            seg.set(2 * poss[x], T(1, 0));
            debug {
              writeln(j, " ", x, ": ", seg.ts[1]);
            }
          }
          ans[j] = x;
          // bomb
          seg.set(2 * Q[j] + 1, T(-1, 0));
        }
      }
      foreach (j; 0 .. N) {
        if (j > 0) write(" ");
        write(ans[j]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}