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


int N;
long K;
int[] P;
long[] S;

int[][] graph;

int[] lens;
long[3][] kss, fss;
long solve(int u, long k) {
  foreach (j; 0 .. lens[u]) {
    if (kss[u][j] == k) {
      return fss[u][j];
    }
  }
  
  long ret = S[u] * k;
  const deg = cast(int)(graph[u].length);
  if (deg) {
    const q = k / deg;
    const r = k % deg;
    auto ds = new long[deg];
    foreach (j; 0 .. deg) {
      const v = graph[u][j];
      const res0 = solve(v, q);
      ret += res0;
      if (r) {
        const res1 = solve(v, q + 1);
        ds[j] = res1 - res0;
      }
    }
    ds.sort;
    ret += ds[deg - cast(int)(r) .. deg].sum;
  }
  
  assert(lens[u] < 3);
  kss[u][lens[u]] = k;
  fss[u][lens[u]] = ret;
  ++lens[u];
  return ret;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        K = readLong;
        P = new int[N];
        P[0] = -1;
        foreach (u; 1 .. N) {
          P[u] = readInt - 1;
        }
        S = new long[N];
        foreach (u; 0 .. N) {
          S[u] = readLong;
        }
        
        graph = new int[][N];
        foreach (u; 1 .. N) {
          graph[P[u]] ~= u;
        }
        
        lens = new int[N];
        kss = new long[3][N];
        fss = new long[3][N];
        const ans = solve(0, K);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}