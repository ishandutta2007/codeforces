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
      const N = readInt();
      const K = readInt();
      auto A = new int[K];
      foreach (k; 0 .. K) {
        A[k] = readInt() - 1;
      }
      
      auto fav = new int[1 << N];
      foreach (k; 0 .. K) {
        fav[A[k]] = 1;
      }
      
      auto dp = new int[][][][](N + 1);
      dp[1] = new int[][][](1 << (N - 1), 2, 2);
      foreach (i; 0 .. 1 << (N - 1)) {
        foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
          dp[1][i][s][t] = -1;
        }
        const f0 = fav[i << 1 | 0];
        const f1 = fav[i << 1 | 1];
        chmax(dp[1][i][f0][f1], f0 | f1);
        chmax(dp[1][i][f1][f0], f0 | f1);
      }
      foreach (e; 2 .. N + 1) {
        dp[e] = new int[][][](1 << (N - e), 2, 2);
        foreach (i; 0 .. 1 << (N - e)) {
          foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
            dp[e][i][s][t] = -1;
          }
          foreach (s0; 0 .. 2) foreach (t0; 0 .. 2) {
            foreach (s1; 0 .. 2) foreach (t1; 0 .. 2) {
              const d0 = dp[e - 1][i << 1 | 0][s0][t0];
              const d1 = dp[e - 1][i << 1 | 1][s1][t1];
              if (d0 >= 0 && d1 >= 0) {
                const score = d0 + d1 + (s0 | s1) + (t0 | t1);
                chmax(dp[e][i][s0][s1 | t0 | t1], score + (s1 | t0 | t1));
                chmax(dp[e][i][s1][s0 | t0 | t1], score + (s0 | t0 | t1));
              }
            }
          }
        }
      }
      
      int ans = -1;
      foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
        const d = dp[N][0][s][t];
        if (d >= 0) {
          chmax(ans, d + (s | t));
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}