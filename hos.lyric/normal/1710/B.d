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
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        const M = readLong;
        auto X = new long[N];
        auto P = new long[N];
        foreach (i; 0 .. N) {
          X[i] = readLong;
          P[i] = readLong;
        }
        
        alias Entry = Tuple!(long, "x", long, "a", long, "b");
        auto es = new Entry[3 * N];
        foreach (i; 0 .. N) {
          es[i * 3 + 0] = Entry(X[i] - P[i], +1, -(X[i] - P[i]));
          es[i * 3 + 1] = Entry(X[i]       , -2, +2 * X[i]);
          es[i * 3 + 2] = Entry(X[i] + P[i], +1, -(X[i] + P[i]));
        }
        es.sort;
        
        long maxS = long.min;
        long maxT = long.min;
        {
          long a, b;
          foreach (ref e; es) {
            const x = e.x;
            const y = (a * x + b) - M;
            debug {
              writeln(x, " ", y);
            }
            if (y > 0) {
              chmax(maxS, y + x);
              chmax(maxT, y - x);
            }
            a += e.a;
            b += e.b;
          }
        }
        
        auto ans = new char[N];
        foreach (i; 0 .. N) {
          const s = P[i] + X[i];
          const t = P[i] - X[i];
          ans[i] = (s >= maxS && t >= maxT) ? '1' : '0';
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}