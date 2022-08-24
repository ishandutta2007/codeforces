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


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const S = readInt() - 1;
      const T = readInt() - 1;
      auto A = new int[M];
      auto B = new int[M];
      auto G = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        G[i] = readInt();
      }
      
      auto mf0 = new MaxFlow!int(N);
      foreach (i; 0 .. M) {
        if (G[i] == 1) {
          mf0.addEdge(A[i], B[i], 1);
          mf0.addEdge(B[i], A[i], M + 1);
        } else {
          mf0.addEdge(A[i], B[i], M + 1);
        }
      }
      mf0.dinic(S, T);
      assert(mf0.tof <= M);
      auto d = new bool[][](N, N);
      foreach (u; 0 .. N) {
        d[u][u] = true;
      }
      foreach (i; 0 .. mf0.m) {
        if (mf0.capa[i] > 0) {
          d[mf0.zu[i ^ 1]][mf0.zu[i]] = true;
        }
      }
      foreach (w; 0 .. N) foreach (u; 0 .. N) foreach (v; 0 .. N) {
        if (d[u][w] && d[w][v]) {
          d[u][v] = true;
        }
      }
      
      auto ex = new int[N];
      foreach (i; 0 .. M) {
        if (G[i] == 1) {
          --ex[A[i]];
          ++ex[B[i]];
        }
      }
      debug {
        writeln("ex = ", ex);
      }
      auto mf1 = new MaxFlow!int(N);
      auto ids1 = new int[M];
      ids1[] = -1;
      foreach (u; 0 .. N) {
        if (u != S && u != T) {
          if (ex[u] < 0) {
            mf1.addEdge(S, u, -ex[u]);
          } else {
            mf1.addEdge(u, T, ex[u]);
          }
        }
      }
      foreach (i; 0 .. M) {
        if (G[i] == 1) {
          ids1[i] = mf1.m;
          mf1.addEdge(A[i], B[i], M);
        }
      }
      mf1.dinic(S, T);
      
      writeln(mf0.tof);
      foreach (i; 0 .. M) {
        int f, c;
        if (G[i] == 1) {
          f = 1 + mf1.capa[ids1[i] ^ 1];
          c = (d[S][A[i]] && !d[S][B[i]]) ? f : (f + 1);
        } else {
          f = 0;
          c = 1;
        }
        writeln(f, " ", c);
      }
    }
  } catch (EOFException e) {
  }
}