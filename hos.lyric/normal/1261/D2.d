import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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

enum MO = 998244353;
alias Mint = ModInt!MO;

enum LIM = 10^^6;
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

void main() {
  prepare();
  
  try {
    for (; ; ) {
      const N = readInt();
      const K = readLong();
      auto H = new int[N];
      foreach (i; 0 .. N) {
        H[i] = readInt();
      }
      
      int l, m;
      foreach (i; 0 .. N) {
        const ha = H[i];
        const hb = H[(i + 1) % N];
        if (ha == hb) {
          ++l;
        } else {
          ++m;
        }
      }
      debug {
        writeln("l = ", l, ", m = ", m);
      }
      
      auto pw2 = new Mint[m + 1];
      auto pwKm2 = new Mint[m + 1];
      pw2[0] = 1;
      pwKm2[0] = 1;
      foreach (i; 1 .. m + 1) {
        pw2[i] = pw2[i - 1] * Mint(2);
        pwKm2[i] = pwKm2[i - 1] * Mint(K - 2);
      }
      Mint ans;
      foreach (z; 0 .. m + 1) {
        /*
          x + y = z
          x < y
        */
        Mint prod = binom(m, z) * pwKm2[m - z];
        Mint s = pw2[z];
        if (z % 2 == 0) {
          s -= binom(z, z / 2);
        }
        s *= inv[2];
        ans += prod * s;
      }
      
      ans *= Mint(K)^^l;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}