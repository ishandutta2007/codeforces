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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new long[N];
        foreach (i; 0 .. N) {
          A[i] = readLong;
        }
        
        auto ls = new long[N + 1];
        auto rs = new long[N + 1];
        ls[0] = -INF;
        foreach (i; 0 .. N) {
          ls[i + 1] = max(ls[i], A[i]);
        }
        rs[N] = +INF;
        foreach_reverse (i; 0 .. N) {
          rs[i] = min(A[i], rs[i + 1]);
        }
        
        bool ans;
        foreach (i; 1 .. N) {
          ans = ans || (ls[i] > rs[i]);
        }
        writeln(ans ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}