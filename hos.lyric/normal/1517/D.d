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
      const M = readInt();
      const N = readInt();
      const K = readInt();
      auto yoko = new int[][](M, N - 1);
      foreach (x; 0 .. M) foreach (y; 0 .. N - 1) {
        yoko[x][y] = readInt();
      }
      auto tate = new int[][](M - 1, N);
      foreach (x; 0 .. M - 1) foreach (y; 0 .. N) {
        tate[x][y] = readInt();
      }
      
      auto ans = new int[][](M, N);
      if (K % 2 == 0) {
        auto dp = new int[][][](K / 2 + 1, M, N);
        foreach (k; 1 .. K / 2 + 1) {
          foreach (x; 0 .. M) foreach (y; 0 .. N) {
            dp[k][x][y] = INF;
          }
        }
        foreach (k; 0 .. K / 2) {
          foreach (x; 0 .. M) foreach (y; 0 .. N - 1) {
            chmin(dp[k + 1][x][y + 1], dp[k][x][y] + yoko[x][y]);
            chmin(dp[k + 1][x][y], dp[k][x][y + 1] + yoko[x][y]);
          }
          foreach (x; 0 .. M - 1) foreach (y; 0 .. N) {
            chmin(dp[k + 1][x + 1][y], dp[k][x][y] + tate[x][y]);
            chmin(dp[k + 1][x][y], dp[k][x + 1][y] + tate[x][y]);
          }
        }
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          ans[x][y] = 2 * dp[K / 2][x][y];
        }
      } else {
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          ans[x][y] = -1;
        }
      }
      
      foreach (x; 0 .. M) {
        foreach (y; 0 .. N) {
          if (y > 0) write(" ");
          write(ans[x][y]);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}