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


enum INF = 10L^^18;

int N;
int[] U, V;
long[] W;
int S;
int M;
int[] X;

int[][] G;

long[][][][] cache;

// arriving at u from p via ip, a above, b below
long calc(int u, int p, int ip, int a, int b) {
  assert(b > 0);
  auto ret = &cache[u][p][a][b];
  if (*ret == -1) {
    debug {
      writeln("calc ", u, " ", p, " ", ip, " ", a, " ", b);
    }
    if (G[u].length == 1) {
      // leaf
      if (a == 0) {
        *ret = 0;
      } else {
        *ret = W[G[u][0]] + calc(p, u, ip, 0, a);
      }
    } else {
      assert(b > 0);
      // c_j for j-th child
      // maximize min { W[i] + calc(u, v_j, i_j, a + b - c_j, c_j) | c_j > 0 }
      auto dp = new long[b + 1];
      dp[] = -INF;
      dp[0] = INF;
      foreach (i; G[u]) {
        const v = U[i] ^ V[i] ^ u;
        if (v != p) {
          foreach_reverse (c; 0 .. b + 1) {
            if (dp[c] >= -INF) {
              foreach (d; 1 .. b - c + 1) {
                if (dp[c + d] < dp[c]) {
                  chmax(dp[c + d], min(dp[c], W[i] + calc(v, u, i, a + b - d, d)));
                }
              }
            }
          }
        }
      }
      *ret = dp[b];
    }
    debug {
      writeln(u, " ", p, " ", ip, " ", a, " ", b, ": ", *ret);
    }
  }
  return *ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      U = new int[N - 1];
      V = new int[N - 1];
      W = new long[N - 1];
      foreach (i; 0 .. N - 1) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
        W[i] = readLong();
      }
      S = readInt() - 1;
      M = readInt();
      X = new int[M];
      foreach (m; 0 .. M) {
        X[m] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[U[i]] ~= i;
        G[V[i]] ~= i;
      }
      
      cache = new long[][][][](N, N, M + 1, M + 1);
      foreach (u; 0 .. N) foreach (p; 0 .. N) {
        foreach (a; 0 .. M + 1) foreach (b; 0 .. M + 1) {
          cache[u][p][a][b] = -1;
        }
      }
      
      auto d = new int[][](N, N);
      foreach (u; 0 .. N) {
        d[u][] = N;
        d[u][u] = 0;
      }
      foreach (i; 0 .. N - 1) {
        d[U[i]][V[i]] = d[V[i]][U[i]] = 1;
      }
      foreach (w; 0 .. N) foreach (u; 0 .. N) foreach (v; 0 .. N) {
        chmin(d[u][v], d[u][w] + d[w][v]);
      }
      
      long ans = INF;
      foreach (i; G[S]) {
        const v = U[i] ^ V[i] ^ S;
        int b;
        foreach (x; X) {
          if (d[S][x] == 1 + d[v][x]) {
            ++b;
          }
        }
        debug {
          writeln(v, " ", i, ": ", b);
        }
        if (b > 0) {
          chmin(ans, W[i] + calc(v, S, i, M - b, b));
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}