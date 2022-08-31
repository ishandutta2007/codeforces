import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum K = 5;

int N;
real[] X, Y;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      X = new real[N];
      Y = new real[N];
      foreach (i; 0 .. N) {
        X[i] = readReal();
        Y[i] = readReal();
      }
      
      Tuple!(real, int, int)[] edges;
      foreach (i; 0 .. N) foreach (j; 0 .. N) {
        if (i != j) {
          edges ~= tuple(atan2(Y[j] - Y[i], X[j] - X[i]), i, j);
        }
      }
      edges.sort;
      
      auto dp = new long[][][](K + 1, N, N);
      foreach (i; 0 .. N) {
        dp[0][i][i] = 1;
      }
      foreach (const ref edge; edges) {
        const j = edge[1], k = edge[2];
        foreach (t; 0 .. K) {
          foreach (i; 0 .. N) {
            dp[t + 1][i][k] += dp[t][i][j];
          }
        }
      }
      long ans;
      foreach (i; 0 .. N) {
        ans += dp[K][i][i];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}