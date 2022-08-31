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
      auto K = new int[2];
      auto S = new int[][2];
      foreach (i; 0 .. 2) {
        K[i] = readInt();
        S[i] = new int[K[i]];
        foreach (j; 0 .. K[i]) {
          S[i][j] = readInt();
        }
      }
      
      auto dp = new int[][](2, N);
      auto cnt = new int[][](2, N);
      foreach (t; 0 .. 2) foreach (u; 0 .. N) {
        dp[t][u] = -1;
        cnt[t][u] = K[t];
      }
      
      auto que = new int[2 * N * 2];
      int qb, qe;
      foreach (t; 0 .. 2) {
        dp[t][0] = 0;
        que[qe++] = t;
        que[qe++] = 0;
      }
      
      for (; qb != qe; ) {
        const t = que[qb++];
        const x = que[qb++];
        foreach (s; S[t ^ 1]) {
          const tt = t ^ 1;
          const xx = (x - s < 0) ? (x - s + N) : (x - s);
          if (dp[tt][xx] == -1) {
            if (dp[t][x] & 1) {
              if (--cnt[tt][xx] > 0) {
                continue;
              }
            }
            dp[tt][xx] = dp[t][x] + 1;
            que[qe++] = tt;
            que[qe++] = xx;
          }
        }
      }
      
      foreach (t; 0 .. 2) {
        foreach (x; 1 .. N) {
          if (x > 1) write(" ");
          write((dp[t][x] == -1) ? "Loop" : (dp[t][x] & 1) ? "Win" : "Lose");
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}