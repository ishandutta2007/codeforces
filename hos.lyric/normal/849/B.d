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
      auto Y = new long[N];
      foreach (x; 0 .. N) {
        Y[x] = readLong();
      }
      
      bool ans;
      foreach (i; 0 .. 2) {
        foreach (j; 0 .. N) {
          if (i != j) {
            // (i, Y[i]), (j, Y[j])
            int[] xs;
            foreach (x; 0 .. N) {
              if ((j - i) * (Y[x] - Y[i]) != (Y[j] - Y[i]) * (x - i)) {
                xs ~= x;
              }
            }
            if (!xs.empty) {
              bool ok = true;
              foreach (x; xs) {
                if ((j - i) * (Y[x] - Y[xs[0]]) != (Y[j] - Y[i]) * (x - xs[0])) {
                  ok = false;
                }
              }
              if (ok) {
                ans = true;
              }
            }
          }
        }
      }
      writeln(ans ? "Yes" : "No");
    }
  } catch (EOFException e) {
  }
}