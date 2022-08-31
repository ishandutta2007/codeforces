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


class MaxFlow(Capa) {
  enum Capa wEPS = 0;
  enum Capa wINF = 10L^^18;
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


long N;
int M;
long[] XA, YA, XB, YB;

void main() {
  try {
    for (; ; ) {
      N = readLong();
      M = readInt();
      XA = new long[M];
      YA = new long[M];
      XB = new long[M];
      YB = new long[M];
      foreach (i; 0 .. M) {
        XA[i] = readLong() - 1;
        YA[i] = readLong() - 1;
        XB[i] = readLong();
        YB[i] = readLong();
      }
      
      auto xs = [0L, N] ~ XA.dup ~ XB.dup;
      auto ys = [0L, N] ~ YA.dup ~ YB.dup;
      xs = xs.sort.uniq.array;
      ys = ys.sort.uniq.array;
      const H = cast(int)(xs.length) - 1;
      const W = cast(int)(xs.length) - 1;
      auto board = new bool[][](H, W);
      foreach (i; 0 .. M) {
        const ea = xs.lowerBound(XA[i]);
        const fa = ys.lowerBound(YA[i]);
        const eb = xs.lowerBound(XB[i]);
        const fb = ys.lowerBound(YB[i]);
        foreach (e; ea .. eb) foreach (f; fa .. fb) {
          board[e][f] = true;
        }
      }
      debug {
        writeln("xs = ", xs);
        writeln("ys = ", ys);
        foreach (e; 0 .. H) {
          foreach (f; 0 .. W) {
            write(board[e][f] ? '#' : '.');
          }
          writeln();
        }
      }
      
      auto mf = new MaxFlow!long(2 + H + W);
      foreach (e; 0 .. H) {
        mf.addEdge(0, 2 + e, xs[e + 1] - xs[e]);
      }
      foreach (f; 0 .. W) {
        mf.addEdge(2 + H + f, 1, ys[f + 1] - ys[f]);
      }
      foreach (e; 0 .. H) foreach (f; 0 .. W) {
        if (board[e][f]) {
          mf.addEdge(2 + e, 2 + H + f, MaxFlow!long.wINF);
        }
      }
      mf.dinic(0, 1);
      writeln(mf.tof);
    }
  } catch (EOFException e) {
  }
}