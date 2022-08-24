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


enum N = 60;

void main() {
  try {
    for (; ; ) {
      const X0 = BigInt(readLong());
      const Y0 = BigInt(readLong());
      const AX = BigInt(readLong());
      const AY = BigInt(readLong());
      const BX = BigInt(readLong());
      const BY = BigInt(readLong());
      const XS = BigInt(readLong());
      const YS = BigInt(readLong());
      const T = BigInt(readLong());
      
      auto xs = new BigInt[N];
      auto ys = new BigInt[N];
      xs[0] = X0;
      ys[0] = Y0;
      foreach (i; 1 .. N) {
        xs[i] = AX * xs[i - 1] + BX;
        ys[i] = AY * ys[i - 1] + BY;
      }
      
      int ans;
      foreach (i; 0 .. N) foreach (j; 0 .. N) {
        BigInt cost;
        cost += abs(XS - xs[i]) + abs(YS - ys[i]);
        cost += abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]);
        if (cost <= T) {
          chmax(ans, abs(i - j) + 1);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}