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


enum DOWS = [
"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"
];

void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const T = readToken();
      
      const s = DOWS.countUntil(S);
      const t = DOWS.countUntil(T);
      bool ans;
      foreach (n; [28, 30, 31]) {
        if ((s + n - t) % 7 == 0) {
          debug {
            writeln("ok ", n);
          }
          ans = true;
        }
      }
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}