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


alias Entry = Tuple!(long, "val", long, "num");

Entry[] solve(long[] A, long M) {
  const N = cast(int)(A.length);
  auto es = new Entry[N];
  foreach (i; 0 .. N) {
    auto e = Entry(A[i], 1);
    for (; e.val % M == 0; ) {
      e.val /= M;
      e.num *= M;
    }
    es[i] = e;
  }
  Entry[] ans;
  for (int i = 0, j; i < N; i = j) {
    long sum;
    for (j = i; j < N && es[i].val == es[j].val; ++j) {
      sum += es[j].num;
    }
    ans ~= Entry(es[i].val, sum);
  }
  debug {
    writeln(ans);
  }
  return ans;
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const ALen = readInt;
        const M = readLong;
        auto A = new long[ALen];
        foreach (i; 0 .. ALen) {
          A[i] = readLong;
        }
        const BLen = readInt;
        auto B = new long[BLen];
        foreach (i; 0 .. BLen) {
          B[i] = readLong;
        }
        
        const resA = solve(A, M);
        const resB = solve(B, M);
        writeln((resA == resB) ? "Yes" : "No");
      }
    }
  } catch (EOFException e) {
  }
}