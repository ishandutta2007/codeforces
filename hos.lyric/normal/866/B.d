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
  try {
    for (; ; ) {
      const N = readInt();
      const R = readLong();
      auto S = new long[N];
      auto A = new long[N];
      auto B = new long[N];
      foreach (i; 0 .. N) {
        S[i] = readLong();
        A[i] = readLong();
        B[i] = readLong();
      }
      
      long sumS, sumS0, sumS1;
      long ansBase;
      alias Entry = Tuple!(long, "d", long, "s");
      Entry[] es0, es1;
      foreach (i; 0 .. N) {
        sumS += S[i];
        if (A[i] >= B[i]) {
          sumS0 += S[i];
          ansBase += S[i] * A[i];
          es0 ~= Entry(A[i] - B[i], S[i]);
        } else {
          sumS1 += S[i];
          ansBase += S[i] * B[i];
          es1 ~= Entry(B[i] - A[i], S[i]);
        }
      }
      es0.sort;
      es1.sort;
      
      const k = (sumS + R - 1) / R;
      long ans;
      foreach (l; sumS0 / R - 2 .. sumS0 / R + 2 + 1) {
        if (0 <= l && l <= k) {
          long score = ansBase;
          {
            long lot = max(sumS0 - R * l, 0);
            foreach (ref e; es0) {
              const tmp = min(e.s, lot);
              score -= e.d * tmp;
              lot -= tmp;
            }
          }
          {
            long lot = max(sumS1 - R * (k - l), 0);
            foreach (ref e; es1) {
              const tmp = min(e.s, lot);
              score -= e.d * tmp;
              lot -= tmp;
            }
          }
          debug {
            writeln(l, " ", k - l, ": ", score);
          }
          chmax(ans, score);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}