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

int N;
Mint[] A;
int[] U, V;

int[][] G;
int[] par;
Mint[][] dp, DP;

void dfs(int u, int p) {
  par[u] = p;
  foreach (v; G[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  auto sums = new Mint[2];
  foreach (v; G[u]) {
    if (v != p) {
      // add dp[v]
      sums[] += dp[v][];
    }
  }
  // calc dp[u]
  dp[u][0] = sums[1];
  dp[u][1] = 1 + sums[0];
}

void DFS(int u, int p) {
  auto sums = new Mint[2];
  foreach (v; G[u]) {
    if (v != p) {
      // add dp[v]
      sums[] += dp[v][];
    }
  }
  if (p != -1) {
    // add DP[u]
    sums[] += DP[u][];
  }
  foreach (v; G[u]) {
    if (v != p) {
      // calc DP[v], removing dp[v]
      sums[] -= dp[v][];
      DP[v][0] = sums[1];
      DP[v][1] = 1 + sums[0];
      sums[] += dp[v][];
    }
  }
  foreach (v; G[u]) {
    if (v != p) {
      DFS(v, u);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new Mint[N];
      foreach (u; 0 .. N) {
        A[u] = Mint(readLong());
      }
      U = new int[N - 1];
      V = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[U[i]] ~= V[i];
        G[V[i]] ~= U[i];
      }
      par = new int[N];
      dp = new Mint[][](N, 2);
      DP = new Mint[][](N, 2);
      const rt = 0;
      dfs(rt, -1);
      DFS(rt, -1);
      debug {
        writeln("rt = ", rt);
        writeln("dp = ", dp);
        writeln("DP = ", DP);
      }
      
      Mint ans;
      foreach (u; 0 .. N) {
        auto sums = new Mint[2];
        Mint[][] seq;
        foreach (v; G[u]) {
          if (v != par[u]) {
            // add dp[v]
            sums[] += dp[v][];
            seq ~= dp[v];
          }
        }
        if (u != rt) {
          // add DP[u]
          sums[] += DP[u][];
          seq ~= DP[u];
        }
        // rooted at u
        Mint sum;
        sum += 1 * 1;
        sum += 1 * sums[0];
        sum += 1 * sums[1];
        foreach (j; 0 .. seq.length) {
          sum += seq[j][0] * 1;
          sum -= seq[j][1] * 1;
          sum += seq[j][0] * (sums[0] - seq[j][0]);
          sum += seq[j][0] * (sums[1] - seq[j][1]);
          sum -= seq[j][1] * (sums[0] - seq[j][0]);
          sum -= seq[j][1] * (sums[1] - seq[j][1]);
        }
        debug {
          writeln(u, ": ", sum);
        }
        ans += A[u] * sum;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}