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

// floor(a^(1/k))
ulong floorKthRoot(ulong a, ulong k) {
  import core.bitop : bsr;
  import std.algorithm : min;
  if (a == 0) {
    return 0;
  } else if (k <= 1) {
    return a;
  } else if (k == 2) {
    ulong b = a, x = 0, y = 0;
    for (int e = bsr(a) & ~1; e >= 0; e -= 2) {
      x <<= 1;
      y <<= 1;
      if (b >= (y | 1) << e) {
        b -= (y | 1) << e;
        x |= 1;
        y += 2;
      }
    }
    return x;
  } else if (k <= 40) {
    // min x s.t. x^k >= 2^64
    enum ulong[] HIS =
        [0, 0, 4294967296UL, 2642246, 65536, 7132, 1626, 566, 256, 139, 85, 57,
         41, 31, 24, 20, 16, 14, 12, 11, 10, 9, 8, 7, 7, 6, 6, 6, 5, 5, 5, 5,
         4, 4, 4, 4, 4, 4, 4, 4, 4];
    ulong lo = 1UL << (bsr(a) / k);
    ulong hi = min(1UL << (bsr(a) / k + 1), HIS[cast(size_t)(k)]);
    for (; lo + 1 < hi; ) {
      const ulong mid = (lo + hi) / 2;
      ulong b = mid * mid;
      foreach (i; 2 .. k) b *= mid;
      ((b <= a) ? lo : hi) = mid;
    }
    return lo;
  } else if (k <= 63) {
    return ((1UL << k) <= a) ? 2 : 1;
  } else {
    return 1;
  }
}


enum S = "codeforces";
enum L = cast(int)(S.length);

void main() {
  try {
    for (; ; ) {
      const K = readLong();
      
      const long a = floorKthRoot(K, L);
      foreach (m; 0 .. L + 1) {
        long prod = 1;
        foreach (i; 0 .. L) {
          prod *= ((i < m) ? (a + 1) : a);
        }
        if (prod >= K) {
          foreach (i; 0 .. L) {
            foreach (_; 0 .. ((i < m) ? (a + 1) : a)) {
              write(S[i]);
            }
          }
          writeln();
          break;
        }
      }
    }
  } catch (EOFException e) {
  }
}