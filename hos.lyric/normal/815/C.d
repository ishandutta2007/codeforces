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


int N;
int B;
int[] C, D;
int[] P;

int[][] child;
int[] sz;
int[][][] dp;

void dfs(int u, int p) {
  auto crt = [[0], [0]];
  foreach (v; child[u]) {
    dfs(v, u);
    auto nxt = new int[][](2, sz[u] + sz[v] + 1);
    nxt[0][] = B + 1;
    nxt[1][] = B + 1;
    foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
      foreach (a; 0 .. sz[u] + 1) foreach (b; 0 .. sz[v] + 1) {
        chmin(nxt[s | t][a + b], crt[s][a] + dp[v][t][b]);
      }
    }
    crt = nxt;
    sz[u] += sz[v];
  }
  dp[u] = new int[][](2, sz[u] + 1 + 1);
  dp[u][0][] = B + 1;
  dp[u][1][] = B + 1;
  foreach (a; 0 .. sz[u] + 1) {
    chmin(dp[u][0][a], crt[0][a]);
    chmin(dp[u][0][a + 1], crt[0][a] + C[u]);
    chmin(dp[u][1][a], crt[0][a]);
    chmin(dp[u][1][a + 1], crt[0][a] + C[u]);
    chmin(dp[u][1][a + 1], crt[0][a] + (C[u] - D[u]));
    chmin(dp[u][1][a + 1], crt[1][a] + (C[u] - D[u]));
  }
  sz[u] += 1;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      B = readInt();
      C = new int[N];
      D = new int[N];
      P = new int[N];
      foreach (u; 0 .. N) {
        C[u] = readInt();
        D[u] = readInt();
        P[u] = (u == 0) ? -1 : (readInt() - 1);
      }
      
      child = new int[][N];
      foreach (u; 1 .. N) {
        child[P[u]] ~= u;
      }
      
      sz = new int[N];
      dp = new int[][][N];
      dfs(0, -1);
      debug {
        foreach (u; 0 .. N) {
          writeln(u, ": ", dp[u]);
        }
      }
      
      int ans;
      foreach (s; 0 .. 2) {
        foreach (a; 0 .. N + 1) {
          if (dp[0][s][a] <= B) {
            chmax(ans, a);
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}