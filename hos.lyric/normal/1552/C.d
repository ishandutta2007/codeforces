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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const K = readInt();
        auto X = new int[K];
        auto Y = new int[K];
        foreach (k; 0 .. K) {
          X[k] = readInt() - 1;
          Y[k] = readInt() - 1;
          if (X[k] > Y[k]) {
            swap(X[k], Y[k]);
          }
        }
        
        auto used = new bool[2 * N];
        foreach (k; 0 .. K) {
          used[X[k]] = true;
          used[Y[k]] = true;
        }
        auto xs = X.dup, ys = Y.dup;
        foreach (u; 0 .. 2 * N) {
          if (!used[u]) {
            ((xs.length < N) ? xs : ys) ~= u;
          }
        }
        
        int ans;
        foreach (i; 0 .. N) foreach (j; 0 .. N) {
          if (xs[i] < xs[j] && xs[j] < ys[i] && ys[i] < ys[j]) {
            ++ans;
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}