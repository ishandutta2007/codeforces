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
  auto A = new long[3];
  foreach (i; 0 .. 3) {
    A[i] = readLong();
  }
  writeln("First");
  stdout.flush;
  
  enum ini = 10L^^10;
  writeln(ini);
  stdout.flush;
  const i0 = readInt() - 1;
  if (i0 == -1) {
    return;
  }
  A[i0] += ini;
  debug {
    writeln("A = ", A);
  }
  
  auto a = A.dup;
  a.sort;
  const magic = (a[1] - a[0]) + 2 * (a[2] - a[1]);
  writeln(magic);
  stdout.flush;
  const i1 = readInt() - 1;
  if (i1 == -1) {
    return;
  }
  A[i1] += magic;
  debug {
    writeln("A = ", A);
  }
  
  auto b = A.dup;
  b.sort;
  assert(b[1] - b[0] == b[2] - b[1]);
  const diff = b[1] - b[0];
  writeln(diff);
  stdout.flush;
  const i2 = readInt() - 1;
  if (i2 == -1) {
    return;
  }
  assert(false);
}