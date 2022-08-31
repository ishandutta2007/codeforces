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

T[] subsetConvolution(T)(T[] as, T[] bs)
in {
  assert(as.length == bs.length, "subsetConvolution: |as| = |bs| must hold");
  assert(as.length && !(as.length & as.length - 1),
         "subsetConvolution: |as| and |bs| must be a power of two");
}
do {
  import core.bitop : bsr, popcnt;
  const n = bsr(as.length);
  auto fas = new T[][](n + 1, 1 << n);
  foreach (h; 0 .. 1 << n) fas[popcnt(h)][h] += as[h];
  foreach (i; 0 .. n + 1) foreach (j; 0 .. n) foreach (h; 0 .. 1 << n) {
    if (!(h & 1 << j)) fas[i][h | 1 << j] += fas[i][h];
  }
  auto fbs = new T[][](n + 1, 1 << n);
  foreach (h; 0 .. 1 << n) fbs[popcnt(h)][h] += bs[h];
  foreach (i; 0 .. n + 1) foreach (j; 0 .. n) foreach (h; 0 .. 1 << n) {
    if (!(h & 1 << j)) fbs[i][h | 1 << j] += fbs[i][h];
  }
  auto fcs = new T[][](n + 1, 1 << n);
  foreach (i; 0 .. n + 1) foreach (j; 0 .. n - i + 1) foreach (h; 0 .. 1 << n) {
    fcs[i + j][h] += fas[i][h] * fbs[j][h];
  }
  foreach (i; 0 .. n + 1) foreach (j; 0 .. n) foreach (h; 0 .. 1 << n) {
    if (!(h & 1 << j)) fcs[i][h | 1 << j] -= fcs[i][h];
  }
  auto cs = new T[1 << n];
  foreach (h; 0 .. 1 << n) cs[h] = fcs[popcnt(h)][h];
  return cs;
}


enum E = 17;

void main() {
  auto fib = new Mint[1 << E];
  fib[0] = 0;
  fib[1] = 1;
  foreach (j; 2 .. 1 << E) {
    fib[j] = fib[j - 1] + fib[j - 2];
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      auto S = new int[N];
      foreach (i; 0 .. N) {
        S[i] = readInt();
      }
      
      auto freq = new Mint[1 << E];
      foreach (i; 0 .. N) {
        freq[S[i]] += 1;
      }
      
      auto ab = subsetConvolution(freq, freq);
      
      auto c = freq.dup;
      
      auto de = freq.dup;
      foreach (e; 0 .. E) {
        foreach (j; 0 .. 1 << E) {
          if (!(j & 1 << e)) {
            const t = de[j] - de[j | 1 << e];
            de[j] += de[j | 1 << e];
            de[j | 1 << e] = t;
          }
        }
      }
      foreach (j; 0 .. 1 << E) {
        de[j] = de[j] * de[j];
      }
      foreach (e; 0 .. E) {
        foreach (j; 0 .. 1 << E) {
          if (!(j & 1 << e)) {
            const t = de[j] - de[j | 1 << e];
            de[j] += de[j | 1 << e];
            de[j | 1 << e] = t;
          }
        }
      }
      de[] *= Mint(1 << E).inv;
      
      debug {
        writeln("ab = ", ab[0 .. 64]);
        writeln("c = ", c[0 .. 64]);
        writeln("de = ", de[0 .. 64]);
      }
      
      ab[] *= fib[];
      c[] *= fib[];
      de[] *= fib[];
      foreach (e; 0 .. E) {
        foreach (j; 0 .. 1 << E) {
          if (!(j & 1 << e)) {
            ab[j] += ab[j | 1 << e];
            c[j] += c[j | 1 << e];
            de[j] += de[j | 1 << e];
          }
        }
      }
      auto all = new Mint[1 << E];
      foreach (j; 0 .. 1 << E) {
        all[j] = ab[j] * c[j] * de[j];
      }
      foreach (e; 0 .. E) {
        foreach (j; 0 .. 1 << E) {
          if (!(j & 1 << e)) {
            all[j] -= all[j | 1 << e];
          }
        }
      }
      Mint ans;
      foreach (e; 0 .. E) {
        ans += all[1 << e];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}