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




void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new long[N];
        foreach (i; 0 .. N) {
          A[i] = readLong;
        }
        const X = readLong;
        
        auto B = new long[N + 1];
        foreach (i; 0 .. N) {
          B[i + 1] = B[i] + (A[i] - X);
        }
        debug {
          writeln("B = ", B);
        }
        
        auto dp = new int[][](N + 2, 2);
        foreach (i; 0 .. N + 2) {
          dp[i][] = -1;
        }
        dp[0][0] = 0;
        foreach (i; 0 .. N + 2) foreach (s; 0 .. 2) if (dp[i][s] >= 0) {
          // cut
          if (i + 1 <= N + 1) {
            chmax(dp[i + 1][0], dp[i][s]);
          }
          if (i + 2 <= N + 1 && B[i] > B[i + 1]) {
            chmax(dp[i + 2][1], dp[i][s] + 1);
          }
          // 1
          if (i + 1 <= N + 1) {
            if (i == 0 || B[s ? (i - 2) : (i - 1)] <= B[i]) {
              chmax(dp[i + 1][0], dp[i][s] + 1);
            }
          }
          // 2
          if (i + 2 <= N + 1 && B[i] > B[i + 1]) {
            if (i == 0 || B[s ? (i - 2) : (i - 1)] <= B[i + 1]) {
              chmax(dp[i + 2][1], dp[i][s] + 2);
            }
          }
        }
        
        const ans = dp[$ - 1].maxElement;
        writeln(ans - 1);
      }
    }
  } catch (EOFException e) {
  }
}