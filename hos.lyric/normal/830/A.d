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
      const P = readLong();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      auto B = new long[K];
      foreach (j; 0 .. K) {
        B[j] = readLong();
      }
      A.sort;
      B.sort;
      
      long ans = long.max;
      foreach (j0; 0 .. K - N + 1) {
        long mx;
        foreach (i; 0 .. N) {
          chmax(mx, abs(A[i] - B[j0 + i]) + abs(B[j0 + i] - P));
        }
        chmin(ans, mx);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}