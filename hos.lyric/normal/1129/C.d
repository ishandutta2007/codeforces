import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum MO = 10L^^9 + 7;

int M;
int[] A;

void main() {
  try {
    for (; ; ) {
      M = readInt();
      A = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt();
      }
      
      auto dp = new long[][](M + 1, M + 1);
      foreach (i; 0 .. M + 1) {
        dp[i][i] = 1;
        foreach (j; i + 1 .. M + 1) {
          foreach (k; 1 .. 4 + 1) {
            if (i <= j - k) {
              if (k == 4) {
                if (A[j - 4 .. j] == [0, 0, 1, 1]) continue;
                if (A[j - 4 .. j] == [0, 1, 0, 1]) continue;
                if (A[j - 4 .. j] == [1, 1, 1, 0]) continue;
                if (A[j - 4 .. j] == [1, 1, 1, 1]) continue;
              }
              if ((dp[i][j] += dp[i][j - k]) >= MO) {
                dp[i][j] -= MO;
              }
            }
          }
        }
      }
      
      auto com = new int[][](M + 1, M + 1);
      foreach_reverse (i; 0 .. M + 1) foreach_reverse (j; 0 .. M + 1) {
        com[i][j] = (i == M || j == M || A[i] != A[j]) ? 0 : (1 + com[i + 1][j + 1]);
      }
      
      auto rs = new int[M];
      foreach (i; 0 .. M) {
        foreach (j; 0 .. i) {
          chmax(rs[i], com[j][i]);
        }
      }
      
      long ans;
      foreach (j; 1 .. M + 1) {
        foreach (i; 0 .. j) {
          if (j - i > rs[i]) {
            debug {
              writeln("add ", i, " ", j, ": ", dp[i][j]);
            }
            if ((ans += dp[i][j]) >= MO) {
              ans -= MO;
            }
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}