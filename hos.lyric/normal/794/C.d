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
      const S = readToken();
      const T = readToken();
      const N = cast(int)(S.length);
      
      auto as = new int[N];
      auto bs = new int[N];
      foreach (i; 0 .. N) {
        as[i] = S[i] - 'a';
        bs[i] = T[i] - 'a';
      }
      as.sort;
      bs.sort;
      int al = 0, ar = (N + 1) / 2;
      int bl = N - N / 2, br = N;
      
      auto cs = new int[N];
      int cl = 0, cr = N;
      for (; ; ) {
        // min
        if (al == ar) {
          break;
        }
        if (bl == br || as[al] < bs[br - 1]) {
          cs[cl++] = as[al++];
        } else {
          cs[--cr] = as[--ar];
        }
        // max
        if (bl == br) {
          break;
        }
        if (al == ar || bs[br - 1] > as[al]) {
          cs[cl++] = bs[--br];
        } else {
          cs[--cr] = bs[bl++];
        }
      }
      
      auto ans = new char[N];
      foreach (i; 0 .. N) {
        ans[i] = cast(char)('a' + cs[i]);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}