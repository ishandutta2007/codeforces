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


Int gojo(Int)(Int a, Int b, out Int x, out Int y) {
  if (b != 0) { Int g = gojo(b, a % b, y, x); y -= (a / b) * x; return g; }
  x = 1; y = 0; return a;
}
Tuple!(Int, "b", Int, "m") modSol(Int)(Int b0, Int m0, Int b1, Int m1) {
  Int b, m, x, y;
  const g = gojo(m0, m1, x, y);
  if ((b1 - b0) % g == 0) {
    b = b0 + m0 * ((x * (((b1 - b0) / g) % (m1 / g))) % (m1 / g));
    m = m0 * (m1 / g);
    if ((b %= m) < 0) {
      b += m;
    }
  }
  return Tuple!(Int, "b", Int, "m")(b, m);
}


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const M = readLong();
      const N = readLong();
      const K = readInt();
      auto X = new long[K];
      auto Y = new long[K];
      foreach (k; 0 .. K) {
        X[k] = readLong();
        Y[k] = readLong();
      }
      
      long calc(long x, long y) {
        const res = modSol(x, 2 * M, y, 2 * N);
        debug {
          writeln(x, " ", y, ": ", res);
        }
        return (res.m == 0) ? INF : res.b;
      }
      
      foreach (k; 0 .. K) {
        long ans = INF;
        foreach (x; [X[k], 2 * M - X[k]]) foreach (y; [Y[k], 2 * N - Y[k]]) {
          const res = calc(x, y);
          chmin(ans, res);
        }
        writeln((ans >= INF) ? -1 : ans);
      }
    }
  } catch (EOFException e) {
  }
}