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


int N, K;
long[] S;

bool solve() {
  if (K == 1) {
    return true;
  }
  auto as = new long[N + 1];
  foreach_reverse (i; N - K + 1 .. N) {
    as[i] = S[i + 1] - S[i];
  }
  foreach_reverse (i; 0 .. N - K + 1) {
    as[i] = as[i + 1];
  }
  debug {
    writeln("K = ", K);
    writeln("S = ", S);
    writeln("as = ", as);
  }
  foreach (i; 0 .. N - 1) {
    if (!(as[i] <= as[i + 1])) {
      return false;
    }
  }
  const S0 = S[N] - as.sum;
  return (S0 <= 0);
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        K = readInt;
        S = new long[N + 1];
        foreach (i; N - K + 1 .. N + 1) {
          S[i] = readLong;
        }
        
        const ans = solve;
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}