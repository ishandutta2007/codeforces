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


int M, N;
int[][] A, B;

void main() {
  try {
    for (; ; ) {
      M = readInt();
      N = readInt();
      A = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        A[x][y] = readInt();
      }
      B = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        B[x][y] = readInt();
      }
      
      auto a = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        a[x][y] = A[x][y];
      }
      foreach (x; 0 .. M - 1) foreach (y; 0 .. N - 1) {
        if (a[x][y] != B[x][y]) {
          a[x][y] ^= 1;
          a[x][y + 1] ^= 1;
          a[x + 1][y] ^= 1;
          a[x + 1][y + 1] ^= 1;
        }
      }
      bool ans = true;
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        ans = ans && (a[x][y] == B[x][y]);
      }
      writeln(ans ? "Yes" : "No");
    }
  } catch (EOFException e) {
  }
}