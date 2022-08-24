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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      auto B = new long[N];
      foreach (i; 0 .. N) {
        B[i] = readLong();
      }
      
      auto sel = new bool[N];
      auto as = A.dup;
      sort(as);
      foreach (k; 0 .. N - 1) {
        if (as[k] == as[k + 1]) {
          foreach (i; 0 .. N) {
            if ((as[k] | A[i]) == as[k]) {
              sel[i] = true;
            }
          }
        }
      }
      long ans;
      foreach (i; 0 .. N) {
        if (sel[i]) {
          ans += B[i];
        }
      }
      writeln(ans);
      
      debug {
        long brt;
        foreach (h; 0 .. 1 << N) {
          if (popcnt(h) >= 2) {
            bool ok = true;
            foreach (i; 0 .. N) if (h & 1 << i) {
              bool every = true;
              foreach (j; 0 .. N) if (h & 1 << j) {
                if (i != j) {
                  every = every && ((A[i] & ~A[j]) != 0);
                }
              }
              ok = ok && !every;
            }
            if (ok) {
              long sum;
              foreach (i; 0 .. N) if (h & 1 << i) {
                sum += B[i];
              }
              writeln(h, " ", sum);
              chmax(brt, sum);
            }
          }
        }
        assert(brt == ans);
      }
    }
  } catch (EOFException e) {
  }
}