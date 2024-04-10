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
      const M = readInt();
      auto U = new int[M];
      auto V = new int[M];
      auto D = new long[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
        D[i] = readLong();
      }
      
      auto fs = new long[N];
      foreach (i; 0 .. M) {
        fs[U[i]] -= D[i];
        fs[V[i]] += D[i];
      }
      
      int[] us, vs;
      foreach (u; 0 .. N) {
        if (fs[u] < 0) us ~= u;
        if (fs[u] > 0) vs ~= u;
      }
      const usLen = cast(int)(us.length);
      const vsLen = cast(int)(vs.length);
      auto fus = new long[usLen];
      auto fvs = new long[vsLen];
      foreach (j; 0 .. usLen) {
        fus[j] = -fs[us[j]];
      }
      foreach (k; 0 .. vsLen) {
        fvs[k] = fs[vs[k]];
      }
      
      alias Entry = Tuple!(int, "u", int, "v", long, "d");
      Entry[] ans;
      for (int j = 0, k = 0; j < usLen && k < vsLen; ) {
        const t = min(fus[j], fvs[k]);
        if (t > 0) {
          fus[j] -= t;
          fvs[k] -= t;
          ans ~= Entry(us[j], vs[k], t);
        }
        if (j < usLen && fus[j] == 0) {
          ++j;
        } else if (k < vsLen && fvs[k] == 0) {
          ++k;
        } else {
          assert(false);
        }
      }
      
      writeln(ans.length);
      foreach (ref e; ans) {
        writeln(e.u + 1, " ", e.v + 1, " ", e.d);
      }
    }
  } catch (EOFException e) {
  }
}