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

enum MO = 1000000007;
alias Mint = ModInt!MO;


// square matrices
Mint[][] mul(Mint[][] a, Mint[][] b) {
  const size = cast(int)(a.length);
  auto c = new Mint[][](size, size);
  foreach (i; 0 .. size) foreach (k; 0 .. size) foreach (j; 0 .. size) {
    c[i][j] += a[i][k] * b[k][j];
  }
  return c;
}
Mint[] mul(Mint[][] a, Mint[] x) {
  const size = cast(int)(a.length);
  auto y = new Mint[size];
  foreach (i; 0 .. size) foreach (j; 0 .. size) {
    y[i] += a[i][j] * x[j];
  }
  return y;
}
Mint[][] power(Mint[][] a, long e) {
  const size = cast(int)(a.length);
  auto b = new Mint[][](size, size), c = new Mint[][](size, size);
  foreach (i; 0 .. size) foreach (j; 0 .. size) b[i][j] = a[i][j];
  foreach (i; 0 .. size) foreach (j; 0 .. size) c[i][j] = (i == j) ? 1 : 0;
  for (; e; e >>= 1) {
    if (e & 1) c = mul(c, b);
    b = mul(b, b);
  }
  return c;
}


F[] findLinearRecurrence(F)(F[] as) {
  import std.algorithm : min;
  const n = cast(int)(as.length);
  int d, m;
  auto cs = new F[n + 1], bs = new F[n + 1];
  cs[0] = bs[0] = 1;
  F invBef = 1;
  foreach (i; 0 .. n) {
    ++m;
    F dif = as[i];
    foreach (j; 1 .. d + 1) dif += cs[j] * as[i - j];
    if (dif.x != 0) {
      auto csDup = cs.dup;
      const r = dif * invBef;
      foreach (j; m .. n) cs[j] -= r * bs[j - m];
      if (2 * d <= i) {
        d = i + 1 - d;
        m = 0;
        bs = csDup;
        invBef = dif.inv;
      }
    }
  }
  return cs[0 .. d + 1];
}


void main() {
  try {
    for (; ; ) {
      const F = readInt();
      const B = readInt();
      const N = readLong();
      auto P = new long[F];
      foreach (f; 0 .. F) {
        P[f] = readLong();
      }
      auto C = new int[B];
      foreach (b; 0 .. B) {
        C[b] = readInt();
      }
      
      const D = max(C.maxElement, 2);
      auto dp = new Mint[D];
      dp[0] = 1;
      foreach (i; 1 .. D) {
        foreach (c; C) {
          if (i >= c) {
            dp[i] += dp[i - c];
          }
        }
      }
      Mint[] mul(Mint[] fs, Mint[] gs) {
        auto hs = new Mint[2 * D - 1];
        foreach (i; 0 .. D) foreach (j; 0 .. D) {
          hs[i + j] += fs[i] * gs[j];
        }
        foreach_reverse (i; D .. 2 * D - 1) {
          foreach (c; C) {
            hs[i - c] += hs[i];
          }
        }
        return hs[0 .. D];
      }
      
      auto pats = new Mint[2 * D];
      foreach (f; 0 .. F) {
        const k0 = cast(int)(min(2 * D - 1, P[f]));
        auto as = new Mint[D], bs = new Mint[D];
        as[1] = 1;
        bs[0] = 1;
        for (long e = P[f] - k0; e; e >>= 1) {
          if (e & 1) {
            bs = mul(bs, as);
          }
          as = mul(as, as);
        }
        foreach_reverse (k; 0 .. k0 + 1) {
          foreach (i; 0 .. D) {
            pats[k] += dp[i] * bs[i];
          }
          auto bbs = new Mint[D + 1];
          bbs[1 .. D + 1] = bs[];
          foreach (c; C) {
            bbs[D - c] += bbs[D];
          }
          bs = bbs[0 .. D];
        }
      }
      
      auto a = new Mint[][](D, D);
      foreach (u; 0 .. D) foreach (v; 0 .. D) {
        foreach (f; 0 .. F) {
          if (u - P[f] == v) {
            a[u][v] += 1;
          }
        }
        foreach (c; C) {
          if (v < c) {
            a[u][v] += pats[u + (c - v)];
          }
        }
      }
      debug {
        foreach (u; 0 .. D) {
          writeln(a[u]);
        }
      }
      
      /*
      auto aa = a.power(N);
      writeln(aa[0][0]);
      */
      auto DP = new Mint[][](2 * D, D);
      DP[0][0] = 1;
      foreach (n; 1 .. 2 * D) {
        foreach (u; 0 .. D) foreach (v; 0 .. D) {
          DP[n][v] += DP[n - 1][u] * a[u][v];
        }
      }
      auto xs = new Mint[2 * D];
      foreach (n; 0 .. 2 * D) {
        xs[n] = DP[n][0];
      }
      auto ys = xs.findLinearRecurrence;
      if (cast(int)(ys.length) - 1 < 2) {
        ys ~= Mint(0);
      }
      const len = cast(int)(ys.length) - 1;
      Mint[] MUL(Mint[] fs, Mint[] gs) {
        auto hs = new Mint[2 * len - 1];
        foreach (i; 0 .. len) foreach (j; 0 .. len) {
          hs[i + j] += fs[i] * gs[j];
        }
        foreach_reverse (i; len .. 2 * len - 1) {
          foreach (j; 1 .. len + 1) {
            hs[i - j] -= ys[j] * hs[i];
          }
        }
        return hs[0 .. len];
      }
      auto zs = new Mint[len];
      auto ws = new Mint[len];
      zs[1] = 1;
      ws[0] = 1;
      for (long e = N; e; e >>= 1) {
        if (e & 1) {
          ws = MUL(ws, zs);
        }
        zs = MUL(zs, zs);
      }
      Mint ans;
      foreach (i; 0 .. len) {
        ans += xs[i] * ws[i];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}