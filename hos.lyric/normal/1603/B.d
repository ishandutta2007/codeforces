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


long solve(long X, long Y) {
  const c = Y / X, d = Y % X;
  long a, b, r;
  if (c == 0) {
    a = 1;
    b = 0;
    r = d;
  } else {
    a = c;
    b = 1;
    r = d / 2;
  }
  const n = X * a + r;
  debug {
    // writeln(X, " ", Y, ": ", n);
  }
  assert(1 <= n); assert(n <= 2 * max(X, Y)^^2);
  assert(n % X == Y % n);
  return n;
}

void main() {
  debug {{
    enum lim = 100;
    for (long x = 2; x <= lim; x += 2) for (long y = 2; y <= lim; y += 2) {
      solve(x, y);
    }
  }}
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (_; 0 .. numCases) {
        const X = readLong();
        const Y = readLong();
        
        const ans = solve(X, Y);
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}