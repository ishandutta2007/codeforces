import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


int N, I;
int[] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      I = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      A.sort;
      
      int k;
      for (k = N; k >= 1; --k) {
        long logK = bsr(k);
        if (k & k - 1) {
          ++logK;
        }
        debug {
          writeln(k, " ", logK);
        }
        if (N * logK <= 8 * I) {
          break;
        }
      }
      debug {
        writeln("k = ", k);
      }
      
      auto as = A.dup;
      as = as.sort.uniq.array;
      const asLen = cast(int)(as.length);
      auto cnt = new int[asLen];
      foreach (i; 0 .. N) {
        ++cnt[as.lowerBound(A[i])];
      }
      debug {
        writeln("cnt = ", cnt);
      }
      auto sum = new int[asLen + 1];
      foreach (j; 0 .. asLen) {
        sum[j + 1] = sum[j] + cnt[j];
      }
      
      int ans;
      foreach (j; 0 .. asLen) {
        chmax(ans, sum[min(j + k, asLen)] - sum[j]);
      }
      ans = N - ans;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}