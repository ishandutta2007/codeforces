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
  debug {
    enum lim = 100;
    auto dp = new int[][][][](lim, lim, 2, 2);
    foreach (a; 0 .. lim) foreach (b; 0 .. lim) foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
      if (a + b == 0) {
        dp[a][b][s][t] = s;
      } else if (t == 1) {
        dp[a][b][s][t] = 0;
        if (a > 0 && dp[a - 1][b][s ^ 0][t ^ 1] == 1) dp[a][b][s][t] = 1;
        if (b > 0 && dp[a][b - 1][s ^ 1][t ^ 1] == 1) dp[a][b][s][t] = 1;
      } else {
        dp[a][b][s][t] = 1;
        if (a > 0 && dp[a - 1][b][s][t ^ 1] == 0) dp[a][b][s][t] = 0;
        if (b > 0 && dp[a][b - 1][s][t ^ 1] == 0) dp[a][b][s][t] = 0;
      }
    }
    foreach (a; 0 .. lim) foreach (b; 0 .. lim) {
      if (b % 2 != 0) {
        // writeln(a, " ", b, ": ", dp[a][b]);
        foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
          assert(dp[a][b][s][t] == ((a % 2 == 0) ? (((b >> 1) & 1) ^ s ^ t) : t));
        }
      }
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new long[N];
        foreach (i; 0 .. N) {
          A[i] = readLong();
        }
        
        long sum;
        foreach (i; 0 .. N) {
          sum ^= A[i];
        }
        if (sum == 0) {
          writeln("DRAW");
        } else {
          const e = bsr(sum);
          auto cnt = new int[2];
          foreach (i; 0 .. N) {
            ++cnt[cast(int)((A[i] >> e) & 1)];
          }
          debug {
            writeln(cnt);
          }
          const ans = (cnt[0] % 2 == 0) ? (((cnt[1] >> 1) & 1) ^ 1) : 1;
          writeln(ans ? "WIN" : "LOSE");
        }
      }
    }
  } catch (EOFException e) {
  }
}