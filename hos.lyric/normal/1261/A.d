import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
        const S = readToken();
        
        string t;
        foreach (_; 0 .. N / 2 - (K - 1)) t ~= '(';
        foreach (_; 0 .. N / 2 - (K - 1)) t ~= ')';
        foreach (_; 0 .. K - 1) t ~= "()";
        debug {
          writeln("t = ", t);
        }
        
        auto s = S.dup;
        writeln(N);
        foreach (i; 0 .. N) {
          foreach (j; i .. N) {
            if (s[j] == t[i]) {
              s[i .. j + 1].reverse;
              writeln(i + 1, " ", j + 1);
              goto found;
            }
          }
          assert(false);
         found:
        }
        assert(s == t);
      }
    }
  } catch (EOFException e) {
  }
}