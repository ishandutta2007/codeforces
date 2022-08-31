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
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const K = (N + 1) / 2;
      auto dp = new int[][](K + 1, N);
      foreach (k; 0 .. K + 1) {
        dp[k][] = INF;
      }
      foreach (i; 0 .. N) {
        int cost;
        if (i - 1 >= 0) {
          cost += max(A[i - 1] - A[i] + 1, 0);
        }
        if (i + 1 < N) {
          cost += max(A[i + 1] - A[i] + 1, 0);
        }
        dp[1][i] = cost;
      }
      auto dpMin = new int[N + 1];
      foreach (k; 1 .. K) {
        dpMin[0] = INF;
        foreach (i; 0 .. N) {
          dpMin[i + 1] = min(dpMin[i], dp[k][i]);
        }
        foreach (i; 2 .. N) {
          {
            int cost = dpMin[i - 2];
            cost += max(A[i - 1] - A[i] + 1, 0);
            if (i + 1 < N) {
              cost += max(A[i + 1] - A[i] + 1, 0);
            }
            chmin(dp[k + 1][i], cost);
          }
          {
            int cost = dp[k][i - 2];
            cost -= max(A[i - 1] - A[i - 2] + 1, 0);
            cost += max(A[i - 1] - min(A[i - 2], A[i]) + 1, 0);
            if (i + 1 < N) {
              cost += max(A[i + 1] - A[i] + 1, 0);
            }
            chmin(dp[k + 1][i], cost);
          }
        }
      }
      debug {
        foreach (k; 1 .. K + 1) {
          writeln(k, ": ", dp[k]);
        }
      }
      
      foreach (k; 1 .. K + 1) {
        if (k > 1) write(" ");
        write(dp[k].minElement);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}