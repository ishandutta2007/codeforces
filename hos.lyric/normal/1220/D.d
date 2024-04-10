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
long[] B;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      B = new long[N];
      foreach (i; 0 .. N) {
        B[i] = readLong();
      }
      
      auto cnt = new int[64];
      foreach (i; 0 .. N) {
        ++cnt[bsf(B[i])];
      }
      const em = cnt.maxIndex;
      
      writeln(N - cnt[em]);
      int ou;
      foreach (i; 0 .. N) {
        if (em != bsf(B[i])) {
          if (ou++) write(" ");
          write(B[i]);
        }
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}