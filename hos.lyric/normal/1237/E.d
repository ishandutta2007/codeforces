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




void main() {
  debug {
    foreach (m; 1 .. 7) {
      auto cs = new char[][](m, 1 << m);
      foreach (x; 0 .. m) {
        cs[x][] = '.';
      }
      foreach (y; 1 .. 1 << m) {
        cs[m - 1 - bsf(y)][y] = "01"[popcnt((1 << m) - y) & 1 ^ 1];
      }
      foreach (x; 0 .. m) {
        writeln(cs[x]);
      }
      writeln();
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      if (N == 1) {
        writeln(1);
        continue;
      }
      for (int m = 1; ; ++m) {
        if (1 << (m - 1) <= N && N < 1 << m) {
          auto f = new int[1 << m];
          foreach (y; 1 .. 1 << m) {
            f[y] = popcnt((1 << m) - y) & 1 ^ 1 ^ (N & 1);
          }
          int n = (1 << (m - 1)) - 1;
          for (int y = 1; y < (1 << m) - 1; y += 2) {
            if (f[y - 1] != f[y] && f[y] != f[y + 1]) {
              ++n;
            }
          }
          debug {
            writeln("m = ", m, ", top = ", N & 1);
            writeln("  f = ", f);
            writeln("  n = ", n);
          }
          writeln((N == n) ? 1 : 0);
          break;
        }
      }
    }
  } catch (EOFException e) {
  }
}