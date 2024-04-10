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


int N, K;
int[] A, B;

int[][] G;
bool[] on;
int[] rs, par, dep;

Tuple!(int, int) dfs(int r, int u, int p) {
  rs[u] = r;
  par[u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  auto ret = tuple(0, u);
  foreach (v; G[u]) {
    if (v != p && !on[v]) {
      auto res = dfs(r, v, u);
      chmax(ret, tuple(1 + res[0], res[1]));
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= B[i];
        G[B[i]] ~= A[i];
      }
      on = new bool[N];
      rs = new int[N];
      par = new int[N];
      dep = new int[N];
      const res0 = dfs(0, 0, -1);
      const res1 = dfs(res0[1], res0[1], -1);
      
      int[] diam;
      for (int u = res1[1]; u != -1; u = par[u]) {
        diam ~= u;
      }
      const diamLen = cast(int)(diam.length);
      debug {
        writeln("diam = ", diam);
      }
      
      auto ans = new int[N];
      if (K == 2) {
        dfs(0, 0, -1);
        ans = new int[N];
        foreach (u; 0 .. N) {
          ans[u] = dep[u] % 2;
        }
      } else {
        foreach (j; 0 .. diamLen) {
          on[diam[j]] = true;
        }
        auto ds = new int[diamLen];
        foreach (j; 0 .. diamLen) {
          ds[j] = dfs(j, diam[j], -1)[0];
          if (ds[j] > 0) {
            if (j + 1 + ds[j] >= K && diamLen - j + ds[j] >= K) {
              ans = null;
              goto failed;
            }
          }
        }
        foreach (u; 0 .. N) {
          const j = rs[u];
          if (j + 1 >= diamLen - j) {
            ans[u] = (j + dep[u]) % K;
          } else {
            ans[u] = ((j - dep[u]) % K + K) % K;
          }
        }
       failed:
      }
      
      if (ans) {
        writeln("Yes");
        foreach (u; 0 .. N) {
          if (u > 0) write(" ");
          write(ans[u] + 1);
        }
        writeln();
      } else {
        writeln("No");
      }
    }
  } catch (EOFException e) {
  }
}