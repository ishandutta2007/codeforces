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
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new int[N]; foreach (i; 0 .. N) A[i] = readInt;
        auto B = new int[N]; foreach (i; 0 .. N) B[i] = readInt;
        
        foreach (i; 0 .. N) {
          if (A[i] > B[i]) {
            swap(A[i], B[i]);
          }
        }
        const sumA = A.sum;
        const sumB = B.sum;
        const lim = sumB - sumA;
        auto dp = new bool[lim + 1];
        dp[0] = 1;
        foreach (i; 0 .. N) {
          const d = B[i] - A[i];
          foreach_reverse (x; 0 .. lim - d + 1) {
            if (dp[x]) {
              dp[x + d] = true;
            }
          }
        }
        
        long ans = long.max;
        foreach (x; 0 .. lim + 1) if (dp[x]) {
          const long sa = sumA + x;
          const long sb = sumB - x;
          chmin(ans, sa^^2 + sb^^2);
        }
        foreach (i; 0 .. N) {
          ans += 1L * (N - 2) * (A[i]^^2 + B[i]^^2);
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}