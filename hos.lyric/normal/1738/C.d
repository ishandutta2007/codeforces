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


enum LIM = 105;

void main() {
  auto ali = new bool[][][](LIM, LIM, 2);
  auto bob = new bool[][][](LIM, LIM, 2);
  foreach (m; 0 .. LIM) foreach (n; 0 .. LIM) foreach (s; 0 .. 2) {
    if (m == 0 && n == 0) {
      ali[m][n][s] = (s == 0);
      bob[m][n][s] = (s != 0);
    } else {
      if (m > 0 && !bob[m - 1][n][s ^ 0]) ali[m][n][s] = true;
      if (n > 0 && !bob[m][n - 1][s ^ 1]) ali[m][n][s] = true;
      if (m > 0 && !ali[m - 1][n][s]) bob[m][n][s] = true;
      if (n > 0 && !ali[m][n - 1][s]) bob[m][n][s] = true;
    }
  }
  debug {
    foreach (m; 0 .. 10) write(m, ": ", ali[m]);
    foreach (m; 0 .. 10) write(m, ": ", bob[m]);
  }
  
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt;
        }
        
        int[2] cnt;
        foreach (i; 0 .. N) {
          ++cnt[A[i] & 1];
        }
        const ans = ali[cnt[0]][cnt[1]][0];
        writeln(ans ? "Alice" : "Bob");
      }
    }
  } catch (EOFException e) {
  }
}