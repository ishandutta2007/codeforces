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
  debug {
    bool[long] app;
    foreach (i; 0 .. 100) {
      for (int a = 0; ; ++a) {
        if (a !in app) {
          for (int b = 0; ; ++b) {
            const c = a ^ b;
            if ((b !in app) && (c !in app)) {
              writefln("%3d %3d %3d %10b %10b %10b", a, b, c, a, b, c);
              app[a] = app[b] = app[c] = true;
              goto found;
            }
          }
        }
      }
     found:
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readLong() - 1;
        long n = N / 3;
        for (int k = 0; ; ++k) {
          // a \in [2^(2k), 2^(2k+1))
          if (n < 1L << (2 * k)) {
            debug {
              writefln("k = %s, n = %s", k, n);
            }
            long a = 1L << (2 * k);
            a += n;
            long b = 1L << (2 * k + 1);
            foreach (i; 0 .. k) {
              b |= [0L, 2L, 3L, 1L][cast(int)((a >> (2 * i)) & 3)] << (2 * i);
            }
            const c = a ^ b;
            debug {
              writefln("%064b", a);
              writefln("%064b", b);
              writefln("%064b", c);
            }
            writeln([a, b, c][cast(int)(N % 3)]);
            break;
          } else {
            n -= 1L << (2 * k);
          }
        }
      }
    }
  } catch (EOFException e) {
  }
}