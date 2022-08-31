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

struct ModInt(uint M_) {
  import std.conv : to;
  alias M = M_;
  uint x;
  this(ModInt a) { x = a.x; }
  this(uint x_) { x = x_ % M; }
  this(ulong x_) { x = x_ % M; }
  this(int x_) { x = ((x_ %= cast(int)(M)) < 0) ? (x_ + cast(int)(M)) : x_; }
  this(long x_) { x = cast(uint)(((x_ %= cast(long)(M)) < 0) ? (x_ + cast(long)(M)) : x_); }
  ref ModInt opAssign(T)(inout(T) a) if (is(T == uint) || is(T == ulong) || is(T == int) || is(T == long)) { return this = ModInt(a); }
  ref ModInt opOpAssign(string op, T)(T a) {
    static if (is(T == ModInt)) {
      static if (op == "+") { x = ((x += a.x) >= M) ? (x - M) : x; }
      else static if (op == "-") { x = ((x -= a.x) >= M) ? (x + M) : x; }
      else static if (op == "*") { x = cast(uint)((cast(ulong)(x) * a.x) % M); }
      else static if (op == "/") { this *= a.inv(); }
      else static assert(false);
      return this;
    } else static if (op == "^^") {
      if (a < 0) return this = inv()^^(-a);
      ModInt b = this, c = 1U;
      for (long e = a; e; e >>= 1) { if (e & 1) c *= b; b *= b; }
      return this = c;
    } else {
      return mixin("this " ~ op ~ "= ModInt(a)");
    }
  }
  ModInt inv() const {
    uint a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const q = a / b; const c = a - q * b; a = b; b = c; const w = y - cast(int)(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt opUnary(string op)() const {
    static if (op == "+") { return this; }
    else static if (op == "-") { ModInt a; a.x = x ? (M - x) : 0U; return a; }
    else static assert(false);
  }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op, T)(T a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  bool opCast(T: bool)() const { return (x != 0U); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


// n * (n + 1)
// modifies a
Mint[] solveLinearEq(Mint[][] a) {
  const n = cast(int)(a.length);
  foreach (h; 0 .. n) {
    foreach (i; h + 1 .. n) {
      if (a[i][h].x != 0) {
        swap(a[h], a[i]);
        break;
      }
    }
    const r = a[h][h].inv;
    a[h][] *= r;
    foreach (i; h + 1 .. n) {
      foreach_reverse (j; h .. n + 1) {
        a[i][j] -= a[i][h] * a[h][j];
      }
    }
  }
  auto x = new Mint[n];
  foreach_reverse (i; 0 .. n) {
    x[i] = a[i][n];
    foreach (j; i + 1 .. n) {
      x[i] -= a[i][j] * x[j];
    }
  }
  return x;
}


void main() {
  debug {{
    foreach (n; 1 .. 8 + 1) {
      int[][] ptns;
      void dfs(int m, int[] ptn) {
        if (m == 0) {
          ptns ~= ptn;
        } else {
          foreach_reverse (p; 1 .. (ptn.empty ? m : min(m, ptn[$ - 1])) + 1) {
            dfs(m - p, ptn ~ p);
          }
        }
      }
      dfs(n, []);
      const len = cast(int)(ptns.length);
      // writeln(ptns);
      auto a = new Mint[][](len, len + 1);
      a[0][0] = 1;
      foreach (i; 1 .. len) {
        a[i][i] = 1;
        a[i][len] = 1;
        const sz = cast(int)(ptns[i].length);
        foreach (x; 0 .. sz) foreach (y; 0 .. sz) if (x != y) {
          auto ps = ptns[i].dup;
          ps[x] += 1;
          ps ~= 1.repeat(ps[y] - 1).array;
          ps[y] = 1;
          ps.sort.reverse;
          const j = ptns.binarySearch!((ptn) => (ptn <= ps));
          a[i][j] -= Mint(sz * (sz - 1)).inv;
        }
      }
      const es = a.solveLinearEq;
      // writeln(es);
      
      auto fs = new Mint[n + 1];
      foreach (p; 1 .. n + 1) {
        fs[p] = Mint(2)^^(p - 1) - 1;
      }
      foreach (i; 0 .. len) {
        const conjecture = fs[n] - ptns[i].map!(p => fs[p]).sum;
        writeln(ptns[i], " ", es[i], " ", conjecture);
        assert(es[i] == conjecture);
      }
      writeln;
    }
  }}
  
  try {
    for (; ; ) {
      const N = readInt;
      auto P = new int[N];
      foreach (u; 0 .. N) {
        P[u] = readInt - 1;
      }
      
      auto cnt = new int[N];
      foreach (u; 0 .. N) {
        if (P[u] >= 0) {
          ++cnt[P[u]];
        }
      }
      
      auto fs = new Mint[N];
      foreach (p; 0 .. N) {
        fs[p] = Mint(2)^^p - 1;
      }
      Mint ans = fs[N - 1];
      foreach (u; 0 .. N) {
        ans -= fs[cnt[u]];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}