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
      
      long[] ds;
      foreach (i; 0 .. N) {
        for (long x = 1, y; x <= A[i]; x = y) {
          // [x, y): d
          const d = (A[i] + x - 1) / x;
          y = (d <= 1) ? (A[i] + 1) : ((A[i] + (d - 1) - 1) / (d - 1));
          ds ~= d;
          debug {
            assert(x < y);
            assert((A[i] + x - 1) / x == d);
            assert((A[i] + (y - 1) - 1) / (y - 1) == d);
          }
        }
      }
      ds = ds.sort.uniq.array;
      debug {
        writeln("ds = ", ds);
      }
      
      bool check(long d) {
        long sum;
        foreach (i; 0 .. N) {
          sum += (A[i] + d - 1) / d * d - A[i];
          if (sum > K) {
            return false;
          }
        }
        return true;
      }
      
      const dsLen = cast(int)(ds.length);
      ds ~= ds[dsLen - 1] + K + 1;
      long ans;
      foreach_reverse (j; 0 .. dsLen) {
        if (check(ds[j])) {
          long lo = ds[j], hi = ds[j + 1];
          for (; lo + 1 < hi; ) {
            const mid = (lo + hi) / 2;
            (check(mid) ? lo : hi) = mid;
          }
          ans = lo;
          break;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}