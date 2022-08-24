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
      const L = cast(int)(S.length);
      
      auto kss = new int[][26];
      foreach (k; 0 .. L) {
        kss[S[k] - 'a'] ~= k;
      }
      int ans;
      foreach (a; 0 .. 26) {
        int mx;
        foreach (x; 0 .. L) {
          auto cnt = new int[26];
          foreach (k; kss[a]) {
            ++cnt[S[(k + x) % L] - 'a'];
          }
          int num1;
          foreach (b; 0 .. 26) {
            if (cnt[b] == 1) {
              ++num1;
            }
          }
          chmax(mx, num1);
        }
        ans += mx;
      }
      writefln("%.10f", ans / cast(real)(L));
    }
  } catch (EOFException e) {
  }
}