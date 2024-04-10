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
  try {
    for (; ; ) {
      const R = readInt();
      auto A = new long[4];
      foreach (i; 0 .. 4) {
        A[i] = readLong();
      }
      
      const ASum = A.sum;
      auto P = new Mint[4];
      foreach (i; 0 .. 4) {
        P[i] = Mint(A[i]) / ASum;
      }
      auto PInv = new Mint[4];
      foreach (i; 0 .. 4) {
        PInv[i] = P[i].inv;
      }
      
      const n = 2 * R + 1;
      bool inside(int x, int y) {
        return ((x - R)^^2 + (y - R)^^2 <= R^^2);
      }
      
      auto cs = new Mint[][][](n + 1, n);
      foreach (x; 0 .. n + 1) {
        foreach (y; 0 .. n) {
          if (inside(x - 1, y)) {
            // walk from (x - 1, y)
            cs[x][y] = cs[x - 1][y].dup;
            cs[x][y][n] -= 1;
            if (inside(x - 1, y + 1)) {
              foreach (i; 0 .. n + 1) {
                cs[x][y][i] -= P[1] * cs[x - 1][y + 1][i];
              }
            }
            if (inside(x - 2, y)) {
              foreach (i; 0 .. n + 1) {
                cs[x][y][i] -= P[2] * cs[x - 2][y][i];
              }
            }
            if (inside(x - 1, y - 1)) {
              foreach (i; 0 .. n + 1) {
                cs[x][y][i] -= P[3] * cs[x - 1][y - 1][i];
              }
            }
            cs[x][y][] *= PInv[0];
          } else {
            // out -> [in]
            cs[x][y] = new Mint[n + 1];
            cs[x][y][y] = 1;
          }
        }
      }
      auto a = new Mint[][n];
      foreach (y; 0 .. n) {
        foreach (x; 0 .. n + 1) {
          if (inside(x - 1, y) && !inside(x, y)) {
            // = 0
            a[y] = cs[x][y].dup;
            a[y][n] *= -1;
          }
        }
      }
      
      const x = solveLinearEq(a);
      Mint ans;
      foreach (i; 0 .. n) {
        ans += cs[R][R][i] * x[i];
      }
      ans += cs[R][R][n];
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}