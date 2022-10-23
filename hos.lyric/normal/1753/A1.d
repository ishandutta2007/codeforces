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


int N;
int[] A;

int[] solve() {
  const sumA = A.sum;
  if (sumA % 2 != 0) {
    return null;
  }
  
  auto fs = new bool[N];
  bool greedy(int a, int k) {
    foreach (i; 0 .. N) {
      if (i == 0 || fs[i - 1]) {
        continue;
      }
      if (A[i] == a && k > 0) {
        fs[i] = true;
        --k;
      }
    }
    return (k == 0);
  }
  if (sumA >= 0) {
    if (!greedy(+1, sumA / 2)) return null;
  } else {
    if (!greedy(-1, -sumA / 2)) return null;
  }
  debug {
    writeln("fs = ", fs);
  }
  
  int[] cuts;
  cuts ~= 0;
  foreach (i; 1 .. N) {
    if (fs[i - 1] == fs[i]) {
      assert(!fs[i]);
      cuts ~= i;
    }
  }
  cuts ~= N;
  return cuts;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        N = readInt;
        A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt;
        }
        
        const ans = solve;
        debug {
          writeln(A, ": ", ans);
        }
        const len = cast(int)(ans.length) - 1;
        if (len >= 0) {
          writeln(len);
          foreach (i; 0 .. len) {
            writeln(ans[i] + 1, " ", ans[i + 1]);
          }
        } else {
          writeln(-1);
        }
      }
    }
  } catch (EOFException e) {
  }
}