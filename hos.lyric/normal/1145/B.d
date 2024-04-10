import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum BAN = [
  // one
  1, 21, 31, 41, 51, 61, 71, 81, 91,
  // seven
  7, 27, 37, 47, 57, 67, 77, 87, 97,
  // nine
  9, 29, 39, 49, 59, 69, 79, 89, 99,
  // ten
  10,
  // eleven
  11,
  // teen
  13, 14, 15, 16, 17, 18, 19,
  // twenty
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
  // seventy
  70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
  // ninety
  90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
];

int A;

void main() {
  try {
    for (; ; ) {
      A = readInt();
      const ans = BAN.find(A).empty;
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}