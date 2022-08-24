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


struct ModInt(int M_) {
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op)() const if (op == "-") { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 403;
alias Mint = ModInt!MO;

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


Mint R;
Mint[] RR;

struct Info {
  int num1, len, head;
  Mint val;
  Info opBinary(string op)(const(Info) o) const if (op == "*") {
    Info ret;
    ret.num1 = num1 + o.num1;
    if (len == 0) {
      ret.len = o.len;
      ret.head = (num1 & 1) ^ o.head;
      ret.val = o.val;
    } else if (o.len == 0) {
      ret.len = len;
      ret.head = head;
      ret.val = val;
    } else if ((head ^ (len & 1)) == ((num1 & 1) ^ o.head)) {
      // concat
      ret.len = len + o.len;
      ret.head = head;
      ret.val = val + RR[len] * o.val;
    } else {
      // overlap
      ret.len = len + o.len - 1;
      ret.head = head;
      ret.val = val + RR[len - 1] * o.val;
    }
    return ret;
  }
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const T = readToken();
      const Q = readInt();
      auto A = new int[Q];
      auto B = new int[Q];
      auto L = new int[Q];
      foreach (q; 0 .. Q) {
        A[q] = readInt() - 1;
        B[q] = readInt() - 1;
        L[q] = readInt();
      }
      
      import std.datetime;
      R = 2020 ^ Clock.currStdTime;
      debug {
        writeln("R = ", R);
      }
      RR = new Mint[N + 1];
      RR[0] = 1;
      foreach (i; 1 .. N + 1) {
        RR[i] = RR[i - 1] * R;
      }
      
      auto seg = new SegmentTree!(Info, "a * b")(N, Info(0, 0, 0, Mint(0)));
      foreach (i; 0 .. N) {
        seg.at(i) = (T[i] == '1') ? Info(1, 0, 0, Mint(0)) : Info(0, 1, 0, Mint(1));
      }
      seg.build;
      debug {
        foreach (i; 0 .. N) foreach (j; i + 1 .. N + 1) {
          // writeln(i, " ", j, ": ", seg.query(i, j));
        }
      }
      
      foreach (q; 0 .. Q) {
        const resA = seg.query(A[q], A[q] + L[q]);
        const resB = seg.query(B[q], B[q] + L[q]);
        debug {
          writeln(true, " ", resA, " ", resB);
        }
        const ans = (resA == resB);
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}