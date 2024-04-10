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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const C = readLong();
      auto P = new long[N];
      foreach (i; 0 .. N) {
        P[i] = readLong();
      }
      auto S = new long[N];
      foreach (i; 0 .. N) {
        S[i] = readLong();
      }
      
      // num src-side
      auto dp = new long[N + 1];
      dp[] = INF;
      dp[0] = 0;
      foreach (i; 0 .. N) {
        foreach_reverse (j; 1 .. i + 1 + 1) {
          dp[j] = min(dp[j - 1] + S[i], dp[j] + P[i] + C * j);
        }
        dp[0] = dp[0] + P[i] + C * 0;
      }
      const ans = dp.minElement;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}