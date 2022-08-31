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
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      int[int] fs;
      foreach (i; 0 .. N) {
        int a = A[i];
        for (int p = 2; p^^2 <= a; ++p) {
          if (a % p == 0) {
            int e;
            do {
              ++e;
              a /= p;
            } while (a % p == 0);
            fs[p] |= 1 << e;
          }
        }
        if (a > 1) {
          fs[a] |= 1 << 1;
        }
      }
      debug {
        writeln("fs = ", fs);
      }
      
      long[int] cache;
      long calc(int f) {
        long ret;
        cache.update(f, {
          long app;
          if (f) {
            foreach (e; 1 .. bsr(f) + 1) {
              const ff = ((f & ((1 << e) - 1)) | (f >> e)) & ~1;
              app |= 1L << calc(ff);
            }
          }
          ret = bsf(~app);
          debug {
            writefln("calc %b = %s", f, ret);
          }
          return ret;
        }, (ref long r) {
          return ret = r;
        });
        return ret;
      }
      
      long ans;
      foreach (p, f; fs) {
        ans ^= calc(f);
      }
      writeln(ans ? "Mojtaba" : "Arpa");
    }
  } catch (EOFException e) {
  }
}