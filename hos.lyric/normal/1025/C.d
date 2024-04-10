import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
      const S = readToken();
      const N = cast(int)(S.length);
      
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = "bw".indexOf(S[i]) ^ (i & 1);
      }
      debug {
        writeln("A = ", A);
      }
      
      int ans;
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && A[i] == A[j]; ++j) {}
        chmax(ans, j - i);
      }
      
      int head, tail;
      foreach (i; 0 .. N) {
        if (A[0] == A[i]) {
          ++head;
        } else {
          break;
        }
      }
      foreach_reverse (i; 0 .. N) {
        if (A[i] == A[N - 1]) {
          ++tail;
        } else {
          break;
        }
      }
      foreach (k; 1 .. N) {
        // S[k .. N] ~ S[0 .. k]
        if (A[N - 1] == (A[0] ^ (N & 1))) {
          chmax(ans, min(tail, N - k) + min(head, k));
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}