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


enum E = 18;
enum INF = 10^^9 + 10;

int N, M;
int[] A, B, C;

bool[] on;
int[][] G;
int[][] par;
int[] pari;
int[] dep;

void dfs(int u, int p, int pi) {
  par[0][u] = p;
  pari[u] = pi;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u, i);
    }
  }
}

int[] ans;
int[][] adds, rems;

alias Multiset = RedBlackTree!(int, "a < b", true);
Multiset solve(int u, int p, int pi) {
  auto ret = new Multiset;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      auto res = solve(v, u, i);
      if (ret.length < res.length) {
        swap(ret, res);
      }
      foreach (c; res) {
        ret.insert(c);
      }
    }
  }
  foreach (i; adds[u]) {
    ret.insert(C[i]);
  }
  foreach (i; rems[u]) {
    ret.removeKey(C[i]);
    ret.removeKey(C[i]);
  }
  if (pi != -1) {
    if (!ret.empty) {
      chmin(ans[pi], ret.front - 1);
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      C = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        C[i] = readInt();
      }
      
      alias Entry = Tuple!(int, "c", int, "i");
      auto es = new Entry[M];
      foreach (i; 0 .. M) {
        es[i] = Entry(C[i], i);
      }
      es.sort;
      auto uf = new int[N];
      uf[] = -1;
      on = new bool[M];
      foreach (ref e; es) {
        const i = e.i;
        on[i] = uf.connect(A[i], B[i]);
      }
      debug {
        writeln("on = ", on);
      }
      assert(on.count(true) == N - 1);
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        if (on[i]) {
          G[A[i]] ~= i;
          G[B[i]] ~= i;
        }
      }
      par = new int[][](E, N);
      pari = new int[N];
      dep = new int[N];
      const rt = 0;
      dfs(rt, -1, -1);
      par[0][rt] = rt;
      auto mxs = new int[][](E, N);
      foreach (u; 0 .. N) {
        mxs[0][u] = (pari[u] == -1) ? -INF : C[pari[u]];
      }
      foreach (e; 1 .. E) {
        foreach (u; 0 .. N) {
          par[e][u] = par[e - 1][par[e - 1][u]];
          mxs[e][u] = max(mxs[e - 1][u], mxs[e - 1][par[e - 1][u]]);
        }
      }
      
      ans = new int[M];
      ans[] = INF;
      adds = new int[][N];
      rems = new int[][N];
      foreach (i; 0 .. M) {
        if (!on[i]) {
          int u = A[i], v = B[i];
          int mx = -INF;
          foreach_reverse (e; 0 .. E) {
            if (dep[u] - (1 << e) >= dep[v]) {
              chmax(mx, mxs[e][u]);
              u = par[e][u];
            }
            if (dep[v] - (1 << e) >= dep[u]) {
              chmax(mx, mxs[e][v]);
              v = par[e][v];
            }
          }
          foreach_reverse (e; 0 .. E) {
            if (par[e][u] != par[e][v]) {
              chmax(mx, mxs[e][u]);
              chmax(mx, mxs[e][v]);
              u = par[e][u];
              v = par[e][v];
            }
          }
          if (u != v) {
            chmax(mx, mxs[0][u]);
            chmax(mx, mxs[0][v]);
            u = par[0][u];
            v = par[0][v];
          }
          debug {
            writeln(i, ": ", A[i], " ", B[i], " ", u, "; ", mx);
          }
          chmin(ans[i], mx - 1);
          adds[A[i]] ~= i;
          adds[B[i]] ~= i;
          rems[u] ~= i;
        }
      }
      solve(rt, -1, -1);
      
      foreach (i; 0 .. M) {
        if (i > 0) write(" ");
        write((ans[i] >= INF) ? -1 : ans[i]);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}