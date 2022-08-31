import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


int N;
string[] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new string[N];
      foreach (x; 0 .. N) {
        A[x] = readToken();
      }
      
      auto sum = new int[][](N + 1, N + 1);
      foreach (x; 0 .. N) foreach (y; 0 .. N) {
        sum[x + 1][y + 1] = sum[x + 1][y] + sum[x][y + 1] - sum[x][y] + ((A[x][y] == '#') ? 1 : 0);
      }
      
      auto dp = new int[][][][](N + 1, N + 1, N + 1, N + 1);
      foreach (k; 1 .. N + 1) foreach (l; 1 .. N + 1) {
        foreach (xa; 0 .. N - k + 1) foreach (ya; 0 .. N - l + 1) {
          const xb = xa + k, yb = ya + l;
          if (sum[xa][ya] - sum[xb][ya] - sum[xa][yb] + sum[xb][yb] == 0) {
            dp[xa][xb][ya][yb] = 0;
          } else {
            dp[xa][xb][ya][yb] = max(k, l);
            foreach (x; xa + 1 .. xb) {
              chmin(dp[xa][xb][ya][yb], dp[xa][x][ya][yb] + dp[x][xb][ya][yb]);
            }
            foreach (y; ya + 1 .. yb) {
              chmin(dp[xa][xb][ya][yb], dp[xa][xb][ya][y] + dp[xa][xb][y][yb]);
            }
          }
        }
      }
      writeln(dp[0][N][0][N]);
    }
  } catch (EOFException e) {
  }
}