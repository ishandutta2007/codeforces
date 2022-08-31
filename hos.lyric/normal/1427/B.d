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
        const N = readInt();
        const K = readInt();
        const S = readToken();
        
        int ans;
        int k = K;
        chmin(k, cast(int)(S.count('L')));
        if (S.count('W') == 0) {
          ans = max(2 * k - 1, 0);
        } else {
          foreach (i; 0 .. N) {
            if (S[i] == 'W') {
              ans += (i - 1 >= 0 && S[i - 1] == 'W') ? 2 : 1;
            }
          }
          int[] ds;
          for (int i = 0, j; i < N; i = j) {
            for (j = i; j < N && S[i] == S[j]; ++j) {}
            if (S[i] == 'L' && !(i == 0 || j == N)) {
              ds ~= j - i;
            }
          }
          ds.sort;
          foreach (d; ds) {
            if (k >= d) {
              k -= d;
              ans += 2 * d + 1;
            }
          }
          ans += 2 * k;
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}