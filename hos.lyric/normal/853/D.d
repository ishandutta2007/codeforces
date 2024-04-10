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
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt() / 1000;
      }
      
      auto ASum = new int[N + 1];
      foreach (i; 0 .. N) {
        ASum[i + 1] = ASum[i] + A[i];
      }
      
      int ans;
      foreach (i; 0 .. N + 1) {
        chmax(ans, min(ASum[i], 10 * (ASum[N] - ASum[i])));
      }
      
      /*
        |1     
          22|22
      */
      foreach (i; 0 .. N) {
        if (A[i] == 1) {
          int j;
          for (j = i + 1; j < N && A[j] == 2; ++j) {}
          const s = j - (i + 1);
          foreach (t; 0 .. s + 1) {
            const a = min(ASum[i], 10);
            const score = a + min(ASum[i] - a + 2 * t, 20 * (s - t) + 10 * (ASum[N] - ASum[j]));
            chmax(ans, score);
          }
        }
      }
      /*
             1|
        22|22  
      */
      foreach (i; 0 .. N) {
        if (A[i] == 1) {
          int j;
          for (j = i; j > 0 && A[j - 1] == 2; --j) {}
          debug {
            writeln("! ", j, " ", i);
          }
          const s = i - j;
          foreach (t; 0 .. s + 1) {
            const a = min(ASum[j] + 2 * t, 20 * (s - t));
            const score = a + min((ASum[j] + 2 * t) - a + 1, 10 * (ASum[N] - ASum[i + 1]));
            debug {
              writeln("  ", t, ": ", score);
            }
            chmax(ans, score);
          }
        }
      }
      
      debug {
        writeln("ans = ", ans);
      }
      writeln(1000L * ASum[N] - 100L * ans);
      
      debug {
        auto dp = new int[][](N + 1, 2 * N + 1);
        foreach (i; 0 .. N + 1) {
          dp[i][] = -1;
        }
        dp[0][0] = 0;
        foreach (i; 0 .. N) {
          foreach (j; 0 .. 2 * N + 1) {
            if (dp[i][j] >= 0) {
              // chmax(dp[i + 1][j + A[i]], dp[i][j] + A[i]);
              foreach (dj; 1 .. A[i] + 1) {
                chmax(dp[i + 1][j + dj], dp[i][j] + dj);
              }
              chmax(dp[i + 1][max(j - 10 * A[i], 0)], dp[i][j]);
            }
          }
        }
        foreach (i; 0 .. N + 1) {
          writeln(i, ": ", dp[i]);
        }
        assert(dp[N][0] == ans);
      }
    }
  } catch (EOFException e) {
  }
}