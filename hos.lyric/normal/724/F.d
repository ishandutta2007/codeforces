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



void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const D = readInt();
      ModInt.M = readInt();
      
      if (N == 1) {
        writeln(1);
        continue;
      }
      
      // R
      auto dp = new ModInt[][](N + 1, D + 1);
      dp[1][0] = 1;
      foreach (n; 1 .. N + 1) {
        auto dpNext = new ModInt[][](N + 1, D + 1);
        foreach (nn; 0 .. N + 1) {
          dpNext[nn][] = dp[nn][];
        }
        const num = dp[n][0] + dp[n][D - 1];
        ModInt mul = 1;
        foreach (k; 1 .. D + 1) {
          mul *= (num + (k - 1));
          mul /= k;
          debug {
            if (N <= 10) {
              writeln(n, " ", k, "; ", num, " ", mul);
            }
          }
          foreach (nn; k * n .. N + 1) {
            foreach (d; k .. D + 1) {
              dpNext[nn][d] += dp[nn - k * n][d - k] * mul;
            }
          }
        }
        dp = dpNext;
      }
      debug {
        if (N <= 10) {
          foreach (n; 1 .. N + 1) {
            writeln(n, ": ", dp[n]);
          }
        }
      }
      
      // R + H(R, 2) = U + R^2
      ModInt ans;
      // R
      ans += (dp[N][1] + dp[N][D]);
      // H(R, 2)
      for (int n = 1; n <= N - n; ++n) {
        if (n == N - n) {
          ans += dp[n][0] * (dp[n][0] + 1) / 2;
          ans += dp[n][D - 1] * (dp[n][D - 1] + 1) / 2;
          ans += dp[n][0] * dp[n][D - 1];
        } else {
          ans += (dp[n][0] + dp[n][D - 1]) * (dp[N - n][0] + dp[N - n][D - 1]);
        }
      }
      // R^2
      foreach (n; 1 .. N) {
        ans -= (dp[n][0] + dp[n][D - 1]) * (dp[N - n][0] + dp[N - n][D - 1]);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}