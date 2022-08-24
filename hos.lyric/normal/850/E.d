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


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const A = readToken();
      
      auto fs = new Mint[][](2, 1 << N);
      foreach (s; 0 .. 2) {
        foreach (h; 0 .. 1 << N) {
          if (A[h] - '0' == s) {
            fs[s][h] = 1;
          }
        }
        debug {
          writefln("fs[%s] = %s", s, fs[s]);
        }
      }
      
      foreach (s; 0 .. 2) {
        foreach (i; 0 .. N) {
          foreach (h; 0 .. 1 << N) {
            if (!(h & 1 << i)) {
              const tmp = fs[s][h] - fs[s][h | 1 << i];
              fs[s][h] += fs[s][h | 1 << i];
              fs[s][h | 1 << i] = tmp;
            }
          }
        }
      }
      auto gs = new Mint[1 << N];
      foreach (h; 0 .. 1 << N) {
        gs[h] = fs[0][h] * fs[1][h];
      }
      foreach (i; 0 .. N) {
        foreach (h; 0 .. 1 << N) {
          if (!(h & 1 << i)) {
            const tmp = gs[h] - gs[h | 1 << i];
            gs[h] += gs[h | 1 << i];
            gs[h | 1 << i] = tmp;
          }
        }
      }
      gs[] *= Mint(1 << N).inv;
      debug {
        writeln("gs = ", gs);
      }
      
      Mint ans;
      foreach (h; 0 .. 1 << N) {
        ans += gs[h] * (1 << popcnt(h));
      }
      ans *= 3;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}