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


struct Info {
  int sz;
  // int[2][2] a;
  int a00, a01, a10, a11;
  Info opBinary(string op)(Info f) const if (op == "*") {
    Info g;
    g.sz = sz + f.sz;
    /*
    foreach (x; 0 .. 2) foreach (y; 0 .. 2) {
      foreach (xx; 0 .. 2 - x) foreach (yy; 0 .. 2 - y) {
        g.a[x + xx][y + yy] += a[x][y] * f.a[xx][yy];
      }
    }
    */
    g.a00 += a00 * f.a00;
    g.a01 += a00 * f.a01;
    g.a10 += a00 * f.a10;
    g.a11 += a00 * f.a11;
    g.a01 += a01 * f.a00;
    g.a11 += a01 * f.a10;
    g.a10 += a10 * f.a00;
    g.a11 += a10 * f.a01;
    g.a11 += a11 * f.a00;
    return g;
  }
  Info up() const {
    Info f;
    f.sz = 1 + sz;
    // f.a[0][1] += a[0][0];
    // f.a[1][0] += a[0][0];
    // f.a[1][1] += a[0][1];
    // f.a[0][0] += a[1][0];
    // f.a[0][1] += a[1][1];
    f.a01 += a00;
    f.a10 += a00;
    f.a11 += a01;
    f.a00 += a10;
    f.a01 += a11;
    return f;
  }
}
Info identity() {
  Info f;
  // f.a[0][0] = 1;
  f.a00 = 1;
  return f;
}

int N;
int[] A, B;

int[][] G;
int[] par;
Info[] dp, DP;

void dfs(int u, int p) {
  par[u] = p;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
  Info f = identity;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      f = f * dp[v];
    }
  }
  dp[u] = f.up;
}

void DFS(int u, int p) {
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
    }
  }
  const len = cast(int)(vs.length);
  auto ls = new Info[len + 1];
  auto rs = new Info[len + 1];
  ls[0] = rs[len] = identity;
  if (p != -1) {
    rs[len] = DP[u];
  }
  foreach (j; 0 .. len) {
    ls[j + 1] = ls[j] * dp[vs[j]];
  }
  foreach_reverse (j; 0 .. len) {
    rs[j] = dp[vs[j]] * rs[j + 1];
  }
  foreach (j; 0 .. len) {
    DP[vs[j]] = (ls[j] * rs[j + 1]).up;
  }
  foreach (j; 0 .. len) {
    DFS(vs[j], u);
  }
}


void main() {
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
      
      par = new int[N];
      dp = new Info[N];
      DP = new Info[N];
      const rt = 0;
      dfs(rt, -1);
      DFS(rt, -1);
      debug {
        writeln("rt = ", rt);
        writeln("dp = ", dp);
        writeln("DP = ", DP);
      }
      long ans;
      foreach (u; 0 .. N) {
        if (u != rt) {
          // if (dp[u].a[0][0] && DP[u].a[0][0]) {
          if (dp[u].a00 && DP[u].a00) {
            ans += 1L * dp[u].sz * DP[u].sz;
          } else {
            ans += 1L * dp[u].a01 * DP[u].a01;
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}