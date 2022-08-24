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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const M = readInt();
        const N = readInt();
        auto A = new int[][](M, N);
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          A[x][y] = readInt();
        }
        
        auto deg = new int[][](M, N);
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          if (x - 1 >= 0) {
            ++deg[x - 1][y];
            ++deg[x][y];
          }
          if (y - 1 >= 0) {
            ++deg[x][y - 1];
            ++deg[x][y];
          }
        }
        
        bool ans = true;
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          ans = ans && (A[x][y] <= deg[x][y]);
        }
        if (ans) {
          writeln("YES");
          foreach (x; 0 .. M) {
            foreach (y; 0 .. N) {
              if (y > 0) write(" ");
              write(deg[x][y]);
            }
            writeln;
          }
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}