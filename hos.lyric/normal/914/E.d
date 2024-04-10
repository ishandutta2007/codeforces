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


enum K = 20;

int N;
int[] A, B;
string C;

int[][] G;
long[] ans;

void solveCentroidDecomp() {
  auto sz = new int[N];
  auto del = new bool[N];
  void dfsSz(int u, int p) {
    sz[u] = 1;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      if (v != p) {
        dfsSz(v, u);
        sz[u] += sz[v];
      }
    }
  }
  dfsSz(0, -1);

  auto par = new int[N];
  auto dp = new long[N];
  auto freq = new int[1 << K];

  // r: centroid
  void solveSubtree(int r) {
    debug {
      string dfsDebug(int u, int p) {
        string ret = u.to!string;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v] && v != p) {
            ret ~= "(" ~ dfsDebug(v, u) ~ ")";
          }
        }
        return ret;
      }
      writeln("solveSubtree ", dfsDebug(r, -1));
    }
    //
    const deg = cast(int)(G[r].length);
    alias Entry = Tuple!(int, "u", int, "d");
    auto ess = new Entry[][deg];
    const dR = 1 << (C[r] - 'a');
    //
    void dfs(int j, int u, int p, int d) {
      //
      d ^= 1 << (C[u] - 'a');
      ess[j] ~= Entry(u, d);
      par[u] = p;
      //
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v] && v != p) {
          dfs(j, v, u, d);
        }
      }
    }
    foreach (j; 0 .. deg) {
      const i = G[r][j];
      const v = A[i] ^ B[i] ^ r;
      if (!del[v]) {
        dfs(j, v, r, dR);
      }
    }
    dp[r] = 0;
    foreach (j; 0 .. deg) foreach (ref e; ess[j]) ++freq[e.d];
    foreach (j; 0 .. deg) {
      foreach (ref e; ess[j]) --freq[e.d];
      foreach (ref e; ess[j]) {
        dp[e.u] = 0;
        if (!(e.d & e.d - 1)) {
          // u-r
          dp[e.u] += 1;
          dp[r] += 1;
        }
        // u-v
        dp[e.u] += freq[e.d ^ dR];
        foreach (k; 0 .. K) {
          dp[e.u] += freq[e.d ^ dR ^ 1 << k];
        }
      }
      foreach (ref e; ess[j]) ++freq[e.d];
    }
    foreach (j; 0 .. deg) foreach (ref e; ess[j]) --freq[e.d];
    // r-r
    dp[r] += 1;
    dp[r] += 1;
    foreach (j; 0 .. deg) {
      foreach_reverse (ref e; ess[j]) {
        ans[e.u] += dp[e.u];
        dp[par[e.u]] += dp[e.u];
      }
    }
    ans[r] += dp[r] / 2;
  }

  void solveRec(int u) {
    for (; ; ) {
      int vm = -1;
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v]) {
          if (vm == -1 || sz[vm] < sz[v]) {
            vm = v;
          }
        }
      }
      if (vm == -1 || sz[u] >= 2 * sz[vm]) {
        solveSubtree(u);
        del[u] = true;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v]) {
            solveRec(v);
          }
        }
        break;
      } else {
        sz[u] -= sz[vm];
        sz[vm] += sz[u];
        u = vm;
      }
    }
  }
  solveRec(0);
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      C = readToken();
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      ans = new long[N];
      solveCentroidDecomp();
      foreach (u; 0 .. N) {
        if (u > 0) write(" ");
        write(ans[u]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}