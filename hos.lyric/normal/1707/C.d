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
int[] A, B;

int[][] G;
int[] dep;
enum E = 17;
int[][] par;
int[] fs;

void dfs(int u, int p) {
  dep[u] = (~p) ? (dep[p] + 1) : -1;
  par[0][u] = p;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
}
void DFS(int u, int p) {
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      fs[v] += fs[u];
      DFS(v, u);
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


void main() {
  try {
    for (; ; ) {
      N = readInt;
      M = readInt;
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt - 1;
        B[i] = readInt - 1;
      }
      
      auto uf = new int[N];
      uf[] = -1;
      auto on = new bool[M];
      foreach (i; 0 .. M) {
        on[i] = uf.connect(A[i], B[i]);
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) if (on[i]) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      dep = new int[N];
      par = new int[][](E, N);
      dfs(0, -1);
      foreach (e; 0 .. E - 1) {
        foreach (u; 0 .. N) {
          const p = par[e][u];
          par[e + 1][u] = (~p) ? par[e][p] : -1;
        }
      }
      
      fs = new int[N];
      foreach (i; 0 .. M) if (!on[i]) {
        const l = lca(A[i], B[i]);
        if (l == A[i]) {
          int u = B[i];
          foreach_reverse (e; 0 .. E) {
            if (dep[u] - (1 << e) > dep[l]) {
              u = par[e][u];
            }
          }
          fs[u] += 1;
          fs[B[i]] -= 1;
        } else if (l == B[i]) {
          int u = A[i];
          foreach_reverse (e; 0 .. E) {
            if (dep[u] - (1 << e) > dep[l]) {
              u = par[e][u];
            }
          }
          fs[u] += 1;
          fs[A[i]] -= 1;
        } else {
          fs[0] += 1;
          fs[A[i]] -= 1;
          fs[B[i]] -= 1;
        }
      }
      DFS(0, -1);
      
      auto ans = new char[N];
      foreach (u; 0 .. N) {
        ans[u] = (fs[u] == 0) ? '1' : '0';
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}