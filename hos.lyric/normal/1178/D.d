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


enum LIM = 10^^5;
bool[] isnp;

void main() {
  isnp = new bool[LIM];
  foreach (p; 2 .. LIM) {
    if (!isnp[p]) {
      for (int n = 2 * p; n < LIM; n += p) {
        isnp[n] = true;
      }
    }
  }
  
  debug {
    for (int n = 3; n <= 1000; ++n) {
      bool found;
      foreach (p; n .. n + n / 2) {
        if (p >= 2 && !isnp[p]) {
          found = true;
        }
      }
      if (!found) {
        writeln("failed ", n);
      }
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      
      int k;
      for (k = 0; k < N / 2; ++k) {
        if (N + k >= 2 && !isnp[N + k]) {
          break;
        }
      }
      debug {
        writeln("N = ", N, ": k = ", k);
      }
      
      int[] as, bs;
      foreach (i; 0 .. N) {
        as ~= i;
        bs ~= (i + 1) % N;
      }
      foreach (i; 0 .. k) {
        as ~= i;
        bs ~= (i + N / 2) % N;
      }
      
      writeln(N + k);
      foreach (i; 0 .. N + k) {
        writeln(as[i] + 1, " ", bs[i] + 1);
      }
    }
  } catch (EOFException e) {
  }
}