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
      const A = readInt();
      const B = readInt();
      
      for (int x = 0; A * x <= N; ++x) {
        if ((N - A * x) % B == 0) {
          const y = (N - A * x) / B;
          int[] ans;
          int pos;
          foreach (i; 0 .. x) {
            foreach (j; 0 .. A) {
              ans ~= pos + (j + 1) % A;
            }
            pos += A;
          }
          foreach (i; 0 .. y) {
            foreach (j; 0 .. B) {
              ans ~= pos + (j + 1) % B;
            }
            pos += B;
          }
          foreach (i; 0 .. N) {
            if (i > 0) write(" ");
            write(ans[i] + 1);
          }
          writeln();
          goto found;
        }
      }
      writeln(-1);
     found:
    }
  } catch (EOFException e) {
  }
}