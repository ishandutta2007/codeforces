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


enum INF = 10L^^9;

long Ask(long w) {
  writeln("? ", w);
  stdout.flush;
  long res = readLong;
  if (res == 0) {
    res = INF;
  }
  return res;
}

void main() {
  const N = readInt;
  
  long lo = 0, hi = 2010L * N;
  for (; lo + 1 < hi; ) {
    const mid = (lo + hi) / 2;
    const res = Ask(mid);
    ((res == 1) ? hi : lo) = mid;
  }
  
  long ans = hi;
  foreach (h; 2 .. N + 1) {
    // check [hi - (h - 1), hi]
    const w = hi / h;
    const res = Ask(w);
    chmin(ans, w * res);
  }
  
  writeln("! ", ans);
  stdout.flush;
}