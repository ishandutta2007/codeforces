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
int[] A, B;

int[][] G;
int[][] dp;
int ans;

void dfs(int u, int p) {
  int deg;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      ++deg;
    }
  }
  dp[u] = [deg, 1];
  auto score = new int[2];
  auto mxs = new int[][](2, 2);
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      chmax(dp[u][0], max(dp[v][0], dp[v][1]) + (deg - 1));
      chmax(dp[u][1], dp[v][0] + 1);
      chmax(score[0], max(dp[v][0], dp[v][1]) + (deg - 1) + ((p != -1) ? 1 : 0));
      chmax(score[1], dp[v][0] + 1);
      foreach (s; 0 .. 2) {
        int tmp = (s == 0) ? max(dp[v][0], dp[v][1]) : dp[v][0];
        foreach (j; 0 .. 2) {
          if (mxs[s][j] < tmp) {
            swap(mxs[s][j], tmp);
          }
        }
      }
    }
  }
  if (deg >= 2) {
    chmax(score[0], mxs[0].sum + (deg - 2) + ((p != -1) ? 1 : 0));
    chmax(score[1], mxs[1].sum + 1);
  }
  foreach (s; 0 .. 2) {
    chmax(ans, score[s]);
  }
  debug {
    writeln(u, ": ", deg, " ", score);
  }
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
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      dp = new int[][](N, 2);
      ans = 0;
      dfs(0, -1);
      debug {
        writeln("dp = ", dp);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}