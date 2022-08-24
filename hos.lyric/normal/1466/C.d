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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const S = readToken();
        const N = cast(int)(S.length);
        
        auto dp = new int[2][2][N + 1];
        foreach (i; 0 .. N + 1) {
          foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
            dp[i][s][t] = INF;
          }
        }
        dp[0][1][1] = 0;
        foreach (i; 0 .. N) {
          foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
            if (dp[i][s][t] < INF) {
              const c2 = s ? '?' : S[i - 2];
              const c1 = t ? '?' : S[i - 1];
              if (c2 != S[i] && c1 != S[i]) {
                chmin(dp[i + 1][t][0], dp[i][s][t]);
              }
              chmin(dp[i + 1][t][1], dp[i][s][t] + 1);
            }
          }
        }
        debug {
          writeln("dp = ", dp);
        }
        
        int ans = INF;
        foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
          chmin(ans, dp[N][s][t]);
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}