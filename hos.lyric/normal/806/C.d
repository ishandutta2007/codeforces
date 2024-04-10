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


/*
  1: 1-1
  1+2: 1-3
  1+2+4: 1-7
  1+2+4+8: 1-15
*/
enum E = 45;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      auto bs = new int[E];
      auto cs = new int[E];
      foreach (i; 0 .. N) {
        const e = bsr(A[i]);
        if (A[i] == 1L << e) {
          ++bs[e];
        } else {
          ++cs[e];
        }
      }
      debug {
        writeln("bs = ", bs);
        writeln("cs = ", cs);
      }
      
      int[] ans;
      auto ds = new int[E];
      for (int n = 1; ; ++n) {
        int l;
        for (l = 0; ; ++l) {
          if (bs[l] == 0) {
            break;
          }
          --bs[l];
        }
        if (l == 0) {
          break;
        }
        ++ds[l - 1];
        auto bcs = new int[E];
        bcs[] += bs[];
        bcs[] += cs[];
        int f = E;
        foreach_reverse (e; 0 .. E) {
          chmin(f, e);
          int d = ds[e];
          for (; ; ) {
            if (d == 0) {
              break;
            }
            for (; f >= 0 && bcs[f] == 0; --f) {}
            if (f < 0) {
              break;
            }
            const tmp = min(d, bcs[f]);
            d -= tmp;
            bcs[f] -= tmp;
          }
        }
        if (bcs.all!"a == 0") {
          ans ~= n;
        }
      }
      
      if (ans.empty) {
        writeln(-1);
      } else {
        foreach (index, n; ans) {
          if (index > 0) write(" ");
          write(n);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}