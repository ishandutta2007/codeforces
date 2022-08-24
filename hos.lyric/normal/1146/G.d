import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


class MaxFlow(Capa) {
  enum Capa wEPS = 0;
  enum Capa wINF = 10^^9;
  int n, m;
  int[][] g;
  int[] zu;
  Capa[] capa;
  Capa tof;
  int[] lev, see, que;
  this(int n) {
    this.n = n; m = 0; g = new int[][n]; zu = []; capa = [];
    lev = new int[n]; see = new int[n]; que = new int[n];
  }
  void addEdge(int u, int v, Capa w0, Capa w1 = 0) {
    g[u] ~= m; zu ~= v; capa ~= w0; ++m;
    g[v] ~= m; zu ~= u; capa ~= w1; ++m;
  }
  Capa augment(int src, int ink, Capa flo) {
    if (src == ink) return flo;
    foreach (i; g[src][see[src] .. $]) {
      if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
        Capa f = augment(zu[i], ink, min(flo, capa[i]));
        if (f > wEPS) { capa[i] -= f; capa[i ^ 1] += f; return f; }
      }
      ++see[src];
    }
    return 0;
  }
  bool dinic(int src, int ink, Capa flo = wINF) {
    for (tof = 0; tof + wEPS < flo; ) {
      int[] q;
      lev[] = -1;
     dinicBFS:
      for (lev[src] = 0, q ~= src; !q.empty; ) {
        int u = q.front; q.popFront;
        foreach (i; g[u]) {
          int v = zu[i];
          if (capa[i] > wEPS && lev[v] == -1) {
            lev[v] = lev[u] + 1; q ~= v;
            if (v == ink) break dinicBFS;
          }
        }
      }
      if (lev[ink] == -1) return false;
      see[] = 0;
      for (; ; ) {
        Capa f = augment(src, ink, flo - tof);
        if (f <= wEPS) break;
        tof += f;
      }
    }
    return true;
  }
}


int N, H, M;
int[] L, R, X, C;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      H = readInt();
      M = readInt();
      L = new int[M];
      R = new int[M];
      X = new int[M];
      C = new int[M];
      foreach (i; 0 .. M) {
        L[i] = readInt() - 1;
        R[i] = readInt();
        X[i] = readInt();
        C[i] = readInt();
      }
      
      enum INF = 10^^9;
      auto mf = new MaxFlow!int(2 + M + N * (H + 1));
      int id(int j, int h) {
        return 2 + M + j * (H + 1) + h;
      }
      foreach (i; 0 .. M) {
        // if >= X[i], fine
        if (X[i] < H) {
          foreach (j; L[i] .. R[i]) {
            mf.addEdge(id(j, X[i] + 1), 2 + i, INF);
          }
          mf.addEdge(2 + i, 1, C[i]);
        }
      }
      foreach (j; 0 .. N) {
        foreach (h; 0 .. H) {
          mf.addEdge(id(j, h + 1), id(j, h), INF);
        }
        foreach (h; 0 .. H) {
          mf.addEdge(0, id(j, h + 1), (h + 1)^^2 - h^^2);
        }
        mf.addEdge(0, id(j, 0), INF);
      }
      mf.dinic(0, 1);
      
      int ans;
      foreach (j; 0 .. N) {
        ans += H^^2;
      }
      ans -= mf.tof;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}