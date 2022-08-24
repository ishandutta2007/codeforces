import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum K = 9;

void main() {
  const numCases = readInt();
  foreach (caseId; 0 .. numCases) {
    const N = readInt();
    int ans;
    foreach (k; 0 .. K) {
      int[][2] a;
      foreach (u; 0 .. N) {
        a[(u >> k) & 1] ~= u;
      }
      if (!a[0].empty && !a[1].empty) {
        writefln("%s %s %s %s", a[0].length, a[1].length,
                 a[0].map!(u => u + 1).to!string.replaceAll(regex(`[\[\],]`), ""),
                 a[1].map!(u => u + 1).to!string.replaceAll(regex(`[\[\],]`), ""));
        stdout.flush;
        const res = readInt();
        if (res == -1) {
          import core.stdc.stdlib;
          exit(0);
        }
        chmax(ans, res);
      }
    }
    writefln("-1 %s", ans);
    stdout.flush;
  }
}