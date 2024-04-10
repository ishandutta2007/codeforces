import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


int N;
int[] C;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      C = new int[N];
      foreach (i; 0 .. N) {
        C[i] = readInt();
      }
      
      int l, r;
      for (l = 0; l < N && C[0] == C[l]; ++l) {}
      for (r = N - 1; r >= 0 && C[N - 1] == C[r]; --r) {}
      assert(l < N);
      assert(r >= 0);
      
      int ans;
      foreach (i; 0 .. N) {
        chmax(ans, abs(i - ((C[0] == C[i]) ? l : 0)));
        chmax(ans, abs(i - ((C[N - 1] == C[i]) ? r : (N - 1))));
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}