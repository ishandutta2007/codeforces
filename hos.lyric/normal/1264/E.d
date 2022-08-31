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

class MinCostFlow(wint, cint) {
  int n, m;
  int[][] g;
  int[] zu;
  wint[] capa0, capa, ex;
  cint[] cost;
  real[] pot;
  bool[] vis;
  int[] itr, lev;
  this(int n) {
    this.n = n; m = 0; g = new int[][n]; zu = null; capa = null; cost = null;
    ex = new wint[n]; pot = new real[n]; pot[] = 0; vis = new bool[n]; itr = new int[n]; lev = new int[n];
  }
  int addEdge(int u, int v, wint w, cint c) {
    debug {
      writeln("addEdge ", u, " ", v, " ", w, " ", c);
    }
    const i = m;
    g[u] ~= m; zu ~= v; capa0 ~= w; capa ~= w; cost ~= +c; ++m;
    g[v] ~= m; zu ~= u; capa0 ~= 0; capa ~= 0; cost ~= -c; ++m;
    return i;
  }
  wint augment(int u, int t, wint f) {
    if (u == t) return f;
    foreach (i; g[u][itr[u] .. $]) {
      if (capa[i] > 0 && lev[u] < lev[zu[i]]) {
        wint g = augment(zu[i], t, min(f, capa[i]));
        if (g > 0) {
          capa[i] -= g; capa[i ^ 1] += g; return g;
        }
      }
      ++itr[u];
    }
    return 0;
  }
  wint augment(int u, wint f) {
    if (ex[u] < 0) {
      wint g = min(f, -ex[u]); ex[u] += g; return g;
    }
    foreach (i; g[u][itr[u] .. $]) {
      if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
        wint g = augment(zu[i], min(f, capa[i]));
        if (g > 0) {
          capa[i] -= g; capa[i ^ 1] += g; return g;
        }
      }
      ++itr[u];
    }
    return 0;
  }
  wint dinic(int s, int t, wint f) {
    wint tof = 0;
    for (; tof < f; ) {
      int[] q;
      lev[] = -1;
      for (lev[s] = 0, q ~= s; !q.empty; ) {
        int u = q.front; q.popFront;
        foreach (i; g[u]) {
          int v = zu[i];
          if (capa[i] > 0 && lev[v] == -1) {
            lev[v] = lev[u] + 1; q ~= v;
          }
        }
      }
      if (lev[t] == -1) break;
      itr[] = 0;
      for (wint g; (g = augment(s, t, f - tof)) > 0; ) tof += g;
    }
    return tof;
  }
  void dfs(int u) {
    if (vis[u]) return; vis[u] = true;
    foreach (i; g[u]) if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
      dfs(zu[i]);
    }
  }
  cint solve() {
    real eps = 0;
  // cint solve(int s, int t, wint flow) {
    // real eps = 1;
    // ex[s] += flow;
    // ex[t] -= flow;
    foreach (i; 0 .. m) if (capa[i] > 0) chmax(eps, cast(real)(-cost[i]));
    for (; eps * n >= 1; ) {
      eps /= 4;
      foreach (i; 0 .. m) if (capa[i] > 0 && cost[i] + pot[zu[i ^ 1]] - pot[zu[i]] < 0) {
        ex[zu[i ^ 1]] -= capa[i]; ex[zu[i]] += capa[i]; capa[i ^ 1] += capa[i]; capa[i] = 0;
      }
      for (; ; ) {
        vis[] = false; itr[] = 0;
        foreach (u; 0 .. n) if (ex[u] > 0) dfs(u);
        foreach (u; 0 .. n) if (vis[u]) pot[u] -= eps;
        foreach (u; 0 .. n) for (wint f; ex[u] > 0 && (f = augment(u, ex[u])) > 0; ) ex[u] -= f;
        if (ex.all!"a <= 0") break;
      }
    }
    cint toc = 0;
    foreach (i; 0 .. m) if (capa0[i] > capa[i]) toc += (capa0[i] - capa[i]) * cost[i];
    return toc;
  }
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto U = new int[M];
      auto V = new int[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      
      auto adj = new int[][](N, N);
      foreach (u; 0 .. N) {
        adj[u][] = -1;
      }
      foreach (i; 0 .. M) {
        adj[U[i]][V[i]] = 1;
        adj[V[i]][U[i]] = 0;
      }
      debug {
        writeln("adj = ", adj);
      }
      
      auto mcf = new MinCostFlow!(int, int)(2 + N + N * (N - 1) / 2);
      auto ids = new int[][](N, N);
      foreach (u; 0 .. N) {
        // -d (N - 1 - d)
        foreach (d; 0 .. N - 1) {
          const diff = (-(d + 1) * (N - 1 - (d + 1))) - (-d * (N - 1 - d));
          mcf.addEdge(0, 2 + u, 1, diff);
          debug {
            // writeln(u, " ", d, ": ", diff);
          }
        }
      }
      foreach (x; 2 + N .. 2 + N + N * (N - 1) / 2) {
        mcf.addEdge(x, 1, 1, 0);
      }
      foreach (u; 0 .. N) {
        ids[u][] = -1;
      }
      {
        int x = 2 + N;
        foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
          if (adj[u][v] != 0) ids[u][v] = mcf.addEdge(2 + u, x, 1, 0);
          if (adj[v][u] != 0) ids[v][u] = mcf.addEdge(2 + v, x, 1, 0);
          ++x;
        }
        assert(x == 2 + N + N * (N - 1) / 2);
      }
      /*
      const res = mcf.solve(0, 1, N * (N - 1) / 2);
      debug {
        writeln("tof = ", mcf.tof, ", toc = ", mcf.toc);
      }
      assert(res);
      */
      mcf.addEdge(1, 0, N * (N - 1) / 2, -2 * N);
      const res = mcf.solve;
      // const res = mcf.solve(0, 1, N * (N - 1) / 2);
      debug {
        writeln("res = ", res);
      }
      
      auto ans = new int[][](N, N);
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        if (ids[u][v] != -1 && mcf.capa[ids[u][v]] == 0) ans[u][v] = 1;
        if (ids[v][u] != -1 && mcf.capa[ids[v][u]] == 0) ans[v][u] = 1;
        // assert(ans[u][v] + ans[v][u] == 1);
      }
      foreach (u; 0 .. N) {
        foreach (v; 0 .. N) {
          write(ans[u][v]);
        }
        writeln();
      }
    }
  } catch (EOFException e) {
  }
}