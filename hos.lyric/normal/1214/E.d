import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
int[] D;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      D = new int[N];
      foreach (i; 0 .. N) {
        D[i] = readInt();
      }
      
      auto ds = new Tuple!(int, int)[N];
      foreach (i; 0 .. N) {
        ds[i] = tuple(D[i], i);
      }
      sort(ds);
      reverse(ds);
      
      auto us = new int[N];
      foreach (j; 0 .. N) {
        const i = ds[j][1];
        us[j] = 2 * i + 1;
      }
      
      Tuple!(int, int)[] ans;
      foreach (j; 1 .. N) {
        ans ~= tuple(us[j - 1], us[j]);
      }
      foreach (j; 0 .. N) {
        const i = ds[j][1];
        assert(j + D[i] <= us.length);
        ans ~= tuple(2 * i + 2, us[j + D[i] - 1]);
        if (j + D[i] == us.length) {
          us ~= 2 * i + 2;
        }
      }
      debug {
        writeln("us = ", us);
      }
      
      foreach (e; ans) {
        writeln(e[0], " ", e[1]);
      }
    }
  } catch (EOFException e) {
  }
}