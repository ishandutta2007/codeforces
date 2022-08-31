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

/*
  t -> -> -> a t + b
  sum (without last): c t + d
*/
alias Func = Tuple!(Mint, "a", Mint, "b", Mint, "c", Mint, "d");
enum IDENTITY = Func(Mint(1), Mint(0), Mint(0), Mint(0));

// f then g
Func mul(const(Func) f, const(Func) g) {
  return Func(g.a * f.a, g.a * f.b + g.b, f.c + g.c * f.a, f.d + g.c * f.b + g.d);
}

Func power(const(Func) f, long e) {
  Func g = f, h = IDENTITY;
  for (; e; e >>= 1) {
    if (e & 1) h = mul(h, g);
    g = mul(g, g);
  }
  return h;
}

Func calc(long a, long b, const(Func) x, const(Func) y) {
  Func ret;
  if (b == 0) {
    ret = x;
  } else if (a == 0) {
    ret = y;
  } else if (a >= b) {
    ret = calc(a % b, b, x, mul(power(x, a / b), y));
  } else {
    ret = calc(a, b % a, mul(x, power(y, b / a)), y);
  }
  return ret;
}

Mint solve(const(long) N, const(long) K) {
  // t -> t + 1
  enum x = Func(Mint(1), Mint(1), Mint(1), Mint(0));
  // t -> t / 2 (not for sum)
  enum y = Func(Mint(2).inv, Mint(0), Mint(0), Mint(0));
  const g = gcd(N, K);
  const f = power(calc(N / g, K / g, x, y), g);
  const t0 = f.b / (1 - f.a);
  debug {
    writeln("f = ", f, ", t0 = ", t0);
  }
  Mint ans = f.c * t0 + f.d;
  ans /= N;
  ans += 1;
  debug {
    enum z = Mint(2).inv;
    const zk = z^^K;
    Mint brtSum;
    foreach (i; 0 .. N * K) {
      brtSum += (i / K) * z^^(i / N);
    }
    Mint brt;
    brt += brtSum / (1 - zk);
    brt += N * N * (1 - zk) / (1 - z) * zk / (1 - zk)^^2;
    brt *= z;
    brt /= N;
    brt += 1;
    writeln("brt = ", brt);
  }
  return ans;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readLong();
        const K = readLong();
        const ans = solve(N, K);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}