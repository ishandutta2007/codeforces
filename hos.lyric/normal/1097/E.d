import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex, std.typecons;
import core.bitop, core.thread;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return readToken().to!int; }
long readLong() { return readToken().to!long; }
real readReal() { return readToken().to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


class XRand {
  uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  void setSeed(uint seed) { w ^= seed * 65535; }
  uint next() { uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8; }
  uint nextInt(uint m) { return next() % m; }
  int nextInt(int a, int b) { return a + nextInt(b - a + 1); }
  real nextReal() { return next() / 4294967296.0; }
}

immutable LIM_N = 10^^5 + 10;
int[] K;

int[][] solve(int[] a) {
  debug {
    writefln("solve %s", a);
  }
  const n = cast(int)(a.length);
  if (n == 0) {
    return [];
  }
  
  auto dp = new int[n];
  int[] lis;
  foreach (i; 0 .. n) {
    const pos = lis.lowerBound(a[i]);
    dp[i] = pos + 1;
    if (pos == lis.length) {
      lis ~= a[i];
    } else {
      lis[pos] = a[i];
    }
  }
  debug {
    writefln("  dp = %s", dp);
  }
  const mx = dp.maxElement;
  if (mx <= K[n]) {
    auto seqs = new int[][mx];
    foreach (i; 0 .. n) {
      seqs[dp[i] - 1] ~= a[i];
    }
// foreach(seq;seqs)foreach(h;1..seq.length)assert(seq[h-1]>seq[h]);
    return seqs;
  } else {
    auto used = new int[n];
    int[] seq, rem;
    int j = mx;
    foreach_reverse (i; 0 .. n) {
      if (dp[i] == j) {
        used[i] = true;
        seq ~= a[i];
        --j;
      }
    }
    seq.reverse;
    debug {
      writefln("  seq = %s", seq);
    }
// foreach(h;1..seq.length)assert(seq[h-1]<seq[h]);
    foreach (i; 0 .. n) {
      if (!used[i]) {
        rem ~= a[i];
      }
    }
    return seq ~ solve(rem);
  }
}

int N;
int[] A;

void main() {
  K = new int[LIM_N];
  for (int k = 1; k * (k + 1) / 2 <= LIM_N; ++k) {
    K[k * (k + 1) / 2 .. min((k + 1) * (k + 2) / 2, LIM_N)] = k;
  }
  debug {
    writefln("K = %s", K[0 .. 18]);
  }
  
  foreach (tc; 0 .. readInt()) {
    N = readInt();
    A = new int[N];
    foreach (i; 0 .. N) {
      A[i] = readInt();
    }
    auto ans = solve(A);
    writeln(ans.length);
    foreach (seq; ans) {
      writeln(seq.length, " ", seq.map!(to!string).join(" "));
    }
  }
}