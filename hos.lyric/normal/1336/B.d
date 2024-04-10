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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        auto N = new int[3];
        foreach (h; 0 .. 3) {
          N[h] = readInt();
        }
        auto A = new long[][3];
        foreach (h; 0 .. 3) {
          A[h] = new long[N[h]];
          foreach (i; 0 .. N[h]) {
            A[h][i] = readLong();
          }
          A[h].sort;
        }
        
        long ans = long.max;
        
        void check(long x, long y, long z) {
          debug {
            writeln("check ", x, " ", y, " ", z);
          }
          const score = (y - z)^^2 + (z - x)^^2 + (x - y)^^2;
          chmin(ans, score);
        }
        void checkH(int h, long y, long z) {
          const pos = A[h].upperBound((y + z) / 2);
          if (pos < N[h]) {
            check(A[h][pos], y, z);
          }
          if (pos - 1 >= 0) {
            check(A[h][pos - 1], y, z);
          }
        }
        
        foreach (h; 0 .. 3) {
          const h1 = (h + 1) % 3;
          const h2 = (h + 2) % 3;
          for (int i1 = 0, i2 = 0; i1 < N[h1] && i2 < N[h2]; ) {
            debug {
              writeln(h1, " ", h2, "; ", i1, " ", i2);
            }
            checkH(h, A[h1][i1], A[h2][i2]);
            if (A[h1][i1] < A[h2][i2]) {
              ++i1;
            } else {
              ++i2;
            }
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}