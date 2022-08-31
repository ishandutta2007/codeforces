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
      auto T = new int[N];
      auto A = new long[][N];
      foreach (i; 0 .. N) {
        T[i] = readInt();
        A[i] = new long[T[i]];
        foreach (j; 0 .. T[i]) {
          A[i][j] = readLong();
        }
      }
      
      auto ASum = new long[][N];
      foreach (i; 0 .. N) {
        ASum[i] = new long[T[i] + 1];
        foreach (j; 0 .. T[i]) {
          ASum[i][j + 1] = ASum[i][j] + A[i][j];
        }
      }
      
      long ans;
      void solve(int l, int r, long[] dp) {
        if (r - l == 1) {
          foreach (x; 0 .. K + 1) {
            if (K - x <= T[l]) {
              chmax(ans, dp[x] + ASum[l][K - x]);
            }
          }
        } else {
          const mid = (l + r) / 2;
          auto dpL = dp.dup;
          foreach (i; mid .. r) {
            foreach_reverse (x; T[i] .. K + 1) {
              chmax(dpL[x], dpL[x - T[i]] + ASum[i][T[i]]);
            }
          }
          solve(l, mid, dpL);
          auto dpR = dp.dup;
          foreach (i; l .. mid) {
            foreach_reverse (x; T[i] .. K + 1) {
              chmax(dpR[x], dpR[x - T[i]] + ASum[i][T[i]]);
            }
          }
          solve(mid, r, dpR);
        }
      }
      
      solve(0, N, new long[K + 1]);
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}