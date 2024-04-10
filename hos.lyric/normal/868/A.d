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
      const A = readToken();
      const N = readInt();
      auto B = new string[N];
      foreach (i; 0 .. N) {
        B[i] = readToken();
      }
      
      const L = cast(int)(A.length);
      auto M = new int[N];
      foreach (i; 0 .. N) {
        M[i] = cast(int)(B[i].length);
      }
      
      auto dp = new bool[L + 1];
      dp[0] = true;
      foreach (i; 0 .. N) {
        foreach (x; 1 .. L + 1) {
          if (x <= M[i] && A[0 .. x] == B[i][M[i] - x .. M[i]]) {
            dp[x] = true;
          }
        }
      }
      foreach (x; 0 .. L) {
        if (dp[x]) {
          foreach (i; 0 .. N) {
            if (x + M[i] <= L && A[x .. x + M[i]] == B[i]) {
              dp[x + M[i]] = true;
            }
          }
        }
      }
      bool ans;
      foreach (x; 0 .. L + 1) {
        if (dp[x]) {
          foreach (i; 0 .. N) {
            if (L - x <= M[i] && A[x .. L] == B[i][0 .. L - x]) {
              ans = true;
            }
          }
        }
      }
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}