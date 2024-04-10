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


long M, N;
int K;
long[] A;

bool check(long m, long n) {
  long sum;
  bool all2 = true;
  foreach (k; 0 .. K) {
    const num = A[k] / n;
    if (num >= 2) {
      sum += num;
      all2 = all2 && (num == 2);
    }
  }
  if (m % 2 != 0 && all2) {
    return false;
  }
  if (sum >= m) {
    return true;
  }
  return false;
}

bool solve() {
  if (check(M, N)) return true;
  if (check(N, M)) return true;
  return false;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        M = readLong;
        N = readLong;
        K = readInt;
        A = new long[K];
        foreach (k; 0 .. K) {
          A[k] = readLong;
        }
        
        const ans = solve;
        writeln(ans ? "Yes" : "No");
      }
    }
  } catch (EOFException e) {
  }
}