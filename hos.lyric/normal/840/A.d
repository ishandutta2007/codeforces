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
      const M = readInt();
      auto A = new long[M];
      foreach (i; 0 .. M) {
        A[i] = readLong();
      }
      auto B = new long[M];
      foreach (i; 0 .. M) {
        B[i] = readLong();
      }
      
      auto as = new Tuple!(long, int)[M];
      auto bs = new Tuple!(long, int)[M];
      foreach (i; 0 .. M) {
        as[i] = tuple(A[i], i);
        bs[i] = tuple(B[i], i);
      }
      as.sort;
      bs.sort;
      
      auto ans = new long[M];
      foreach (i; 0 .. M) {
        ans[bs[i][1]] = as[M - 1 - i][0];
      }
      
      foreach (i; 0 .. M) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}