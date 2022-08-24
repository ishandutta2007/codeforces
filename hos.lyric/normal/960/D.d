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


enum E = 61;

void main() {
  try {
    for (; ; ) {
      const Q = readInt();
      auto T = new int[Q];
      auto X = new long[Q];
      auto K = new long[Q];
      foreach (q; 0 .. Q) {
        T[q] = readInt();
        X[q] = readLong();
        if (T[q] == 1 || T[q] == 2) {
          K[q] = readLong();
        }
      }
      
      // e: [2^e, 2^(e+1))
      auto xs = new long[E];
      auto ys = new long[E];
      auto zs = new long[E];
      foreach (q; 0 .. Q) {
        int e = bsr(X[q]);
        switch (T[q]) {
          case 1: {
            (xs[e] += K[q]) &= ((1L << e) - 1);
          } break;
          case 2: {
            (ys[e] += K[q]) &= ((1L << e) - 1);
            long k = K[q] & ((1L << e) - 1);
            foreach (f; e .. E) {
              (zs[f] += k) &= ((1L << f) - 1);
              k <<= 1;
            }
          } break;
          case 3: {
            debug {
              writeln("query ", X[q]);
              writeln("  xs = ", xs);
              writeln("  ys = ", ys);
              writeln("  zs = ", zs);
            }
            long[] ans;
            long u = X[q];
            // u = (1L << e) + ((u - (1L << e) - zs[e]) & ((1L << e) - 1));
            u = (1L << e) + ((u - (1L << e) + xs[e]) & ((1L << e) - 1));
            for (; ; ) {
              const val = (1L << e) + ((u - (1L << e) - xs[e]) & ((1L << e) - 1));
              ans ~= val;
              if (e == 0) {
                break;
              }
              u = (1L << e) + ((u - (1L << e) + ys[e]) & ((1L << e) - 1));
              u >>= 1;
              --e;
            }
            foreach (idx, val; ans) {
              if (idx > 0) write(" ");
              write(val);
            }
            writeln();
          } break;
          default: assert(false);
        }
      }
    }
  } catch (EOFException e) {
  }
}