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
      const P = readInt();
      const Q = readInt();
      const R = readInt();
      auto A = new int[N];
      auto B = new int[N];
      auto C = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
        B[i] = readInt();
        C[i] = readInt();
      }
      
      auto zs = new long[Q + 1];
      foreach (i; 0 .. N) {
        chmax(zs[B[i]], C[i]);
      }
      foreach_reverse (y; 1 .. Q + 1) {
        chmax(zs[y - 1], zs[y]);
      }
      debug {
        writeln("zs = ", zs);
      }
      auto zsSum = new long[Q + 1 + 1];
      foreach (y; 0 .. Q + 1) {
        zsSum[y + 1] = zsSum[y] + zs[y];
      }
      
      auto iss = new int[][P + 1];
      foreach (i; 0 .. N) {
        iss[A[i]] ~= i;
      }
      int ym = 0, zm = 0;
      long ans;
      foreach_reverse (x; 1 .. P + 1) {
        foreach (i; iss[x]) {
          chmax(ym, B[i]);
          chmax(zm, C[i]);
        }
        const y0 = max(ym + 1, zs.binarySearch!(z => (z < zm + 1)));
        ans += (1L * (y0 - (ym + 1)) * R) - (zsSum[y0] - zsSum[ym + 1]);
        ans += 1L * ((Q + 1) - y0) * (R - zm);
        debug {
          writeln(x, " ", ym, " ", zm, " ", y0, " ", ans);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}