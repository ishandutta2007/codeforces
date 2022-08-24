import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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

class Heap(T) {
  Heap l, r;
  T val;
  this () {}
  this (T val) { this.val = val; }
}
Heap!T merge(T)(Heap!T a, Heap!T b) {
  if (!a) return b;
  if (!b) return a;
  if (a.val > b.val) swap(a, b);
  a.r = merge(a.r, b);
  swap(a.l, a.r);
  return a;
}
void pop(T)(ref Heap!T a) {
  a = merge(a.l, a.r);
}


enum E = 21;

int N, K, M;
int[] GA, GB;
int[] FA, FB;
long[] FW;

int[][] graph;
int[] dep;
int[][] par;
Tuple!(int, int)[][] inss;
int[] anss;

void dfs(int u, int p) {
  dep[u] = (p == u) ? 0 : (dep[p] + 1);
  par[0][u] = p;
  foreach (k; graph[u]) {
    const v = (k < K) ? (GA[k] ^ GB[k] ^ u) : (FA[k - K] ^ FB[k - K] ^ u);
    if (v != p) {
      dfs(v, u);
    }
  }
}

int lca(int u, int v) {
  foreach_reverse (e; 0 .. E) {
    if (dep[u] - (1 << e) >= dep[v]) {
      u = par[e][u];
    }
    if (dep[v] - (1 << e) >= dep[u]) {
      v = par[e][v];
    }
  }
  foreach_reverse (e; 0 .. E) {
    if (par[e][u] != par[e][v]) {
      u = par[e][u];
      v = par[e][v];
    }
  }
  if (u != v) {
    u = par[0][u];
    v = par[0][v];
  }
  return u;
}

Heap!(Tuple!(int, int)) solve(int u, int p) {
  Heap!(Tuple!(int, int)) ret;
  foreach (k; graph[u]) {
    const v = (k < K) ? (GA[k] ^ GB[k] ^ u) : (FA[k - K] ^ FB[k - K] ^ u);
    if (v != p) {
      auto res = solve(v, u);
      for (; res && dep[res.val[1]] >= dep[v]; res.pop) {}
      if (k < K) {
        anss[k] = res ? res.val[0] : -1;
      }
      ret = ret.merge(res);
    }
  }
  foreach (m; inss[u]) {
    ret = ret.merge(new Heap!(Tuple!(int, int))(m));
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      M = readInt();
      GA = new int[K];
      GB = new int[K];
      foreach (k; 0 .. K) {
        GA[k] = readInt() - 1;
        GB[k] = readInt() - 1;
      }
      FA = new int[M];
      FB = new int[M];
      FW = new long[M];
      foreach (m; 0 .. M) {
        FA[m] = readInt() - 1;
        FB[m] = readInt() - 1;
        FW[m] = readLong();
      }
      
      auto uf = new int[N];
      uf[] = -1;
      graph = new int[][N];
      foreach (k; 0 .. K) {
        uf.connect(GA[k], GB[k]);
        graph[GA[k]] ~= k;
        graph[GB[k]] ~= k;
      }
      foreach (m; 0 .. M) {
        if (uf.connect(FA[m], FB[m])) {
          graph[FA[m]] ~= K + m;
          graph[FB[m]] ~= K + m;
        }
      }
      
      dep = new int[N];
      par = new int[][](E, N);
      dep[] = -1;
      foreach (u; 0 .. N) {
        if (dep[u] == -1) {
          dfs(u, u);
        }
      }
      foreach (e; 0 .. E - 1) {
        foreach (u; 0 .. N) {
          par[e + 1][u] = par[e][par[e][u]];
        }
      }
      debug {
        writeln("par[0] = ", par[0]);
      }
      
      inss = new Tuple!(int, int)[][N];
      foreach (m; 0 .. M) {
        int l = lca(FA[m], FB[m]);
        if (FA[m] != l) {
          inss[FA[m]] ~= tuple(m, l);
        }
        if (FB[m] != l) {
          inss[FB[m]] ~= tuple(m, l);
        }
      }
      debug {
        writeln("inss = ", inss);
      }
      anss = new int[K];
      anss[] = -1;
      foreach (u; 0 .. N) {
        if (par[0][u] == u) {
          solve(u, u);
        }
      }
      debug {
        writeln("anss = ", anss);
      }
      
      long ans;
      foreach (k; 0 .. K) {
        if (anss[k] == -1) {
          ans = -1;
          break;
        } else {
          ans += FW[anss[k]];
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}