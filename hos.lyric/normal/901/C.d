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

void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


int N, M;
int[] A, B;
int Q;
int[] L, R;

int[][] G;
int[] par, dep;
int[][] rss;

void dfs(int u, int p) {
  par[u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      if (dep[v] == -1) {
        dfs(v, u);
      } else if (dep[v] < dep[u]) {
        int mn = N, mx = -1;
        for (int w = u; ; w = par[w]) {
          chmin(mn, w);
          chmax(mx, w);
          if (w == v) break;
        }
        debug {
          writeln([mn, mx]);
        }
        rss[mn] ~= mx;
      }
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      Q = readInt();
      L = new int[Q];
      R = new int[Q];
      foreach (q; 0 .. Q) {
        L[q] = readInt() - 1;
        R[q] = readInt();
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      par = new int[N];
      dep = new int[N];
      dep[] = -1;
      rss = new int[][N];
      foreach (u; 0 .. N) {
        if (dep[u] == -1) {
          dfs(u, -1);
        }
      }
      
      auto rMins = new int[N + 1];
      rMins[N] = N;
      foreach_reverse (u; 0 .. N) {
        rMins[u] = rMins[u + 1];
        foreach (r; rss[u]) {
          chmin(rMins[u], r);
        }
      }
      debug {
        writeln("rMins = ", rMins);
      }
      auto lss = new int[][N + 1];
      foreach (l; 0 .. N + 1) {
        lss[rMins[l]] ~= l;
      }
      
      auto queriess = new int[][N + 1];
      foreach (q; 0 .. Q) {
        queriess[R[q]] ~= q;
      }
      auto bit1 = new long[N + 1];
      auto bitL = new long[N + 1];
      auto bitR = new long[N + 1];
      auto ans = new long[Q];
      foreach (r; 0 .. N + 1) {
        foreach (l; lss[r]) {
          debug {
            writefln("add %s %s", l, r);
          }
          bit1.bAdd(l, 1);
          bitL.bAdd(l, l);
          bitR.bAdd(l, r);
        }
        foreach (q; queriess[r]) {
          const sum1 = bit1.bSum(R[q]) - bit1.bSum(L[q]);
          const sumL = bitL.bSum(R[q]) - bitL.bSum(L[q]);
          const sumR = bitR.bSum(R[q]) - bitR.bSum(L[q]);
          debug {
            writefln("sum [%s, %s): %s %s %s", L[q], R[q], sum1, sumL, sumR);
          }
          ans[q] += sumR - sumL;
          ans[q] += R[q] * (R[q] - L[q] - sum1) - (1L * (L[q] + R[q] - 1) * (R[q] - L[q]) / 2 - sumL);
        }
      }
      
      foreach (q; 0 .. Q) {
        writeln(ans[q]);
      }
    }
  } catch (EOFException e) {
  }
}