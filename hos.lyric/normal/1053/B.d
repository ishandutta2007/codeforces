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


enum K = 120;

void main() {
  try {
    for (; ; ) {
      const N = readInt;
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong;
      }
      
      const bs = A.map!(a => popcnt(a)).array;
      debug {
        writeln("bs = ", bs);
      }
      
      auto bsSum = new int[N + 1];
      foreach (i; 0 .. N) {
        bsSum[i + 1] = bsSum[i] + bs[i];
      }
      
      long ans;
      
      // all
      {
        long[2] cnt;
        foreach (i; 0 .. N + 1) {
          ans += cnt[bsSum[i] & 1];
          cnt[bsSum[i] & 1] += 1;
        }
      }
      
      // bad
      foreach (i; 0 .. N) {
        int sum;
        int mx;
        foreach (j; i .. min(i + K, N)) {
          sum += bs[j];
          chmax(mx, bs[j]);
          if (sum % 2 == 0 && 2 * mx > sum) {
            --ans;
          }
        }
      }
      
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}