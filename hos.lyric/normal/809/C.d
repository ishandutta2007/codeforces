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
  import std.conv : to;
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
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
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
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;

enum E = 35;

// < m, < n, < k
Mint solve(long m, long n, long k) {
  debug {
    writefln("solve %s %s %s", m, n, k);
  }
  auto crt0 = new Mint[][][](2, 2, 2);
  auto crt1 = new Mint[][][](2, 2, 2);
  crt0[0][0][0] = 1;
  foreach_reverse (e; 0 .. E) {
    auto nxt0 = new Mint[][][](2, 2, 2);
    auto nxt1 = new Mint[][][](2, 2, 2);
    const mm = cast(int)((m >> e) & 1);
    const nn = cast(int)((n >> e) & 1);
    const kk = cast(int)((k >> e) & 1);
    foreach (s; 0 .. 2) foreach (t; 0 .. 2) foreach (u; 0 .. 2) {
      foreach (x; 0 .. 2) foreach (y; 0 .. 2) {
        const z = x ^ y;
        if ((s || x <= mm) && (t || y <= nn) && (u || z <= kk)) {
          const ss = (s || x < mm) ? 1 : 0;
          const tt = (t || y < nn) ? 1 : 0;
          const uu = (u || z < kk) ? 1 : 0;
          nxt0[ss][tt][uu] += crt0[s][t][u];
          nxt1[ss][tt][uu] += crt1[s][t][u] * 2 + crt0[s][t][u] * z;
        }
      }
    }
    debug {
      if (e <= 5) {
        writeln("e = ", e);
        writeln("nxt0 = ", nxt0);
        writeln("nxt1 = ", nxt1);
      }
    }
    crt0 = nxt0;
    crt1 = nxt1;
  }
  Mint ret;
  ret += crt1[1][1][1];
  ret += crt0[1][1][1];
  return ret;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const X1 = readLong() - 1;
        const Y1 = readLong() - 1;
        const X2 = readLong();
        const Y2 = readLong();
        const K = readLong();
        Mint ans;
        ans += solve(X1, Y1, K);
        ans -= solve(X1, Y2, K);
        ans -= solve(X2, Y1, K);
        ans += solve(X2, Y2, K);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}