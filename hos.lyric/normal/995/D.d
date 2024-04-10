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
      const R = readInt();
      auto C = new long[1 << N];
      foreach (i; 0 .. 1 << N) {
        C[i] = readLong();
      }
      auto Z = new int[R];
      auto G = new long[R];
      foreach (r; 0 .. R) {
        Z[r] = readInt();
        G[r] = readLong();
      }
      
      auto cs = C.dup;
      long now = cs.sum;
      foreach (r; 0 .. R + 1) {
        writefln("%.10f", now / cast(real)(1 << N));
        if (r < R) {
          now -= cs[Z[r]];
          cs[Z[r]] = G[r];
          now += cs[Z[r]];
        }
      }
    }
  } catch (EOFException e) {
  }
}