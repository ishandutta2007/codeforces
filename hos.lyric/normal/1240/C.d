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
int[] U, V;
long[] W;

int[][] G;
long[][] dp;

void dfs(int u, int p) {
  long sum0;
  long[] diffs;
  foreach (i; G[u]) {
    const v = U[i] ^ V[i] ^ u;
    if (v != p) {
      dfs(v, u);
      sum0 += dp[v][0];
      diffs ~= max((W[i] + dp[v][1]) - dp[v][0], 0);
    }
  }
  sort(diffs);
  reverse(diffs);
  dp[u][] = sum0;
  foreach (j; 0 .. diffs.length) {
    if (j < K) {
      dp[u][0] += diffs[j];
    }
    if (j < K - 1) {
      dp[u][1] += diffs[j];
    }
  }
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt();
        K = readInt();
        U = new int[N - 1];
        V = new int[N - 1];
        W = new long[N - 1];
        foreach (i; 0 .. N - 1) {
          U[i] = readInt() - 1;
          V[i] = readInt() - 1;
          W[i] = readLong();
        }
        
        G = new int[][N];
        foreach (i; 0 .. N - 1) {
          G[U[i]] ~= i;
          G[V[i]] ~= i;
        }
        dp = new long[][](N, 2);
        const rt = 0;
        dfs(rt, -1);
        debug {
          writeln("dp = ", dp);
        }
        writeln(dp[rt][0]);
      }
    }
  } catch (EOFException e) {
  }
}