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
      if (a < 0) return (this = inv()^^(-a));
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

enum LIM = 1010;
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

Mint[2] mul(Mint[2] a, Mint[2] b) {
  return [a[0] * b[0], a[0] * b[1] + a[1] * b[0]];
}

void main() {
  /*
  debug {
    foreach (n; 1 .. 20 + 1) {
      auto dp0 = new long[][](n + 1, 1 << n);
      auto dp1 = new long[][](n + 1, 1 << n);
      dp0[0][0] = 1;
      foreach (i; 0 .. n) {
        foreach (p; 0 .. 1 << n) {
          {
            int xx = -1;
            foreach (x; 0 .. n) {
              if (!(p & 1 << x)) {
                const l = x - xx;
                dp0[i + 1][p | 1 << x] += dp0[i][p] * l;
                dp1[i + 1][p | 1 << x] += dp0[i][p] * (l * (l - 1) / 2) + dp1[i][p] * l;
                xx = x;
              }
            }
          }
          {
            int xx = n;
            foreach_reverse (x; 0 .. n) {
              if (!(p & 1 << x)) {
                const l = xx - x;
                dp0[i + 1][p | 1 << x] += dp0[i][p] * l;
                dp1[i + 1][p | 1 << x] += dp0[i][p] * (l * (l - 1) / 2) + dp1[i][p] * l;
                xx = x;
              }
            }
          }
        }
      }
      foreach (i; 0 .. n + 1) {
        // writeln(n, " ", i, ": ", dp1[i].sum);
        write(dp1[i].sum, " ");
      }
      writeln;
      stdout.flush;
    }
  }
  //*/
  
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      Mint.M = readInt();
      prepare;
      
      auto dp = new Mint[2][N + 1];
      dp[0] = [Mint(1), Mint(0)];
      foreach (n; 1 .. N + 1) {
        foreach (i; 0 .. n) {
          const num = binom(n - 1, i);
          Mint[2] tmp = mul(dp[i], dp[n - 1 - i]);
          tmp[0] *= num;
          tmp[1] *= num;
          dp[n][0] += tmp[0] * (n + 1);
          dp[n][1] += tmp[0] * ((i + 1) * i / 2 + (n - i) * (n - 1 - i) / 2);
          dp[n][1] += tmp[1] * (n + 1);
        }
      }
      debug {
        writeln("dp = ", dp);
      }
      
      auto DP = new Mint[2][2][][](N + 1, M + 1);
      DP[0][0][0] = [Mint(1), Mint(0)];
      foreach (i; 0 .. N) foreach (j; 0 .. M + 1) {
        if (i >= j) {
          foreach (s; 0 .. 2) {
            DP[i + 1][j][0][0] += DP[i][j][s][0];
            DP[i + 1][j][0][1] += DP[i][j][s][1];
            if (s == 0) {
              foreach (n; 1 .. min(N - i, M - j) + 1) {
                const num = binom(M - j, n);
                Mint[2] tmp = mul(DP[i][j][s], dp[n]);
                tmp[0] *= num;
                tmp[1] *= num;
                DP[i + n][j + n][1][0] += tmp[0];
                DP[i + n][j + n][1][1] += tmp[1];
              }
            }
          }
        }
      }
      Mint ans;
      foreach (s; 0 .. 2) {
        ans += DP[N][M][s][1];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}