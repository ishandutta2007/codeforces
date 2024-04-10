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
      int[] fs = [0, 1];
      int[] gs = [1];
      foreach (i; 1 .. N) {
        // g + X f
        auto hs = gs.dup;
        hs ~= [0, 0];
        hs[1 .. $] += fs[];
        if (hs.any!"abs(a) > 1") {
          hs[1 .. $] -= fs[];
          hs[1 .. $] -= fs[];
        }
        if (hs.any!"abs(a) > 1") {
          assert(false);
        }
        gs = fs;
        fs = hs;
      }
      
      if (fs[$ - 1] < 0) {
        fs[] *= -1;
      }
      if (gs[$ - 1] < 0) {
        gs[] *= -1;
      }
      
      writeln(N);
      foreach (j; 0 .. N) {
        write(fs[j], " ");
      }
      writeln(fs[N]);
      writeln(N - 1);
      foreach (j; 0 .. N - 1) {
        write(gs[j], " ");
      }
      writeln(gs[N - 1]);
    }
  } catch (EOFException e) {
  }
}