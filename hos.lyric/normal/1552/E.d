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
      const K = readInt();
      auto C = new int[N * K];
      foreach (i; 0 .. N * K) {
        C[i] = readInt() - 1;
      }
      
      auto xss = new int[][N];
      foreach (i; 0 .. N * K) {
        xss[C[i]] ~= i;
      }
      
      auto as = new int[N];
      auto bs = new int[N];
      as[] = -1;
      bs[] = -1;
      auto nums = new int[K - 1];
      foreach (c; 0 .. N) {
        ++nums[c % (K - 1)];
      }
      foreach (k; 0 .. K - 1) {
        alias Entry = Tuple!(int, "x", int, "c");
        Entry[] es;
        foreach (c; 0 .. N) {
          if (as[c] == -1) {
            es ~= Entry(xss[c][k + 1], c);
          }
        }
        es.sort;
        foreach (j; 0 .. nums[k]) {
          const c = es[j].c;
          as[c] = xss[c][k];
          bs[c] = xss[c][k + 1];
        }
      }
      
      foreach (c; 0 .. N) {
        writeln(as[c] + 1, " ", bs[c] + 1);
      }
    }
  } catch (EOFException e) {
  }
}