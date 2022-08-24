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

enum MO = 998244353;
alias Mint = ModInt!MO;


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const M = A.sum;
      const invM = Mint(M).inv;
      const invN1 = Mint(N - 1).inv;
      
      // e[i] = 1 + (i/M) e[i-1] + (1-i/M) (1-1/(N-1)) e[i] + (1-i/M) (1/(N_1)) e[i+1]
      auto fs = new Mint[M + 1];
      auto gs = new Mint[M + 1];
      gs[M - 1] = 1;
      foreach_reverse (i; 1 .. M) {
        const probN = i * invM;
        const prob0 = (1 - i * invM) * (1 - invN1);
        const probP = (1 - i * invM) * invN1;
        fs[i - 1] = ((1 - prob0) * fs[i] - probP * fs[i + 1] - 1) / probN;
        gs[i - 1] = ((1 - prob0) * gs[i] - probP * gs[i + 1] - 0) / probN;
      }
      // e[0] = 1 + (1-1/(N-1)) e[0] + (1/(N_1)) e[1]
      const fM1 = (1 - (1 - invN1)) * fs[0] - invN1 * fs[1] - 1;
      const gM1 = (1 - (1 - invN1)) * gs[0] - invN1 * gs[1] - 0;
      const eM1 = -fM1 / gM1;
      auto es = new Mint[M + 1];
      foreach (i; 0 .. M + 1) {
        es[i] = fs[i] + gs[i] * eM1;
      }
      
      Mint ans;
      foreach (i; 0 .. N) {
        ans += es[A[i]];
      }
      ans -= es[0] * (N - 1);
      ans /= N;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}