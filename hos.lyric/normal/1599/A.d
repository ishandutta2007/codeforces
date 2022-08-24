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
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      A.sort;
      const S = readToken();
      
      auto cs = new char[N];
      cs[N - 1] = S[N - 1];
      foreach_reverse (i; 0 .. N - 1) {
        cs[i] = 'L' ^ 'R' ^ cs[i + 1];
      }
      
      int cnt;
      char last = '@';
      foreach (s; S) {
        if (last != s) {
          ++cnt;
        }
        last = s;
      }
      
      int l = N - cnt, r = N - cnt;
      last = '@';
      foreach (s; S) {
        int i;
        if (last != s) {
          i = r++;
        } else {
          i = --l;
        }
        writeln(A[i], " ", cs[i]);
        last = s;
      }
    }
  } catch (EOFException e) {
  }
}