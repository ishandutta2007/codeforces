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

void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T sum = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    sum += bit[x];
  }
  return sum;
}

// min pos s.t. pred(sum of [0, pos))
//   assume pred(sum of [0, pos)) is non-decreasing
int bBinarySearch(alias pred, T)(T[] bit) {
  import core.bitop : bsr;
  import std.functional : unaryFun;
  alias predFun = unaryFun!pred;
  if (predFun(0)) return 0;
  int pos = 0;
  T sum = 0;
  foreach_reverse (e; 0 .. bsr(bit.length) + 1) {
    const x = (pos | 1 << e) - 1;
    if (x < bit.length && !predFun(sum + bit[x])) {
      pos |= 1 << e;
      sum += bit[x];
    }
  }
  return pos + 1;
}




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      const M = readInt();
      auto K = new int[M];
      auto P = new int[M];
      foreach (m; 0 .. M) {
        K[m] = readInt();
        P[m] = readInt();
      }
      
      auto queries = new int[][N + 1];
      foreach (m; 0 .. M) {
        queries[K[m]] ~= m;
      }
      auto ans = new int[M];
      
      auto as = new Tuple!(int, int)[N];
      foreach (i; 0 .. N) {
        as[i] = tuple(A[i], i);
      }
      as.sort!((a, b) => ((a[0] != b[0]) ? (a[0] > b[0]) : (a[1] < b[1])));
      
      auto bit = new int[N];
      foreach (i; 0 .. N) {
        bit.bAdd(as[i][1], 1);
        foreach (m; queries[i + 1]) {
          const res = bit.bBinarySearch!(s => (s >= P[m]));
          ans[m] = A[res - 1];
        }
      }
      
      foreach (m; 0 .. M) {
        writeln(ans[m]);
      }
    }
  } catch (EOFException e) {
  }
}