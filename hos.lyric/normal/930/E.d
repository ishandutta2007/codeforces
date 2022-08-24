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

void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}

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

enum MO = 1000000007;
alias Mint = ModInt!MO;

alias Interval = Tuple!(int, "l", int, "r", int, "s");

void main() {
  try {
    for (; ; ) {
      const K = readLong();
      const M = readInt();
      const N = readInt();
      auto A = new long[M];
      auto B = new long[M];
      foreach (i; 0 .. M) {
        A[i] = readLong() - 1;
        B[i] = readLong();
      }
      auto C = new long[N];
      auto D = new long[N];
      foreach (i; 0 .. N) {
        C[i] = readLong() - 1;
        D[i] = readLong();
      }
      
      auto xs = [0, K] ~ A ~ B ~ C ~ D;
      xs = xs.sort.uniq.array;
      const xsLen = cast(int)(xs.length);
      auto E = new Interval[M + N];
      foreach (i; 0 .. M) {
        E[i] = Interval(xs.lowerBound(A[i]), xs.lowerBound(B[i]), 0);
      }
      foreach (i; 0 .. N) {
        E[M + i] = Interval(xs.lowerBound(C[i]), xs.lowerBound(D[i]), 1);
      }
      E.sort!((a, b) => ((a.r != b.r) ? (a.r < b.r) : (a.l > b.l)));
      debug {
        writeln("xs = ", xs);
        writeln("E = ", E);
      }
      
      auto twos = new Mint[xsLen];
      auto invTwos = new Mint[xsLen];
      foreach (j; 0 .. xsLen) {
        twos[j] = Mint(2)^^xs[j];
        invTwos[j] = twos[j].inv;
      }
      // ovl: overlap > 0
      auto ovls = new Mint[][](2, xsLen);
      auto gaps = new Mint[][](2, xsLen);
      ovls[0].bAdd(0, Mint(1));
      gaps[0].bAdd(0, Mint(1));
      int[] maxLs = [-1, -1];
      foreach (ref e; E) {
        if (chmax(maxLs[e.s], e.l)) {
          Mint now;
          // same
          now += ovls[e.s].bSum(xsLen) - ovls[e.s].bSum(e.l + 1);
          now += gaps[e.s].bSum(e.l + 1) * twos[e.l];
          // diff
          now += gaps[e.s ^ 1].bSum(e.l + 1) * twos[e.l];
          now *= -1;
          ovls[e.s].bAdd(e.r, now);
          gaps[e.s].bAdd(e.r, now * invTwos[e.r]);
        }
      }
      
      Mint ans;
      foreach (s; 0 .. 2) {
        ans += gaps[s].bSum(xsLen) * twos[xsLen - 1];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}