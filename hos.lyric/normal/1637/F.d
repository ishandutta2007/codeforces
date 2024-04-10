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
long[] H;
int[] A, B;

int[][] G;
int[] par;
alias Result = Tuple!(long, "m", long, "s");
Result[] dp, DP;

void dfs(int u, int p) {
  par[u] = p;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
  // init
  Result f;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // add dp[v]
      chmax(f.m, dp[v].m);
      f.s += dp[v].s;
    }
  }
  // calc dp[u]
  if (f.m < H[u]) {
    f.s += (H[u] - f.m);
    f.m = H[u];
  }
  dp[u] = f;
}

void DFS(int u, int p) {
  // init
  Result[] gs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // add dp[v]
      gs ~= dp[v];
    }
  }
  if (p != -1) {
    // add DP[u]
    gs ~= DP[u];
  }
  
  const len = cast(int)(gs.length);
  auto ls = new long[len + 1];
  auto rs = new long[len + 1];
  ls[0] = 0;
  foreach (j; 0 .. len) ls[j + 1] = max(ls[j], gs[j].m);
  rs[len] = 0;
  foreach_reverse (j; 0 .. len) rs[j] = max(gs[j].m, rs[j + 1]);
  long sum;
  foreach (j; 0 .. len) sum += gs[j].s;
  
  int j;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // calc DP[v], removing dp[v]
      Result f;
      f.m = max(ls[j], rs[j + 1]);
      f.s = sum - gs[j].s;
      if (f.m < H[u]) {
        f.s += (H[u] - f.m);
        f.m = H[u];
      }
      DP[v] = f;
      ++j;
    }
  }
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      DFS(v, u);
    }
  }
}


void main() {
  try {
    for (; ; ) {
      N = readInt;
      H = new long[N];
      foreach (u; 0 .. N) {
        H[u] = readLong;
      }
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt - 1;
        B[i] = readInt - 1;
      }
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      
      
      par.length = N;
      dp.length = N;
      DP.length = N;
      const rt = 0;
      dfs(rt, -1);
      DFS(rt, -1);
      debug {
        writeln("rt = ", rt);
        writeln("dp = ", dp);
        writeln("DP = ", DP);
      }
      long ans = long.max;
      foreach (u; 0 .. N) if (G[u].length == 1) {
        // init
        Result f;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (v != par[u]) {
            // add dp[v]
            chmax(f.m, dp[v].m);
            f.s += dp[v].s;
          }
        }
        if (u != rt) {
          // add DP[u]
          chmax(f.m, DP[u].m);
          f.s += DP[u].s;
        }
        // calc ans, rooted at u
        if (f.m < H[u]) {
          f.s += (H[u] - f.m);
          f.m = H[u];
        }
        const cost = f.s + f.m;
        debug {
          writeln(u, ": ", f, " ", cost);
        }
        chmin(ans, cost);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}