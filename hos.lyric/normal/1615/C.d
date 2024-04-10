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


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const A = readToken();
        const B = readToken();
        
        int ans = INF;
        if (A == B) {
          ans = 0;
        } else {
          const a = cast(int)(A.count('1'));
          const b = cast(int)(B.count('1'));
          if (a >= 1 && b >= 1 && a == b) {
            int d;
            foreach (i; 0 .. N) {
              if (A[i] != B[i]) {
                ++d;
              }
            }
            chmin(ans, d);
          }
          if (a >= 1 && b >= 1 && (a - 1) + (b - 1) == N - 1) {
            int d;
            foreach (i; 0 .. N) {
              if (A[i] == B[i]) {
                ++d;
              }
            }
            chmin(ans, d);
          }
        }
        
        writeln((ans >= INF) ? -1 : ans);
      }
    }
  } catch (EOFException e) {
  }
}