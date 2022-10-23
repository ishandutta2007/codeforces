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


enum L = 10L^^9;

bool solve(long M, long N, long Q) {
  long P = M * N;
  const g = gcd(P, Q);
  P /= g;
  Q /= g;
  if (!(Q == 1 || Q == 2)) {
    return false;
  }
  if (Q == 1) {
    P *= 2;
    Q *= 2;
  }
  debug {
    writefln("M = %s, N = %s, P = %s, Q = %s", M, N, P, Q);
  }
  // P = a d - b c
  const a = M;
  const b = 1;
  const d = (P + M - 1) / M;
  const c = a * d - P;
  writeln("YES");
  writefln("%s %s", 0, 0);
  writefln("%s %s", a, b);
  writefln("%s %s", c, d);
  return true;
}

void main() {
  try {
    for (; ; ) {
      const M = readLong;
      const N = readLong;
      const K = readLong;
      
      const ans = solve(M, N, K);
      if (!ans) {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}