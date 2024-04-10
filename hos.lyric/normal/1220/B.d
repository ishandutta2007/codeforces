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
long[][] M;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = new long[][](N, N);
      foreach (x; 0 .. N) foreach (y; 0 .. N) {
        M[x][y] = readLong();
      }
      
      auto ans = new long[N];
      foreach (i; 0 .. N) {
        const j = (i + 1) % N;
        const k = (i + 2) % N;
        const b = M[i][j] * M[i][k] / M[j][k];
        long lo = 0, hi = 2 * cast(long)(sqrt(cast(real)(b))) + 10;
        for (; lo + 1 < hi; ) {
          const mid = (lo + hi) / 2;
          (mid * mid >= b) ? (hi = mid) : (lo = mid);
        }
        ans[i] = hi;
      }
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ans[i]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}