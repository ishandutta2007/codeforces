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
      const N = readInt();
      const K = readLong();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      long df(int i, long b) {
        return A[i] - 1 - 3 * b * (1 + b);
      }
      
      long calc(int i, long val) {
        // >= val, < val
        long lo = -1, hi = A[i];
        for (; lo + 1 < hi; ) {
          const mid = (lo + hi) / 2;
          ((df(i, mid) >= val) ? lo : hi) = mid;
        }
        return hi;
      }
      
      // >= K, < K
      long lo = -4 * 10L^^18, hi = 2 * 10L^^9;
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        long num;
        foreach (i; 0 .. N) {
          num += calc(i, mid);
        }
        ((num >= K) ? lo : hi) = mid;
      }
      debug {
        // writeln("lo = ", lo, ", hi = ", hi);
      }
      
      auto bs = new long[N];
      long now;
      foreach (i; 0 .. N) {
        now += bs[i] = calc(i, hi);
      }
      foreach (i; 0 .. N) {
        if (now < K && bs[i] < A[i] && df(i, bs[i]) == lo) {
          ++now;
          ++bs[i];
        }
      }
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(bs[i]);
      }
      writeln();
      
      debug {
        auto brt = new long[N];
        foreach (k; 0 .. K) {
          long mx = long.min;
          int im = -1;
          foreach (i; 0 .. N) {
            if (brt[i] < A[i]) {
              if (chmax(mx, df(i, brt[i]))) {
                im = i;
              }
            }
          }
          assert(im != -1);
          // writeln(im, " ", mx);
          ++brt[im];
        }
        writeln(brt);
        assert(brt == bs);
      }
    }
  } catch (EOFException e) {
  }
}