import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


int A;

void main() {
  try {
    for (; ; ) {
      A = readInt();
      
      auto x = new int[4];
      foreach (i; 0 .. 4) {
        x[i] = (A >> i) & 1;
      }
      
      auto y = x.dup;
      y.reverse;
      foreach (j; 0 .. 4) {
        if (y[0 .. j].all) {
          y[j] ^= 1;
        }
      }
      y.reverse;
      
      int ans;
      foreach (i; 0 .. 4) {
        ans |= y[i] << i;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}