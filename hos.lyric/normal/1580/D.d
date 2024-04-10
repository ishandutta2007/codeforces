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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      long[] solve(int l, int r) {
        auto ret = new long[r - l + 1];
        if (l < r) {
          int im = -1;
          foreach (i; l .. r) {
            if (!~im || A[im] > A[i]) {
              im = i;
            }
          }
          const resL = solve(l, im);
          const resR = solve(im + 1, r);
          ret[] = -INF;
          foreach (x; 0 .. im - l + 1) foreach (y; 0 .. r - im) {
            chmax(ret[x + y], resL[x] + resR[y] - A[im] * 2L * x * y);
            chmax(ret[x + y + 1], resL[x] + resR[y] - A[im] * 2L * (x * y + x + y) + A[im] * (M - 1));
          }
        }
        return ret;
      }
      const auto ans = solve(0, N);
      writeln(ans[M]);
    }
  } catch (EOFException e) {
  }
}