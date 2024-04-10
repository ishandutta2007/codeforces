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
  this(ulong x_) { x = cast(uint)(x_ % M); }
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

enum MO = 998244353;
alias Mint = ModInt!MO;

enum LIM = 2 * 10^^6 + 10;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM];
  fac = new Mint[LIM];
  invFac = new Mint[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = -((Mint.M / i) * inv[cast(size_t)(Mint.M % i)]);
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (n < 0) {
    if (k >= 0) {
      return (-1)^^(k & 1) * binom(-n + k - 1, k);
    } else if (n - k >= 0) {
      return (-1)^^((n - k) & 1) * binom(-k - 1, n - k);
    } else {
      return Mint(0);
    }
  } else {
    if (0 <= k && k <= n) {
      assert(n < LIM);
      return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
    } else {
      return Mint(0);
    }
  }
}



void main() {
  prepare;
  
  /*
  debug {
    foreach (n; 1 .. 5 + 1) {
      auto freq = new int[string][n];
      auto ps = iota(n).array;
      do {
        int[] qs = ps.dup;
        int[][] qss = [qs.dup];
        foreach (k; 0 .. n - 1) {
          foreach (i; 0 .. n - 1) {
            if (qs[i] > qs[i + 1]) {
              swap(qs[i], qs[i + 1]);
            }
          }
          qss ~= qs.dup;
        }
        auto rss = new int[][](n, n);
        foreach (k; 0 .. n) {
          foreach (i; 0 .. n) {
            foreach (j; 0 .. i) if (qss[k][j] > qss[k][i]) {
              ++rss[k][i];
            }
          }
        }
        writeln(qss, " ", rss);
        foreach (k; 0 .. n - 1) {
          auto fs = rss[k].dup;
          auto gs = rss[k + 1].dup;
          fs.sort;
          gs.sort;
          foreach (i; 0 .. n) {
            assert(max(fs[i] - 1, 0) == gs[i]);
          }
        }
        foreach (k; 0 .. n) {
          ++freq[k][rss[k].to!string];
        }
      } while (ps.nextPermutation);
      foreach (k; 0 .. n) {
        foreach (rs, val; freq[k]) {
          writeln(k, " ", rs, ": ", val);
        }
      }
    }
    // return;
  }
  */
  
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        const K = readInt;
        auto V = new int[N];
        foreach (i; 0 .. N) {
          V[i] = readInt;
        }
        
        Mint ans = 1;
        foreach (i; 0 .. N - K) {
          if (~V[i]) {
            if (V[i] == 0) {
              ans *= (K + 1);
            }
          } else {
            ans *= ((K + 1) + i);
          }
        }
        foreach (i; N - K .. N) {
          if (~V[i]) {
            if (V[i] != 0) {
              ans = 0;
            }
          }
          ans *= (N - i);
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}