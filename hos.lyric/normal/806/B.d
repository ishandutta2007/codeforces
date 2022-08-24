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


enum M = 5;
enum K = 6;
enum LIM = 10^^6;

int calc(long p, long q) {
  foreach (k; 0 .. K - 1) {
    if (p > (q >> (k + 1))) {
      return k;
    }
  }
  return K - 1;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[][](N, M);
      foreach (i; 0 .. N) foreach (j; 0 .. M) {
        A[i][j] = readInt();
      }
      
      auto cnt = new int[M];
      foreach (i; 0 .. N) foreach (j; 0 .. M) {
        if (A[i][j] != -1) {
          ++cnt[j];
        }
      }
      
      foreach (n; 0 .. LIM) {
        int sum;
        foreach (j; 0 .. M) {
          int k;
          if (A[0][j] != -1 && A[1][j] != -1 && A[0][j] > A[1][j]) {
            k = calc(cnt[j] + n, N + n);
          } else {
            k = calc(cnt[j], N + n);
          }
          if (A[0][j] != -1) sum += 500 * (k + 1) - 2 * (k + 1) * A[0][j];
          if (A[1][j] != -1) sum -= 500 * (k + 1) - 2 * (k + 1) * A[1][j];
        }
        if (sum > 0) {
          writeln(n);
          goto found;
        }
      }
      writeln(-1);
     found:
    }
  } catch (EOFException e) {
  }
}