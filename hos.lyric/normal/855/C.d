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


int N, M, K, X;
int[] U, V;

int[][] G;
Mint[][][] dp;

void dfs(int u, int p) {
  auto crt = new Mint[][](X + 1, 3);
  crt[0][0] = 1;
  foreach (i; G[u]) {
    const v = U[i] ^ V[i] ^ u;
    if (v != p) {
      dfs(v, u);
      auto nxt = new Mint[][](X + 1, 3);
      foreach (x; 0 .. X + 1) foreach (y; 0 .. 3) {
        if (crt[x][y]) {
          foreach (dx; 0 .. X - x + 1) {
            nxt[x + dx][max(y, 0)] += crt[x][y] * dp[v][dx][0];
            nxt[x + dx][max(y, 2)] += crt[x][y] * dp[v][dx][1];
            nxt[x + dx][max(y, 1)] += crt[x][y] * dp[v][dx][2];
          }
        }
      }
      crt = nxt;
    }
  }
  foreach (x; 0 .. X + 1) {
    dp[u][x][0] = (crt[x][0] + crt[x][1] + crt[x][2]) * (K - 1);
    if (x >= 1) {
      dp[u][x][1] = crt[x - 1][0];
    }
    dp[u][x][2] = (crt[x][0] + crt[x][1]) * (M - K);
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      U = new int[N - 1];
      V = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      K = readInt();
      X = readInt();
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[U[i]] ~= i;
        G[V[i]] ~= i;
      }
      
      dp = new Mint[][][](N, X + 1, 3);
      dfs(0, -1);
      Mint ans;
      foreach (x; 0 .. X + 1) foreach (y; 0 .. 3) {
        ans += dp[0][x][y];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}