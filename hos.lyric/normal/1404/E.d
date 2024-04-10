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
      int qb, qe;
      lev[] = -1;
     dinicBFS:
      for (lev[src] = 0, que[qe++] = src; qb != qe; ) {
        const u = que[qb++];
        foreach (i; g[u]) {
          const v = zu[i];
          if (capa[i] > wEPS && lev[v] == -1) {
            lev[v] = lev[u] + 1; que[qe++] = v;
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
      const M = readInt();
      const N = readInt();
      auto A = new string[M];
      foreach (x; 0 .. M) {
        A[x] = readToken();
      }
      
      int num;
      auto ids = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        if (A[x][y] == '#') {
          ids[x][y] = num++;
        } else {
          ids[x][y] = -1;
        }
      }
      
      auto mf = new MaxFlow!int(num + 2);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        if (ids[x][y] != -1) {
          if (x == 0 || ids[x - 1][y] == -1) {
            mf.addEdge(ids[x][y], num + 1, 1);
          }
          if (x == M - 1 || ids[x + 1][y] == -1) {
            mf.addEdge(ids[x][y], num + 1, 1);
          }
          if (y == 0 || ids[x][y - 1] == -1) {
            mf.addEdge(num, ids[x][y], 1);
          }
          if (y == N - 1 || ids[x][y + 1] == -1) {
            mf.addEdge(num, ids[x][y], 1);
          }
        }
      }
      foreach (x; 0 .. M - 1) foreach (y; 0 .. N) {
        if (ids[x][y] != -1 && ids[x + 1][y] != -1) {
          mf.addEdge(ids[x][y], ids[x + 1][y], 1, 1);
        }
      }
      foreach (x; 0 .. M) foreach (y; 0 .. N - 1) {
        if (ids[x][y] != -1 && ids[x][y + 1] != -1) {
          mf.addEdge(ids[x][y], ids[x][y + 1], 1, 1);
        }
      }
      mf.dinic(num, num + 1);
      assert(mf.tof % 2 == 0);
      writeln(mf.tof / 2);
    }
  } catch (EOFException e) {
  }
}