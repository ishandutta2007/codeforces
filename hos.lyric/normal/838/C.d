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


struct ModInt {
  static int M;
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

alias Mint = ModInt;

enum LIM = 250_010;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM];
  fac = new Mint[LIM];
  invFac = new Mint[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = -(Mint.M / i) * inv[cast(size_t)(Mint.M % i)];
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
  } else {
    return Mint(0);
  }
}


T[][] zeta(T)(const(T[]) as) {
  const n = bsr(as.length);
  assert(as.length == 1 << n, "zeta: |as| = 2^n must hold");
  auto zas = new T[][](n + 1, 1 << n);
  foreach (h; 0 .. 1 << n) zas[popcnt(h)][h] = as[h];
  foreach (k; 0 .. n + 1) foreach (i; 0 .. n) foreach (h; 0 .. 1 << n) {
    if (!(h & 1 << i)) zas[k][h | 1 << i] += zas[k][h];
  }
  return zas;
}

// Modifies zas
T[] moebius(T)(T[][] zas) {
  const n = cast(int)(zas.length) - 1;
  foreach (k; 0 .. n + 1) foreach (i; 0 .. n) foreach (h; 0 .. 1 << n) {
    if (!(h & 1 << i)) zas[k][h | 1 << i] -= zas[k][h];
  }
  auto as = new T[1 << n];
  foreach (h; 0 .. 1 << n) as[h] = zas[popcnt(h)][h];
  return as;
}

Mint[] subsetMul(const(Mint[]) as, const(Mint[]) bs) {
  const n = bsr(as.length);
  assert(as.length == 1 << n, "subsetMul: |as| = 2^n must hold");
  assert(bs.length == 1 << n, "subsetMul: |bs| = 2^n must hold");
  const zas = zeta(as);
  const zbs = zeta(bs);
  auto zcs = new Mint[][](n + 1, 1 << n);
  foreach (k; 0 .. n + 1) foreach (l; 0 .. n - k + 1) foreach (h; 0 .. 1 << n) {
    zcs[k + l][h] += zas[k][h] * zbs[l][h];
  }
  return moebius(zcs);
}

// Needs inv[1], ..., inv[n]
Mint[] subsetExp(const(Mint[]) as) {
  const n = bsr(as.length);
  assert(as.length == 1 << n, "subsetExp: |as| = 2^n must hold");
  assert(as[0].x == 0, "subsetExp: as[0] = 1 must hold");
  foreach (k; 1 .. n + 1) {
    assert((k * inv[k]).x == 1, "subsetExp: inv must be prepared");
  }
  const zas = zeta(as);
  auto zbs = new Mint[][](n + 1, 1 << n);
  zbs[0][] = Mint(1);
  foreach (h; 0 .. 1 << n) foreach (k; 1 .. n + 1) {
    Mint sum;
    foreach (l; 1 .. k + 1) sum += l * zas[l][h] * zbs[k - l][h];
    zbs[k][h] = inv[k] * sum;
  }
  return moebius(zbs);
}

// Needs inv[1], ..., inv[n]
Mint[] subsetLog(const(Mint[]) as) {
  const n = bsr(as.length);
  assert(as.length == 1 << n, "subsetLog: |as| = 2^n must hold");
  assert(as[0].x == 1, "subsetLog: as[0] = 1 must hold");
  foreach (k; 1 .. n + 1) {
    assert((k * inv[k]).x == 1, "subsetLog: inv must be prepared");
  }
  const zas = zeta(as);
  auto zbs = new Mint[][](n + 1, 1 << n);
  foreach (h; 0 .. 1 << n) foreach (k; 1 .. n + 1) {
    Mint sum;
    foreach (l; 1 .. k) sum += l * zas[k - l][h] * zbs[l][h];
    zbs[k][h] = zas[k][h] - inv[k] * sum;
  }
  return moebius(zbs);
}

// Needs inv[1], ..., inv[n]
Mint[] subsetPow(const(Mint[]) as, Mint e) {
  const n = bsr(as.length);
  assert(as.length == 1 << n, "subsetPow: |as| = 2^n must hold");
  assert(as[0].x == 1, "subsetPow: as[0] = 1 must hold");
  foreach (k; 1 .. n + 1) {
    assert((k * inv[k]).x == 1, "subsetPow: inv must be prepared");
  }
  const zas = zeta(as);
  auto zbs = new Mint[][](n + 1, 1 << n);
  auto fs = new Mint[n + 1], gs = new Mint[n + 1];
  zbs[0][] = Mint(1);
  foreach (h; 0 .. 1 << n) {
    fs[0] = 0;
    foreach (k; 1 .. n + 1) {
      Mint sum;
      foreach (l; 1 .. k) sum += l * zas[k - l][h] * fs[l];
      fs[k] = zas[k][h] - inv[k] * sum;
    }
    foreach (k; 1 .. n + 1) fs[k] *= e;
    foreach (k; 1 .. n + 1) {
      Mint sum;
      foreach (l; 1 .. k + 1) sum += l * fs[l] * zbs[k - l][h];
      zbs[k][h] = inv[k] * sum;
    }
  }
  return moebius(zbs);
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      const P = readInt();
      
      Mint.M = P;
      prepare;
      
      Mint ans = Mint(K)^^N;
      if (N % 2 == 0) {
        int[] es;
        foreach (e; 1 .. bsr(N) + 1) {
          if (N & 1 << e) {
            es ~= e;
          }
        }
        const esLen = cast(int)(es.length);
        auto sums = new int[1 << esLen];
        sums[0] = 0;
        foreach (u; 0 .. esLen) {
          foreach (h; 0 .. 1 << u) {
            sums[h | 1 << u] = sums[h] | 1 << es[u];
          }
        }
        auto as = new Mint[1 << esLen];
        foreach (h; 0 .. 1 << esLen) {
          as[h] = invFac[sums[h]];
        }
        const bs = subsetPow(as, Mint(K));
        ans -= fac[sums[$ - 1]] * bs[$ - 1];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}