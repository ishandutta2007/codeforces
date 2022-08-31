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


alias Pt = Tuple!(int, "x", int, "y");

long solve(Pt[] ps) {
  const n = cast(int)(ps.length);
  int mn = int.max;
  foreach (i; 0 .. n) {
    chmin(mn, ps[i].x);
    chmin(mn, ps[i].y);
  }
  foreach (i; 0 .. n) {
    ps[i].x -= mn;
    ps[i].y -= mn;
  }
  int L;
  foreach (i; 0 .. n) {
    chmax(L, ps[i].x);
    chmax(L, ps[i].y);
  }
  ++L;
  debug {
    writeln("ps = ", ps);
    writeln("L = ", L);
  }
  
  int n0, n1;
  auto bit0 = new int[L];
  auto bit1 = new int[L];
  foreach (i; 0 .. n) {
    ++n1;
    bit1.bAdd(ps[i].y, +1);
  }
  
  auto adds = new int[][L];
  foreach (i; 0 .. n) {
    adds[ps[i].x] ~= i;
  }
  long ret;
  foreach (x; 0 .. L) {
    foreach (i; adds[x]) {
      ++n0;
      --n1;
      bit0.bAdd(ps[i].y, +1);
      bit1.bAdd(ps[i].y, -1);
    }
    /*
      sum0 of [0, y) >= 1
      sum0 of [y, L) >= 1
      sum1 of [0, y) >= 1
      sum1 of [y, L) >= 1
    */
    // [lb, ub)
    int lb = 1, ub = L;
    chmax(lb, bit0.bBinarySearch!(s => (s >= 1)));
    chmin(ub, bit0.bBinarySearch!(s => (n0 - s < 1)));
    chmax(lb, bit1.bBinarySearch!(s => (s >= 1)));
    chmin(ub, bit1.bBinarySearch!(s => (n1 - s < 1)));
    if (lb < ub) {
      ret += ub - lb;
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto X = new int[N];
      auto Y = new int[N];
      foreach (i; 0 .. N) {
        X[i] = readInt();
        Y[i] = readInt();
      }
      
      long ans;
      foreach (s; 0 .. 2) {
        Pt[] ps;
        foreach (i; 0 .. N) {
          if ((X[i] + Y[i] + s) % 2 == 0) {
            ps ~= Pt((X[i] + Y[i] + s) / 2, (X[i] - Y[i] + s) / 2);
          }
        }
        ans += solve(ps);
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}