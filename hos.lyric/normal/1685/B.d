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


int solve(int A, int B, int C, int D, string S) {
  debug {
    writeln("  ", [A, B, C, D], " ", S);
  }
  const N = cast(int)(S.length);
  const cntA = cast(int)(S.count('A'));
  const cntB = cast(int)(S.count('B'));
  if (cntA != A + C + D) return 1;
  if (cntB != B + C + D) return 2;
  
  int odd;
  int[][2] fss;
  for (int i = 0, j; i < N; i = j) {
    for (j = i; j < N && ((S[i] == S[j]) == ((i & 1) == (j & 1))); ++j) {}
    debug {
      writeln("    ", S[i .. j]);
    }
    if ((j - i) % 2 != 0) {
      odd += (j - i) / 2;
    } else {
      fss[S[i] - 'A'] ~= (j - i) / 2;
    }
  }
  foreach (h; 0 .. 2) {
    fss[h].sort;
  }
  debug {
    writeln("    odd = ", odd);
    writeln("    fss = ", fss);
  }
  
  int[2] cs = [C, D];
  foreach (h; 0 .. 2) {
    foreach (ref f; fss[h]) {
      const t = min(f, cs[h]);
      f -= t;
      cs[h] -= t;
    }
  }
  debug {
    writeln("    ", fss, " ", cs);
  }
  foreach (h; 0 .. 2) {
    foreach (ref f; fss[h ^ 1]) if (f >= 1) {
      const t = min(f - 1, cs[h]);
      cs[h] -= t;
    }
  }
  if (cs[0] + cs[1] > odd) {
    return 3;
  }
  
  return 0;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const A = readInt;
        const B = readInt;
        const C = readInt;
        const D = readInt;
        const S = readToken;
        
        const ans = solve(A, B, C, D, S);
        writeln((ans == 0) ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}