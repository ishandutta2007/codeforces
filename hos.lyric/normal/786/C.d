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
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
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
        A[i] = readInt() - 1;
      }
      
      auto app = new int[N];
      app[] = -1;
      auto nxt = new int[N];
      foreach_reverse (i; 0 .. N) {
        nxt[i] = app[A[i]];
        app[A[i]] = i;
      }
      
      auto ans = new int[N + 1];
      auto kss = new int[][N];
      foreach (k; 1 .. N + 1) {
        kss[0] ~= k;
      }
      
      auto bit = new int[N];
      foreach (a; 0 .. N) {
        if (app[a] != -1) {
          bit.bAdd(app[a], +1);
        }
      }
      foreach (i; 0 .. N) {
        foreach (k; kss[i]) {
          ++ans[k];
          const pos = bit.bBinarySearch!(s => (s > k)) - 1;
          if (pos < N) {
            kss[pos] ~= k;
          }
        }
        bit.bAdd(i, -1);
        if (nxt[i] != -1) {
          bit.bAdd(nxt[i], +1);
        }
      }
      
      foreach (k; 1 .. N + 1) {
        if (k > 1) write(" ");
        write(ans[k]);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}