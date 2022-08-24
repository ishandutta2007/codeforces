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

enum E = 30;
enum L = 20;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto X = new int[N];
      auto Y = new int[N];
      foreach (i; 0 .. N) {
        X[i] = readInt();
        Y[i] = readInt();
      }
      
      int limX0 = 0, limX1 = 0;
      int limY0 = 0, limY1 = 0;
      foreach (i; 0 .. N) {
        if (X[i] > 0) limX0 += X[i];
        if (X[i] < 0) limX1 -= X[i];
        if (Y[i] > 0) limY0 += Y[i];
        if (Y[i] < 0) limY1 -= Y[i];
      }
      chmax(limX0, 1);
      chmax(limX1, 1);
      chmax(limY0, 1);
      chmax(limY1, 1);
      
      Mint solve(int mx, int my) {
        // pos, smaller (x, y), carry (+x, -x, +y, -y)
        auto dp = new Mint[][][][][][][](E + 1, 2, 2, limX0, limX1, limY0, limY1);
        dp[E][0][0][0][0][0][0] = 1;
        foreach_reverse (e; 0 .. E) {
          const ax = (mx >> e) & 1;
          const ay = (my >> e) & 1;
          foreach (sx; 0 .. 2) foreach (sy; 0 .. 2) {
            foreach (cx0; 0 .. limX0) foreach (cx1; 0 .. limX1)
            foreach (cy0; 0 .. limY0) foreach (cy1; 0 .. limY1)
            {
              foreach (p; 0 .. 1 << N) {
                int ccx0 = cx0, ccx1 = cx1;
                int ccy0 = cy0, ccy1 = cy1;
                foreach (i; 0 .. N) {
                  if ((p >> i) & 1) {
                    if (X[i] > 0) ccx0 += X[i];
                    if (X[i] < 0) ccx1 -= X[i];
                    if (Y[i] > 0) ccy0 += Y[i];
                    if (Y[i] < 0) ccy1 -= Y[i];
                  }
                }
                if ((ccx0 & 1) == (ccx1 & 1) && (ccy0 & 1) == (ccy1 & 1)) {
                  const bx = ccx0 & 1;
                  const by = ccy0 & 1;
                  ccx0 >>= 1;
                  ccx1 >>= 1;
                  ccy0 >>= 1;
                  ccy1 >>= 1;
                  const ssx = (sx ? (bx >= ax) : (bx > ax)) ? 1 : 0;
                  const ssy = (sy ? (by >= ay) : (by > ay)) ? 1 : 0;
                  dp[e][sx][sy][cx0][cx1][cy0][cy1] +=
                      dp[e + 1][ssx][ssy][ccx0][ccx1][ccy0][ccy1];
                }
              }
            }
          }
        }
        return dp[0][0][0][0][0][0][0];
      }
      
      Mint ans;
      ans += solve(M, M);
      ans -= solve(0, M);
      ans -= solve(M, 0);
      ans += 1;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}