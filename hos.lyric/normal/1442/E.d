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
int[] C;
int[] A, B;

int[][] G;
int[] par;
int[2][] dp, DP;

void dfs(int u, int p) {
  par[u] = p;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
  // init
  int[2] mx;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // add dp[v]
      foreach (s; 0 .. 2) {
        chmax(mx[s], dp[v][s]);
      }
    }
  }
  // calc dp[u]
  dp[u] = mx;
  if (C[u] != -1) {
    chmax(dp[u][C[u]], mx[C[u] ^ 1] + 1);
  }
}

void DFS(int u, int p) {
  // init
  alias Entry = Tuple!(int, "val", int, "key");
  Entry[2][2] mxs;
  foreach (s; 0 .. 2) {
    mxs[s][] = Entry(0, -1);
  }
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // add dp[v]
      foreach (s; 0 .. 2) {
        Entry tmp = Entry(dp[v][s], v);
        foreach (k; 0 .. 2) {
          if (mxs[s][k] < tmp) {
            swap(mxs[s][k], tmp);
          }
        }
      }
    }
  }
  if (p != -1) {
    // add DP[u]
    foreach (s; 0 .. 2) {
      Entry tmp = Entry(DP[u][s], u);
      foreach (k; 0 .. 2) {
        if (mxs[s][k] < tmp) {
          swap(mxs[s][k], tmp);
        }
      }
    }
  }
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      // calc DP[v], removing dp[v]
      int[2] mx;
      foreach (s; 0 .. 2) {
        foreach (k; 0 .. 2) {
          if (mxs[s][k].key != v) {
            chmax(mx[s], mxs[s][k].val);
          }
        }
      }
      DP[v] = mx;
      if (C[u] != -1) {
        chmax(DP[v][C[u]], mx[C[u] ^ 1] + 1);
      }
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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt();
        C = new int[N];
        foreach (u; 0 .. N) {
          C[u] = readInt() - 1;
        }
        A = new int[N - 1];
        B = new int[N - 1];
        foreach (i; 0 .. N - 1) {
          A[i] = readInt() - 1;
          B[i] = readInt() - 1;
        }
        
        G = new int[][N];
        foreach (i; 0 .. N - 1) {
          G[A[i]] ~= i;
          G[B[i]] ~= i;
        }
        
        const rt = 0;
        par = new int[N];
        dp = new int[2][N];
        dfs(rt, -1);
        DP = new int[2][N];
        DFS(rt, -1);
        debug {
          writeln("rt = ", rt);
          writeln("dp = ", dp);
          writeln("DP = ", DP);
        }
        int ans;
        foreach (u; 0 .. N) {
          // init
          int[2] mx;
          foreach (i; G[u]) {
            const v = A[i] ^ B[i] ^ u;
            if (v != par[u]) {
              // add dp[v]
              foreach (s; 0 .. 2) {
                chmax(mx[s], dp[v][s]);
              }
            }
          }
          if (u != rt) {
            // add DP[u]
            foreach (s; 0 .. 2) {
              chmax(mx[s], DP[u][s]);
            }
          }
          // calc ans, rooted at u
          foreach (s; 0 .. 2) {
            chmax(ans, mx[s]);
          }
          if (C[u] != -1) {
            chmax(ans, mx[C[u] ^ 1] + 1);
          }
        }
        
        ans = ans / 2 + 1;
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}