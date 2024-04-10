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


int solve(const(int[]) A) {
  const N = cast(int)(A.length);
  const lim = A.maxElement + 1;
  auto posss = new int[][lim];
  foreach (i; 0 .. N) {
    posss[A[i]] ~= i;
  }
  // dp[i][j] := min cost to color [i, j] in A[i] or A[j]
  auto dp = new int[][](N, N);
  foreach (i; 0 .. N) {
    dp[i][] = N;
    dp[i][i] = 0;
  }
  foreach_reverse (i; 0 .. N) {
    foreach (j; i + 1 .. N) {
      chmin(dp[i][j], dp[i + 1][j] + 1);
      // chmin(dp[i][j], dp[i][j - 1] + 1);
      foreach (k; posss[A[i]]) {
        if (i < k && k <= j) {
          chmin(dp[i][j], dp[i][k - 1] + dp[k][j]);
        }
      }
      foreach (k; posss[A[j]]) {
        if (i <= k && k < j) {
          // chmin(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
      }
    }
  }
  return dp[0][N - 1];
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt() - 1;
        }
        
        int[] as;
        for (int i = 0, j; i < N; i = j) {
          for (j = i; j < N && A[i] == A[j]; ++j) {}
          as ~= A[i];
        }
        const ans = solve(as);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}