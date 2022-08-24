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


enum LIM = 10^^6 + 100;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const X = readLong();
      const Y = readLong();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      A.sort;
      
      auto lpf = iota(LIM).array;
      foreach (p; 2 .. LIM) {
        if (lpf[p] == p) {
          for (int n = 2 * p; n < LIM; n += p) {
            chmin(lpf[n], p);
          }
        }
      }
      
      auto freq = new int[LIM];
      foreach (i; 0 .. N) {
        for (int a = A[i]; a > 1; ) {
          const p = lpf[a];
          ++freq[p];
          do {
            a /= p;
          } while (a % p == 0);
        }
      }
      
      long ans = N * X;
      foreach (p; 2 .. LIM) {
        if (ans > (N - freq[p]) * min(X, Y)) {
          long cost;
          foreach (i; 0 .. N) {
            const r = A[i] % p;
            if (r != 0) {
              cost += min(X, Y * (p - r));
              if (ans < cost) {
                break;
              }
            }
          }
          chmin(ans, cost);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}