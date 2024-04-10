import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}

int N, M;
long[] W;
int[] U, V;
int S;

int[][] G;
int zeit;
int[] par, dis, low;

void dfs0(int u, int p) {
  par[u] = p;
  dis[u] = low[u] = zeit++;
  foreach (v; G[u]) {
    if (v != p) {
      if (dis[v] == -1) {
        dfs0(v, u);
        chmin(low[u], low[v]);
      } else {
        chmin(low[u], dis[v]);
      }
    }
  }
}

bool isBridge(int u, int v) {
  if (dis[u] > dis[v]) swap(u, v);
  return (u == par[v] && dis[v] <= low[v]);
}

int[][] H;
int[] sz;
long[] scores;
bool[] free;
long[] dp;

void dfs1(int x, int p) {
  foreach (y; H[x]) {
    if (y != p) {
      dfs1(y, x);
      free[x] = free[x] || free[y];
      chmax(dp[x], dp[y]);
    }
  }
  free[x] = free[x] || (sz[x] >= 2);
  dp[x] += scores[x];
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      W = new long[N];
      foreach (u; 0 .. N) {
        W[u] = readLong();
      }
      U = new int[M];
      V = new int[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      S = readInt() - 1;
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[U[i]] ~= V[i];
        G[V[i]] ~= U[i];
      }
      par = new int[N];
      dis = new int[N];
      low = new int[N];
      dis[] = -1;
      dfs0(S, -1);
      debug {
        writeln("par = ", par);
        writeln("dis = ", dis);
        writeln("low = ", low);
        foreach (i; 0 .. M) {
          write(isBridge(U[i], V[i]), " ");
        }
        writeln();
      }
      
      auto uf = new int[N];
      uf[] = -1;
      foreach (i; 0 .. M) {
        if (!isBridge(U[i], V[i])) {
          uf.connect(U[i], V[i]);
        }
      }
      H = new int[][N];
      foreach (i; 0 .. M) {
        if (isBridge(U[i], V[i])) {
          const x = uf.root(U[i]);
          const y = uf.root(V[i]);
          assert(x != y);
          H[x] ~= y;
          H[y] ~= x;
        }
      }
      sz = new int[N];
      scores = new long[N];
      foreach (u; 0 .. N) {
        const x = uf.root(u);
        ++sz[x];
        scores[x] += W[u];
      }
      free = new bool[N];
      dp = new long[N];
      dfs1(uf.root(S), -1);
      debug {
        writeln("uf = ", uf);
        writeln("free = ", free);
        writeln("dp = ", dp);
      }
      
      long ans;
      foreach (x; 0 .. N) {
        if (uf[x] < 0) {
          if (!free[x]) {
            chmax(ans, dp[x]);
          }
        }
      }
      foreach (x; 0 .. N) {
        if (uf[x] < 0) {
          if (free[x]) {
            ans += scores[x];
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}