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


enum L = 43200;

void main() {
  try {
    for (; ; ) {
      const H = readInt();
      const M = readInt();
      const S = readInt();
      const T1 = readInt();
      const T2 = readInt();
      
      int[] hands;
      hands ~= (((H % 12) * 60 + M) * 60 + S) * 1;
      hands ~= (M * 60 + S) * 12;
      hands ~= S * 720;
      int t1 = (T1 % 12) * 60 * 60 * 1;
      int t2 = (T2 % 12) * 60 * 60 * 1;
      if (t1 > t2) {
        swap(t1, t2);
      }
      debug {
        writeln(hands, " ", t1, " ", t2);
      }
      
      bool ans;
      ans = ans || iota(t1, t2).all!(t => (hands.count(t % L) == 0));
      ans = ans || iota(t2, t1 + L).all!(t => (hands.count(t % L) == 0));
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}