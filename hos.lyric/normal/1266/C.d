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


int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

void main() {
  try {
    for (; ; ) {
      const M = readInt();
      const N = readInt();
      
      auto ans = new int[][](M, N);
      if (M == 1) {
        if (N == 1) {
          ans[0][0] = 0;
        } else {
          foreach (y; 0 .. N) {
            ans[0][y] = 2 + y;
          }
        }
      } else {
        if (N == 1) {
          foreach (x; 0 .. M) {
            ans[x][0] = 2 + x;
          }
        } else {
          foreach (x; 0 .. M) foreach (y; 0 .. N) {
            ans[x][y] = lcm(1 + x, 1 + M + y);
          }
        }
      }
      foreach (x; 0 .. M) {
        foreach (y; 0 .. N) {
          if (y > 0) write(" ");
          write(ans[x][y]);
        }
        writeln();
      }
    }
  } catch (EOFException e) {
  }
}