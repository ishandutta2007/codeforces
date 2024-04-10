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


int N;
int[] A;

bool check(int ban) {
  int[] as;
  foreach (a; A) {
    if (a != ban) {
      as ~= a;
    }
  }
  const asLen = cast(int)(as.length);
  for (int l = 0, r = asLen - 1; l < r; ++l, --r) {
    if (as[l] != as[r]) {
      return false;
    }
  }
  return true;
}

bool solve() {
  for (int l = 0, r = N - 1; l < r; ++l, --r) {
    if (A[l] != A[r]) {
      if (check(A[l])) return true;
      if (check(A[r])) return true;
      return false;
    }
  }
  return true;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        N = readInt();
        A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt();
        }
        
        const ans = solve();
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}