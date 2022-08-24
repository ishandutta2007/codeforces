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


int N;
int[] A, B;

int[][] G;

/*
  dp[u][0][a]: shallowest 0
  dp[u][1][b]: deepest 1 without near 0
  
  color(u) = 0
    - any (0, a)
    - any (1, b) with 1 + b <= K
    becomes (0, 0)
  
  color(u) = 1
    start with (1, 0)
    merge subtres
    - (0, a), (0, a'): (0, min{a, 1 + a'})
    - (0, a), (1, b'):
        (0, a)       if a + 1 + b' <= K
        (1, 1 + b')  if a + 1 + b' >  K
    - (1, b), (0, a'):
        (0, 1 + a')  if a' + 1 + b <= K
        (1, b)       if a' + 1 + b >  K
    - (1, b), (1, b'): (0, max{b, 1 + b'})
*/
int K;
Mint[][][] dp;

void dfs(int u, int p) {
  Mint prod = 1;
  int l = 0;
  auto crt = new Mint[][](2, 0 + 1);
  crt[1][0] = 1;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      const m = cast(int)(dp[v][0].length) - 1;
      // 0
      Mint sum;
      foreach (y; 0 .. m + 1) {
        sum += dp[v][0][y];
        if (1 + y <= K) {
          sum += dp[v][1][y];
        }
      }
      prod *= sum;
      // 1
      const ll = max(l, 1 + m);
      auto nxt = new Mint[][](2, ll + 1);
      foreach (x; 0 .. l + 1) foreach (y; 0 .. m + 1) {
        nxt[0][min(x, 1 + y)] += crt[0][x] * dp[v][0][y];
        ((x + 1 + y <= K) ? nxt[0][x] : nxt[1][1 + y]) += crt[0][x] * dp[v][1][y];
        ((x + 1 + y <= K) ? nxt[0][1 + y] : nxt[1][x]) += crt[1][x] * dp[v][0][y];
        nxt[1][max(x, 1 + y)] += crt[1][x] * dp[v][1][y];
      }
      l = ll;
      crt = nxt;
    }
  }
  dp[u] = new Mint[][](2, l + 1);
  dp[u][0][0] += prod;
  foreach (x; 0 .. l + 1) {
    dp[u][0][x] += crt[0][x];
    dp[u][1][x] += crt[1][x];
  }
}

void main() {
  debug {
    writeln(2^^3 * Mint(499122177));
    writeln(2^^5 * Mint(249561089));
    writeln(2^^10 * Mint(821796866));
  }
  
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      
      dp = new Mint[][][N];
      
      Mint ans;
      for (K = 1; K <= N; ++K) {
        debug {
          writefln("---- K = %s ----", K);
        }
        /*
          < K
          #{S | \forall u \in S, \exists v \not\in S, d(u, v) <= K}
        */
        const rt = 0;
        dfs(rt, -1);
        const sum = dp[rt][0].sum;
        debug {
          writeln("dp = ", dp);
          writeln("sum = ", sum);
        }
        // >= K
        ans += (Mint(2)^^N - sum);
      }
      // -1
      ans -= 1;
      ans /= Mint(2)^^N;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}