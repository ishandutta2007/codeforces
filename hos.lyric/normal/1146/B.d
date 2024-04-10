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
string T;

void main() {
  try {
    for (; ; ) {
      T = readToken();
      N = cast(int)(T.length);
      
      int cnt;
      foreach (i; 0 .. N) {
        if (T[i] != 'a') {
          ++cnt;
        }
      }
      
      string ans;
      if (cnt % 2 == 0) {
        const string s = T[0 .. N - cnt / 2];
        string ss;
        foreach (c; s) {
          if (c != 'a') {
            ss ~= c;
          }
        }
        if (s ~ ss == T) {
          ans = s;
        }
      }
      writeln((ans == "") ? ":(" : ans);
    }
  } catch (EOFException e) {
  }
}