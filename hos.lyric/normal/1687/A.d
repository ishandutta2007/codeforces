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
        const K = readLong;
        auto A = new long[N];
        foreach (i; 0 .. N) {
          A[i] = readLong;
        }
        
        auto ASum = new long[N + 1];
        foreach (i; 0 .. N) {
          ASum[i + 1] = ASum[i] + A[i];
        }
        
        const k = min(K, N);
        long ans;
        foreach (i; 0 .. N - k + 1) {
          chmax(ans, ASum[cast(int)(i + k)] - ASum[cast(int)(i)]);
        }
        foreach (j; 0 .. k) {
          ans += (K - 1 - j);
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}