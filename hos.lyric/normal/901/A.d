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
      const H = readInt();
      auto A = new int[H + 1];
      foreach (d; 0 .. H + 1) {
        A[d] = readInt();
      }
      
      bool amb;
      foreach (d; 0 .. H) {
        amb = amb || (A[d] >= 2 && A[d + 1] >= 2);
      }
      if (!amb) {
        writeln("perfect");
      } else {
        auto ASum = new int[H + 2];
        foreach (d; 0 .. H + 1) {
          ASum[d + 1] = ASum[d] + A[d];
        }
        auto ans = new int[][2];
        ans[0] ~= -1;
        ans[1] ~= -1;
        foreach (d; 1 .. H + 1) {
          foreach (j; 0 .. A[d]) {
            ans[0] ~= ASum[d - 1];
            ans[1] ~= ASum[d - 1] + j % A[d - 1];
          }
        }
        writeln("ambiguous");
        foreach (s; 0 .. 2) {
          foreach (u; 0 .. ASum[H + 1]) {
            if (u > 0) write(" ");
            write(ans[s][u] + 1);
          }
          writeln();
        }
      }
    }
  } catch (EOFException e) {
  }
}