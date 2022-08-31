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


int M, N;
int[][] A;

bool check(int y0, int y1) {
  foreach (x; 0 .. M) {
    int cnt;
    foreach (y; 0 .. N) {
      const a = A[x][(y == y0) ? y1 : (y == y1) ? y0 : y];
      if (a != y) {
        ++cnt;
      }
    }
    if (cnt > 2) {
      return false;
    }
  }
  debug {
    writeln("ok ", y0, " ", y1);
  }
  return true;
}

bool solve() {
  if (check(-1, -1)) {
    return true;
  }
  foreach (y0; 0 .. N) foreach (y1; y0 + 1 .. N) {
    if (check(y0, y1)) {
      return true;
    }
  }
  return false;
}

void main() {
  try {
    for (; ; ) {
      M = readInt();
      N = readInt();
      A = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        A[x][y] = readInt() - 1;
      }
      
      const ans = solve();
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}