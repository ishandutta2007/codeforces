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
      const R = readInt();
      auto F = new int[N];
      auto S = new int[N];
      auto P = new real[N];
      foreach (i; 0 .. N) {
        F[i] = readInt();
        S[i] = readInt();
        P[i] = readInt() / 100.0L;
      }
      
      // <= 5000 * (1 / 0.8)^50
      real lo = 0.0L, hi = 1e+12;
      foreach (_; 0 .. 100) {
        const mid = (lo + hi) / 2.0L;
        auto dp = new real[][](N + 1, R + 1);
        dp[N][] = 0.0L;
        foreach_reverse (i; 0 .. N) {
          foreach (x; 0 .. R + 1) {
            dp[i][x] = 0.0;
            dp[i][x] += P[i] * (F[i] + ((x + F[i] <= R) ? dp[i + 1][x + F[i]] : mid));
            dp[i][x] += (1.0L - P[i]) * (S[i] + ((x + S[i] <= R) ? dp[i + 1][x + S[i]] : mid));
            chmin(dp[i][x], mid);
          }
        }
        ((dp[0][0] < mid) ? hi : lo) = mid;
      }
      writefln("%.12f", lo);
    }
  } catch (EOFException e) {
  }
}